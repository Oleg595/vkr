//
// Created by oleg on 13.04.2022.
//

#ifndef VKR_DEVICE_H
#define VKR_DEVICE_H

#include <librealsense2/rs.hpp>
#include "./processor.h"

class Device: public Processor {
public:
    explicit Device(const std::string& serial);
    ~Device();
};


#endif //VKR_DEVICE_H
