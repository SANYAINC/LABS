#include "expression.h"
expression::expression(string& expr) {
    string bufStr;
    mStandard = true;
    for (int i = 0; expr[i]; ++i) {
        if (!isValidChar(expr[i])) {
            exit(9);
        }
        if (expr[i] == ' ') {
            continue;
        }
        if (isNumberChar(expr[i])) {
            while (isNumberChar(expr[i])) {
                bufStr += expr[i++];
            }
            --i;

            mOrder.push_back(true);
            mOperands.push_back(bufStr);
            bufStr.clear();
        } else {
            mOrder.push_back(false);
            mOperators.push_back(expr[i]);
        }
    }
    int operandsIter = 0;
    int operatorsIter = 0;
    for (int i = 0; i < mOrder.size(); ++i) {
        if (mOrder[i]) {
            mExpression += mOperands[operandsIter++];
            mExpression += " ";
        } else {
            mExpression += mOperators[operatorsIter++];
            mExpression += " ";
        }
    }
}

expression::expression(char* expr) {
    string bufStr;
    mStandard = true;
    for (int i = 0; expr[i]; ++i) {
        if (!isValidChar(expr[i])) {
            exit(9);
        }
        if (expr[i] == ' ') {
            continue;
        }
        if (isNumberChar(expr[i])) {
            while (isNumberChar(expr[i])) {
                bufStr += expr[i++];
            }
            --i;

            mOrder.push_back(true);
            mOperands.push_back(bufStr);
            bufStr.clear();
        } else {
            mOrder.push_back(false);
            mOperators.push_back(expr[i]);
        }
    }
    int operandsIter = 0;
    int operatorsIter = 0;
    for (int i = 0; i < mOrder.size(); ++i) {
        if (mOrder[i]) {
            mExpression += mOperands[operandsIter++];
            mExpression += " ";
        } else {
            mExpression += mOperators[operatorsIter++];
            mExpression += " ";
        }
    }
}

bool expression::isValidChar(char c) {
    return (c >= 40 and c <= 43) or (c >= 45 and c <= 57) or c == ' ';
}

bool expression::isNumberChar(char c) {
    return (c >= 48 and c <= 57) or c == 46;
}

void expression::show() {
    cout << mExpression << endl;
}

void expression::convertToRPN() {
    if (!mStandard) {
        return;
    }

    vector<bool> newOrder;
    vector<char> newOperators;
    stack<char> buffer;
    int curPriority;

    mStandard = false;
    mExpression.clear();


    int oprtrI = 0;
    int oprndI = 0;
    for (int i = 0; i < mOrder.size(); ++i) {
        //Если это число, просто добавляем к ответу
        if (mOrder[i]) {
            newOrder.push_back(true);
            mExpression += mOperands[oprndI++];
            mExpression += " ";
        } else {
            curPriority = getPriority(mOperators[oprtrI]);
            //Если закрывающаяся скобка - выталкиваем из стека в ответ, пока не дойдем до открывающейся
            if (mOperators[oprtrI] == ')') {
                while (buffer.top() != '(') {
                    newOrder.push_back(false);
                    newOperators.push_back(buffer.top());
                    mExpression += buffer.top();
                    mExpression += " ";
                    buffer.pop();
                }
                buffer.pop();
                oprtrI++;
                continue;
            }
            if (!buffer.empty()) {
                //Если приоритет текущей операции больше приоритета вершины стека, добавляем операцию в стек
                if (curPriority > getPriority(buffer.top()) or mOperators[oprtrI] == '(') {
                    buffer.push(mOperators[oprtrI]);
                } else {
                    //Если ниже, выталкиваем все из стека пока не встретим операцию приоритетом ниже или он опустеет
                    while (!buffer.empty() and getPriority(buffer.top()) >= curPriority) {
                        newOrder.push_back(false);
                        newOperators.push_back(buffer.top());
                        mExpression += " ";
                        mExpression += buffer.top();
                        buffer.pop();
                    }
                    buffer.push(mOperators[oprtrI]);
                }
            } else {
                //Если буфер пустой, добавляем операцию в стек
                buffer.push(mOperators[oprtrI]);
            }
            oprtrI++;
        }
    }
    //Выталкиваем остатки из стека
    while (!buffer.empty()) {
        newOrder.push_back(false);
        newOperators.push_back(buffer.top());
        mExpression += buffer.top();
        mExpression += " ";
        buffer.pop();
    }
    mOperators = newOperators;
    mOrder = newOrder;
}

