#pragma once

#include <fstream>
#include "class.h"

#define RANGE 100
#define AMOUNT 100


bool fileInit(char *fileName, int amount);
vector getRepeats(char *fileName);