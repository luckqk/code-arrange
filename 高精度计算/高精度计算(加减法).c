/***************************************
描述
高精度计算两数之和n,m。
为正整数、负整数、或者零

输入
输入两个字符串n，m。

输出
输出n+m的答案
****************************************/
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string num1, num2;

struct bign {
	int d[1000];
	int len;
	int flag;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
		flag = 1;
	}
};

bign change(string str)
{
	bign a;
	if (str.length() == 0)
		return a;
	if (str[0] == '-') {
		a.flag = -1;
	}
	a.len = str.length();

	if (a.flag == -1) {
		a.len--;
		for (int i = 1;i < a.len + 1;i++) {
			a.d[i - 1] = str[a.len+1-i] - '0';
		}
	}
	else {
		for (int i = 0;i < a.len;i++) {
			a.d[i] = str[a.len-i-1] - '0';
		}
	}
	return a;
}

bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for (int i = 0;i < a.len || i < b.len;i++) {
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

void print(bign a, int type) {
	if (type == 0)
		cout << '-';
	for (int i = a.len - 1;i >= 0;i--) {
		cout << a.d[i];
	}
}

bign sub(bign a, bign b)
{
	bign c;
	for (int i = 0;i < a.len || i < b.len;i++) {
		if (a.d[i] < b.d[i]) {
			a.d[i + 1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		c.len--;
	}
	return c;
}

bool cmp(bign a, bign b) {
	if (a.len != b.len)
		return a.len > b.len;
	for (int i = 0;i < a.len;i++) {
		if (a.d[i] < b.d[i])
			return false;
	}
	return true;
}

int main()
{
	getline(cin, num1);
	getline(cin, num2);

	bign a = change(num1);
	bign b = change(num2);
	
	bign c;
	if (a.flag == -1 && b.flag == -1) {
		c = add(a, b);
		print(c, 0);
	}
	else if (a.flag == 1 && b.flag == 1) {
		c = add(a, b);
		print(c, 1);
	}
	else {
		int type;
		if (a.flag == -1) {
			if (cmp(a, b)) {
				c = sub(a, b);
				type = 0;
			}
			else {
				c = sub(b, a);
				type = 1;
			}
		}
		else {
			if (cmp(a, b)) {
				c = sub(a, b);
				type = 1;
			}
			else {
				c = sub(b, a);
				type = 0;
			}
		}
		print(c, type);
	}
	return 0;
}