int expression::getPriority(char c) {
    switch (c) {
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        case '(': case ')': return 1;
        default: return 0;
    }
}

double expression::calculate() {
    if (mStandard) {
        cerr << "Firstly convert to reverse Polish notation" << endl;
        return 0;
    }

    vector<string> currentOperands = mOperands;
    vector<char> currentOperators = mOperators;
    vector<bool> currentOrder = mOrder;

    int searcher1, cou1 = 0;
    int searcher2, cou2 = 0;
    double bufferDbl;
    string bufferStr;

    //Пока остались операторы крутим цикл
    while (!currentOperators.empty()) {
        cout << expressionWithParams(currentOrder, currentOperands, currentOperators) << endl;
        //Обходим выражение в поисках оператора
        for (int i = 0; i < currentOrder.size(); ++i) {
            if (!currentOrder[i]) {
                //Поиск первых двух операндов перед оператором
                for (searcher1 = i; !currentOrder[searcher1] ; --searcher1);
                for (int j = 0; j < searcher1; ++j) {
                    if (currentOrder[j]) {
                        cou1++;
                    }
                }
                for (searcher2 = searcher1 - 1; !currentOrder[searcher2]; --searcher2);
                for (int j = 0; j < searcher2; ++j) {
                    if (currentOrder[j]) {
                        cou2++;
                    }
                }
                //Выполняем операцию
                switch (currentOperators[0]) {
                    case '+': {
                        bufferDbl = stod(currentOperands[cou2]) + stod(currentOperands[cou1]);
                        break;
                    }
                    case '-': {
                        bufferDbl = stod(currentOperands[cou2]) - stod(currentOperands[cou1]);
                        break;
                    }
                    case '*': {
                        bufferDbl = stod(currentOperands[cou2]) * stod(currentOperands[cou1]);
                        break;
                    }
                    case '/': {
                        bufferDbl = stod(currentOperands[cou2]) / stod(currentOperands[cou1]);
                        break;
                    }
                    default: bufferDbl = 0;
                }
                //Приводим результат к строке, обрезая ненужные нули с конца
                bufferStr = to_string(bufferDbl);
                unsigned int end = bufferStr.size()-1;
                while (bufferStr.size() > 2 and bufferStr[end] == '0' and bufferStr[end - 1] != '.') {
                    bufferStr.erase(bufferStr.begin() + end);
                    end = bufferStr.size()-1;
                }

                currentOperands.insert(currentOperands.begin() + cou2, bufferStr); //Вставляем результат в вектор операндов
                currentOperands.erase(currentOperands.begin() + cou2 + 1, currentOperands.begin() + cou2 + 3); //Удаляем 2 операнда, которые использовали
                currentOrder.insert(currentOrder.begin() + cou2, true); //Вставляем в порядок операнд
                currentOrder.erase(currentOrder.begin() + cou2 + 1, currentOrder.begin() + cou2 + 4);   //Удаляем 2 операнда из порядка, которые использовали
                currentOperators.erase(currentOperators.begin()); //Удаляем оператор, который использовали

                cou1 = 0;
                cou2 = 0;
                break;
            }
        }
    }
    cout << endl;
    //В конце останется один операнд, который и будет рузельтатом
    return stod(currentOperands[0]);
}

string expression::expressionWithParams(vector <bool>& order, vector <string>& operands, vector <char>& operators) {
    string result;
    int oprndI = 0;
    int oprtrI = 0;
    for (int i = 0; i < order.size(); ++i) {
        if (order[i]) {
            (result += operands[oprndI++]) += ' ';
        } else {
            (result += operators[oprtrI++]) += ' ';
        }
    }
    return result;
}
