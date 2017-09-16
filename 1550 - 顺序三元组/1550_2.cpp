#include <iostream>
#include <string>
using namespace std;

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
			tree+=two;
		}
	}

	cout << tree << endl;

	return 0;
}