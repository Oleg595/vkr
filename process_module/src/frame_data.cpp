//
// Created by oleg on 16.04.22.
//

#include "../headers/frame_data.h"

KeyData FrameData::getKeyPoints() {
    cv::BRISK* descriptor = new cv::BRISK();
    std::vector<cv::KeyPoint> points = {};
    cv::Mat desc;

    cv::Mat img(cv::Size(frame.get_width(), frame.get_height()), CV_8UC3, const_cast<void *>(frame.get_data()),
                cv::Mat::AUTO_STEP);

    cv::FAST(img, points, 0, false);
    descriptor->compute(img, points, desc);

    std::vector<Vector3D> points_cors;
    for(auto point : points){
        points_cors.push_back(cors(int(point.pt.x), int(point.pt.y)));
    }
    return { points_cors, desc };
}

std::vector<Vector3D> FrameData::find_matches(FrameData frame1, FrameData frame2) {
    auto data1 = frame1.getKeyPoints();
    auto data2 = frame2.getKeyPoints();
    auto descriptor = cv::BFMatcher();

    std::vector<cv::DMatch> matches;
    std::vector<cv::DMatch> correctMatches;
    descriptor.match(data1.descs, data2.descs, matches);
    std::copy_if(matches.begin(), matches.end(), std::back_inserter(correctMatches),
                 [](const cv::DMatch &match) { return match.distance <= 50; });

    std::vector<Vector3D> result;
    for(auto match: matches){
        auto dist = data1.points[match.queryIdx] - data2.points[match.trainIdx];
        result.push_back(dist);
    }
    return result;
}
