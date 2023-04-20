ADD_EXECUTABLE(group-joerg-sensors-main sensors-main.cpp)
TARGET_LINK_LIBRARIES(group-joerg-sensors-main group-joerg)

ADD_EXECUTABLE(group-joerg-sensors-shared-ptr sensors-shared-ptr.cpp)
TARGET_LINK_LIBRARIES(group-joerg-sensors-shared-ptr group-joerg)

ADD_EXECUTABLE(sensor-const sensor-const-main.cpp)
TARGET_LINK_LIBRARIES(sensor-const group-joerg)

ADD_EXECUTABLE(sensor-random sensor-random-main.cpp)
TARGET_LINK_LIBRARIES(sensor-random group-joerg)
