cmake_minimum_required(VERSION 3.0.2)
project(gtest_gmock_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  roslint
)

catkin_package()

include_directories(include
  ${catkin_INCLUDE_DIRS}
  ./include/
)

# invoke lintery
roslint_cpp()

add_library(message_provider src/message_provider.cpp)
target_link_libraries(message_provider ${catkin_LIBRARIES})

# create library and executable for non virtual talker
add_library(non_virtual_talker src/non_virtual_talker.cpp)
target_link_libraries(non_virtual_talker ${catkin_LIBRARIES})

add_executable(non_virtual_talker_node src/non_virtual_talker_main.cpp)
target_link_libraries(non_virtual_talker_node non_virtual_talker message_provider ${catkin_LIBRARIES})

# create library and executable for virtual talker
add_library(virtual_talker src/virtual_talker.cpp src/virtual_publisher.cpp)
target_link_libraries(virtual_talker ${catkin_LIBRARIES})

add_executable(virtual_talker_node src/virtual_talker_main.cpp)
target_link_libraries(virtual_talker_node virtual_talker message_provider ${catkin_LIBRARIES})

# add gtests
catkin_add_gtest(google_test_tests
  test/test.cpp
  test/test_non_virtual_talker.cpp
  test/test_virtual_talker.cpp
)

# link libraries to gtests
target_link_libraries(google_test_tests
  non_virtual_talker
  virtual_talker
  # gmock is only reqired if the mocks are created
  gmock 
)