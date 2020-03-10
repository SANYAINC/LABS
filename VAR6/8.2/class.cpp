#include "class.h"

std::ostream& custom::operator << (std::ostream &output, const custom::string &str) {
    output << str.mString << std::endl;
    return output;
}
std::istream& custom::operator >> (std::istream &input, custom::string &str) {
    char *buffer = new char[BUFFER_MAX];
    input.getline(buffer, BUFFER_MAX);
    int bufferLength = 0;
    for (; buffer[bufferLength]; ++bufferLength);
    char *newString = new char[bufferLength + 1];
    for (int i = 0; i < bufferLength; ++i) {
        newString[i] = buffer[i];
    }
    newString[bufferLength] = 0;
    str.mString = newString;
    str.mLength = bufferLength;
    str.mSize = bufferLength + 1;
    delete [] buffer;

    return input;
}
char& custom::string::operator [] (const int index) const {
    try {
        if (index < 0 or index > getLength()) {
            throw index;
        }
    } catch (int invalidIndex) {
        std::cerr << "INDEX " << invalidIndex <<" IS OUT OF RANGE (" << "0-"  << mSize - 1 << ")" << std::endl;
        exit(404);
    }
    return mString[index];
}

custom::string::~string() {
    delete [] mString;
}
custom::string::string() {
    mLength = 0;
    mSize = 0;
    mString = nullptr;
}
custom::string::string(const char *string) {
    int bufferLength = 0;
    for (int i = 0; string[i]; ++i) {
        bufferLength++;
    }
    char *newString = new char[bufferLength + 1];
    for (int i = 0; i < bufferLength; ++i) {
        newString[i] = string[i];
    }
    newString[bufferLength] = 0;
    mString = newString;
    mLength = bufferLength;
    mSize = bufferLength + 1;
}
custom::string::string(const custom::string &secondString) {
    mString = new char[secondString.getSize()];
    mLength = secondString.getLength();
    mSize = secondString.getSize();
    for (int i = 0; secondString[i]; ++i) {
        mString[i] = secondString[i];
    }
    mString[mLength] = 0;
}

int custom::string::getSize() const {
    return mSize;
}
int custom::string::getLength() const {
    return mLength;
}
void custom::string::removeAt(const int index) {
    try {
        if (index < 0 or index >= getLength()) {
            throw index;
        }
        if (mSize == 2) {
            throw "WARNING: REMOVING LAST CHARACTER";
        }
    } catch (int invalidIndex) {
        std::cerr << "INDEX " << invalidIndex <<" IS OUT OF RANGE (" << "0-"  << mLength - 1 << ")" << std::endl;
        exit(404);
    } catch (const char *warning) {
        std::cerr << warning << std::endl;
    }

    char *newString = new char[mSize - 1];
    int newIndex = 0;
    int oldIndex = 0;
    while(mString[oldIndex]) {
        if (oldIndex == index) {
            oldIndex++;
        }
        newString[newIndex++] = mString[oldIndex++];
    }
    newString[mLength - 1] = 0;
    delete [] mString;
    mString = newString;
    mSize--;
    mLength--;

}
void custom::string::trim() {
    int counter = 0;
    for (; mString[counter] == ' '; ++counter);
    if (!counter) {
        return;
    }
    int newSize = mSize - counter;
    char *newString = new char[newSize];
    for (int i = 0; mString[counter] ; ++i, ++counter) {
        newString[i] = mString[counter];
    }
    newString[newSize - 1] = 0;
    delete [] mString;
    mString = newString;
    mSize = newSize;
    mLength = mSize - 1;
}
void custom::string::insert(const char character, const int index) {
    char *newString = new char[++mSize];
    int oldIndex = 0;
    int newIndex = 0;
    while (mString[oldIndex]) {
        if (newIndex == index) {
            newString[index] = character;
            newIndex++;
        }
        newString[newIndex++] = mString[oldIndex++];
    }
    newString[mSize - 1] = 0;
    delete [] mString;
    mString = newString;
    mLength = mSize - 1;
}
void custom::string::insertExcludedFrom(const custom::string &secondStr) {
    custom::string originalStr = (*this);
    bool notFoundInSecond = true;
    for (int i = 0; i < secondStr.getLength(); ++i) {
        for (int j = 0; j < originalStr.mLength; ++j) {
            if (i != j and originalStr[j] == secondStr[i]) {
                notFoundInSecond = false;
            }
        }
        if (notFoundInSecond) {
            insert(secondStr[i], i);
        }
        notFoundInSecond = true;
    }
}
void custom::string::insertExcludedFrom(const char *secondStr) {
    custom::string originalStr = (*this);
    bool notFoundInSecond = true;
    int secondStrLen = 0;
    for (; secondStr[secondStrLen] ; ++secondStrLen);
    for (int i = 0; i < secondStrLen; ++i) {
        for (int j = 0; j < originalStr.mLength; ++j) {
            if (i != j and originalStr[j] == secondStr[i]) {
                notFoundInSecond = false;
            }
        }
        if (notFoundInSecond) {
            insert(secondStr[i], i);
        }
        notFoundInSecond = true;
    }
}
