ADD_EXECUTABLE(
  group1-suite

  test-sensor.cpp
)

TARGET_LINK_LIBRARIES(
  group1-suite

  group1
  gtest_main 
)
