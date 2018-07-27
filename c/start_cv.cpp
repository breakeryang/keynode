
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv) {

    Mat image;
    image = imread("/home/rabbit/project/keynode/c/images/2018-07-2715-29-18.png", 1);
    if (!image.data) {
        printf("没有找到图片\n");
        return 1;
    }

    namedWindow("Display Image:", WINDOW_AUTOSIZE);

    imshow("Display Image:", image);

    waitKey(0);

    return 0;
}