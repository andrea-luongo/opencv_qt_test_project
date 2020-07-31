#include "MainGUI.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QFileDialog>

MainGUI::MainGUI(ImageProcesser* ip)
{
	image_processer = ip;
	initializeCentralWidgets();
	this->setCentralWidget(central_widget);
}

MainGUI::~MainGUI()
{

}

void MainGUI::initializeCentralWidgets() 
{
	central_widget = new QWidget(this);
	//central_widget contains two widget and a horizontal layout: the left widget holds the buttons
	// the right widget shows the image
	QWidget* left_widget = new QWidget(central_widget);
	QPushButton* select_image_button = new QPushButton("Select image", left_widget);
	select_image_button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	QObject::connect(select_image_button, &QPushButton::clicked, this, &MainGUI::selectImage);
	QVBoxLayout* left_layout = new QVBoxLayout();
	left_layout->addWidget(select_image_button);
	left_widget->setLayout(left_layout);
	left_widget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);


	right_widget = new QLabel(central_widget);
	right_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	right_widget->setMinimumSize(1000, 1000);

	QHBoxLayout* central_layout = new QHBoxLayout();
	central_layout->addWidget(left_widget);
	central_layout->addWidget(right_widget);
	central_widget->setLayout(central_layout);
}

void MainGUI::selectImage() 
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"), "./", tr("Image Files (*.png *.jpg *.bmp)"));
	image_processer->loadImage(fileName.toStdString());
	QImage image;
	mat2qimage(image_processer->getImage(), image);
	QPixmap pixmap = QPixmap::fromImage(image);
	right_widget->setPixmap(pixmap);
	right_widget->show();
}

void MainGUI::mat2qimage(const cv::Mat& opencv_image, QImage& qimage) 
{
	qimage = QImage((const unsigned char*)(opencv_image.data), opencv_image.cols, opencv_image.rows, opencv_image.step, QImage::Format_BGR888);
	qimage.convertToFormat(QImage::Format_RGB888);
}