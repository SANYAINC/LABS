#pragma once

#include <iostream>

#define BUFFER_MAX 10000

namespace custom {
    class string {
        char *mString;
        int mSize;
        int mLength;

        friend std::ostream& operator << (std::ostream& output, const string& str);
        friend std::istream& operator >> (std::istream& input, string& str);

    public:
        string();
        string(const char* string);
        string(const string& secondString);

        char& operator [] (int index) const;

        int getSize() const;
        int getLength() const;
        void removeAt(int index);
        void trim();
        void insert(char character, int index);
        void insertExcludedFrom(const string& secondStr);
        void insertExcludedFrom(const char* secondStr);

        ~string();
    };

}

