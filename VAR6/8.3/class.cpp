#include "class.h"

std::ostream& operator<<(std::ostream& out, const uInt& number) {
    int beg = number.findBeg();
    for (; beg < number.mSize; ++beg) {
        out << number.mBits[beg];
    }
    out << std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, uInt& number) {
    unsigned int buffer;
    in >> buffer;
    int digitIndex = number.mSize - 1;
    while (digitIndex >= 0 and buffer) {
        number.mBits[digitIndex] = buffer % number.mNumSysBase;
        buffer /= number.mNumSysBase;
        digitIndex--;
    }
    for (int i = digitIndex; i >= 0; --i) {
        number.mBits[i] = 0;
    }
    return in;
}

uInt::uInt() {
    int* newDigits = new int[mSize];
    for (int i = 0; i < mSize; ++i) {
        newDigits[i] = 0;
    }
    mBits = newDigits;
}
uInt::uInt(unsigned int number) {
    int* newDigits = new int[mSize];
    int digitIndex = mSize - 1;
    while (digitIndex >= 0 and number) {
        newDigits[digitIndex] = number % mNumSysBase;
        number /= mNumSysBase;
        digitIndex--;
    }
    for (int i = digitIndex; i >= 0; --i) {
        newDigits[i] = 0;
    }
    mBits = newDigits;
}
uInt::uInt(const uInt& number) {
    int* newDigits = new int[number.mSize];
    mBits = newDigits;
    for (int i = 0; i < number.mSize; ++i) {
        mBits[i] = number.mBits[i];
    }
}
uInt::~uInt() {
    delete [] mBits;
}

uInt operator*(const uInt& number1, const uInt& number2) {
    uInt result;

    int beg2 = number2.findBeg();
    int shift = 0;
    for (int i = number1.mSize - 1; i >= beg2 ; --i) {
        //Суммирование со сдвигом
        result = result + (number2.mBits[i] * number1  << shift);
        shift++;
    }
    //Корректировка разрядов
    int index = number1.mSize - 1;
    while (index) {
        if (index - 1 >= 0) {
            result.mBits[index - 1] += result.mBits[index] / result.mNumSysBase;
        }
        result.mBits[index] %= result.mNumSysBase;
        index--;
    }
    return result;
}
uInt operator*(int number1, const uInt& number2) {
    uInt result;
    if (number1 == 0 or number2 == 0) {
        return result;
    }

    result = number2;

    int beg = number2.findBeg();

    //Умножение всех разрядов на число
    for (int i = result.mSize - 1; i >= beg; --i) {
        result.mBits[i] *= number1;
    }

    //Корректировка разрядов
    int index = result.mSize - 1;
    while (index) {
        if (index - 1 >= 0) {
            result.mBits[index - 1] += result.mBits[index] / result.mNumSysBase;
        }
        result.mBits[index] %= result.mNumSysBase;
        index--;
    }
    return result;
}

uInt operator+(const uInt& number1, const uInt& number2) {
    uInt result(number1);

    int beg = number2.findBeg();

    int currentBit = number2.mSize - 1;
    //Перебор от младшего бита до старшего второго слогаемого
    for (; currentBit >= beg; --currentBit) {
        result.mBits[currentBit] += number2.mBits[currentBit];
        //Корректировка разрядов
        for (int i = 0; result.mBits[currentBit - i] >= result.mNumSysBase; ++i) {
            if (currentBit - i - 1 >= 0) {
                result.mBits[currentBit - i - 1] += result.mBits[currentBit - i] / result.mNumSysBase;
            }
            result.mBits[currentBit - i] %= result.mNumSysBase;
        }
    }
    return result;
}
uInt operator-(const uInt& number1, const uInt& number2) {
    uInt result(number1);

    int beg = number2.findBeg();

    int currentBit = number2.mSize - 1;
    //Перебор от младшего бита до старшего у вычитаемого
    for (; currentBit >= beg; --currentBit) {
        result.mBits[currentBit] -= number2.mBits[currentBit];
        //Корректировка разрядов
        for (int i = 0; result.mBits[currentBit - i] < 0; ++i) {
            if (currentBit - i - 1 >= 0) {
                result.mBits[currentBit - i - 1] -= 1;
            }
            result.mBits[currentBit - i] += result.mNumSysBase;
        }
    }
    return result;
}
uInt operator/(const uInt& divisible, const uInt& divisor) {
    if (divisor.isZero()) {
        std::cerr << "DIVIDED BY ZERO" << std::endl;
        exit(999999999);
    }
    if (divisible.isZero()) {
        return divisible;
    }
    uInt result;
    uInt divisibleCopy = divisible; // Копия делимого
    uInt divisorCopy = divisor; //Копия делителя
    uInt solutions(1); //Счетчик деления
    while (divisibleCopy >= divisor) {

        while (divisibleCopy > (divisorCopy << 1)) {
            divisorCopy = (divisorCopy << 1);   //Сдвиг делителя
            solutions = solutions * divisible.mNumSysBase;
        }
        divisibleCopy = divisibleCopy - divisorCopy;
        result = result + solutions; //Добавляем счетчик

        solutions = 1;
        divisorCopy = divisor;
    }
    return result;
}
uInt operator<<(const uInt &number1, int number2) {
    uInt result;
    if (number1.isZero() or number2 == 0) {
        return number1;
    }
    if (number2 >= result.mSize or number2 < 0) {
        return result;
    }

    //Поиск первого бита для копирования
    int beg = number1.findBeg();
    while (beg - number2 < 0) {
        ++beg;
    }

    for (int i = beg; i < result.mSize; ++i) {
        result.mBits[i - number2] = number1.mBits[i];
    }

    return result;
}
uInt operator>>(const uInt& number1, int number2) {
    uInt result;
    if (number1.isZero() or number2 == 0) {
        return number1;
    }
    if (number2 >= result.mSize or number2 < 0) {
        return result;
    }

    //Поиск первого бита для копирования
    int beg = number1.findBeg();
    int startIndex = result.mSize - 1;
    for (; startIndex + number2 >= result.mSize; --startIndex);

    for (int i = startIndex; i >= beg; --i) {
        result.mBits[i + number2] = number1.mBits[i];
    }
    return result;
}

