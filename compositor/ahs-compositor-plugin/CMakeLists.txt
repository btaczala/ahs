find_package(Qt5Quick REQUIRED)
add_library(ahs-compositor-plugin SHARED 
    ApplicationManager.cpp 
    ApplicationEntry.cpp
    Controller.cpp
    Notification.cpp
)
target_include_directories(ahs-compositor-plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ahs-compositor-plugin PUBLIC Qt5::Quick)
