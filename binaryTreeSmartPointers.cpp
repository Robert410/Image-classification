#include "binaryTreeSmartPointers.h"
#include <queue>
using namespace std;
BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::~BinaryTree() {
}

std::shared_ptr<node> BinaryTree::getRoot() {
	return root;
}

void BinaryTree::freqAll(shared_ptr<node> current) {
	if (current != nullptr) {
		current->freqNode = freqs[current->symbol];
		freqAll(current->left);
		freqAll(current->right);
	}
}

const std::shared_ptr<node> BinaryTree::insert(const char key) {
	std::shared_ptr<node> current = root;
	if (current == nullptr) {
		root = std::make_shared<node>(key);
		freqs[root->symbol]++;
		return root;
	}
	queue<shared_ptr<node>> q;
	q.push(root);
	while (!q.empty()) {
		shared_ptr<node> temp = q.front();
		q.pop();
		if (temp->left != nullptr)
			q.push(temp->left);
		else{
			temp->left = make_shared<node>(key);
			return root;
		}
		if (temp->right != nullptr)
			q.push(temp->right);
		else {
			temp->right = make_shared<node>(key);
			return root;
		}
	}
}

void BinaryTree::preOrder(shared_ptr<node> current ) {
	if (current != nullptr) {
		cout << current->symbol << " ";
		preOrder(current->left);
		preOrder(current->right);
	}
}

void BinaryTree::inOrder(shared_ptr<node> current) {
	if (current != nullptr) {
		preOrder(current->left);
		cout << current->symbol << " ";
		preOrder(current->right);
	}
}

void BinaryTree::postOrder(shared_ptr<node> current) {
	if (current != nullptr) {
		preOrder(current->left);
		preOrder(current->right);
		cout << current->symbol << " ";
	}
}

ostream& operator<<(ostream& os, BinaryTree root) {
	os << "In preorder: ";
	root.preOrder(root.getRoot());
	os << "\nIn inorder: ";
	root.inOrder(root.getRoot());
	os << "\nIn postorder: ";
	root.postOrder(root.getRoot());
	return os;
}

shared_ptr<node> BinaryTree::newParent(shared_ptr<node> Node1, shared_ptr<node> Node2) {
	shared_ptr<node> finalNode = std::make_shared<node>('*');
	finalNode->left = Node1;
	finalNode->right = Node2;
	finalNode->freqNode = Node1->freqNode + Node2->freqNode;
	return finalNode;
}