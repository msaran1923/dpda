#pragma once

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;


class ImageSaver {
public:
	virtual void save(const Mat& image, string outputFileName) = NULL;

private:

};
