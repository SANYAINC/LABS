#include "6.1.h"
#include "../../common/common.h"

void deleteRepeats(string &str) {
    int cou = 1; //Счетчик вхождений символа
    int size = str.size();
    char *buffer = new char[size](); //Буфер для хранения символов, которые нужно исключить
    int bufIndex = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            //Ищем повторения у каждого символа
            if (i != j and str[i] == str[j]) {
                cou++;
            }
        }
        //Если символ нужно удалить, ищем его в буфере. Если его нет, добавляем.
        if (cou >= 2) {
            if (arrays::find(buffer, str[i], size) == -1) {
                buffer[bufIndex++] = str[i];
            }
        }
        cou = 0;
    }
    //Удаляем символы из буфера в исхожной строке
    excludeChars(str, buffer, bufIndex);
}
void excludeChars(string &str, char *buffer, int charsAmount) {
    int size = str.size();
    //Для каждого символа из строки проверяем не входит ли он в буфер
    for (int i = 0; i < charsAmount; ++i) {
        for (int j = 0; j < size; ++j) {
            if (str[j] == buffer[i]) {
                //Если входит, удаляем и сдвигаем размер и индекс
                str.erase(j, 1);
                size--;
                j--;
            }
        }
    }
}

void decToHex(string &str) {
    //Ищем разделитель целой и дробной частей, если нет то считаем число целым
    int dotPos = str.find('.');
    bool isInteger = false;
    if (!(dotPos - string::npos)) {
        isInteger = true;
    }

    //Переводим число в double, запоминаем, отрицательно ли оно и делаем положительным
    double number = stod(str);
    bool isNegative = number < 0;
    number = abs(number);

    str.erase(); //очищаем строку
    int integerPart = int (number); //Берем целую часть

    //Записываем остатки от деления, и результат последнего
    while (integerPart > 15) {
        str += getHexChar(integerPart%16);
        integerPart /= 16;
    }
    str += getHexChar(integerPart);

    //Отражаем строку
    int integerLen = str.size();
    for (int i = 0; i < integerLen / 2; ++i) {
        swap(str[i], str[integerLen - 1 - i]);
    }
    //Если число было отрицательно, добавляем в начало минус
    if (isNegative) {
        str.insert(0, "-");
    }
    //если число было целое, можно его возвращать
    if (isInteger) {
        return;
    }

    str += '.';
    double floatPart = number - int (number);//Извлекаем дробную часть
    int epsilonCounter = 0; //Кол-во знаков после запятой
    //умножение на 16, извлечение дробной части до получения нужной точности
    while (epsilonCounter < 6) {
        floatPart *= 16;
        str += getHexChar(int(floatPart));
        floatPart = floatPart - int (floatPart);
        epsilonCounter++;
    }

}
char getHexChar(int number) {
    if (number < 0 or number > 15) {
        return '?';
    }
    switch (number) {
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        default: return static_cast<char>(number + 48);
    }
}

string maxConsonantsWord(string &str) {
    string maxConsonantStr;
    int strLen = str.size();
    char *buffer = new char[100] {0}; //буфер для текущего слова
    int maxConsonant = 0; //максимальное количество согласных
    int absIndex = 0;   //Индекс обхода строки

    while (absIndex < strLen) {
        int letterCou = 0;  //счетчик букв
        int consonantCou = 0;   //счетчик согласных
        int bufferIndex = 0;    //Индекс обхода буфера
        //Если текущий символ не разделитель, записываем его в буфер. увеличиваем счетчики всех букв
        while (absIndex < strLen and !isSeparator(str[absIndex])) {
            buffer[bufferIndex++] = str[absIndex++];
            letterCou++;
            if (isConsonant(str[absIndex])) {
                consonantCou++;
            }
        }
        //Если не была найдена ни одна буква, продолжаем обход строки.
        if (!letterCou) {
            absIndex++;
            continue;
        }
        //Если нашли больше согласных, чем текущее максимальное
        if (consonantCou >= maxConsonant) {
            if (consonantCou > maxConsonant) {
                maxConsonantStr.erase(); //Очищаем все что было до этого
            }
            maxConsonant = consonantCou;
            maxConsonantStr += buffer;
            maxConsonantStr += ' ';
        }
        //Очищаем буфер
        for (int i = 0; i < letterCou; ++i) {
            buffer[i] = 0;
        }
        absIndex++;
    }
    return maxConsonantStr;
}
bool isConsonant(char letter) {

    //Определяет, является ли символ согласной буквой

    switch (letter) {
        case 'b':
        case 'B':
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'f':
        case 'F':
        case 'g':
        case 'G':
        case 'h':
        case 'H':
        case 'j':
        case 'J':
        case 'k':
        case 'K':
        case 'l':
        case 'L':
        case 'm':
        case 'M':
        case 'n':
        case 'N':
        case 'p':
        case 'P':
        case 'q':
        case 'Q':
        case 'r':
        case 'R':
        case 's':
        case 'S':
        case 't':
        case 'T':
        case 'v':
        case 'V':
        case 'w':
        case 'W':
        case 'x':
        case 'X':
        case 'z':
        case 'Z': {return true;}
        default: {return false;}
    }
}
bool isSeparator(char symbol) {

    //Определяет, является ли символ разделителем

    switch (symbol) {
        case ' ':
        case '.':
        case ',':
        case '!':
        case '?':
        case ':':
        case ';':
        case '-':
        case '(':
        case ')':
        case '/': {return true;}
        default: {return false;}
    }

}
