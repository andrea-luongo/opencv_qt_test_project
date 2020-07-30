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
	QImage mat2qimage(const cv::Mat mat);
	QLabel* image_viewer;
	ImageProcesser* image_processer;
};