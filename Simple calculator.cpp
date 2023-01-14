/*
习题2.1 简单计算器 (20 分)
模拟简单运算器的工作。假设计算器只能进行加减乘除运算，运算数和结果都是整数，四种运算符的优先级相同，按从左到右的顺序计算。

输入格式:
输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。

输出格式:
在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。

输入样例:
1+2*10-10/2=

输出样例:
10
*/

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

bool isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

int toNumber(stack<char> &S) {
    int number = 0;
    int i = 0;
    while(!S.empty() && !isOperator(S.top())) {
        number = number + pow(10, i) * (S.top() - '0');
        S.pop();
        i++;
    }
    return number;
}

bool calculate(stack<int> &S, char op) {
    int n2 = S.top();
    S.pop();
    int n1 = S.top();
    S.pop();
    if(op == '/' && n2 == 0)
        return false;
    switch(op) {
        case '+' :
            S.push(n1 + n2);
            break;
        case '-' :
            S.push(n1 - n2);
            break;
        case '*' :
            S.push(n1 * n2);
            break;
        case '/' :
            S.push(n1 / n2);
            break;
    }
    return true;
}

int main() {
    stack<char> s1;
    stack<int> s2;
    string str;
    cin >> str;
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if(str[i] == '=') {
            if((isOperator(s1.top()) && s2.size() < 2) || (s1.empty() && s2.empty())) {
                cout << "ERROR";
                return 0;
            }
            else {
                s2.push(toNumber(s1));
                if(s1.empty() || !calculate(s2, s1.top())) {
                    cout << "ERROR";
                    return 0;
                }
                cout << s2.top();
                return 0;
            }
        }
        if(!isOperator(str[i]))
            s1.push(str[i]);
        else {
            s2.push(toNumber(s1));
            if(!s1.empty()) {
                if(!calculate(s2, s1.top())) {
                    cout << "ERROR";
                    return 0;
                }
                s1.pop();
            }
            s1.push(str[i]);
        }
    }
    cout << "ERROR";
    return 0;
}