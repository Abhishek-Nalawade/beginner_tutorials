/**
 * MIT License

 * Copyright (c) 2021 Abhishek Nalawade

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

/**
 * @file service_test.cpp
 * @author Abhishek Nalawade
 * @brief Publishes string data on a topic
 * @version 0.1
 * @date 2021-11-15
 *
 * @copyright Copyright (c) 2021
 */
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
