//#pragma once

#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <memory>

using namespace std;

struct node {
	char symbol;
	std::shared_ptr<node> left; 
	std::shared_ptr<node> right;
	int freqNode;
	node(const char value) {
		symbol = value;
		left = nullptr;
		right = nullptr;
		freqNode = 1;
	}
};
class BinaryTree {
	int freqs[300];
private:
	std::shared_ptr<node> root;

public:
	BinaryTree();
	~BinaryTree();
	std::shared_ptr<node> getRoot();
	void preOrder(std::shared_ptr<node>);
	void inOrder(std::shared_ptr<node>);
	void postOrder(std::shared_ptr<node>);
	const std::shared_ptr<node> insert(const char);
	friend ostream& operator<<(ostream&, BinaryTree);
	void freqAll(shared_ptr<node>);
	static shared_ptr<node> newParent(shared_ptr<node>, shared_ptr<node>);
};
