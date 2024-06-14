cmake_minimum_required(VERSION 3.28)
project(cpp_engine)

set(CMAKE_CXX_STANDARD 20)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} main.cpp)

# Dependencies

# cpp_engine
set(PROJECT_NAME_LIB "_${PROJECT_NAME}")
add_library(${PROJECT_NAME_LIB} STATIC cppengine.cpp
        src/Application.cpp
        src/Application.h
)
include_directories(${PROJECT_NAME_LIB} "src/")
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME_LIB})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME_LIB})

# raylib
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME_LIB} raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    if (NOT DEFINED RAYLIB_CPP_VERSION)
        set(RAYLIB_CPP_VERSION v5.0.1)
    endif()
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
            GIT_TAG ${RAYLIB_CPP_VERSION}
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

target_link_libraries(${PROJECT_NAME_LIB} raylib_cpp)

# entt
find_package(EnTT QUIET)
if (NOT EnTT_FOUND)
    if (NOT DEFINED ENTT_VERSION)
        set(ENTT_VERSION v3.13.2)
    endif()
    include(FetchContent)
    FetchContent_Declare(
            EnTT
            GIT_REPOSITORY https://github.com/skypjack/entt
            GIT_TAG ${ENTT_VERSION}
    )
    FetchContent_MakeAvailable(EnTT)
endif()

target_link_libraries(${PROJECT_NAME_LIB} EnTT::EnTT)

# Test Framework

# catch2
find_package(Catch2 3)
if (NOT Catch2_FOUND)
    if (NOT DEFINED Catch2_VERSION)
        set(Catch2_VERSION v3.6.0)
    endif()
    include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG ${Catch2_VERSION}
    )
    FetchContent_MakeAvailable(Catch2)
endif()

# These tests can use the Catch2-provided main
add_executable(tests
        tests/Test_Application.cpp
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain ${PROJECT_NAME_LIB})

include(CTest)
include(Catch)
catch_discover_tests(tests)

# These tests need their own main
#add_executable(custom-main-tests test.cpp test-main.cpp)
#target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)