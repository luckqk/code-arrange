#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[500001];
long long ans;
int tmp_num[500001];

void MergeSort(int l, int r)
{
	if (l >= r-1)
		return;
	int mid = (l + r) >> 1;
	MergeSort(l, mid);
	MergeSort(mid, r);
	int sec_pt = mid;
	int fi_pt = l;
	int curt_pt = l;
	while (fi_pt < mid && sec_pt < r) {
		if (num[fi_pt] <= num[sec_pt]) {
				tmp_num[curt_pt] = num[fi_pt];
				curt_pt++;
				fi_pt++;
		}else {
			tmp_num[curt_pt] = num[sec_pt];
			ans += mid - fi_pt;
			curt_pt++;
			sec_pt++;
		}
	}
	while (fi_pt < mid) {
		tmp_num[curt_pt] = num[fi_pt];
		curt_pt++;
		fi_pt++;
	}
	while(sec_pt < r){
		tmp_num[curt_pt] = num[sec_pt];
		curt_pt++;
		sec_pt++;
	}

	for (int i = l;i < r;++i) {
		num[i] = tmp_num[i];
	}
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;++i)
		scanf("%d", &num[i]);
	MergeSort(0, n);
	printf("%lld\n", ans);
	return 0;
}