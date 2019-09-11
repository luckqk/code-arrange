//øÏÀŸ≈≈–Ú
#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int partiton(int p_lo, int p_hi)
{
	int pivot = a[p_lo];
	int lo_end = p_lo;
	for (int k = p_lo + 1;k < p_hi;++k) {
		if (a[k] <= pivot) {
			swap(a[k], a[lo_end + 1]);
			++lo_end;
		}
	}
	swap(a[p_lo], a[lo_end]);
	return lo_end;
}

int quicksort(int lo, int hi)
{
	if (lo >= hi - 1) {
		return 0;
	}
	int mi = partiton(lo, hi);
	quicksort(lo, mi);
	quicksort(mi + 1, hi);
	return 1;
}

vector<int> getAnswer(int n) {
	quicksort(0, n);
	return a;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    a = getAnswer(n);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
    return 0;
}
