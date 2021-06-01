#include <stdio.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include "KNN.h"
#include <iomanip>
using namespace std::chrono;
#pragma warning(disable : 4996)

#include "binaryTreeSmartPointers.h"

using namespace std;

int main() {
	auto start = high_resolution_clock::now();
	KNN test;
	test.training();
	test.confusionMatrix();
	auto stop = high_resolution_clock::now();


	auto duration = duration_cast<seconds>(stop - start);
	cout << "Time taken by function: "	
		<< duration.count() << " seconds" << endl;

	/*BinaryTree binTree;
	shared_ptr<node> fin;
	binTree.insert('a');
	binTree.insert('b');
	binTree.insert('d');
	binTree.insert('e');
	binTree.insert('c');
	binTree.insert('a');
	binTree.insert('e');
	fin = binTree.newParent(binTree.getRoot()->left, binTree.getRoot()->right);
	cout << fin->symbol << '\n';
	binTree.freqAll   (binTree.getRoot());
	binTree.preOrder  (binTree.getRoot());
	cout << endl;
	cout << binTree;*/
	return 0;
}