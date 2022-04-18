#include "get_data_module/headers/frame_processor.h"



int main() {
    auto processor = FrameProcessor(PROCESSOR_CLASS::RECORD, "/home/oleg/Documents/vkr/bag_files/20220324_200517.bag");
    auto setPoints = processor.getPoints();
    for(auto iter = setPoints.begin(); iter < setPoints.end(); iter++){
        FrameData::find_matches(std::move(*iter.base()), std::move(*(iter + 1).base()));
    }
    return 0;
}
