#include <iostream>
#include <string>
using namespace std;

/*
思路:
    简化: 只考虑1和2的情况, 当遇到一个2时, 前面有几个1, 就有几个顺序二元组{1,2}
    扩展: 当遇到一个3时, 前面有个{1,2}, 就有几个顺序三元组{1,2,3}
    简单的累加即可.
*/
int main() {
	int i = 0;
	long one = 0;
	long two = 0;
	long tree = 0;
	int temp;
	// 输入测试数据的组数
	int count;
	cin >> count;

	// 输入测试数据
	for (i = 0; i < count; i++) {
		cin >> temp;
		if (1 == temp) {
			one++;
		}
		else if (2 == temp) {
			two += one;
		}
		else if (3 == temp) {
			tree += two;
		}
	}

	cout << tree << endl;

	return 0;
}