#include <iostream>
#include "6.3.h"

using namespace std;

int main() {
    char name1[NAME_MAX_LEN] = "Alexander";
    char name2[NAME_MAX_LEN] = "Sibirtsev";
    char name3[NAME_MAX_LEN] = "Vyacheslavovich";
    student alex(name1, name2, name3, 18, 'M', 1, 6.67);




    return 0;
}