uInt& uInt::operator=(const uInt& number) {
    if (&number == this) {
        return *this;
    }
    for (int i = 0; i < mSize; ++i) {
        mBits[i] = number.mBits[i];
    }
    return *this;
}
int uInt::operator[](const int index) const {
    if (index < 0 or index >= mSize) {
        std::cerr << "OUT OF RANGE" << std::endl;
        exit(404);
    }
    return mBits[index];
}
uInt uInt::operator%(const uInt& divisor) const {
    if (divisor == 2) {
        return this->mBits[mSize - 1];
    }
    uInt result(*this);
    return  result - (result / divisor) * divisor;
}
bool uInt::operator==(const uInt& number) const {
    for (int i = 0; i < mSize; ++i) {
        if (mBits[i] != number.mBits[i]) {
            return false;
        }
    }
    return true;
}
bool uInt::operator>(const uInt& number) const {
    if (*this == number) {
        return false;
    }
    int beg1 = this->findBeg();
    int beg2 = number.findBeg();

    //Больше то число, у которого первый значащий бит старше
    if (beg1 != beg2) {
        return beg1 < beg2;
    } else {
        while (beg1 < mSize and mBits[beg1] == number.mBits[beg1]) {
            beg1++;
        }
        return mBits[beg1] > number.mBits[beg1];
    }
}
bool uInt::operator<(const uInt& number) const {
    if (*this == number) {
        return false;
    }
    int beg1 = this->findBeg();
    int beg2 = number.findBeg();

    //Меньше то число, у которого первый значащий бит младше
    if (beg1 != beg2) {
        return beg1 > beg2;
    } else {
        while (beg1 < mSize and mBits[beg1] == number.mBits[beg1]) {
            beg1++;
        }
        return mBits[beg1] < number.mBits[beg1];
    }
}
bool uInt::operator>=(const uInt& number) const {
    return *this > number or *this == number;
}
bool uInt::operator<=(const uInt& number) const {
    return *this < number or *this == number;
}
bool uInt::operator!=(const uInt& number) const {
    return !(*this == number);
}

bool uInt::isZero() const {
    for (int i = 0; i < mSize; ++i) {
        if (mBits[i] != 0) {
            return false;
        }
    }
    return true;
}
int uInt::findBeg() const {
    int begFinder = 0;
    for (; begFinder < mSize - 1 and mBits[begFinder] == 0 ; ++begFinder);
    return begFinder;
}
uInt uInt::gcd(uInt& number) {
    uInt zero(0);
    uInt one(1);
    uInt two(2);
    return gcdRecur(*this, number, zero, one, two);
}
uInt uInt::gcdRecur(uInt n1, uInt n2, uInt& zero, uInt& one, uInt& two) {
    if (n1 == zero) {return n2;}

    if (n2 == zero) {return n1;}

    if (n1 == n2) {return n1;}

    if (n1 == one or n2 == one) {return one;}

    if (n1 % two == zero and n2 % two == zero) {return gcdRecur(n1 >> 1, n2 >> 1, zero, one, two) << 1;}

    if (n1 % two == zero and n2 % two != zero) {return gcdRecur(n1 >> 1, n2, zero, one, two);}

    if (n1 % two != zero and n2 % two == zero) {return gcdRecur(n1, n2 >> 1, zero, one, two);}

    if (n1 < n2) {return gcdRecur((n2 - n1) >> 1, n1, zero, one, two);}

    else {return gcdRecur((n1 - n2) >> 1, n2, zero, one, two);}
}
