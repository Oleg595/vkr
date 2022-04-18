//
// Created by oleg on 13.04.2022.
//

#ifndef VKR_RECORD_H
#define VKR_RECORD_H

#include "./processor.h"

class Record: public Processor {
public:
    explicit Record(const std::string& path);
    ~Record();
};


#endif //VKR_RECORD_H
