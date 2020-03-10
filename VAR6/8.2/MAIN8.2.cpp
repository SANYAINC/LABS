#include <iostream>
#include "class.h"
#include "8.2.h"

using namespace std;

int main() {
    custom::string str1("   hello");
    custom::string str2 = str1;

    str1.trim();
    str2.trim();
    str2.insert('!', 0);

    cout << str1 << str2;

    custom::string str3;
    cin >> str3;
    str1.insertExcludedFrom(str3);

    cout << str1;




    return 0;
}
