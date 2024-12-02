#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <map>
using namespace std;

string simplifyExpression(const string& expression);
bool evaluateExpression(const string& expression, map<char, bool> values);
bool isOperator(char c);

#endif