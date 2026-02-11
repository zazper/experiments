# CMakeList.txt : CMake project for memoryleaks, include source and define
# project specific logic here.
#

# Add source to this project's executable.
#add_executable (memoryleaks "memoryleaks.cpp" "memoryleaks.h "src/memoryleaks.cpp"")
add_executable (chrono "src/chrono.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET memoryleaks PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
