#include <QWidget>
#include "ImageProcesser.h"
#include <QLabel>
#include <QImage>
#pragma once
class MainGUI : public QWidget
{
public:
	MainGUI(ImageProcesser* ip);
	~MainGUI();
	
private: 
	void initializeWidgets();
	void selectImage();
	void mat2qimage(const cv::Mat& opencv_image, QImage& qimage);
	QLabel* image_viewer;
	ImageProcesser* image_processer;
};