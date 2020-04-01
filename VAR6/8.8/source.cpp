#include <iostream>
#include <cfloat>
#include "matrix.h"
#include "calc.h"
#define MAX_POWER 100

using namespace std;

int main() {

    cout << "sCalc v0.1" << endl << endl;

    matrix mainMatrix = matrixCreate();

    int action = -1;

    while (action) {
        cout << mainMatrix << endl;
        cout << "Available actions: " << endl;
        cout << "0) Exit" << endl << endl;
        cout << "1) Add number;" << endl;
        cout << "2) Multiply by a number;" << endl;
        cout << "3) Divide by a number;" << endl;
        cout << "4) Add matrix;" << endl;
        cout << "5) Subtract matrix;" << endl;
        cout << "6) Multiply by matrix;" << endl;
        cout << "7) Compare matrices;" << endl;
        cout << "8) Check type;" << endl;
        cout << "9) Transpose;" << endl;
        cout << "10) Raise to the power;" << endl << endl;

        cout << "11) Change main matrix;" << endl << endl;
        action = getOption();
        system("cls");
        switch (action) {
            case 0: {
                cout << "Thanks for choosing sCalc!" << endl;
                break;
            }
            case 1: {
                double bufNumber;
                matrix answer;
                cout << mainMatrix << endl << endl;
                cout << "Please, enter your number: ";
                input(bufNumber, "Please, enter correct number: ", -DBL_MAX, DBL_MAX);
                cout << endl;

                answer = mainMatrix + bufNumber;

                cout << mainMatrix << "\n\tPLUS " << bufNumber << " EQUAlS TO\n\n" << answer << endl;

                save(answer, mainMatrix);
                system("cls");
                break;
            }
            case 2: {
                double bufNumber;
                matrix answer;
                cout << mainMatrix << endl << endl;
                cout << "Please, enter your number: ";
                input(bufNumber, "Please, enter correct number: ", -DBL_MAX, DBL_MAX);
                cout << endl;

                answer = mainMatrix * bufNumber;

                cout << mainMatrix << "\n\tMULTIPLIED BY " << bufNumber << " EQUALS TO\n\n" << answer << endl;

                save(answer, mainMatrix);
                system("cls");
                break;
            }
            case 3: {
                double bufNumber;
                matrix answer;
                cout << mainMatrix << endl << endl;
                cout << "Please, enter your number: ";
                input(bufNumber, "Please, enter correct number: ", -DBL_MAX, DBL_MAX);
                cout << endl;

                if (bufNumber == 0) {
                    cout << mainMatrix << endl << endl << "Matrix can't be divided by zero" << endl << endl;
                    cout << "Press any key to continue...";
                    cin.get();
                    system("cls");
                    break;
                }

                answer = mainMatrix / bufNumber;

                cout << mainMatrix << "\n\tDIVIDED BY " << bufNumber << " EQUALS TO\n\n" << answer << endl;

                save(answer, mainMatrix);
                system("cls");
                break;
            }
            case 4: {
                cout << mainMatrix << endl << "WILL BE ADDED TO " << endl << endl;
                matrix secondaryMatrix = matrixCreate();
                matrix answer(mainMatrix);

                if (!mainMatrix.isSameSizeWith(secondaryMatrix)) {
                    cout << mainMatrix << endl << secondaryMatrix << endl << endl << "Matrices can't be added due to their sizes" << endl << endl;
                    cout << "Press any key to continue...";
                    cin.get();
                    system("cls");
                    break;
                }

                answer += secondaryMatrix;

                cout << mainMatrix << "\n\tPLUS\n\n" << secondaryMatrix << "\n\tEQUAlS\n\n" << answer << endl;

                save(answer, mainMatrix);
                system("cls");
                break;
            }
            case 5: {
                cout << mainMatrix << endl << "WILL BE SUBTRACTED FROM" << endl << endl;
                matrix secondaryMatrix = matrixCreate();
                matrix answer(mainMatrix);

                if (!mainMatrix.isSameSizeWith(secondaryMatrix)) {
                    cout << mainMatrix << endl << secondaryMatrix << endl << endl << "Matrices can't be subtracted due to their sizes" << endl << endl;
                    cout << "Press any key to continue...";
                    cin.get();
                    system("cls");
                    break;
                }

                answer -= secondaryMatrix;

                cout << mainMatrix << "\n\tMINUS\n\n" << secondaryMatrix << "\n\tEQUAlS\n\n" << answer << endl;

                save(answer, mainMatrix);
                system("cls");
                break;
            }
            case 6: {
                cout << mainMatrix << endl << "WILL BE MULTIPLIED BY " << endl << endl;
                matrix secondaryMatrix = matrixCreate();
                matrix answer;

                if (!mainMatrix.isCompatibleWith(secondaryMatrix) or mainMatrix.isNull() or secondaryMatrix.isNull()) {
                    cout << mainMatrix << endl << secondaryMatrix << endl << endl << "Matrices can't be multiplied due to their sizes" << endl << endl;
                    cout << "Press any key to continue...";
                    cin.get();
                    system("cls");
                    break;
                }

                answer = mainMatrix * secondaryMatrix;

                cout << mainMatrix << "\n\tMULTIPLIED BY\n\n" << secondaryMatrix << "\n\tEQUAlS\n\n" << answer << endl;

                save(answer, mainMatrix);
                system("cls");
                break;
            }
            case 7: {
                cout << mainMatrix << endl << "WILL BE COMPARED WITH " << endl << endl;
                matrix secondaryMatrix = matrixCreate();

                if (mainMatrix.isSameSizeWith(secondaryMatrix)) {
                    if (mainMatrix == secondaryMatrix) {
                        cout << "\n\tMATRICES\n\n" << mainMatrix << "\n\tAND\n\n" << secondaryMatrix << "\n\tARE EQUAL.\n\n";
                    } else {
                        cout << "\n\tMATRICES\n\n" << mainMatrix << "\n\tAND\n\n" << secondaryMatrix << "\n\tARE UNEQUAL.\n\n";
                    }
                } else {
                    cout << mainMatrix << endl << secondaryMatrix << endl << endl << "Matrices can't be compared due to their sizes" << endl << endl;
                }
                cout << "Press any key to continue...";
                cin.get();
                system("cls");
                break;
            }
            case 8: {
                bool found = false;
                cout << mainMatrix << endl;
                if (mainMatrix.isSquared()) {
                    cout << "SQUARED ";
                    found = true;
                }
                if (mainMatrix.isZero()) {
                    cout << "ZERO ";
                    found = true;
                }
                if (mainMatrix.isIdentity()) {
                    cout << "IDENTITY ";
                    found = true;
                }
                if (mainMatrix.isDiagonal()) {
                    cout << "DIAGONAL ";
                    found = true;
                }
                if (mainMatrix.isSymmetrical()) {
                    cout << "SYMMETRICAL ";
                    found = true;
                }
                if (mainMatrix.isLowerTriangle()) {
                    cout << "TRIANGLE(LOWER) ";
                    found = true;
                }
                if (mainMatrix.isUpperTriangle()) {
                    cout << "TRIANGLE(UPPER) ";
                    found = true;
                }
                if (!found) {
                    cout << "NOTHING";
                }
                cout << endl << endl << "Press any key to continue...";
                cin.get();
                system("cls");
                break;
            }
            case 9: {
                matrix answer;

                answer = mainMatrix.getTransposed();

                cout << mainMatrix << "\n\tTRANSPOSED EQUALS TO\n\n" << answer << endl;

                save(answer, mainMatrix);
                system("cls");
                break;
            }
            case 10: {
                int power;
                matrix answer(mainMatrix);
                cout << mainMatrix << endl << "WILL BE RAISED TO THE POWER OF " << endl << endl;
                cout << "Please, enter number to raise matrix: ";
                input(power, "Please, enter correct number: ", 0, MAX_POWER);

                if (!mainMatrix.isSquared()) {
                    cout << answer << endl << endl << "Matrix can't be raised to the power due to it's size" << endl << endl;
                    cout << "Press any key to continue...";
                    cin.get();
                    system("cls");
                    break;
                }

                answer = mainMatrix.getRaisedIn(power);

                cout << mainMatrix << "\n\tIN THE POWER OF " << power << " EQUAlS TO\n\n" << answer << endl;

                save(answer, mainMatrix);
                system("cls");
                break;
            }
            case 11: {
                mainMatrix = matrixCreate();
                break;
            }
        }
    }


    system("pause");
    return 0;
}

