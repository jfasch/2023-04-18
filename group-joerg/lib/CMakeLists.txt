ADD_LIBRARY(
  group-joerg

  sensor.h
  sensor.cpp

  sensor-registry.h
  sensor-registry.cpp

  sensor-const.h
  sensor-const.cpp

  sensor-random.h
  sensor-random.cpp
)

TARGET_INCLUDE_DIRECTORIES(group-joerg PUBLIC .)
