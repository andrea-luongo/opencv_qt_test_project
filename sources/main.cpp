#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <qstring.h>

using namespace cv;

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		QString a("cacca puzza");
		printf(a.toStdString().c_str());
		return -1;
	}

	Mat image;
	image = imread(argv[1], 1);

	if (!image.data)
	{
		printf("No image data \n");
		return -1;
	}
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);

	waitKey(0);

	return 0;
}