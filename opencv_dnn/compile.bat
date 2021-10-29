ECHO "Starting Build using OpenCV C++"
cd build
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
cd ..
set file_name=%1
.\build\Release\%file_name%.exe