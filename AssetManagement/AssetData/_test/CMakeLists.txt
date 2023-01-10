cmake_minimum_required(VERSION 3.5)

project(AssetDBServiceTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AssetDBServiceTest main.cpp AssetManagementDBTest.cpp)
target_link_libraries(AssetDBServiceTest PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(AssetDBServiceTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(AssetDBServiceTest PRIVATE Qt6::Sql)
include_directories("${CMAKE_SOURCE_DIR}/googletest/googletest/include")
include_directories("${CMAKE_SOURCE_DIR}/googletest/googlemock/include")
include_directories("${CMAKE_SOURCE_DIR}/SqlDataBase/")
include_directories("${CMAKE_SOURCE_DIR}/AssetData/")
target_link_directories(AssetDBServiceTest PUBLIC AssetData/)
target_link_libraries(AssetDBServiceTest PUBLIC  AssetData SqlDataBase gtest gmock)

