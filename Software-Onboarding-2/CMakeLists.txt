cmake_minimum_required(VERSION 3.16)
project(Software-Onboarding2)

include(CTest)
enable_testing()

set(OpenCV_DIR "C:/opencv/build/x64/vc16/lib")

find_package(OpenCV REQUIRED)

add_executable(main src/main.cpp)
add_executable(test_setup src/test_setup.cpp)

include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries( main ${OpenCV_LIBS} )
target_link_libraries( test_setup ${OpenCV_LIBS} )


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)