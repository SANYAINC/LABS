#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSeparator(char character);
bool comparator(vector<char>& v1, vector<char>& v2);

int main() {
    char text[] = "Celebrimbor was a prince, who lived in Middle-earth."
                  "He was a ruler of Eregion in the Second Age, and a master smith."
                  "He is remembered primarily for his creation of the three greatest Elven Rings of Power: Vilya, Narya, and Nenya.";
    vector< vector<char> > result;
    vector<char> tmp;

    int indexInText = 0;
    int wordIndex = 0;

    while(text[indexInText]) {
        if (isSeparator(text[indexInText])) {
            indexInText++;
            continue;
        }
        result.push_back(tmp);
        while(!isSeparator(text[indexInText])) {
            result[wordIndex].push_back(text[indexInText++]);
        }
        wordIndex++;
    }

    sort(result.begin(), result.end(), comparator);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
        }
        cout << ' ';
    }

    return 0;
}

bool isSeparator(char character) {
    switch (character) {
        case '\0': return true;
        case ' ': return true;
        case ',': return true;
        case '.': return true;
        case ':': return true;
        case '!': return true;
        case '?': return true;
        case ';': return true;
        case '(': return true;
        case ')': return true;
        default: return false;
    }
}
bool comparator(vector<char>& v1, vector<char>& v2) {
    return v1.size() > v2.size();
}