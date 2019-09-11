#include <bits/stdc++.h>
using namespace std;

vector<int> num = { 3,2,4,7,5,1,9 };

void insertSort()
{
	int i,j;
	int tmp;
	int number = num.size();

	for (i = 1;i < number;++i) {
		tmp = num[i];
		for (j = i - 1;j >= 0 && num[j] > tmp ;--j) 
				num[j + 1] = num[j];
		num[j + 1] = tmp;
	}
	return;
}

void main()
{
	insertSort();
	return;
}