// Problem 3
// find same files in the list of files

#include <iostream>
#include <vector>
#include <fstream>

struct Image
{
	int width;
	int height;
	std::string data;
};

Image readImage(const std::string& fileName)
{
	std::ifstream fin(fileName);
	Image image;
	
	fin >> image.width >> image.height;
	for (int i = 0; i < image.width * image.height; ++i)
	{
		char t = fin.get();
		image.data.push_back(t);
	}
	
	return image;
}

class ImageComparator
{
public:
	ImageComparator(const Image& image)
	{
		_imageWidth = image.width;
		_imageHeight = image.height;
		_imageHashFAQ6 = hashFAQ6(image.data);
		_imageHashRot13 = hashRot13(image.data);
	}
	
	bool compare(const Image& image)
	{
		if (_imageWidth != image.width || _imageHeight != image.height)
			return false;

		if (_imageHashRot13 != hashRot13(image.data))
			return false;
			
		if (_imageHashFAQ6 != hashFAQ6(image.data))
			return false;
			
		return true;
	}

private:
	unsigned int hashFAQ6(const std::string& data)
	{
		unsigned int hash = 0;
	
		for (const auto& c : data)
		{
			hash += (unsigned char)c;
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);
	
		return hash;
	}

	unsigned int hashRot13(const std::string& data)
	{
		unsigned int hash = 0;
	
		for (const auto& c : data)
		{
			hash += (unsigned char)c;
			hash -= (hash << 13) | (hash >> 19);
		}
	
		return hash;
	}
	
private:
	int _imageWidth;
	int _imageHeight;
	unsigned int _imageHashFAQ6;
	unsigned int _imageHashRot13;
};

int main()
{
	std::string imageFileNameToFind;
	std::vector<std::string> imageFileNames;
	
	ImageComparator imageComparator(readImage(imageFileNameToFind));
	
	for (const auto& imageFileName : imageFileNames)
	{
		if (imageComparator.compare(readImage(imageFileName)))
			std::cout << imageFileNameToFind << " is the same as " << imageFileName;
	}
	
	return 0;
}
