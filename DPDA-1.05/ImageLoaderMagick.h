#pragma once

#include <iostream>
#include <opencv2\opencv.hpp>
#include <Magick++.h>
#include "ImageLoader.h"

using namespace std;
using namespace cv;
using namespace Magick;


class ImageLoaderMagick : public ImageLoader {
public:
	ImageLoaderMagick()
	{
		InitializeMagick("");
	}

	virtual ~ImageLoaderMagick() 
	{
		remove(getTempFileName());
	}

	static string getTempFileName()
	{
		return "_temp_.png";
	}

	Mat load(path imagePath)
	{
		String inputFileName = getFileName(imagePath);

		Image imMagick;
		try {
			imMagick.read(inputFileName);
			#pragma omp critical
			{
				cout << inputFileName << " : " << imMagick.size().width() << " x " << imMagick.size().height() << " x " << imMagick.channels() << " ";
			}
			if (imMagick.channels() >= 3)
				imMagick.write(getTempFileName());
			else {
				cout << ",  Invalid channel size!" << endl;
				return Mat();
			}
		}
		catch (std::exception& error_)
		{
			addImageLoadError(imagePath);
			return Mat();
		}

		Mat image = imread(getTempFileName(), cv::IMREAD_COLOR);
		if (image.cols > 0 && image.rows > 0) {
			return image;
		}

		return Mat();
	}

};
