#include "MainGUI.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QFileDialog>
#include <QScrollArea>

MainGUI::MainGUI(ImageProcesser* ip, QWidget* parent ) : QMainWindow(parent)
{
	image_processer = ip;
	initializeWidgets();
}

MainGUI::~MainGUI()
{

}

void MainGUI::initializeWidgets() 
{
	QWidget* central_widget = new QWidget(this);
	central_widget->setMinimumSize(500, 500);

	QWidget* left_widget = new QWidget(central_widget);
	QWidget* right_widget = new QWidget(central_widget);

	QPushButton* select_image_button = new QPushButton("Select image", left_widget);
	QObject::connect(select_image_button, &QPushButton::clicked, this, &MainGUI::selectImage);
	
	QVBoxLayout* left_layout = new QVBoxLayout();
	left_layout->addWidget(select_image_button);
	left_widget->setLayout(left_layout);

	
	//image_viewer = new QLabel(right_widget);
	QVBoxLayout* right_layout = new QVBoxLayout();

	QScrollArea* scrollArea = new QScrollArea(right_widget);

	image_viewer = new QLabel(scrollArea);
	

	image_viewer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	image_viewer->setBackgroundRole(QPalette::Light);
	//image_viewer->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	//image_viewer->setScaledContents(true);*/

	scrollArea->setBackgroundRole(QPalette::Dark);
	//scrollArea->setVisible(true);
	scrollArea->setWidget(image_viewer);
	scrollArea->setWidgetResizable(true);
	//scrollArea->setWidgetResizable(fitToWindow);
	

	//right_layout->addWidget(image_viewer);
	right_layout->addWidget(scrollArea);
	right_widget->setLayout(right_layout);
	


	//image_viewer->setFixedSize(500, 500);
	//image_viewer->setFixedSize(this->width(), this->height());

	QHBoxLayout* central_layout = new QHBoxLayout();
	central_layout->addWidget(left_widget);
	central_layout->addWidget(right_widget);
	central_widget->setLayout(central_layout);

	this->setCentralWidget(central_widget);

	//QScrollArea* scrollArea = new QScrollArea;
	//scrollArea->setBackgroundRole(QPalette::Dark);
	//scrollArea->setWidgetResizable(true);
	//scrollArea->setWidget(image_viewer);
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
}

void MainGUI::mat2qimage(const cv::Mat& opencv_image, QImage& qimage) 
{
	qimage = QImage((const unsigned char*)(opencv_image.data), opencv_image.cols, opencv_image.rows, opencv_image.step, QImage::Format_BGR888);
	qimage.convertToFormat(QImage::Format_RGB888);
}