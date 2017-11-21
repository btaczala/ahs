set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5WaylandCompositor REQUIRED)
find_package(Qt5Core REQUIRED)

qt5_add_resources(resource_files pure-qml.qrc)
add_executable(ahs-compositor main.cpp ApplicationManager.cpp ${resource_files})

target_link_libraries(ahs-compositor Qt5::WaylandCompositor Qt5::Core)
