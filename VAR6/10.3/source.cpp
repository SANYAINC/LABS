#include <iostream>
#include <ctime>
#include "sEye_Entity/sEye_Entity.h"
#include "sEye_Entity/sEye_Entity_Vector.h"

using namespace std;

void scanFrame(entityVector& result);
char randBool();
char randSex();
const char* randColor();
const char* randItemName();
const char* randRegisterPlate();
const char* randTime();
char randBodyType();


int main() {
    srand(time(nullptr));

    entityVector allEntities;

    scanFrame(allEntities);

    for (int i = 0; i < allEntities.getSize(); ++i) {
        allEntities[i]->print();
    }

    return 0;
}





void scanFrame(entityVector& result) {
    int objects = rand()%3+1;
    int type;


    for (int i = 0; i < objects; ++i) {
        type = rand()%5;
        short xMin = rand()%1600;
        short xMax = rand()%1600 + xMin;
        short yMin = rand()%1000;
        short yMax = rand()%1000 + yMin;
        switch (type) {
            case 0: {
                human a(xMin, xMax, yMin, yMax, randSex(), randBool(), randBool(), randBool());
                result.pushBack(a);
                break;
            }
            case 1: {
                item a(xMin, xMax, yMin, yMax, randItemName(), randTime());
                result.pushBack(a);
                break;
            }
            case 2: {
                bike a(xMin, xMax, yMin, yMax, randColor(), randBool());
                result.pushBack(a);
                break;
            }
            case 3: {
                cyclist a(xMin, xMax, yMin, yMax, randSex(), randBool(), randBool(), randBool(), randColor(), randBool(), randBool());
                result.pushBack(a);
                break;
            }
            case 4: {
                car a(xMin, xMax, yMin, yMax, randColor(), randRegisterPlate(), randBodyType(), randBool());
                result.pushBack(a);
                break;
            }
        }
    }
}

char randBool() {
    int type = rand()%3;
    switch (type) {
        case 0: {
            return 'Y';
        }
        case 1: {
            return 'N';
        }
        case 2: {
            return 'U';
        }
    }
    return ' ';
}
char randSex() {
    int type = rand()%3;
    switch (type) {
        case 0: {
            return 'M';
        }
        case 1: {
            return 'F';
        }
        case 2: {
            return 'U';
        }
    }
    return ' ';
}
const char* randItemName() {
    int type = rand()%3;
    switch (type) {
        case 0: {
            return "Bag";
        }
        case 1: {
            return "Backpack";
        }
        case 2: {
            return "Case";
        }
    }
    return "";
}
const char* randTime() {
    int type = rand()%10;
    switch (type) {
        case 0: {
            return "11:05";
        }
        case 1: {
            return "11:45";
        }
        case 2: {
            return "12:10";
        }
        case 3: {
            return "12:50";
        }
        case 4: {
            return "13:15";
        }
        case 5: {
            return "13:55";
        }
        case 6: {
            return "14:20";
        }
        case 7: {
            return "15:00";
        }
        case 8: {
            return "15:25";
        }
        case 9: {
            return "16:00";
        }
    }
    return "";
}
const char* randColor() {
    int type = rand()%5;
    switch (type) {
        case 0: {
            return "Red";
        }
        case 1: {
            return "White";
        }
        case 2: {
            return "Blue";
        }
        case 3: {
            return "Black";
        }
        case 4: {
            return "Yellow";
        }
    }
    return "";
}
const char* randRegisterPlate() {
    int type = rand()%10;
    switch (type) {
        case 0: {
            return "1656AA-2";
        }
        case 1: {
            return "7492BC-7";
        }
        case 2: {
            return "1739PE-7";
        }
        case 3: {
            return "6408MX-7";
        }
        case 4: {
            return "5033HI-7";
        }
        case 5: {
            return "0098CB-7";
        }
        case 6: {
            return "1111AA-7";
        }
        case 7: {
            return "7402PX-2";
        }
        case 8: {
            return "5839ME-4";
        }
        case 9: {
            return "7492PB-4";
        }
    }
    return "";
};
char randBodyType() {
    int type = rand()%5;
    switch (type) {
        case 0: {
            return '0';
        }
        case 1: {
            return '1';
        }
        case 2: {
            return '2';
        }
        case 3: {
            return '3';
        }
        case 4: {
            return '4';
        }
    }
    return ' ';
}
