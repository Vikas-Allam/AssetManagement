cmake_minimum_required(VERSION 3.5)

project(AssetManagement VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_subdirectory(AssetData/)
add_subdirectory(googletest/)
add_subdirectory(SqlDataBase/)
set(PROJECT_SOURCES
        main.cpp
      
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AssetManagement
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET AssetManagement APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(AssetManagement SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(AssetManagement
            ${PROJECT_SOURCES}
        )
    endif()
endif()
find_package(Qt6 REQUIRED COMPONENTS Sql)
target_link_libraries(AssetManagement PRIVATE Qt6::Sql)
target_link_libraries(AssetManagement PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(AssetManagement PRIVATE Qt${QT_VERSION_MAJOR}::Core)
include_directories("${CMAKE_SOURCE_DIR}/AssetData/")
target_link_libraries(AssetManagement PUBLIC AssetData)


target_link_directories(AssetManagement PUBLIC SqlDataBase/)
target_link_libraries(AssetManagement PUBLIC SqlDataBase)
set_target_properties(AssetManagement PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS AssetManagement
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AssetManagement)
endif()
