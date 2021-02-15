# ROS - Google Tests - Example Package

This is an example package for the usage of Google Tests and Google Mocks (`gtest` and `gmock`) with ROS.

Test cases are executed in the root directory of the workspace with:
``` bash
catkin_make run_tests
```

## Testing

Files containing the test cases should be located at `<package_root>/test`.
A file executing the test cases is required.
Within this file a ros node and a ros nodehandle can be initialized if these are required for the test cases.
If a rops node and a ros nodehandle are created a roscore is required.

``` c++
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "tester");
  ros::NodeHandle nodehandle;
  // execute all tests defined in CMakeLists.txt
  return RUN_ALL_TESTS();
}
```
The specific test cases can be placed in the same file as the main or can be placed in different files.
All files containing test cases shall be located in `<package_root>/test`.

### Tests
Tests are defined in with macros.
A name for the test suite (CamelCaseStartingUpper) and the test case (camelCaseStartingLower) are required.
The test utilizes assertions (assert) and expectations (expect) see [here](https://github.com/google/googletest/blob/master/docs/primer.md).
Note that the difference between assert and expect is that after a failed assert the test stops and the test fails immediately, after a failed expect the test will continue and will fail after the test finishes.

``` c++
TEST(TestSuite, testCase) {
  EXPECT_TRUE(true);
}
```

### Mocks
Test can use mocks to ease testing.
Mocks are designed to mock the functionality of virtual functions.
Nevertheless it is possible to mock the functionality of non-virtual functions.

A test including a mock can verify that the mock was called as expected.

#### Virtual Functions
A class with a virtual function could look like this:
``` c++
namespace Virtual {
  class Publisher : public ros::Publisher {
          
  private: 
    ros::Publisher* publisher_pointer;

  public:
    void setPublisher(ros::Publisher*);
    virtual void publish(const std_msgs::String&) const;
  };
}
```
This is a wrapper class for the ros publisher shadowing the publish function with a virtual function.

A mock for this class could look like this:
``` c++
namespace Virtual {
  class MockPublisher : public ros::Publisher {
    public:
      MOCK_METHOD(void, publish, (std_msgs::String&), (const, override));
  };
}
```
Notice that the mock does not have to overwrite all functions. 

A test for such a mock could look like this:
``` c++
TEST(VirtualTalkerTest, verifyPublisherCall) {
  auto mockPublisher = std::make_shared<Virtual::MockPublisher>();
  auto talker = std::make_shared<Virtual::Talker>();
  talker->setPublisher(mockPublisher.get());

  EXPECT_CALL(*mockPublisher.get(), publish(testing::_)).Times(1);
  std_msgs::String message;
  talker->publish(message);
}
```
Notice that the arguments for the call are specified with `testing::_` which matched any call.

#### Non-Virtual Functions
The publisher as defined in ros has no virtual functions.

To verify calls on the publisher the class using the publisher can be a templated class.
A mock class of the publisher without inheritance (the signature of the mocked function needs to be the same) is required.
The mock class can be passed to the templated class.

The templated class could look like this:
``` c++
namespace NonVirtual { ;
  template<typename T>
  class Talker {

  private:
    T *publisher_pointer;

  public:

    void setPublisher(T *publisher) {
        this->publisher_pointer = publisher;
    };

    virtual void publish(const std_msgs::String &message) const {
        ROS_DEBUG("non-virtual publish function is invoked");
        this->publisher_pointer->publish(message);
    };
  };
}
```

A mock for such a class could look like this:
``` c++
namespace NonVirtual {
    class MockPublisher {
        public:
            MOCK_METHOD(void, publish, (const std_msgs::String&), (const));
    };    
}
```

A test for such a mock could look like this:
``` c++
TEST(NonVirtualTalkerTest, verifyPublisherCall) {
    auto mockPublisher = std::make_shared<NonVirtual::MockPublisher>();
    auto talker = std::make_shared<NonVirtual::Talker<NonVirtual::MockPublisher>>();
    talker->setPublisher(mockPublisher.get());
    
    EXPECT_CALL(*mockPublisher.get(), publish(testing::_)).Times(1);
    std_msgs::String message;
    talker->publish(message);
}
```
A more detailed documentation for mocks is provided [here](https://github.com/google/googletest/blob/master/googlemock/README.md).

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
