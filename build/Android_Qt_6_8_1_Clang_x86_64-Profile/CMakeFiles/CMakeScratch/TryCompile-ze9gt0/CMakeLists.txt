cmake_minimum_required(VERSION 3.29.3.0)
set(CMAKE_MODULE_PATH "C:/Qt/6.8.1/android_x86_64/lib/cmake/Qt6;C:/Qt/6.8.1/android_x86_64/lib/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;C:/Qt/6.8.1/android_x86_64/lib/cmake/Qt6/3rdparty/kwin")
cmake_policy(SET CMP0128 OLD)
project(CMAKE_TRY_COMPILE CXX)
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_CXX_FLAGS "-DQT_QML_DEBUG   -DANDROID -fdata-sections -ffunction-sections -funwind-tables -fstack-protector-strong -no-canonical-prefixes -D_FORTIFY_SOURCE=2 -Wformat -Werror=format-security -fexceptions -frtti -stdlib=libc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_DEFINITIONS}")
set(CMAKE_CXX_FLAGS_DEBUG "-g  -fno-limit-debug-info")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--build-id=sha1 -Wl,--no-rosegment -Wl,--no-undefined-version -Wl,--fatal-warnings -Wl,--gc-sections -Qunused-arguments -Wl,--no-undefined  -Wl,--gc-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${EXE_LINKER_FLAGS}")
include_directories(${INCLUDE_DIRECTORIES})
set(CMAKE_SUPPRESS_REGENERATION 1)
link_directories(${LINK_DIRECTORIES})
cmake_policy(SET CMP0065 NEW)
cmake_policy(SET CMP0083 NEW)
cmake_policy(SET CMP0155 OLD)
cmake_policy(SET CMP0157 OLD)
include("${CMAKE_ROOT}/Modules/Internal/HeaderpadWorkaround.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/cpp/projectsQt/SimpleChat/build/Android_Qt_6_8_1_Clang_x86_64-Profile/CMakeFiles/CMakeScratch/TryCompile-ze9gt0")
add_executable(cmTC_c5582)
target_sources(cmTC_c5582 PRIVATE
  "C:/cpp/projectsQt/SimpleChat/build/Android_Qt_6_8_1_Clang_x86_64-Profile/CMakeFiles/CMakeScratch/TryCompile-ze9gt0/CheckForPthreads.cxx"
)
file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/cmTC_c5582_loc"
     CONTENT $<TARGET_FILE:cmTC_c5582>)
set_property(TARGET cmTC_c5582 PROPERTY "CXX_STANDARD" "17")
set_property(TARGET cmTC_c5582 PROPERTY "CXX_STANDARD_REQUIRED" "ON")
target_link_libraries(cmTC_c5582 ${LINK_LIBRARIES})
