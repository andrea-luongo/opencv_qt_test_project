#include "ImageProcesser.h"

ImageProcesser::ImageProcesser() 
{

}

ImageProcesser::~ImageProcesser()
{

}

void ImageProcesser::loadImage(std::string image_path) 
{
	image = cv::imread(image_path, 1);
}

void ImageProcesser::displayImage() 
{
	if (!image.data)
	{
		printf("No image data \n");
		return;
	}
	cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Display Image", image);

	cv::waitKey(0);
}

cv::Mat ImageProcesser::getImage() 
{
	return image;
}