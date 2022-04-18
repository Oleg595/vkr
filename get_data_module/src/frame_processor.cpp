//
// Created by oleg on 13.04.2022.
//

#include "../headers/frame_processor.h"

FrameProcessor::FrameProcessor(PROCESSOR_CLASS processor_type, const std::string &data) {
    if (processor_type == PROCESSOR_CLASS::NONE) {
        exit(EXIT_FAILURE);
    }
    switch (processor_type) {
        case PROCESSOR_CLASS::DEVICE:
            processor = new Device(data);
            break;
        case PROCESSOR_CLASS::RECORD:
            processor = new Record(data);
            break;
        default:
            processor = nullptr;
    }
}

std::vector<FrameData> FrameProcessor::getPoints() {
    auto set = processor->getNextFrame();
    std::vector<FrameData> result{};

    for (auto i = 0; i < set.size(); i++) {
        auto frame = set.get_depth_frame();
        matrix<Vector3D> depth_image(frame.get_width(), frame.get_height());
        cv::Mat matrix(frame.get_width(), frame.get_height(), CV_16SC1, const_cast<void *>(frame.get_data()));
        matrix.forEach<float>(
                [this, &depth_image](float &val, const int *pos) {
                    depth_image(pos[0], pos[1]) = pixelToCor(processor->getDeviceParams(), val, pos);
                }
        );
        result.push_back({ set.get_color_frame(), depth_image});
    }

    return result;
}
