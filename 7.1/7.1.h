#pragma once

#include <iostream>
#include <fstream>
#include <ctime>

#define RANGE 100
#define AMOUNT 100

using namespace std;

bool createFileWithIntegers(string &name, int amount);

int* createFileWithRepeats(string &name);

void expandMemory(int *&array, int oldSize, int newSize);
