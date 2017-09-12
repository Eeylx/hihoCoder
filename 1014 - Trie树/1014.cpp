#include <iostream>
#include <string>
using namespace std;

typedef struct Node
{
	char data;
	int count;
	Node* child[26];
}node;

int initNode(node* node) {
	node->count = 0;
	for (int i = 0; i < 26; i++) {
		node->child[i] = NULL;
	}
	return 0;
}

int main() {
	int i = 0;
	int j = 0;
	node* root = new node;
	initNode(root);
	node* now = NULL;
	string word;

	// 输入词典大小
	int count = 0;
	cin >> count;

	// 输入单词(小写字母)
	for (i = 0; i < count; i++) {
		cin >> word;
		now = root;
		for (j = 0; j < word.length(); j++) {
			if (NULL == now->child[word[j] - 'a']) {
				now->child[word[j] - 'a'] = new node;
				initNode(now->child[word[j] - 'a']);
				now->child[word[j] - 'a']->data = word[j];
			}
			now = now->child[word[j] - 'a'];
			now->count++;

		}
	}

	// 输入询问次数
	cin >> count;

	// 查询
	for (i = 0; i < count; i++) {
		cin >> word;
		now = root;
		for (j = 0; j < word.length(); j++) {
			if (NULL == now->child[word[j] - 'a']) {
				break;
			}
			now = now->child[word[j] - 'a'];
		}

		if (j != word.length()) {
			cout << "0" << endl;
		}
		else {
			cout << now->count << endl;
		}
	}

	return 0;
}