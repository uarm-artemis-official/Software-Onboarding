#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::cout << "=== C++ Installation Test ===" << std::endl;
    std::cout << "Hello World! 🎉" << std::endl;
    std::cout << "C++ compiler is working correctly!" << std::endl;
    std::cout << std::endl;
    
    std::cout << "=== OpenCV Installation Test ===" << std::endl;
    try {
        std::cout << "OpenCV version: " << CV_VERSION << std::endl;
        std::cout << "OpenCV is working correctly!" << std::endl;
        
    } catch (const cv::Exception& e) {
        std::cout << "OpenCV Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
