#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "header.h"

using namespace std;

int main() {
    string inputExpression;
    cout << "Enter the Boolean expression: ";
    getline(cin, inputExpression);

    transform(inputExpression.begin(), inputExpression.end(), inputExpression.begin(), ::toupper);
    inputExpression.erase(remove(inputExpression.begin(), inputExpression.end(), ' '), inputExpression.end());

    string simplified = simplifyExpression(inputExpression);
    cout << "Simplified Expression: " << simplified << endl;

    map<char, bool> testValues = { {'A', true}, {'B', false} };
    bool result = evaluateExpression(simplified, testValues);
    cout << "Evaluation Result with A=true, B=false: " << (result ? "true" : "false") << endl;

    return 0;
}