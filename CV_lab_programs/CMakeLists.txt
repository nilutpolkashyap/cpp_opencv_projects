# SPECIFY THE MINIMUM VERSION OF CMAKE REQUIRED
cmake_minimum_required(VERSION 2.8.12)

# SPECIFY YOUR PROJECT NAME
PROJECT(OpenCV_CPP)

# ENABLE C++11
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# MAKE SURE OPENCV IS INSTALLED CORRECTLY
find_package( OpenCV REQUIRED )

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
add_example(image_grayscale_read_write)
add_example(image_rgb_split)
add_example(image_histogram)
add_example(image_smoothing)
add_example(image_roi)
add_example(discrete_fourier_transform)
add_example(image_erosion_dilation)
add_example(edge_detection)
add_example(image_sharpening)
add_example(image_segmentation)
#add_example(sampleCode2) and so on