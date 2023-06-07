project(bugreport)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(bugreport main.cpp)

target_link_libraries(bugreport
    opencv_core
    OpenImageIO
    )
