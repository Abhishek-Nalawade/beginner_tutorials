#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <std_msgs/String.h>
#include "beginner_tutorials/change_base_output_string.h"

TEST(ServiceTest, ServiceExistence) {
  ros::NodeHandle n;
  auto client = n.serviceClient<beginner_tutorials::change_base_output_string>
  ("change_base_output_string");


  bool exists(client.waitForExistence(ros::Duration(5)));
  EXPECT_FALSE(exists);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "service_tester");
  ros::NodeHandle n;
  return RUN_ALL_TESTS();
}
