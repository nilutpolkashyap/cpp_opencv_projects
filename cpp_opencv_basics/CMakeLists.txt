# SPECIFY THE MINIMUM VERSION OF CMAKE REQUIRED
cmake_minimum_required(VERSION 2.8.12)

# SPECIFY YOUR PROJECT NAME
PROJECT(OpenCV_CPP LANGUAGES CXX CUDA)

# ENABLE C++11
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# MAKE SURE OPENCV IS INSTALLED CORRECTLY
find_package( OpenCV REQUIRED )
find_package(CUDA REQUIRED)
message(STATUS "Found CUDA ${CUDA_VERSION_STRING} at ${CUDA_TOOLKIT_ROOT_DIR}")

set(CUDA_SEPARABLE_COMPILATION ON)
set(CUDA_PROPAGATE_HOST_FLAGS OFF)
set(CUDA_HOST_COMPILER clang++)

set (CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} --gpu-architecture sm_75 -std=c++11)

# INCLUDE OPENCV DIRECTORIES
include_directories( ${OpenCV_INCLUDE_DIRS})

# MACRO TO COMPILE CPP FILES
# Do Not Edit
MACRO(add_example name)
  ADD_EXECUTABLE(${name} ${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS} )
ENDMACRO()

# COMPILE CPP FILES USING THIS LINE
######## EDIT THE FILE NAMES ########
add_example(image_read_display)
add_example(image_read_write)
add_example(video_read_write)
add_example(video_write)
add_example(image_resizing)
add_example(image_resize_interpolation)
add_example(image_cropping)
add_example(image_rotation)
add_example(blob_detector)
add_example(graphics_example)
#add_example(sampleCode2) and so on

# cuda_add_executable(
#     pi-cuda
#     src/pi-cuda.cu)

add_executable(main main.cpp)
add_subdirectory(kernels)

add_library(kernels test.cu test.cuh)

target_compile_features(kernels PUBLIC cxx_std_11)
set_target_properties(kernels
                       PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
target_link_libraries(kernels)