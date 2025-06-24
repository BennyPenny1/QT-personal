cmake_minimum_required(VERSION 3.16)

project(flamingo_animation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Quick)

add_executable(appflamingo_animation
    main.cpp
    flam_resource.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appflamingo_animation PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appflamingo_animation
    QT_QML_IMPORT_PATH "C:/Qt/5.15.18/msvc2019_64/qml"
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appflamingo_animation
    PRIVATE Qt5::Quick Qt5::Qml
)

include(GNUInstallDirs)
install(TARGETS appflamingo_animation
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
