#include <iostream>
#include <OpenImageIO/imagebuf.h>
#include <OpenImageIO/imagebufalgo.h>
#include <fmt/core.h>

#include <opencv2/core.hpp>

template <typename S, typename... Args, typename Char = fmt::char_t<S>>
inline void println(const S& format_str, Args&&... args) {
    fmt::print(format_str, args...);
    std::cout << std::endl;
}

int main(int argc, char ** argv) {
    using namespace OIIO;

    std::string fn = argv[1];

    println("Opening image {}", fn);
    ImageBuf in(fn);
    println("Reading image {}", fn);
    bool const read_success = in.read();
    println("Read success: {}", read_success);
    cv::Mat result;
    println("Converting image {} to cv::Mat", fn);
    ImageBufAlgo::to_OpenCV(result, in);
    println("Size: [{}, {}]", result.cols, result.rows);
}
