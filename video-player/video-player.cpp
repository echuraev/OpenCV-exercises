#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::VideoCapture video("test.mp4");

    if (!video.isOpened()) {
        std::cerr << "Error! Cannot open video file!" << std::endl;
        return -1;
    }

    cv::namedWindow("Video", cv::WINDOW_NORMAL);
    while (1) {
        cv::Mat frame;
        video >> frame;
        if (frame.empty())
            break;

        cv::imshow("Video", frame);
        int ch = cv::waitKey(33);
        if (ch == 27)
            break;
    }

    video.release();
    cv::destroyAllWindows();

    return 0;
}
