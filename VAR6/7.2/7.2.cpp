#include "7.2.h"


squareMatrix2D::squareMatrix2D(int n) {
    double **mx = new double*[n];
    for (int i = 0; i < n; ++i) {
        mx[i] = new double[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mx[i][j] = 0;
        }
    }
    mMatrix = mx;
    mSize = n;
}
bool squareMatrix2D::add(squareMatrix2D &mx) {
    if (mx.mSize != mSize){
        return false;
    }

    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            mMatrix[i][j] += mx.mMatrix[i][j];
        }
    }

    return true;
}
bool squareMatrix2D::subtract(squareMatrix2D &mx) {
    if (mx.mSize != mSize){
        return false;
    }

    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            mMatrix[i][j] -= mx.mMatrix[i][j];
        }
    }

    return true;
}
bool squareMatrix2D::multiply(squareMatrix2D &mx) {
    if (mx.mSize != mSize) {
        return false;
    }

    double **result = new double*[mSize];
    for (int i = 0; i < mSize; ++i) {
        result[i] = new double[mSize];
    }
    double sum = 0;
    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            for (int k = 0; k < mSize; ++k) {
                sum += mMatrix[i][k] * mx.mMatrix[k][j];
                result[i][j] = sum;
            }
            sum = 0;
        }
    }

    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            mMatrix[i][j] = result[i][j];
        }
    }

    for (int i = 0; i < mSize; ++i) {
        delete [] result[i];
    }
    delete [] result;

    return true;
}
bool squareMatrix2D::raise(int n) {
    if (n == 1) {
        return true;
    } else if (n < 1) {
        return false;
    }

    double **result = new double*[mSize];
    for (int i = 0; i < mSize; ++i) {
        result[i] = new double[mSize];
    }
    double **firstForm = new double*[mSize];
    for (int i = 0; i < mSize; ++i) {
        firstForm[i] = new double[mSize];
    }

    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            firstForm[i][j] = mMatrix[i][j];
        }
    }

    int powerCounter = 1;
    double sum;
    while (powerCounter < n) {
        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < mSize; ++j) {
                sum = 0;
                for (int k = 0; k < mSize; ++k) {
                    sum += mMatrix[i][k] * firstForm[k][j];
                    result[i][j] = sum;
                }
            }
        }
        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < mSize; ++j) {
                mMatrix[i][j] = result[i][j];
            }
        }
        ++powerCounter;
    }

    for (int i = 0; i < mSize; ++i) {
        delete [] result[i];
        delete [] firstForm[i];
    }
    delete [] result;
    delete [] firstForm;

    return true;

}
void squareMatrix2D::fillAsIdentity() {
    for (int i = 0; i < mSize; ++i) {
        mMatrix[i][i] = 1;
    }
}
void squareMatrix2D::fillRandom() {
    srand(time(nullptr));
    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            mMatrix[i][j] = rand()%10;
        }
    }
}
void squareMatrix2D::fillKeyboard() {
    int buffer;
    for (int i = 0; i < mSize; ++i) {
        printf("Enter a row:\n");
        for (int j = 0; j < mSize; ++j) {
            scanf("%d", &buffer);
            mMatrix[i][j] = buffer;
        }
        printf("\n");
    }
}
void squareMatrix2D::show() {
    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            cout << setw(5) <<mMatrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


squareMatrix1D::squareMatrix1D(int n) {
    double *mx = new double[n*n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mx[i * n + j] = 0;
        }
    }
    mMatrix = mx;
    mSize = n;
}
bool squareMatrix1D::add(squareMatrix1D &mx) {
    if (mx.mSize != mSize){
        return false;
    }

    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            mMatrix[i * mSize + j] += mx.mMatrix[i * mSize + j];
        }
    }

    return true;
}
bool squareMatrix1D::subtract(squareMatrix1D &mx) {
    if (mx.mSize != mSize){
        return false;
    }

    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            mMatrix[i * mSize + j] -= mx.mMatrix[i * mSize + j];
        }
    }

    return true;
}
bool squareMatrix1D::multiply(squareMatrix1D &mx) {
    if (mx.mSize != mSize) {
        return false;
    }

    double *result = new double[mSize * mSize];
    double sum = 0;
    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            for (int k = 0; k < mSize; ++k) {
                sum += mMatrix[i * mSize + k] * mx.mMatrix[k * mSize + j];
                result[i * mSize + j] = sum;
            }
            sum = 0;
        }
    }

    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            mMatrix[i * mSize + j] = result[i * mSize + j];
        }
    }
    delete [] result;

    return true;
}
bool squareMatrix1D::raise(int n) {
    if (n == 1) {
        return true;
    } else if (n < 1) {
        return false;
    }

    double *result = new double[mSize*mSize];
    double *firstForm = new double[mSize*mSize];

    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            firstForm[i * mSize + j] = mMatrix[i * mSize + j];
        }
    }

    int powerCounter = 1;
    double sum;
    while (powerCounter < n) {
        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < mSize; ++j) {
                sum = 0;
                for (int k = 0; k < mSize; ++k) {
                    sum += mMatrix[i * mSize + k] * firstForm[k * mSize + j];
                    result[i * mSize + j] = sum;
                }
            }
        }
        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < mSize; ++j) {
                mMatrix[i * mSize + j] = result[i * mSize + j];
            }
        }
        ++powerCounter;
    }

    delete [] result;
    delete [] firstForm;

    return true;

}
void squareMatrix1D::fillAsIdentity() {
    for (int i = 0; i < mSize; ++i) {
        mMatrix[i * mSize + i] = 1;
    }
}
void squareMatrix1D::fillRandom() {
    srand(time(nullptr));
    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            mMatrix[i * mSize + j] = rand()%10;
        }
    }
}
void squareMatrix1D::fillKeyboard() {
    int buffer;
    for (int i = 0; i < mSize; ++i) {
        printf("Enter a row:\n");
        for (int j = 0; j < mSize; ++j) {
            scanf("%d", &buffer);
            mMatrix[i * mSize + j] = buffer;
        }
        printf("\n");
    }
}
void squareMatrix1D::show() {
    for (int i = 0; i < mSize; ++i) {
        for (int j = 0; j < mSize; ++j) {
            cout << setw(5) <<mMatrix[i * mSize + j];
        }
        cout << endl;
    }
    cout << endl;
}