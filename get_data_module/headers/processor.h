//
// Created by oleg on 13.04.2022.
//

#ifndef VKR_PROCESSOR_H
#define VKR_PROCESSOR_H

#include <librealsense2/rs.hpp>

class Processor {
public:
    virtual rs2::frameset getNextFrame();
    virtual rs2_intrinsics getDeviceParams();
protected:
    rs2::pipeline* pipe;
};

#endif //VKR_PROCESSOR_H
