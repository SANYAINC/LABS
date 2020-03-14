#include <iostream>

#define BITS_DEFAULT 256
#define NUM_SYS_BASE_DEFAULT 2


class uInt {
    const int mNumSysBase = NUM_SYS_BASE_DEFAULT;
    const int mSize = BITS_DEFAULT;

    int *mBits;

    friend std::ostream& operator<<(std::ostream& out, const uInt& number);
    friend std::istream& operator>>(std::istream& in, uInt& number);

    friend uInt operator*(const uInt& number1, const uInt& number2);
    friend uInt operator*(int number1, const uInt& number2);

    friend uInt operator+(const uInt& number1, const uInt& number2);
    friend uInt operator-(const uInt& number1, const uInt& number2);
    friend uInt operator/(const uInt& number1, const uInt& number2);
    friend uInt operator<<(const uInt& number1, int number2);
    friend uInt operator>>(const uInt& number1, int number2);

    int findBeg() const;

    uInt gcdRecur(uInt n1, uInt n2, uInt& zero, uInt& one, uInt& two);

public:
    uInt();
    uInt(unsigned int number);
    uInt(const uInt &number);

    uInt& operator=(const uInt& number);
    int operator[](int index) const;
    uInt operator%(const uInt& divisor) const;

    bool operator==(const uInt& number) const;
    bool operator!=(const uInt& number) const;
    bool operator>(const uInt& number) const;
    bool operator<(const uInt& number) const;
    bool operator>=(const uInt& number) const;
    bool operator<=(const uInt& number) const;

    bool isZero() const;
    uInt gcd(uInt& number);

    ~uInt();
};

