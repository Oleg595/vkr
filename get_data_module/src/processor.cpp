//
// Created by oleg on 13.04.2022.
//


#include "../headers/processor.h"

rs2::frameset Processor::getNextFrame() {
    return pipe->wait_for_frames();
}

rs2_intrinsics Processor::getDeviceParams() {
    return pipe->get_active_profile().get_stream(RS2_STREAM_DEPTH).as<rs2::video_stream_profile>().get_intrinsics();
}
