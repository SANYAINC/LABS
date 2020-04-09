#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct properties {
    int mAmount = 0;
    vector <int> mLines;
};

void scanCPP(const char* fileName, map <string, properties>& identifiers);

vector <string> split(string& line);
bool isSplitter(char c);
bool isKeyWord(string& word);
bool comp(char c, const char* str);


int main() {
    map <string, properties> identifiers;

    scanCPP("../VAR6/9.4/source.cpp", identifiers);

    ofstream f("out.txt");
    for (auto p = identifiers.begin(); p != identifiers.end(); ++p) {
        cout << "|" << p->first << "| met for " << p->second.mAmount << " times at: ";
        f << "|" << p->first << "| met for " << p->second.mAmount << " times at: ";
        for (int i = 0; i < p->second.mLines.size(); ++i) {
            cout << p->second.mLines[i];
            f << p->second.mLines[i];
            if (i != p->second.mLines.size() - 1) {
                cout << ", ";
                f << ", ";
            }
        }
        cout << endl;
        f << endl;
    }


    return 0;
}




vector <string> split(string& line) {
    vector <string> result;
    string tmp;
    int index = 0;
    int wordIndex = 0;
    while (index != line.size()) {
        if (isSplitter(line[index])) {
            index++;
            continue;
        } else {
            //Пропускаем строки и комментарии
            if (line[index] == '/' and line[index+1] == '/') {
                break;
            }
            if (line[index] == '"') {
                index++;
                while (line[index] != '"') {
                    index++;
                }
                index++;
                continue;
            }
            if (comp(line[index], "'")) {
                index++;
                while (!comp(line[index], "'")) {
                    index++;
                }
                index++;
                continue;
            }
            while (index != line.size() and !isSplitter(line[index])) {
                tmp.push_back(line[index++]);
            }
            result.push_back(tmp);
            tmp.clear();
            wordIndex++;
        }
    }
    for (auto i = result.begin(); i != result.end(); ++i) {
        if (isKeyWord(*i) or ((*i)[0] >= 48 and (*i)[0] <= 57)) {
            i = result.erase(i) - 1;
        }
    }
    return result;
}

bool isSplitter(char c) {
    switch (c) {
        case ' ':
        case '<':
        case '>':
        case ';':
        case '{':
        case '}':
        case '=':
        case '(':
        case ')':
        case '*':
        case ',':
        case '&':
        case '!':
        case '.':
        case '[':
        case ']':
        case '+':
        case '-':
        case ':':
            return true;
        default:
            return false;
    }
}

bool isKeyWord(string& word) {
    return  word == "using" or word == "namespace" or word == "int" or word == "void" or word == "const" or
            word == "char" or word == "bool" or word == "while" or word == "if" or word == "and" or word == "continue" or
            word == "else" or word == "return" or word == "switch" or word == "case" or word == "default" or word == "true" or
            word == "false" or word == "for" or word == "struct";
}

void scanCPP(const char* fileName, map <string, properties>& identifiers) {
    ifstream f(fileName);
    if (!f.is_open()) {
        cerr << "CANT OPEN FILE" << endl;
        exit(9);
    }

    string bufferLine;
    vector <string> bufferWords;
    properties buffer;
    int lineCounter = 1;

    while (!f.eof()) {
        getline(f, bufferLine);

        //Если строка пуста, идем на следующую
        if (bufferLine.empty()) {
            lineCounter++;
            continue;
        }
        //Если строка - директива препроцессора, идем на следующую
        if (bufferLine[0] == '#') {
            lineCounter++;
            continue;
        }
        //Если строка - комментарий, идем на следующую
        if (bufferLine[0] == '/') {
            lineCounter++;
            continue;
        }

        bufferWords = split(bufferLine); //Получаем из строки вектор идентификиторов
        for (int w = 0; w < bufferWords.size(); ++w) {
            if (identifiers.count(bufferWords[w]) == 0) {
                //Если не встречали, инициализируем по умолчанию
                buffer.mAmount = 1;
                buffer.mLines.push_back(lineCounter);
                identifiers[bufferWords[w]] = buffer;
            } else {
                //В противном случае инкрементируем счетчик и, если нужно, добавляем в map
                identifiers[bufferWords[w]].mAmount++;
                if (find(identifiers[bufferWords[w]].mLines.begin(), identifiers[bufferWords[w]].mLines.end(),
                         lineCounter) == identifiers[bufferWords[w]].mLines.end()) {
                    identifiers[bufferWords[w]].mLines.push_back(lineCounter);
                }
            }
            buffer.mLines.clear();
        }
        lineCounter++;
    }
}

bool comp(char c, const char* str) {
    return c == str[0];
}