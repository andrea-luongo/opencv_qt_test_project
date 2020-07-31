#include "MainGUI.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QPixmap>
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
	QImage image;
	mat2qimage(image_processer->getImage(), image);
	QPixmap pixmap = QPixmap::fromImage(image);
	image_viewer->setPixmap(pixmap);
	image_viewer->show();
}

void MainGUI::mat2qimage(const cv::Mat& opencv_image, QImage& qimage) 
{
	qimage = QImage((const unsigned char*)(opencv_image.data), opencv_image.cols, opencv_image.rows, opencv_image.step, QImage::Format_BGR888);
	qimage.convertToFormat(QImage::Format_RGB888);
}