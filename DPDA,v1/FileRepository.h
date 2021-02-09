#pragma once

#include <vector> 
#include <boost\filesystem.hpp>
#include <boost\algorithm\string.hpp>

using namespace std;
using namespace boost;
using namespace boost::filesystem;


class FileRepository {
public:

	virtual vector<path> getImagePaths() = NULL;

	bool isImage(string extension)
	{
		return (extension == ".jpg" ||
			extension == ".jpeg" ||
			extension == ".png" ||
			extension == ".tif" ||
			extension == ".tiff");
	}

private:

};
