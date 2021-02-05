cmake_minimum_required(VERSION 3.0.2)
project(google_test_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(include
  ${catkin_INCLUDE_DIRS}
  ./include/
)

add_library(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(${PROJECT_NAME}_node src/main.cpp)
target_link_libraries(${PROJECT_NAME}_node
  talker
  ${catkin_LIBRARIES}
)

catkin_add_gtest(talker_test test/test.cpp)
target_link_libraries(talker_test ${catkin_LIBRARIES})