
cmake_minimum_required(VERSION 3.4.1)

add_library(
             native-lib
             SHARED

             src/main/cpp/native-lib.cpp )

find_library(
              log-lib
              log )

include_directories(src/main/cpp/include)

#预编译静态库
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCS_DIR}/src/main/cpp/libs/${ADNROID_ABI}")

target_link_libraries(
                       native-lib
                       accodec acfilter acformat avutil swresample swscale
                       log )