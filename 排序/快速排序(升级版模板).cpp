#include <iostream>
#include <cstdlib>
using namespace std;

int n, a[1000001];

void InsertSort(int arr[], int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
		for (int j = i;j > 0 && arr[j] < arr[j - 1]; --j)
			swap(arr[j], arr[j - 1]);
}

//随机选取枢轴的位置，区间在low和high之间
int SelectPivotMedianOfThree(int arr[], int low, int high)
{
	//srand((unsigned)time(NULL));
	int pivotPos = rand() % (high - low) + low;

	swap(arr[pivotPos], arr[low]);
	return arr[low];
}

//快速排序，相同数字聚拢版本
void QSort(int arr[], int low, int high)
{
	int first = low;
	int last = high;

	int left = low;
	int right = high;

	int leftLen = 0; //左边与key相等的元素个数
	int rightLen = 0; //右边与key相等的元素个数

	if (high - low + 1 < 10) {
		InsertSort(arr, low, high);
		return;
	}

	//一次分割(三数取中法选择枢轴）
	int key = SelectPivotMedianOfThree(arr, low, high);

	while (low < high) {
		while (high > low && arr[high] >= key) {
			if (arr[high] == key) {
				swap(arr[right], arr[high]);
				right--;
				rightLen++;
			}
			high--;
		}
		arr[low] = arr[high];
		while (high > low && arr[low] <= key) {
			if (arr[left] == key) {
				swap(arr[left], arr[low]);
				left++;
			    leftLen++;
			}
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = key;

	//本次快排结束
	//将key相同的数进行转移
	int i = low - 1;
	int j = first;
	while (j < left && arr[i] != key) {
		swap(arr[i], arr[j]);
		i--;
		j++;
	}

	i = low + 1;
	j = last;
	while (j > right && arr[i] != key) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	QSort(arr, first, low - 1 - leftLen);
	QSort(arr, low + 1 + rightLen, last);
}

int main()
{
	//srand((int)time(NULL));
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	QSort(a, 0, n - 1);
	for (int i = 0; i < n - 1;++i)
		printf("%d ", a[i]);
	printf("%d\n", a[n - 1]);
	return 0;
}