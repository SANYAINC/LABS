#include "class.h"

std::ostream& operator<<(std::ostream& out, const uInt& number) {
    int begFinder = 0;
    //for (; number.mDigits[begFinder] == 0; ++begFinder);
    for (; begFinder < number.mBits; ++begFinder) {
        out << number.mDigits[begFinder];
    }
    out << std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, const uInt& number) {
    unsigned int buffer;
    in >> buffer;
    int digitIndex = number.mBits - 1;
    while (digitIndex >= 0 and buffer) {
        number.mDigits[digitIndex--] = buffer % number.mNumSysBase;
        buffer /= number.mNumSysBase;
    }
    for (int i = digitIndex; i >= 0; --i) {
        number.mDigits[i] = 0;
    }
}

uInt::uInt() {
    int* newDigits = new int[mBits];
    for (int i = 0; i < mBits; ++i) {
        newDigits[i] = 0;
    }
    mDigits = newDigits;
}
uInt::uInt(unsigned int number) {
    int* newDigits = new int[mBits];
    int digitIndex = mBits - 1;
    while (digitIndex >= 0 and number) {
        newDigits[digitIndex--] = number % mNumSysBase;
        number /= mNumSysBase;
    }
    for (int i = digitIndex; i >= 0; --i) {
        newDigits[i] = 0;
    }
    mDigits = newDigits;
}
uInt::uInt(const uInt& number) {
    int* newDigits = new int[number.mBits];
    mDigits = newDigits;
    for (int i = 0; i < number.mBits; ++i) {
        mDigits[i] = number.mDigits[i];
    }
}
uInt::~uInt() {
    delete[] (mDigits);

}

int uInt::operator[](const int index) {
    if (index < 0 or index >= mBits) {
        std::cerr << "OUT OF RANGE" << std::endl;
        exit(404);
    }
    return mDigits[index];
}
uInt uInt::operator+(const uInt& number) {
    uInt result = *this;

    int begFinder = 0;
    for (; number.mDigits[begFinder] == 0; ++begFinder);

    int currentBit = number.mBits - 1;
    for (; currentBit >= begFinder; --currentBit) {
        result.mDigits[currentBit] += number.mDigits[currentBit];
        for (int i = 0; result.mDigits[currentBit - i] >= result.mNumSysBase; ++i) {
            if (currentBit - i - 1 >= 0) {
                result.mDigits[currentBit - i - 1] += result.mDigits[currentBit - i] / result.mNumSysBase;
            }
            result.mDigits[currentBit - i] %= result.mNumSysBase;
        }
    }
    return result;
}
uInt uInt::operator-(const uInt& number) {
    uInt result = *this;

    int begFinder = 0;
    for (; number.mDigits[begFinder] == 0; ++begFinder);

    int currentBit = number.mBits - 1;
    for (; currentBit >= begFinder; --currentBit) {
        result.mDigits[currentBit] -= number.mDigits[currentBit];
        for (int i = 0; result.mDigits[currentBit - i] < 0; ++i) {
            if (currentBit - i - 1 >= 0) {
                result.mDigits[currentBit - i - 1] -= 1;
            }
            result.mDigits[currentBit - i] += result.mNumSysBase;
        }
    }
    return result;
}
uInt uInt::operator<<(const int n) {
    uInt result(*this);
    if (isZero() or n == 0) {
        return *this;
    }
    if (n >= result.mBits or n < 0) {
        for (int i = 0; i < result.mBits; ++i) {
            result.mDigits[i] = 0;
        }
        return result;
    }

    int begFinder = 0;
    for (; result.mDigits[begFinder] != 1; ++begFinder);
    while (begFinder - n < 0 and ++begFinder);

    for (; begFinder <result. mBits; ++begFinder) {
        result.mDigits[begFinder - n] = result.mDigits[begFinder];
    }
    for (; --begFinder >= result.mBits - n ;) {
        result.mDigits[begFinder] = 0;
    }
    return result;
}
uInt uInt::operator>>(const int n) {
    uInt result(*this);
    if (isZero() or n == 0) {
        return *this;
    }
    if (n >= result.mBits or n < 0) {
        for (int i = 0; i < result.mBits; ++i) {
            result.mDigits[i] = 0;
        }
        return result;
    }
    int begFinder = 0;
    for (; result.mDigits[begFinder] != 1; ++begFinder);

    int startIndex = result.mBits - 1;
    for (; startIndex + n > result.mBits; --startIndex);

    for (; startIndex >= begFinder ; --startIndex) {
        result.mDigits[startIndex + n] = result.mDigits[startIndex];
    }
    for (int i = 0; i < begFinder + n; ++i) {
        result.mDigits[i] = 0;
    }
    return result;
}


unsigned long long int uInt::toInt() {
    unsigned long long int buffer = 0;
    for (int i = mBits - 1; i >= 0; --i) {
        buffer += mDigits[i] * (1 << (mBits - 1 - i));
    }
    return buffer;
}
bool uInt::isZero() {
    for (int i = 0; i < mBits; ++i) {
        if (mDigits[i] != 0) {
            return false;
        }
    }
    return true;
}
