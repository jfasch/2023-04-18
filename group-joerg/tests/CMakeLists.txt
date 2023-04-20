ADD_EXECUTABLE(
  group-joerg-suite

  test-sensor.cpp
  test-sensors-const.cpp
  test-sensor-registry-managed.cpp
)

TARGET_LINK_LIBRARIES(
  group-joerg-suite

  group-joerg
  gtest_main 
)
