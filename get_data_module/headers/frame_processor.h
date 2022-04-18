//
// Created by oleg on 13.04.2022.
//

#ifndef VKR_FRAME_PROCESSOR_H
#define VKR_FRAME_PROCESSOR_H

#include <librealsense2/rs.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "./processor.h"
#include "./device.h"
#include "./record.h"
#include "../../data_module/headers/vectors.h"
#include "../../process_module/headers/frame_data.h"

using namespace boost::numeric::ublas;

enum PROCESSOR_CLASS{
    DEVICE,
    RECORD,
    NONE
};

class FrameProcessor {
public:
    explicit FrameProcessor(PROCESSOR_CLASS proc, const std::string& data);
    std::vector<FrameData> getPoints();
private:
    Processor* processor;
};


#endif //VKR_FRAME_PROCESSOR_H
