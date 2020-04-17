#include <iostream>
#include <vector>
#include <ctime>
#include "s_Eye_Entity/sEye_Entity.h"

using namespace std;

vector<entity*> scanFrame();
char randBool();
char randSex();
const char* randColor();
const char* randItemName();
const char* randRegisterPlate();
const char* randTime();
char randBodyType();

int main() {
    srand(time(nullptr));

    vector<entity*> objects = scanFrame();

    for (auto i = objects.begin(); i != objects.end() ;) {
        cout << **i;
        delete *i;
        i = objects.erase(i);
    }

    cout << "\n\n\n\n\n\n";

    cyclist man(10,20,30,40, 'M', 'Y', 'Y', 'N', "Red", 'Y', 'N');
    cout << "First object:" << endl;
    man.print();
    cyclist friendMan(man);
    man.setVehicleColor("Blue");
    cout << "First object was copied in second object. Then object 1 color changed.:" << endl;
    friendMan.print();
    man.print();
    friendMan.setXRange(90, 100);
    friendMan.setYRange(110, 120);
    cout << "Second object with changed coordinates" << endl;
    friendMan.print();
    cyclist woman(50,60,70,80, 'F', 'N', 'N', 'N', "Black", 'U', 'U');
    cout << "Third object: " << endl;
    woman.print();
    friendMan = woman;
    woman.setVehicleColor("ZXCVBNMASDFGHJKLZXC2QWERTYUIO334878583585");
    cout << "Object 2. Now is a copy of object 3. Then object 3 color changed";
    friendMan.print();

    cout << "Object 3:" << endl;
    cout << endl << endl;
    cout << woman.getXMin() << ' ' << woman.getXMax() << ' ' << woman.getYMin() << ' ' << woman.getYMax() << ' '
         << woman.getPersonSex() << ' ' << woman.getPersonIsAdult() << ' ' << woman.getPersonHasGlasses() << ' ' << woman.getPersonHasBeard() << ' '
         << woman.getVehicleColor() << ' ' << woman.getBikeLock() << ' ' << woman.getCyclistHasHelmet() << endl;

    woman.setXRange(2020, 2040);
    woman.setYRange(1050, 1070);
    woman.setPersonSex('U');
    woman.setPersonIsAdult('U');
    woman.setPersonHasGlasses('U');
    woman.setPersonHasBeard('U');
    woman.setVehicleColor("Yellow");
    woman.setBikeLock('U');
    woman.setCyclistHasHelmet('U');
    cout << "Object 3. All parameters changed:" << woman;

    car test(10,20, 30, 40, "Blue", "1409AA-2", '4', 'Y');

    cout << "Object 4: " << endl;
    test.print();

    car test2(test);

    cout << "Object 5, copy of object 4:" << endl;
    test2.print();
    test.setVehicleColor("White");
    cout << "Object 4 color changed:" << endl;
    test.print();
    test2 = test;
    cout << "Object 5 is now copy of object 4:" << endl;
    test2.print();


    cout << "Trying to assign wrong value..";
    woman.setPersonIsAdult('j');

    return 0;
}


vector<entity*> scanFrame() {
    vector<entity*> result;
    int objects = rand()%15+3;
    int type;


    for (int i = 0; i < objects; ++i) {
        type = rand()%5;
        short xMin = rand()%1600;
        short xMax = rand()%1600 + xMin;
        short yMin = rand()%1000;
        short yMax = rand()%1000 + yMin;
        switch (type) {
            case 0: {
                human* a = new human(xMin, xMax, yMin, yMax, randSex(), randBool(), randBool(), randBool());
                result.push_back(a);
                break;
            }
            case 1: {
                item* a = new item(xMin, xMax, yMin, yMax, randItemName(), randTime());
                result.push_back(a);
                break;
            }
            case 2: {
                bike* a = new bike(xMin, xMax, yMin, yMax, randColor(), randBool());
                result.push_back(a);
                break;
            }
            case 3: {
                cyclist* a = new cyclist(xMin, xMax, yMin, yMax, randSex(), randBool(), randBool(), randBool(), randColor(), randBool(), randBool());
                result.push_back(a);
                break;
            }
            case 4: {
                car* a = new car(xMin, xMax, yMin, yMax, randColor(), randRegisterPlate(), randBodyType(), randBool());
                result.push_back(a);
                break;
            }
        }
    }
    return result;
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