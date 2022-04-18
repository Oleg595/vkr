//
// Created by oleg on 13.04.2022.
//

#include "../headers/record.h"

Record::Record(const std::string& path) {
    rs2::config cfg;
    cfg.enable_record_to_file(path);
    pipe = new rs2::pipeline();
    pipe->start(cfg);
}

Record::~Record() {
    pipe->stop();
    delete pipe;
}
