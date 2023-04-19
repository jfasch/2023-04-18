ADD_EXECUTABLE(
  group-joerg-suite

  test-sensor.cpp
)

TARGET_LINK_LIBRARIES(
  group-joerg-suite

  group-joerg
  gtest_main 
)
