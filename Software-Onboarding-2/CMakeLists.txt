cmake_minimum_required(VERSION 3.16)
project(LightbarDetection)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add executable - simple lightbar detector (single file)
add_executable(lightbar_detector src/main.cpp)

# Link OpenCV libraries
target_link_libraries(lightbar_detector ${OpenCV_LIBS})

# Set output directory
set_target_properties(lightbar_detector
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Print OpenCV information
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
