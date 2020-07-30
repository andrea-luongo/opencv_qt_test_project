#include "MainGUI.h"
#include <QVBoxLayout>
#include <QPushButton>

#include <QFileDialog>

MainGUI::MainGUI(ImageProcesser* ip)
{
	image_processer = ip;
	initializeWidgets();
}

MainGUI::~MainGUI()
{

}

void MainGUI::initializeWidgets() 
{
	QPushButton* select_image_button = new QPushButton("Select image", this);
	QObject::connect(select_image_button, &QPushButton::clicked, this, &MainGUI::selectImage);
	image_viewer = new QLabel(this);

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(select_image_button);
	layout->addWidget(image_viewer);

	this->setLayout(layout);
}

void MainGUI::selectImage() 
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"), "./", tr("Image Files (*.png *.jpg *.bmp)"));
	image_processer->loadImage(fileName.toStdString());
	image_viewer->setPixmap(QPixmap::fromImage(mat2qimage(image_processer->getImage())));
	image_viewer->show();
}

QImage MainGUI::mat2qimage(const cv::Mat mat) {
	//cv::Mat rgb{ mat.rows, mat.cols, mat.type()};
	cv::Mat rgb;
	//rgb = mat.clone();
	cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);
	std::cout << mat.rows<< std::endl;
	std::cout <<  mat.cols  << std::endl;
	std::cout <<  mat.step << std::endl;
	std::cout << mat.type() << std::endl;
	return QImage((const unsigned char*)(rgb.data), rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);

	//return QImage((const unsigned char*)(mat.data), mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
}