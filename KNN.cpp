#include "KNN.h"

#include <fstream>
#include <iomanip>
#define Distances pair<long long int, char>
using namespace std;

void KNN::training() {
	reading d;
	trainingData = d.loadImg();
}

image** KNN::randomImageGenerator() {
	image** databaserandom = new image * [50000];
	int pos = 5;
	while (pos) {
		for (int i = 0; i < 10000; i++) {
			databaserandom[i] = new image;
			databaserandom[i]->label = rand() % 10;
			for (int j = 0; j < 1024; j++) {
				databaserandom[i]->redValue[j] = rand() % 255;
				databaserandom[i]->blueValue[j] = rand() % 255;
				databaserandom[i]->greenValue[j] = rand() % 255;
			}
		}
		pos--;
	}

	return databaserandom;
}


char KNN::randomLabelGenerator() {
	ifstream fin("batches.meta.txt");
	int nr = 0; char label[55];
	while (fin.getline(label, 55)) {
		nr++;
	}
	int result = rand() % nr;
	return result;
}

vector<int> KNN::getTypes(image** db) {
	vector<int> values;
	for (int i = 0; i < 10000; i++)
		values.push_back((int)db[i]->label);
	return values;
}

unsigned int KNN::predict(image* img){

	vector<Distances> vectorOfDists;
	Distances element;
	for (int i = 0; i < 50000; i++){
		element.first = distanceImages(trainingData[i], img);
		element.second = trainingData[i]->label;

		vectorOfDists.push_back(element);
	}

	int i = 0;

	int freq[10];
	for (int i = 0; i < 10; i++)
		freq[i] = 0;



	while (i < 7) {
		for (int j = 0; j < vectorOfDists.size() - (1 + i); j++) {
			if (vectorOfDists[j].first < vectorOfDists[j + 1].first)
				swap(vectorOfDists[j], vectorOfDists[j + 1]);
		}
		i++;
	}


	for (int j = vectorOfDists.size() - 7; j < vectorOfDists.size(); j++) {
		int nr = vectorOfDists[j].second;
		freq[nr]++;
	}

	int mmax = 0, jmax = -1;
	for (int j = 0; j < 10; j++) 
		if (freq[j] > mmax){
			mmax = freq[j];
			jmax = j;
		}
	
	return jmax;
}

long long int KNN::distanceImages(image* img, image* img2){
	long long int distance = 0;
	int blued, redd, greend;
	for (int i = 0; i < 1024; i++) {
		blued = img->blueValue[i] - img2->blueValue[i];
		redd = img->redValue[i] - img2->redValue[i];
		greend = img->greenValue[i] - img2->greenValue[i];

		distance = distance + abs(blued) + abs(redd) + abs(greend);
	}
	return distance;
}

int pozLabels(vector<pair<string, int>> label, string s) {
	for (int i = 0; i < 10; i++)
		if (label[i].first == s)
			return label[i].second;
	return -1;
}

void KNN::confusionMatrix() {

	vector<pair<string, int>> labels;
	pair<string, int> elem;

	ifstream fin("batches.meta.txt");
	int nr = 0; char label[50];
	while (fin.getline(label,50)) {
		elem.first = label;
		elem.second = nr;
		labels.push_back(elem);
		nr++;
	}

	ofstream fout("out.txt");
	fout << "Our labels are: \n";
	for (int i = 0; i < 10; i++) 
		fout << "		" << labels[i].first << " -> " << labels[i].second << '\n';
	fout << '\n';

	int matrix[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			matrix[i][j] = 0;

	vector<int> actual, prediction;
	int nrOfImages = 20, nrr = 0;
	fout << "We compute the prediction for the first " << nrOfImages << " images and the result is: \n";
	for (int i = 10; i < 500; i++) {
		actual.push_back((int)trainingData[i]->label);
		prediction.push_back(predict(trainingData[i]));
		cout << i << endl;
		fout << "		Image: " << i << " had label " << actual[nrr] << " and now has " << prediction[nrr] << "\n";
		
		if (actual[nrr] == prediction[nrr])
			matrix[actual[nrr]][actual[nrr]]++;
		else
			matrix[prediction[nrr]][actual[nrr]]++;
		nrr++;
	} 
	fout << '\n';
	double accuracy;
	fout << "The created confusion matrix is: \n\n";
	int totalLabels = 0, validLabels = 0;
	for (int i = 0; i < 10; i++, fout << "\n")
		for (int j = 0; j < 10; j++){
			int element = matrix[pozLabels(labels, labels[i].first)][pozLabels(labels, labels[j].first)];
			if (i == j) validLabels += element;
			totalLabels += element;
			fout << element << " ";

		}
	accuracy =  (100.0 * validLabels) / totalLabels;

	fout << "\nAnd this confusion matrix has the accuracy: ";
	fout << setprecision(5) << accuracy;
	fout << "\n";
}