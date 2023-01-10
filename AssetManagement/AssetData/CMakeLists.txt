cmake_minimum_required(VERSION 3.5)

project(AssetData)

add_library(AssetData SHARED 
assetmainwindow.cpp
assetmainwindow.h
assetmainwindow.ui
AssetManagerInterface.h
assetmanagerinformation.cpp
assetmanagerinformation.h
assetrecord.cpp
assetrecord.h
assetrecord.ui
assetreport.cpp
assetreport.h
Asset.qrc)
find_package(Qt6 REQUIRED COMPONENTS Sql)
target_link_libraries(AssetData PRIVATE Qt6::Sql)
target_link_libraries(AssetData PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(AssetData PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
include_directories("${CMAKE_SOURCE_DIR}/SqlDataBase/")


target_link_libraries(AssetData PUBLIC  SqlDataBase)
add_subdirectory(_test/)

