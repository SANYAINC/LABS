#include "6.4.h"

plateNumber::plateNumber(char *sign) {
    if (validate(sign)) {
        mRegNum.unit = sign[0] - 48;
        mRegNum.dozen = sign[1] - 48;
        mRegNum.hundred = sign[2] - 48;
        mRegNum.thousand = sign[3] - 48;
        mRegNum.letter1 = sign[4] - 65;
        mRegNum.letter2 = sign[5] - 65;
        mRegNum.city = sign[7] - 48;
    } else {
        mRegNum.unit = 0;
        mRegNum.dozen = 0;
        mRegNum.hundred = 0;
        mRegNum.thousand = 0;
        mRegNum.letter1 = 0;
        mRegNum.letter2 = 0;
        mRegNum.city = 0;
    }
}
plateNumber::plateNumber() {
    mRegNum.unit = 0;
    mRegNum.dozen = 0;
    mRegNum.hundred = 0;
    mRegNum.thousand = 0;
    mRegNum.letter1 = 0;
    mRegNum.letter2 = 0;
    mRegNum.city = 0;
}

bool plateNumber::compare(plateNumber &n1, plateNumber &n2) {
    if (n1.mRegNum.unit != n2.mRegNum.unit) {
        return n1.mRegNum.unit < n2.mRegNum.unit;
    } else {
        if (n1.mRegNum.dozen != n2.mRegNum.dozen) {
            return n1.mRegNum.dozen < n2.mRegNum.dozen;
        } else {
            if (n1.mRegNum.hundred != n2.mRegNum.hundred) {
                return n1.mRegNum.hundred < n2.mRegNum.hundred;
            } else {
                if (n1.mRegNum.thousand != n2.mRegNum.thousand) {
                    return n1.mRegNum.thousand < n2.mRegNum.thousand;
                } else {
                    if (n1.mRegNum.letter1 != n2.mRegNum.letter1) {
                        return n1.mRegNum.letter1 < n2.mRegNum.letter1;
                    } else {
                        if (n1.mRegNum.letter2 != n2.mRegNum.letter2) {
                            return n1.mRegNum.letter2 < n2.mRegNum.letter2;
                        } else {
                            if (n1.mRegNum.city != n2.mRegNum.city) {
                                return n1.mRegNum.city < n2.mRegNum.city;
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
}
void plateNumber::printList(plateNumber *list, int n) {
    for (int i = 0; i < n; ++i) {
        list[i].print();
    }
}

plateNumber& plateNumber::operator = (plateNumber number) {
    mRegNum.thousand = number.mRegNum.thousand;
    mRegNum.hundred = number.mRegNum.hundred;
    mRegNum.dozen = number.mRegNum.dozen;
    mRegNum.unit = number.mRegNum.unit;
    mRegNum.letter1 = number.mRegNum.letter1;
    mRegNum.letter2 = number.mRegNum.letter2;
    mRegNum.city = number.mRegNum.city;
    return *this;
}
bool plateNumber::operator == (plateNumber number) {
    return mRegNum.unit == number.mRegNum.unit and mRegNum.dozen == number.mRegNum.dozen and
           mRegNum.hundred == number.mRegNum.hundred and mRegNum.thousand == number.mRegNum.thousand and
           mRegNum.letter1 == number.mRegNum.letter1 and mRegNum.letter2 == number.mRegNum.letter2 and
           mRegNum.city == number.mRegNum.city;
}


bool plateNumber::validate(char *sign) {
    if (sign[8] != 0) {
        return false;
    }
    if (sign[0] < 48 or sign[0] > 58) {
        return false;
    }
    if (sign[1] < 48 or sign[1] > 58) {
        return false;
    }
    if (sign[2] < 48 or sign[2] > 58) {
        return false;
    }
    if (sign[3] < 48 or sign[3] > 58) {
        return false;
    }
    if (sign[4] < 65 or sign[4] > 90) {
        return false;
    }
    if (sign[5] < 65 or sign[5] > 90) {
        return false;
    }
    if (sign[7] < 49 or sign[7] > 55) {
        return false;
    }
    return true;
}
bool plateNumber::setPlateNumber(char *sign) {
    if (validate(sign)) {
        mRegNum.unit = sign[0] - 48;
        mRegNum.dozen = sign[1] - 48;
        mRegNum.hundred = sign[2] - 48;
        mRegNum.thousand = sign[3] - 48;
        mRegNum.letter1 = sign[4] - 65;
        mRegNum.letter2 = sign[5] - 65;
        mRegNum.city = sign[7] - 48;
        return true;
    } else {
        mRegNum.unit = 0;
        mRegNum.dozen = 0;
        mRegNum.hundred = 0;
        mRegNum.thousand = 0;
        mRegNum.letter1 = 0;
        mRegNum.letter2 = 0;
        mRegNum.city = 0;
    }
    return false;
}
void plateNumber::print() {
    printf("%c%c%c%c%c%c-%c\n", mRegNum.unit + 48, mRegNum.dozen + 48, mRegNum.hundred + 48, mRegNum.thousand + 48,
           mRegNum.letter1 + 65, mRegNum.letter2 + 65, mRegNum.city + 48);
}
