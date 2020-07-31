#include <QWidget>
#include "ImageProcesser.h"
#include <QLabel>
#include <QImage>
#include <QMainWindow>
#pragma once
class MainGUI : public QMainWindow
{
public:
	MainGUI(ImageProcesser* ip);
	~MainGUI();
	
private: 
	void initializeCentralWidgets();
	void selectImage();
	void mat2qimage(const cv::Mat& opencv_image, QImage& qimage);
	QLabel* right_widget;
	ImageProcesser* image_processer;
	QWidget* central_widget;
};