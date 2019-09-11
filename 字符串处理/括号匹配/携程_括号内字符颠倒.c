/****************************************
将括号中的字符颠倒顺序
例		(a(mtf)q)
变化为	qmtfa
****************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

stack<char> stack1;
int t = 0;

static string resolve(string expr)
{
	for (int i = 0;i < expr.length();i++) {
		if (expr[i] == '(') {
			stack1.push(expr[i]);
			t++;
		}
		else if (expr[i] != ')') {
			stack1.push(expr[i]);
		}
		else {
			if (t < 1) {
				return "";
			}
			string newStr;
			while (stack1.top() != '(') {
				newStr += stack1.top();
				stack1.pop();
			}
			stack1.pop();
			t--;
			for (int j = 0;j < newStr.length();j++) {
				stack1.push(newStr[j]);
			}
		}
	}
}


int main()
{
	return 0;
}