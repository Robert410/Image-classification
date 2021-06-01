#include "reading.h"
#include <iostream>
#include <fstream>
using namespace std;
image** reading::loadImg()
{
	image** trainingData = new image * [50000];
	ifstream file("data_batch_1.bin", ios::in | ios::binary);
	for (int i = 0; i < 10000; i++) {
		trainingData[i] = new image;
		file.read((char*)trainingData[i], sizeof(image));
	}
	ifstream file1("data_batch_2.bin", ios::in | ios::binary);
	for (int i = 10000; i < 20000; i++) {
		trainingData[i] = new image;
		file1.read((char*)trainingData[i], sizeof(image));
	}
	ifstream file2("data_batch_3.bin", ios::in | ios::binary);
	for (int i = 20000; i < 30000; i++) {
		trainingData[i] = new image;
		file2.read((char*)trainingData[i], sizeof(image));
	}
	ifstream file3("data_batch_4.bin", ios::in | ios::binary);
	for (int i = 30000; i < 40000; i++) {
		trainingData[i] = new image;
		file3.read((char*)trainingData[i], sizeof(image));
	}
	ifstream file4("data_batch_5.bin", ios::in | ios::binary);
	for (int i = 40000; i < 50000; i++) {
		trainingData[i] = new image;
		file4.read((char*)trainingData[i], sizeof(image));
	}
	return trainingData;
}

