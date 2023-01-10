cmake_minimum_required(VERSION 3.5)

project(SqlDataBase)

add_library(SqlDataBase SHARED assetmanagerdbservice.cpp assetmanagerdbservice.h AssetManagerDBServiceInterface.h)
find_package(Qt6 REQUIRED COMPONENTS Sql)
target_link_libraries(SqlDataBase PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(SqlDataBase PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(SqlDataBase PRIVATE Qt6::Sql)


