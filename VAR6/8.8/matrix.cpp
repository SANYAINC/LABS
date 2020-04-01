#include "matrix.h"

int matrix::sCounter = 1;

std::ostream& operator<<(std::ostream& out, const matrix& matrixToOut) {
    out << matrixToOut.mName << " (" << matrixToOut.mRows << "x" << matrixToOut.mCols << ")" << std::endl;
    if (matrixToOut.mRows == 0 and matrixToOut.mCols == 0) {
        out << "|| ||" << std::endl;
        return out;
    } else {
        for (int i = 0; i < matrixToOut.mRows; ++i) {
            out << "||";
            for (int j = 0; j < matrixToOut.mCols; ++j) {
                out << std::setw(SPACING) << std::setprecision(8) << ((std::abs(matrixToOut.mMatrix[i][j]) < 0.0005) ? 0.0: matrixToOut.mMatrix[i][j]);
            }
            for (int k = 0; k < SPACING - 1; ++k) {
                out << " ";
            }
            out << "||" << std::endl;
        }
        return out;
    }
}
std::istream& operator>>(std::istream& in, matrix& matrixToIn) {
    int rows, cols;
    try {
        std::cout << std::endl << "Please, enter number of rows: ";
        std::cin >> rows;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore((2 << 15) - 1, '\n');
            std::cout << "Please, enter correct number of rows: ";
            std::cin >> rows;
        }
        std::cin.ignore((2 << 15) - 1, '\n');
        std::cout << "Please, enter number of columns: ";
        std::cin >> cols;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore((2 << 15) - 1, '\n');
            std::cout << "Please, enter correct number of cols: ";
            std::cin >> cols;
        }
        std::cin.ignore((2 << 15) - 1, '\n');
        if (rows < 0) {
            throw rows;
        }
        if (cols < 0 ){
            throw cols;
        }
    } catch (int) {
        std::cerr << "WRONG SIZE " << rows << "x" << cols << std::endl;
        exit(800);
    }

    if (rows == 0 or cols == 0) {
        for (int i = 0; i < matrixToIn.mRows; ++i) {
            matrixToIn.mMatrix[i].clear();
        }
        matrixToIn.mMatrix.clear();
        matrixToIn.mRows = 0;
        matrixToIn.mCols = 0;
        return in;
    } else {
        vector <double> temp;
        matrixToIn.mRows = rows;
        matrixToIn.mCols = cols;
        matrixToIn.mMatrix.resize(rows, temp);
        for (int i = 0; i < rows; ++i) {
            matrixToIn.mMatrix[i].resize(cols, 0);
        }
        for (int i = 0; i < matrixToIn.mRows; ++i) {
            std::cout << "Please enter " << matrixToIn.mCols << " numbers of #" << i << " row: ";
            for (int j = 0; j < matrixToIn.mCols; ++j) {
                std::cin >> matrixToIn.mMatrix[i][j];
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore((2 << 15) - 1, '\n');
                    std::cout << "Please, enter correct number: ";
                    std::cin >> matrixToIn.mMatrix[i][j];
                }
                std::cin.ignore((2 << 15) - 1, '\n');
            }
        }
    }
    std::cout << std::endl;
    return in;
}

matrix::matrix() {
    mName = "Matrix " + std::to_string(sCounter++);
    mRows = 0;
    mCols = 0;
}
matrix::matrix(const int rows, const int cols) {
    try {
        if (rows < 0) {
            throw rows;
        }
        if (cols < 0) {
            throw cols;
        }
    } catch (int invalidValue) {
        std::cout << "WRONG SIZE " << invalidValue << std::endl;
        exit(810);
    }

    mName = "Matrix " + std::to_string(sCounter++);
    if (rows == 0 or cols == 0) {
        mRows = 0;
        mCols = 0;
        return;
    }
    mRows = rows;
    mCols = cols;
    vector <double> temp;
    mMatrix.resize(rows, temp);
    for (int i = 0; i < rows; ++i) {
        mMatrix[i].resize(cols, 0);
    }
}
matrix::matrix(const matrix& anotherMatrix) {
    mName = anotherMatrix.mName;
    mRows = anotherMatrix.mRows;
    mCols = anotherMatrix.mCols;
    mMatrix = anotherMatrix.mMatrix;
}
matrix::~matrix() {
    for (int i = 0; i < mRows; ++i) {
        mMatrix[i].clear();
    }
    mMatrix.clear();
}

