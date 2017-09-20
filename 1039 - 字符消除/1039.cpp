#include <iostream>
#include <string>
using namespace std;

int del(string & str, int & result) {
	// 对参数进行处理
	if ((0 == str.length()) || (1 == str.length())) {
		return 0;
	}

	string newStr;
	int n = 0;
	int i = 0;

	// 遍历找出谁能消除, 并统计次数
	for (i = 0; i < str.length(); i++) {

		if (i == 0) {	// 第一位单独判断
			if (str[i] == str[i + 1]) {
				n++;
			}
			else {
				newStr += str[i];
			}
		}
		else if (i == str.length() - 1) {	// 最后一位单独判断
			if (str[i] == str[i - 1]) {
				n++;
			}
			else {
				newStr += str[i];
			}
		}
		else if ((str[i] == str[i - 1]) || (str[i] == str[i + 1])) {
			n++;
		}
		else {
			newStr += str[i];
		}
	}

	if (n > 0) {
		result += n;
		str = newStr;
		return 1;
	}
	return 0;
}

int main() {
	int i = 0;
	int j = 0;
	int n = 0;
	int result = 0;

	// 输入测试组数
	int count = 0;
	cin >> count;
	string *str = new string[count];
	string tempStr;

	// 输入字符串
	for (i = 0; i < count; i++) {
		cin >> str[i];
	}

	// 处理每个字符串
	for (i = 0; i < count; i++) {
		result = 0;

		// 在字符串的每个位置上插入A, B, C
		for (int j = 0; j <= str[i].length(); j++) {
			n = 0;
			tempStr = str[i];
			tempStr.insert(j,"A");
			while (del(tempStr, n)) {}
			if (result < n)	result = n;

			n = 0;
			tempStr = str[i];
			tempStr.insert(j, "B");
			while (del(tempStr, n)) {}
			if (result < n)	result = n;

			n = 0;
			tempStr = str[i];
			tempStr.insert(j, "C");
			while (del(tempStr, n)) {}
			if (result < n)	result = n;
		}
		cout << result << endl;
	}

	return 0;
}