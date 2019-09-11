//¸ß½×°æ»ô·òÂüÊ÷
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL>> Tex;
LL sum = 0;

LL solve(const vector<LL>& w, int n, int k)
{
	LL sum_tmp;
	for (int i = 0;i < n;i++) {
		Tex.push(w[i]);
	}
	if (k != 2) {
		int addition = n % (k-1) == 1 ? 0 : k - n % (k-1);
		while (addition > 0) {
			Tex.push(0);
			--addition;
		}
	}

	while (Tex.size() > 1) {
		sum_tmp = 0;
		for (int i = 0;i < k;i++) {
			sum_tmp += Tex.top();
			Tex.pop();
		}
		Tex.push(sum_tmp);
		sum += sum_tmp;
	}
	return sum;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	vector<LL> w;
	w.reserve(n);
	for (int i = 0; i < n; i++) {
		LL a;
		scanf("%lld", &a);
		w.push_back(a);
	}
		
	printf("%lld\n", solve(w, n, k));
	return 0;
}