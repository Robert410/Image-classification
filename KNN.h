#pragma once
#include "classifier.h"
#include <vector>
#include <utility>
#include <math.h>
#include <vector>
#include <iostream>

class KNN: public classifier
{
public:
	void training()override;
	unsigned int predict(image* img)override;
	static long long int distanceImages(image* img, image* img2);
	image** randomImageGenerator();
	char randomLabelGenerator();
	KNN() {
		trainingData = new image*;
	}
	image** getdata() {
		return trainingData;
	}
	std::vector<int> getTypes(image**);
	void confusionMatrix();
private:
	image** trainingData;
};

