CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
PROJECT(2023-03-07)

FIND_PACKAGE(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 20)

# compiler options. (we only check for gcc)
if (${CMAKE_COMPILER_IS_GNUCC})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3 -Wall -Werror")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3")
endif()

ADD_SUBDIRECTORY(livehacking)

ADD_SUBDIRECTORY(group1)
ADD_SUBDIRECTORY(group2)
ADD_SUBDIRECTORY(group3)
ADD_SUBDIRECTORY(group-joerg)

ADD_SUBDIRECTORY(googletest)
