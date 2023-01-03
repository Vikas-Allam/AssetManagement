cmake_minimum_required(VERSION 3.5)

project(AssetDBServiceTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AssetDBServiceTest main.cpp AssetManagementDBTest.cpp)

include_directories("${CMAKE_SOURCE_DIR}/googletest/googletest/include")
include_directories("${CMAKE_SOURCE_DIR}/googletest/googlemock/include")
include_directories("${CMAKE_SOURCE_DIR}/SqlDataBase")
target_link_libraries(AssetDBServiceTest PUBLIC SqlDataBase gtest gmock)
