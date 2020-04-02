#pragma once
#include <vector>

#define AMOUNT 100
#define RANGE 100

using namespace std;

bool fileInit(char* fileName);
vector<int> getRepeats(char* fileName);