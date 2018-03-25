#include "../header/transform.h"
#include <iostream>
Transform::Transform(cv::Mat &src){
  // Initialize
  src_img = src;
}

void Transform::flip(flipDir direction) {
  switch (direction) {
    case flipDir::horizontal:
      cv::flip(src_img, src_img, 1);
      break;

    case flipDir::vertical:
      cv::flip(src_img, src_img, 0);
      break;

    case flipDir::diagonal:
      cv::flip(src_img, src_img, -1);
      break;

    default:
      std::cout << "Unknown direction! Options are: horizontal, vertical and diagonal" << std::endl;
      break;
  }
}

void Transform::rotate(rotationDir direction){
  switch (direction) {
    case rotationDir::left:
      cv::rotate(src_img, dst_img, cv::ROTATE_90_COUNTERCLOCKWISE);
      break;
    case rotationDir::right:
      cv::rotate(src_img, dst_img, cv::ROTATE_90_CLOCKWISE);
      break;
    default:
      std::cout << "Unknown direction! Options are: left or right" << std::endl;
      break;
    }
}

cv::Mat Transform::get_rotation(){
  return dst_img;
}
