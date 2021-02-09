#define _USE_MATH_DEFINES

#include <chrono> 
#include "FileRepositoryDirectoryBased.h"
#include "DataAugmentationPipeline.h"
#include "DataAugmenterDistributionPreserving.h"
#include "DataAugmenterRandomErase.h"
#include "DataAugmenterSmoothRandomErase.h"
#include "NoiseGeneratorPerlin.h"
#include "ImageLoaderOpenCV.h"
#include "ImageLoaderMagick.h"
#include "ImageSaverOpenCV.h"

using namespace std;


int main(int argc, char** argv[])
{
	cout << "Distribution-preserving Data Augmentation (DPDA) v1.0" << endl << endl;

	vector<string> directoryNames;
	directoryNames.push_back("train");
	//directoryNames.push_back("val");
	//directoryNames.push_back("test");


	const string inputDirectory = "images";
	const string outputDirectory = "results";
	FileRepositoryDirectoryBased fileRepository(inputDirectory, outputDirectory, directoryNames);
	vector<path> imagePaths = fileRepository.getImagePaths();


	/// augment images - begin
	auto t1 = std::chrono::high_resolution_clock::now();

	//ImageLoaderOpenCV imageLoader;
	ImageLoaderMagick imageLoader;
	ImageSaverOpenCV imageSaver;
	NoiseGeneratorPerlin noiseGenerator;
	const float DPDA_Power = 1.0f;
	DataAugmenterDistributionPreserving dataAugmenter(&imageLoader, &imageSaver , &noiseGenerator, DPDA_Power);
	//DataAugmenterRandomErase dataAugmenter(&imageLoader, &imageSaver);
	//DataAugmenterSmoothRandomErase dataAugmenter(&imageLoader, &imageSaver, &noiseGenerator);

	//#pragma omp parallel for schedule(dynamic)
	for (int i = 0; i < imagePaths.size(); i++) {
		path filePath = imagePaths.at(i);

		const int augmentationCount = 5;
		const double scaleFactor = 1.0;
		const int augmentationPercentage = 100;

		dataAugmenter.execute(inputDirectory, outputDirectory, imagePaths.at(i), augmentationCount, scaleFactor, augmentationPercentage);
	}

	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
	cout << endl << endl << "Elapsed time: " << duration << " seconds \n\n";
	/// augment images - end

	string logFileName = "_imageWithProblems.txt";
	imageLoader.saveUnreadedImages(logFileName);

	return 0;
}
