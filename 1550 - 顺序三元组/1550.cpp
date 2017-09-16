#include <iostream>
#include <string>
using namespace std;

int main() {
	int i = 0;
	int one = 0;
	int tree = 0;
	long result = 0;

	// 输入测试数据的组数
	int count;
	cin >> count;
	int *arr = new int[count];

	// 输入测试数据
	for (i = 0; i < count; i++) {
		cin >> arr[i];
		if (3 == arr[i]) {
			tree++;
		}
	}

	// 计算结果
	for (i = 0; i < count; i++) {
		if (1 == arr[i])
			one++;
		else if (2 == arr[i])
			result += one*tree;
		else
			tree--;
	}

	cout << result << endl;

	delete arr;
	return 0;
}