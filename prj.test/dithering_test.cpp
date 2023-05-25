#include <dithering/dithering.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp> 
#include <string>
#include <fstream>

//int argc, char* argv[]


int main() {
    //cv::Mat im = create_image(30, 255, "grad", 0);
    //cv::imwrite("C:/Users/romad/picturesr/in_9.png", im);
    FloydSteinberg ditto;
    Atkinson ditto_1;
    JarvisJudiceNinke ditto_2;
    Stucki ditto_3;


    //std::ifstream file(argv[1]);
    //cv::Mat img=cv::imread(argv[1], cv::IMREAD_UNCHANGED);
    //std::string path = "C:/Users/romad/picturesr/in_9.png";
    //cv::Mat img = cv::imread(path, cv::IMREAD_UNCHANGED);
    //cv::imwrite("out_try.png", img)
    std::string out_file = "out_9.png";


    ditto.Dither(img, out_file);
    ditto_1.Dither(img, out_file);
    //ditto_2.Dither(img, out_file);
    //ditto_3.Dither(img, out_file);
    //ditto.DitheringMap();
}

//cv::Mat create_image(int w, int h, std::string background, int difficulty) {
//    cv::Mat img(w, h, CV_8UC1);
//    if (background == "dark") {
//        img = uchar{ 125 };
//        if (difficulty == 0) {
//        }
//        else if (difficulty == 1) {
//            cv::Point point_1(0, 0), point_2(0, w), point_3(h, 0), point_4(h, w);
//            line(img, point_1, point_4, 0, 2);
//            line(img, point_2, point_3, 0, 2);
//        }
//        else if (difficulty == 2) {
//            ellipse(img, cv::Point(h / 2, w / 2), cv::Size(h / 4, w / 4), 0, 0, 360, cv::Scalar(0), -1,cv:: LINE_8);
//        }
//        else if (difficulty == 3) {
//            ellipse(img, cv::Point(h / 2, w / 2), cv::Size(h / 4, w / 4), 0, 0, 360, cv::Scalar(0), -1,cv:: LINE_8);
//            rectangle(img, cv::Point(h / 6, 0), cv::Point(h / 2, 2 * w / 3), 90, -1,cv:: LINE_8);
//        }
//    }
//    else if (background == "light") {
//        img = uchar{ 200 };
//        if (difficulty == 0) {
//        }
//        else if (difficulty == 1) {
//            cv::Point point_1(0, 0), point_2(0, w), point_3(h, 0), point_4(h, w);
//            line(img, point_1, point_4, 0, 2);
//            line(img, point_2, point_3, 0, 2);
//        }
//        else if (difficulty == 2) {
//            ellipse(img,cv:: Point(h / 2, w / 2), cv::Size(h / 4, w / 4), 0, 0, 360, cv::Scalar(0), -1, cv::LINE_8);
//        }
//        else if (difficulty == 3) {
//            ellipse(img, cv::Point(h / 2, w / 2), cv::Size(h / 4, w / 4), 0, 0, 360, cv::Scalar(0), -1, cv::LINE_8);
//            rectangle(img, cv::Point(h / 6, 0), cv::Point(h / 2, 2 * w / 3), 90, -1, cv::LINE_8);
//        }
//    }
//    else if ("grad") {
//        img = uchar{ 0 };
//        uchar new_col = 0;
//        for (int col = 0; col < img.cols; col += 1) {
//            for (int row = 0; row < img.rows; row += 1) {
//                img.at<uchar>(row, col) = new_col;
//            }
//            new_col += 1;
//        }
//    }
//
//    return img;
//}
