#include <iostream>
#include <string>
using namespace std;

/*
思路:
    顺序三元组的总数等于针对每个2所求得的顺序三元组数之和.
    对于每一个2来说, 包含它的顺序三元组个数为它左侧1的个数乘以它右侧3的个数.
    so,只需要针对每一个2,确定它左侧1的个数和右侧3的个数,将它们相乘,把结果累加起来即可.
*/
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