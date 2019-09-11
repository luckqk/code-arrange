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

//���ѡȡ�����λ�ã�������low��high֮��
int SelectPivotMedianOfThree(int arr[], int low, int high)
{
	//srand((unsigned)time(NULL));
	int pivotPos = rand() % (high - low) + low;

	swap(arr[pivotPos], arr[low]);
	return arr[low];
}

//����������ͬ���־�£�汾
void QSort(int arr[], int low, int high)
{
	int first = low;
	int last = high;

	int left = low;
	int right = high;

	int leftLen = 0; //�����key��ȵ�Ԫ�ظ���
	int rightLen = 0; //�ұ���key��ȵ�Ԫ�ظ���

	if (high - low + 1 < 10) {
		InsertSort(arr, low, high);
		return;
	}

	//һ�ηָ�(����ȡ�з�ѡ�����ᣩ
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

	//���ο��Ž���
	//��key��ͬ��������ת��
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