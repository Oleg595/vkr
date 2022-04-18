//
// Created by oleg on 13.04.2022.
//

#include "../headers/vectors.h"

Vector3D pixelToCor(const rs2_intrinsics &intr, const float& depth_val, const int* pos) {//, Vector2D pixel, const OdomInterval& depth) {
    Vector3D result;
    OdomInterval x_inter (pos[0] + .5, pos[0] + 1.5);
    OdomInterval y_inter (pos[1] + .5, pos[1] + 1.5);
    double val = MAX2(depth_val, .0);
    OdomInterval depth (val * .99, val * 1.01);

    auto x = (x_inter - intr.ppx) / double(intr.fx);
    auto y = (x_inter - intr.ppy) / double(intr.fy);

    if (intr.model == rs2_distortion::RS2_DISTORTION_INVERSE_BROWN_CONRADY) {
        auto r2 = x * x + y * y;
        auto focus = 1. + double(intr.coeffs[0]) * r2 + double(intr.coeffs[1]) * r2 * r2 +
                     double(intr.coeffs[4]) * r2 * r2 * r2;
        auto ux = x * focus + 2. * double(intr.coeffs[2]) * x * y + double(intr.coeffs[3]) * (r2 + 2. * x * x);
        auto uy = y * focus + 2. * double(intr.coeffs[3]) * x * y + double(intr.coeffs[2]) * (r2 + 2. * y * y);
        x = ux;
        y = uy;
    }

    result.x = x * depth;
    result.y = y * depth;
    result.z = depth;
    return result;
}

Vector3D Vector3D::operator-(const Vector3D &other) {
    return { this->x - other.x, this->y - other.y, this->z - other.z };
}
