#pragma once
#include <iostream>

using namespace std;

//Удаление символов, встречающихся более 2х раз
void deleteRepeats(string &str);
void excludeChars(string &str, char *buffer, int charsAmount); //Удалить из строки символы встречающиеся более 2х раз

//Перевод строки из десятичной в шестнадцатиричную систему
void decToHex(string &str);
char getHexChar(int number); //Перевести число [0-15] из десятичной системы (int) в шестнадцатиричную (char)

//Выделение слов с максимальным количеством согласных
string maxConsonantsWord(string &str);
bool isSeparator(char symbol); //Является ли символ разделителем
bool isConsonant(char letter); //Явялется ли символ согласной буквой

