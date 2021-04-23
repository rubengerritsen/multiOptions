cmake_minimum_required(VERSION 3.15)

project(options VERSION 1.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Windows is not so nice with the structure of include files and libraries
# Hence we need to help it a bit to find boost, on UNIX/LINUX this is not needed
# NB Check if the path here actually points to a boost installation folder
if (WIN32) # WIN32 is true on a windows system
    set(Boost_INCLUDE_DIR "C:/Program files/boost/boost_1_75_0")
endif (WIN32)

# Find dependencies
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package (Boost COMPONENTS program_options filesystem REQUIRED)
find_package(OpenMP REQUIRED)

# Include directory that contains header/include files
include_directories(include ${Boost_INCLUDE_DIRS})

# Add all source files from src directory
file(GLOB SOURCES "src/*.cpp")

add_compile_options(-O3)

add_executable(options ${SOURCES})

# Link against libraries
target_link_libraries (options PUBLIC Eigen3::Eigen ${Boost_LIBRARIES} OpenMP::OpenMP_CXX)

install(TARGETS options DESTINATION bin)

