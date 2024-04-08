#include <iostream>
using namespace std;
#define INF 9999

int max_sub_sum(int a[], int len) {
	int this_sum = 0, max_sum = -INF;
	for (int i = 0; i < len; i++) {
		this_sum += a[i];
		if (this_sum < 0) {
			this_sum = 0;
		}
		if (this_sum > max_sum) {
			max_sum = this_sum;
		}
	}
	return max_sum;
}

int main() {
	int a[100], i = 0;
	while (cin >> a[i++],getchar()==',');
	cout << "最大连续子序列和为：" << max_sub_sum(a, i) << endl;
	return 0;
}