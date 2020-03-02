#ifndef LABSGIT_6_4_H
#define LABSGIT_6_4_H

#include <iostream>
using namespace std;

class plateNumber {
    union number {
        unsigned int code;
        struct {
            unsigned int city:5;
            unsigned int letter2:5;
            unsigned int letter1:5;
            unsigned int thousand:4;
            unsigned int hundred:4;
            unsigned int dozen:4;
            unsigned int unit:4;
        };
    } mRegNum;
    static bool validate(char *sign);
public:
    plateNumber();
    plateNumber(char *sign);

    static bool compare(plateNumber &n1, plateNumber &n2);
    static void printList(plateNumber *list, int n);

    plateNumber& operator = (plateNumber number);
    bool operator == (plateNumber number);

    bool setPlateNumber(char *sign);
    void print();
};

#endif //LABSGIT_6_4_H
