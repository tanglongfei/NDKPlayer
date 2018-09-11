
cmake_minimum_required(VERSION 3.4.1)

file(GLOB source_file src/main/cpp/*.cpp)

add_library(
             native-lib
             SHARED

           ${source_file}  )

find_library(
              log-lib
              log )

include_directories(src/main/cpp/include)

#预编译静态库
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/src/main/cpp/libs/${ANDROID_ABI}")

 #avfilter avformat    avcodec  avutil  swresample swscale
target_link_libraries(  native-lib
                avformat avcodec avfilter    avutil swresample swscale
                      log  z)