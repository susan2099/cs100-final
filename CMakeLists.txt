CMAKE_MINIMUM_REQUIRED(VERSION 3.11)
project (QuizProject)

SET(CMAKE_CXX_STANDARD 11)

include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(quiz main.cpp)
target_link_libraries(quiz gtest gtest_main nlohmann_json::nlohmann_json)
ADD_EXECUTABLE(test test.cpp)
target_link_libraries(test gtest gtest_main nlohmann_json::nlohmann_json)


TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
