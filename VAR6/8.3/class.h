#include <iostream>

#define BITS_DEFAULT 8
#define NUM_SYS_BASE_DEFAULT 2


class uInt {
    const int mNumSysBase = NUM_SYS_BASE_DEFAULT;
    const int mBits = BITS_DEFAULT;
    int *mDigits;

    friend std::ostream& operator<<(std::ostream& out, const uInt& number);
    friend std::istream& operator>>(std::istream& in, const uInt& number);
public:
    uInt();
    uInt(unsigned int number);
    uInt(const uInt& number);

    int operator[](int index);
    uInt operator+(const uInt& number);
    uInt operator-(const uInt& number);
    uInt operator<<(int n);
    uInt operator>>(int n);

    unsigned long long int toInt();
    bool isZero();

    ~uInt();


};

