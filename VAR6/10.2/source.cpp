#include <iostream>
#include "sEye_Entity/sEye_Entity.h"
#include "sEye_Entity/sEye_Entity_Vector.h"

using namespace std;


int main() {
    cyclist cy1(1,2,3,4, 'F', 'U', 'U','U', "White", 'U', 'U');
    cyclist cy2(5,6,7,8, 'M', 'Y', 'Y', 'Y', "White", 'N', 'Y');
    car ca1(9, 10, 11, 12, "Red", "1111AB-7", '4', 'N');
    car ca2(13, 14, 15, 16, "Black", "4729II-2", '3', 'Y');
    bike b1(17, 18, 19, 20, "Yellow", 'Y');
    bike b2(21, 22, 23, 24, "Blue", 'U');
    human h1(25, 26, 27, 28, 'M', 'Y', 'Y', 'N');
    human h2(29, 30, 31, 32, 'F', 'U', 'U', 'Y');
    item i1(17, 18, 19, 20, "Bag", "19:05");
    item i2(17, 18, 19, 20, "Backpack", "21:22");

    entityVector v1;

    v1.pushBack(cy1);
    v1.pushBack(ca1);

    cout << "V1" << endl;
    v1.print();

    entityVector v2(v1);

    v1.removeAt(0);
    v2.pushBack(b1);

    cout << "V1 REMOVED [0]" << endl;
    v1.print();
    cout << "V2 PUSHED ELEMENT" << endl;
    v2.print();

    entityVector v3(10);

    v3.pushBack(h1);
    cout << "V3 PUSHED ELEMENT" << endl;
    v3.print();

    v3 = v2;

    cout << "V3 NOW COPY OF V2" << endl;
    v3.print();

    v2.pushAt(2, i1);
    cout << "V2 PUSHED ELEMENT IN 2" << endl;
    v2.print();
    v2.removeAt(3);
    cout << "V2 REMOVED LAST" << endl;
    v2.print();

    v2.clear();
    cout << "V2 CLEARED" << endl;
    v2.print();

    cout << "V1:" << endl;
    v1.pushAt(1, cy2);
    v1.pushAt(2, i2);

    for (int i = 0; i < v1.getSize(); ++i) {
        v1[i]->print();
    }

    return 0;
}