//
// Created by oleg on 16.04.22.
//

#ifndef VKR_FRAME_DATA_H
#define VKR_FRAME_DATA_H

#include <librealsense2/rs.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <utility>
#include <opencv2/xfeatures2d.hpp>

#include "../../data_module/headers/vectors.h"

using namespace boost::numeric::ublas;

struct KeyData{
    KeyData(std::vector<Vector3D> points, cv::Mat descs): points(std::move(points)), descs(std::move(descs)){}
    std::vector<Vector3D> points;
    cv::Mat descs;
};

class FrameData {
public:
    FrameData(rs2::video_frame frame, matrix<Vector3D> cors): frame(std::move(frame)), cors(cors){}
    KeyData getKeyPoints();

    static std::vector<Vector3D> find_matches(FrameData frame1, FrameData frame2);
private:
    rs2::video_frame frame;
    matrix<Vector3D> cors;
};


#endif //VKR_FRAME_DATA_H
