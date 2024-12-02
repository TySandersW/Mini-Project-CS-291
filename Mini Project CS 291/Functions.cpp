#include "header.h"
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '*' || c == '\'');
}

string simplifyExpression(const string& expression) {
    map<string, string> simplifications = {
        {"A+A", "A"},
        {"A*0", "0"},
        {"A*1", "A"},
        {"A+0", "A"},
        {"A+A'", "1"},
        {"A*A'", "0"},
        {"A*A", "A"}
    };

    string result = expression;
    for (const auto& rule : simplifications) {
        size_t pos = result.find(rule.first);
        while (pos != string::npos) {
            result.replace(pos, rule.first.length(), rule.second);
            pos = result.find(rule.first, pos + rule.second.length());
        }
    }
    return result;
}


bool evaluateExpression(const string& expression, map<char, bool> values) {
    stack<bool> operands;

    for (char c : expression) {
        if (c == ' ') continue;

        if (isalpha(c)) {
            operands.push(values[c]);
        }
        else if (c == '\'') {
            bool top = operands.top();
            operands.pop();
            operands.push(!top);
        }
        else if (c == '*') {
            bool a = operands.top();
            operands.pop();
            bool b = operands.top();
            operands.pop();
            operands.push(a && b);
        }
        else if (c == '+') {
            bool a = operands.top();
            operands.pop();
            bool b = operands.top();
            operands.pop();
            operands.push(a || b);
        }
    }
    return operands.top();
}