#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class expression {
    vector<bool> mOrder;    //Порядок следования операндов и операций
    vector<string> mOperands;
    vector<char> mOperators;
    string mExpression; //Строка с итоговым выражением
    bool mStandard; //Обычная ли запись (или Польская)

    bool isValidChar(char c);
    bool isNumberChar(char c);
    int getPriority(char c);
    string expressionWithParams(vector<bool>& order, vector<string>& operands, vector<char>& operators);
public:
    expression(string& expr);
    expression(char* expr);

    void convertToRPN();

    double calculate();

    void show();
};
