#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <qstring.h>
#include "ImageProcesser.h"
#include <QApplication>
#include "MainGUI.h"

using namespace cv;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	ImageProcesser* bubu = new ImageProcesser();

	MainGUI simple_gui{bubu};
	simple_gui.setWindowTitle("Select and Display Image");
	simple_gui.show();
	return app.exec();
	//ImageProcesser bubi{};
	//bubi.loadImage("C:\\Users\\Marta\\Documents\\Tutorial_OpenCV_CMake\\testimage.png");
	//bubi.displayImage();
	//return 0;
}