vector <double>& matrix::operator[](const int index) {
    try {
        if (index < 0 or index >= mRows) {
            throw index;
        }
        return mMatrix[index];
    } catch (int) {
        std::cerr << "INDEX " << index << " IS OUT OF RANGE" << std::endl;
        exit(900);
    }
}

matrix matrix::operator+(double number) {
    matrix ans(*this);
    ans.fillIdentity();
    ans *= number;
    ans += *this;
    return ans;
}
matrix matrix::operator-(double number) {
    matrix ans(*this);
    ans.fillIdentity();
    ans *= number;
    ans -= *this;
    return ans;
}
matrix matrix::operator*(double number) {
    matrix ans(*this);
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            ans.mMatrix[i][j] *= number;
        }
    }
    return ans;
}
matrix matrix::operator/(double number) {
    if (number == 0) {
        std::cerr << "DIVISION BY ZERO" << std::endl;
        exit(902);
    }
    matrix ans(*this);
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            ans.mMatrix[i][j] /= number;
        }
    }
    return ans;
}
matrix matrix::operator+(const matrix& anotherMatrix) {
    if (!isSameSizeWith(anotherMatrix)) {
        std::cerr << "CANT ADD (WRONG SIZE)" << std::endl;
        exit(807);
    }
    matrix ans(mRows, mCols);
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            ans.mMatrix[i][j] = mMatrix[i][j] + anotherMatrix.mMatrix[i][j];
        }
    }
    return ans;
}
matrix matrix::operator-(const matrix& anotherMatrix) {
    if (!isSameSizeWith(anotherMatrix)) {
        std::cerr << "CANT SUBTRACT (WRONG SIZE)" << std::endl;
        exit(809);
    }
    matrix ans(mRows, mCols);
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            ans.mMatrix[i][j] = mMatrix[i][j] - anotherMatrix.mMatrix[i][j];
        }
    }
    return ans;
}
matrix matrix::operator*(const matrix& anotherMatrix) {
    if (!isCompatibleWith(anotherMatrix)) {
        std::cerr << "CANT MULTIPLY (WRONG SIZE)" << std::endl;
        exit(809);
    }
    matrix ans(mRows, anotherMatrix.mCols);
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < anotherMatrix.mCols; ++j) {
            for (int k = 0; k < mCols; ++k) {
                ans.mMatrix[i][j] += mMatrix[i][k] * anotherMatrix.mMatrix[k][j];
            }
        }
    }
    return ans;
}

matrix& matrix::operator=(const matrix& anotherMatrix) {
    if (&anotherMatrix == this) {
        return *this;
    }
    mRows = anotherMatrix.mRows;
    mCols = anotherMatrix.mCols;
    mMatrix = anotherMatrix.mMatrix;
    mName = anotherMatrix.mName;
    return *this;
}

matrix& matrix::operator+=(double number) {
    *this = *this + number;
    return *this;
}
matrix& matrix::operator-=(double number) {
    *this = *this - number;
    return *this;
}
matrix& matrix::operator*=(double number) {
    *this = *this * number;
    return *this;
}
matrix& matrix::operator/=(double number) {
    *this = *this / number;
    return *this;
}
matrix& matrix::operator+=(const matrix& anotherMatrix) {
    *this = *this + anotherMatrix;
    return *this;
}
matrix& matrix::operator-=(const matrix& anotherMatrix) {
    *this = *this - anotherMatrix;
    return *this;
}
matrix& matrix::operator*=(const matrix& anotherMatrix) {
    *this = *this * anotherMatrix;
    return *this;
}

