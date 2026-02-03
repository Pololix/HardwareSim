cmake_minimum_required(VERSION 3.26)

project(APP
    VERSION 0.1
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(APP src/main.cpp)

# engine modules
add_subdirectory(platform)
add_subdirectory(core)

# third party
add_subdirectory(third_party)

target_link_libraries(APP
    PRIVATE
        platform
        core
)