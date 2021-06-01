#pragma once

#include <string>

typedef struct image {
	char label;
	char redValue[1024];
	char greenValue[1024];
	char blueValue[1024];
};

class reading
{
private:
	const char* labels[10] = { "airplane", "automobile", "bird","cat", "deer", "dog", "frog","horse","ship","truck"};
		
public:
	image** loadImg();

};

