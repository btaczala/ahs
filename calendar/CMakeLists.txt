find_package(Qt5Quick REQUIRED)

qt5_add_resources(resource_files qml/qml.qrc)
add_executable(ahs-calendar src/main.cpp ${resource_files})
target_link_libraries(ahs-calendar Qt5::WebKit Qt5::Quick)
