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

    cv::Mat channels[3];
    split(image, channels);

    cv::namedWindow( "Blue", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Blue", channels[0] );
    cv::namedWindow( "Green", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Green", channels[1] );
    cv::namedWindow( "Red", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Red", channels[2] );

    cv::waitKey(0);
    return 0;
}
