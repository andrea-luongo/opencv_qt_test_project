#include <string>
#include <opencv2/opencv.hpp>
#pragma once
class ImageProcesser 
{
public:
	ImageProcesser();
	~ImageProcesser();
	void loadImage(std::string image_path);
	void displayImage();
	cv::Mat getImage();

private:
	cv::Mat image;
};