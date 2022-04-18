//
// Created by oleg on 13.04.2022.
//

#include "../headers/device.h"

Device::Device(const std::string &serial) {
    rs2::config cfg;
    cfg.enable_device(serial);

    pipe = new rs2::pipeline();
    pipe->start(cfg);
}

Device::~Device() {
    pipe->stop();
    delete pipe;
}
