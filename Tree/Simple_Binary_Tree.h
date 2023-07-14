#include <iostream>
using namespace std;
typedef int Data;
struct Node {
	Data data;
	Node* left; Node* right;
	Node(Data d, Node* I = NULL, Node* r = NULL)
	    {data = d; left = I; right = r;}

};
class BinaryTree {
protected:
	Node* root;
	void PrintInorder(Node* n) {
		if (n == NULL)return;
		PrintInorder(n->left);
		cout << n->data << " ";
		PrintInorder(n->right);
	}
public:
	BinaryTree(Node* n = NULL) { root = n; }
	void PrintInorder() { PrintInorder(root); }
};