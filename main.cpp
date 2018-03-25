#include "header/transform.h"
#include <iostream>
#include <string>

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
  cv::Mat img_mod = img;
  cv::Mat img_rot;
  Transform transform(img_mod);
  transform.rotate(rotationDir::left);
  img_rot = transform.get_rotation();

  std::string window2 = "Display Other Window";
  cv::namedWindow(window2, cv::WINDOW_AUTOSIZE);
  cv::imshow(window2, img_rot);
  cv::waitKey(0);

  return 0;
}
