#include <iostream>
#include <string>
using namespace std;

int main() {
	int i = 0;
	int j = 0;

	// 输入测试数据的组数
	int count = 0;
	cin >> count;
	string *name = new string[count];

	// 输入变量名
	for (i = 0; i < count; i++) {
		cin >> name[i];
		// 遍历该变量名
		for (j = 0; j < name[i].length(); j++) {
			// 下划线改小驼峰
			if (name[i][j] == '_') {
				name[i].erase(j, 1);
				name[i][j] = toupper(name[i][j]);
				continue;
			}
			// 小驼峰改下划线
			if (('A' <= name[i][j]) && (name[i][j] <= 'Z')) {
				name[i].insert(j, "_");
				j++;
				name[i][j] = tolower(name[i][j]);
				continue;
			}
		}
	}

	// 输出转换结果
	for (i = 0; i < count; i++) {
		cout << name[i] << endl;
	}
	delete []name;

	return 0;
}