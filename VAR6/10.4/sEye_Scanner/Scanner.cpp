#include "Scanner.h"

void scanFrame(container& result) {
    int objects = rand()%3+1;
    int type;

    for (int i = 0; i < objects; ++i) {
        type = rand()%5;
        int xMin = rand()%(FRAME_WIDTH - 1);
        int xMax = xMin + 1 + rand()%(FRAME_WIDTH - xMin - 1);
        int yMin = rand()%(FRAME_HEIGHT - 1);
        int yMax = yMin + 1 + rand()%(FRAME_HEIGHT - yMin - 1);
        switch (type) {
            case 0: {
                human a(xMin, xMax, yMin, yMax, randSex(), randBool(), randBool(), randBool());
                result.pushBack(a);
                break;
            }
            case 1: {
                char* time = randItemTime();

                item a(xMin, xMax, yMin, yMax, randItemName(), time);
                result.pushBack(a);
                delete [] time;
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
                char* plate = randRegisterPlate();

                car a(xMin, xMax, yMin, yMax, randColor(), plate, randBodyType(), randBool());
                result.pushBack(a);
                delete [] plate;
                break;
            }
        }
    }
}
void testContainer(container& result) {
    item test;

    result.pushAt(0, test);
    std::cout << "PUSHED AT 0" << std::endl;
    result.pushAt(1, test);
    std::cout << "PUSHED AT 1" << std::endl;
    result.pushBack(test);
    std::cout << "PUSHED IN THE END" << std::endl;
    result.print();
    std::cout << "SHOWN" << std::endl;
    result.removeAt(result.getSize()-1);
    std::cout << "REMOVED IN THE END" << std::endl;
    result.removeAt(1);
    std::cout << "REMOVED AT 1" << std::endl;
    result.removeAt(0);
    std::cout << "REMOVED AT 0" << std::endl;
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
    int type = rand()%5;
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
        case 3: {
            return "Bottle";
        }
        case 4: {
            return "Box";
        }
    }
    return "";
}
char* randItemTime() {
    char* time = new char[6];
    time[5] = 0;

    int hrs = rand()%13;
    int mnt = rand()%61;

    time[0] = static_cast<char>(hrs/10 + 48);
    time[1] = static_cast<char>(hrs%10 + 48);

    time[2] = ':';

    time[3] = static_cast<char>(mnt/10 + 48);
    time[4] = static_cast<char>(mnt%10 + 48);

    time[5] = 0;

    return time;
}
const char* randColor() {
    int type = rand()%11;
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
        case 5: {
            return "Cyan";
        }
        case 6: {
            return "Green";
        }
        case 7: {
            return "Orange";
        }
        case 8: {
            return "Pink";
        }
        case 9: {
            return "Purple";
        }
        case 10: {
            return "Grey";
        }
    }
    return "";
}
char* randRegisterPlate() {
    char* plate = new char[9];
    plate[8] = 0;

    for (int i = 0; i < 4; ++i) {
        plate[i] = static_cast<char>(rand()%10 + 48);
    }

    for (int i = 4; i < 6; ++i) {
        plate[i] = static_cast<char>(rand()%26 + 65);
    }

    plate[6] = '-';
    plate[7] = static_cast<char>(rand()%8 + 48);

    return plate;
}

char randBodyType() {
    return static_cast<char>(rand()%10 + 48);
}
