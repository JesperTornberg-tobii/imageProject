#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

enum class TransformType { flip, rotate };
enum class TransformDir { left, right, up, down };

void tranformation(cv::Mat &src, cv::Mat &dst, TransformType type, TransformDir dir) {
  /* TO DO: Create a transformation class with methods "flip" and "rotate" */

  /* Flip code here */
  cv::flip(src, dst, 0);


}

int main() {
  // Load image
  cv::Mat img_src;
  img_src = cv::imread("imgs/Photo-490.JPG", CV_LOAD_IMAGE_COLOR);

  // Resize image
  int cols = 1280, rows = 960;
  cv::Mat img;
  cv::resize(img_src, img, cv::Size(cols, rows));

  // Display original image
  std::string window1 = "Display Original Window";
  cv::namedWindow(window1, cv::WINDOW_AUTOSIZE);
  cv::imshow(window1, img);
  cv::waitKey(0);

  // Display other image
  cv::Mat img_mod;
  tranformation(img, img_mod, TransformType::flip, TransformDir::left);

  std::string window2 = "Display Other Window";
  cv::namedWindow(window2, cv::WINDOW_AUTOSIZE);
  cv::imshow(window2, img_mod);
  cv::waitKey(0);

  return 0;
}
