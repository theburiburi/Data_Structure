#include "Student.h"

class Node {
public:
	Student data;
	Node* left; Node* right;
	Node(Student d, Node* l = NULL, Node* r = NULL) { data = d; left = l; right = r; }
};
class StudentTree {
protected:
	Node* root;
	void PrintInorder(Node* n) {
		if (n == NULL)return;
		PrintInorder(n->left);
		n->data.Print();
		PrintInorder(n->right);
	}

	void PrintPostorder(Node* n) {
		if (n == NULL)return;
		PrintInorder(n->left);
		PrintInorder(n->right);
		n->data.Print();
	}

	void PrintPreorder(Node* n) {
		if (n == NULL)return;
		n->data.Print();
		PrintInorder(n->left);
		PrintInorder(n->right);
	}
public:
	StudentTree(Node* n = NULL) { root = n; }
	void PrintInorder() { PrintInorder(root); }
	void PrintPreorder() { PrintPreorder(root); }
	void PrintPostorder() { PrintPostorder(root); }
};