ADD_EXECUTABLE(
  group3-suite

  test-sensor.cpp
)

TARGET_LINK_LIBRARIES(
  group3-suite

  group3
  gtest_main 
)
