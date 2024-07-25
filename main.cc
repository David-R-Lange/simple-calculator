/*
Name: Calculator
Author: David Lange
Date: 25.07.2024
Description: Simple one file calculator program to add, subtract, multiply and divide user input 
 */
#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

bool isNumber(string s) {
  for(int i = 0; i < s.length(); ++i) {
    if( !isdigit(s[i]) ) {
      return false;
    }
  }
  return true;
}

bool isOperator(string s) {
  if(s == "+" || s == "-" || s == "*" || s == "/") {
    return true;
  }
  return false;
}

double calculate(double a, double b, char op) {
  switch (op) {
    case '+':
      return a+b;
    case '-':
      return a-b;
    case '*':
      return a*b;
    case '/':
      return a/b;
  }
  return numeric_limits<double>::quiet_NaN();
}


int main() {
  string inputNum1, inputOperator, inputNum2 = "";
  double num1, num2, result;
  cout << "Basic Calculator. Type q to quit" << endl;
  while(true) {
    cin >> inputNum1 >> inputOperator >> inputNum2;

    if(inputNum1 == "q" || inputNum1 == "quit" || inputNum2 == "q" || inputNum2 == "quit" || inputOperator == "q" || inputOperator == "quit") {
      return 1;
    }

    // cout << inputNum1 << ' ' << inputNum2 << ' ' << inputOperator << endl;

    // cout << isNumber(inputNum1) << ' ' << isNumber(inputNum2) << ' ' << isOperator(inputOperator) << endl;

    if(!isNumber(inputNum1) || !isNumber(inputNum2) || !isOperator(inputOperator)) {
      cout << "Please enter valid numbers and operators (+ - * /)" << endl;
      continue;
    }
    
    num1 = stod(inputNum1);
    num2 = stod(inputNum2);

    result = calculate(num1, num2, inputOperator[0]);

    cout << result << endl;
  }
}
