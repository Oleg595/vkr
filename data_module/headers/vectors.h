//
// Created by oleg on 13.04.2022.
//

#ifndef VKR_VECTORS_H
#define VKR_VECTORS_H

#include <boost/numeric/ublas/matrix.hpp>
#include <librealsense2/rs.hpp>
#include <utility>

#include "./odom_interval.h"

using namespace boost::numeric::ublas;

class Vector2D {
public:
    Vector2D(): x(0), y(0){}
    Vector2D(OdomInterval  x, OdomInterval  y): x(std::move(x)), y(std::move(y)){}

    OdomInterval x;
    OdomInterval y;
};

class Vector3D{
public:
    Vector3D(): x(0), y(0), z(0){}
    Vector3D(interval<double>  x, interval<double>  y, interval<double>  z): x(std::move(x)), y(std::move(y)), z(std::move(z)){}

    Vector3D operator-(const Vector3D& other);

    OdomInterval x;
    OdomInterval y;
    OdomInterval z;
};

Vector3D pixelToCor(const rs2_intrinsics &intr, const float& depth_val, const int* pos);

#endif //VKR_VECTORS_H