bool matrix::operator==(const matrix& anotherMatrix) {
    if (!isSameSizeWith(anotherMatrix)) {
        std::cerr << "CANT COMPARE (WRONG SIZE)" << std::endl;
        exit(801);
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            if (mMatrix[i][j] != anotherMatrix.mMatrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}
bool matrix::operator!=(const matrix& anotherMatrix) {
    return !(*this == anotherMatrix);
}

bool matrix::isSquared() {
    if (mRows == 0 or mCols == 0) {
        return false;
    }
    return mRows == mCols;
}
bool matrix::isDiagonal() {
    if (mRows == 0 or mCols == 0) {
        return false;
    }
    if (!isSquared()) {
        return false;
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            if (i!=j and mMatrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
bool matrix::isZero() {
    if (mRows == 0 or mCols == 0) {
        return false;
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            if (mMatrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
bool matrix::isNull() {
    return mRows == 0;
}
bool matrix::isIdentity() {
    if (mRows == 0 or mCols == 0) {
        return false;
    }
    if (!isSquared()) {
        return false;
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            if (i!=j and mMatrix[i][j] != 0) {
                return false;
            }
            if (i==j and mMatrix[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}
bool matrix::isSymmetrical() {
    if (mRows == 0 or mCols == 0) {
        return false;
    }
    if (!isSquared()) {
        return false;
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            if (mMatrix[i][j] != mMatrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}
bool matrix::isUpperTriangle() {
    if (mRows == 0 or mCols == 0) {
        return false;
    }
    if (!isSquared()) {
        return false;
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            if (i > j and mMatrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
bool matrix::isLowerTriangle() {
    if (mRows == 0 or mCols == 0) {
        return false;
    }
    if (!isSquared()) {
        return false;
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            if (i < j and mMatrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
bool matrix::isSameSizeWith(const matrix& anotherMatrix) {
    return mRows == anotherMatrix.mRows and mCols == anotherMatrix.mCols;
}
bool matrix::isCompatibleWith(const matrix& anotherMatrix) {
    return mCols == anotherMatrix.mRows;
}

matrix matrix::getTransposed() {
    matrix ans(mCols, mRows);
    for (int i = 0; i < mCols; ++i) {
        for (int j = 0; j < mRows; ++j) {
            ans.mMatrix[i][j] = mMatrix[j][i];
        }
    }
    return ans;
}

matrix matrix::getRaisedIn(int power) {
    if (!isSquared()) {
        std::cerr << "CANT RAISE (WRONG SIZE)" << std::endl;
        exit(804);
    }
    matrix ans(*this);
    if (mRows == 0 or mCols == 0) {
        return ans;
    }
    if (power == 0) {
        ans.fillIdentity();
        return ans;
    } else {
        for (int i = 0; i < power - 1; ++i) {
            ans *= *this;
        }
    }
    return ans;
}
void matrix::fillRandom() {
    srand(time(nullptr));
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mMatrix[i][j] = rand()%100;
        }
    }
}
void matrix::fillKeyboard() {
    for (int i = 0; i < mRows; ++i) {
        std::cout << "Please enter " << mCols << " numbers of #" << i << " row: ";
        for (int j = 0; j < mCols; ++j) {
            std::cin >> mMatrix[i][j];
        }
    }
    std::cout << std::endl;
}
void matrix::fillIdentity() {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            if (i == j) {
                mMatrix[i][j] = 1;
            } else {
                mMatrix[i][j] = 0;
            }
        }
    }
}
int matrix::getRows() {
    return mRows;
}
int matrix::getCols() {
    return mCols;
}
void matrix::print() {
    std::cout << *this;
}





