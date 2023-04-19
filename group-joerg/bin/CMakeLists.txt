ADD_EXECUTABLE(group-joerg-dummy-exe dummy-exe.cpp)
TARGET_LINK_LIBRARIES(group-joerg-dummy-exe group-joerg)

ADD_EXECUTABLE(group-joerg-sensors-main sensors-main.cpp)
TARGET_LINK_LIBRARIES(group-joerg-sensors-main group-joerg)
