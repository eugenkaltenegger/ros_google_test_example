# ROS - Google Tests - Example Package

This is an example package for the usage of Google Tests (`gtest` and `gmock`) with ROS.
This project aims to show how to integrate `gtest` and `gmock` in a ROS package (with `catkin`). The different test methods and mocks are not discussed in detail.

The tests can be executed with:
``` bash
catkin_make run_tests
```

## Tests
The files containing the test cases should be located at `<package_root>/test`.

The test main function can create a ROS node as well as a nodehandle (a running roscore is required).
Both the node as well as the nodehandle are not required.

``` c++
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "tester");
  ros::NodeHandle nodehandle;
  # run all test cases in this directory
  return RUN_ALL_TESTS();
}
```
Tests are defined in with macros.
``` c++
TEST(TestSuite, testCase) {
    EXPECT_TRUE(true);
}
```
The assertions and expects are well documented at [GitHub - googletest - gtest](https://github.com/google/googletest/blob/master/docs/primer.md).
Note that the difference between assert and expect is that after a failed assert the test stops and the test fails immediately, after a failed expect the test will continue and will fail after the test finishes.

## Mocks
There are no mocks provided for ROS classes.
Thus mocks for ROS classes need to be written.
The invoked methods need to be mocked separately.
``` c++
class MockPublisher : public ros::Publisher {
  public:
    MOCK_METHOD(void, publish, (std_msgs::String message), ());
};
```
A mock can called in tests, such calls can be verified.
``` c++
TEST(TalkerTest, verifyPublisherCall) {
    MockPublisher* mockPublisher = new MockPublisher();
    Talker* talker = new Talker(mockPublisher);
    std_msgs::String message;
    talker->publish(message);
    EXPECT_CALL(*mockPublisher, publish(message)).Times(1);
}
```
A more detailed documentation for mocks is provided [Github - googletest - gmock](https://github.com/google/googletest/blob/master/googlemock/README.md).

## Configuration
The `CMakeLists.txt` needs to be extended:
```
catkin_add_gtest(target
  source_1
  ...
  source_n
)

target_link_libraries(target
  library_1
  ...
  library_n
  gmock
)
```

The `package.xml` needs to be extended:
``` xml
<test_depend>rosunit</test_depend>
```
## Requirements
The following packages are required for `gtest` and `gmock`:
- `libgtest-dev` (installation in ubuntu: `sudo apt-get install libgtest-dev`)
- `libgmock-dev` (installation in ubuntu: `sudo apt-get install libgmock-dev`)