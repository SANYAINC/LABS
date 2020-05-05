#pragma once

#include "../sEye_Entity/Entities.h"
#include "../sEye_Entity/Containers.h"

void scanFrame(container& result);
void testContainer(container& result);

char randBool();
char randSex();
const char* randColor();
const char* randItemName();
char* randRegisterPlate();
char* randItemTime();
char randBodyType();