ADD_EXECUTABLE(
  group2-suite

  test-sensor.cpp
)

TARGET_LINK_LIBRARIES(
  group2-suite

  group2
  gtest_main 
)
