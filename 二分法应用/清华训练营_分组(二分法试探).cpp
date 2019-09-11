//用了二分的思想
/***************************************
描述
有n个正整数排成一排，你要将这些数分成m份
（同一份中的数字都是连续的，不能隔开），
同时数字之和最大的那一份的数字之和尽量小。

输入
输入的第一行包含两个正整数n，m。
接下来一行包含n个正整数。

输出
输出一个数，表示最优方案中，数字之和最大
的那一份的数字之和。
****************************************/
#include <bits/stdc++.h>
using namespace std;

bool check(long long d, int n, int m, vector<int> &a)
{
	long long sum = 0;
	int cnt = 1;

	for (int i = 0;i < n;++i) {
		if (a[i] > d) {
			return false;
		}
		sum += a[i];
		if (sum > d) {
			sum = a[i];
			++cnt;
		}
	}
	return cnt <= m;
}

long long getAnswer(int n, int m, vector<int> a) {
	long long l = 1, r = 0;
	for (int i = 0;i < n;++i) {
		r += a[i];
	}

	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid, n, m, a))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return r + 1;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("%lld\n", getAnswer(n, m, a));
    return 0;
}

