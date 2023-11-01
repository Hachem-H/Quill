#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

static int vectorizationLevel = 128;
static cv::Mat vectorizedImage;

void UpdateVectorizedImage(int, void* data)
{
    cv::Mat& grayscaleImage = *(cv::Mat*) data;
    cv::threshold(grayscaleImage, vectorizedImage, vectorizationLevel, 255, cv::THRESH_BINARY);
    cv::imshow("Vectorized Image", vectorizedImage);
}

int main(void) {
    cv::Mat image = cv::imread("Tests/Text Test #1.png");

    if (image.empty()) {
        std::cerr << "[ERR]: Could not open file.\n";
        return -1;
    }

    cv::Mat grayscaleImage;
    cv::cvtColor(image, grayscaleImage, cv::COLOR_BGR2GRAY);

    vectorizedImage = grayscaleImage.clone();

    cv::namedWindow("Vectorized Image", cv::WINDOW_NORMAL);
    cv::imshow("Vectorized Image", vectorizedImage);

    cv::createTrackbar("Vectorization Level", "Vectorized Image", &vectorizationLevel, 255, UpdateVectorizedImage, &grayscaleImage);

    for (bool isRunning = true; isRunning;) 
    {
        switch (cv::waitKey(0))
        {
        case 14:
        {
            cv::imwrite("output.png", vectorizedImage);
            std::cout << "Vectorized image saved as vectorized_image.png" << std::endl;
            isRunning = false;
        } break;

        case 13:
        {
            isRunning = false;
        } break;
        }
    }
}