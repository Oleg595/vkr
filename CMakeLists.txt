cmake_minimum_required(VERSION 3.21)
project(vkr)

set(CMAKE_CXX_STANDARD 11)

find_package(realsense2 CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)
find_package( Boost COMPONENTS REQUIRED )

add_executable(vkr main.cpp get_data_module/src/frame_processor.cpp get_data_module/headers/frame_processor.h get_data_module/headers/processor.h get_data_module/src/device.cpp get_data_module/headers/device.h get_data_module/src/record.cpp get_data_module/headers/record.h get_data_module/src/processor.cpp data_module/src/odom_interval.cpp data_module/headers/odom_interval.h data_module/src/vectors.cpp data_module/headers/vectors.h process_module/src/frame_data.cpp process_module/headers/frame_data.h)

target_link_libraries(vkr PRIVATE realsense2::fw realsense2::usb realsense2::realsense2 realsense2::realsense-file)
target_link_libraries(vkr PRIVATE opencv_highgui ${OpenCV_LIBS})
target_link_libraries(vkr PRIVATE Boost::boost)