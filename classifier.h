#pragma once

#include "reading.h"

class classifier
{
public:
	virtual void training();
	virtual unsigned int predict(image* img);
};

