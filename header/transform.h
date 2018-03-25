#ifndef TRAMSFORM_H
#define TRANSFORM_H

#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

// Define enums
enum class flipDir { horizontal, vertical, diagonal };
enum class rotationDir { left, right };

// Declare class
class Transform {

public:
// constructors
Transform(cv::Mat &img_src);

// methods
void flip(flipDir direction);
void rotate(rotationDir direction);
cv::Mat get_rotation();


private:
// attributes
cv::Mat src_img, dst_img;

};

#endif // TRANSFORM_H
