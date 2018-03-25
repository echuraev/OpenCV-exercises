#include <opencv2/highgui.hpp>
#include <iostream>

int main()
{
    cv::Mat image;
    image = cv::imread("image.jpg" , CV_LOAD_IMAGE_COLOR);

    if(!image.data)
    {
        std::cerr << "Error! Could not open or find the image!" << std::endl;
        return -1;
    }

    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Display window", image );

    cv::waitKey(0);
    return 0;
}
