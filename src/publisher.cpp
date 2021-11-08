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
 * @file publisher.cpp
 * @author Abhishek Nalawade
 * @brief Publishes string data on a topic
 * @version 0.1
 * @date 2021-10-31
 *
 * @copyright Copyright (c) 2021
 */
#include<iostream>
#include"ros/ros.h"
#include"std_msgs/String.h"
#include"beginner_tutorials/change_base_output_string.h"

// string that is changed by the user
std::string txt1 = "Hi there ";

/**
 * @brief To change the string that is being published
 * @param req : Request to the service
 * @param res : Response sent to the client
 * @return bool
 */
bool changeString(beginner_tutorials::change_base_output_string::Request &req,
                beginner_tutorials::change_base_output_string::Response &res) {
                  ROS_WARN_STREAM("The output string has been changed");
                  txt1 = req.previousString;
                  res.nextString = req.previousString;
                  return true;
                  }

/**
 * @brief Runs the code
 * @param argc : Counter to number of arguments
 * @param argv : Contains the rate for publishing data
 * @return int
 */
int main(int argc, char **argv) {
ros::init(argc, argv, "talker");
ros::NodeHandle n;
ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
int rate = std::stoi(argv[1]);

ros::Rate main_rate(1);
main_rate.sleep();

// checks for appropriate publishing rate
if(rate > 10) {
  ROS_WARN_STREAM("The frequency rate is high");
} else if (rate < 0) {
  ROS_FATAL_STREAM("Frequecy rate cannot be negative");
  ROS_INFO("Ending the program");
  ros::shutdown();
  return 1;
} else if (rate == 0) {
  ROS_ERROR_STREAM("Frequncy rate cannot be 0");
  ROS_INFO_STREAM("Increasing the frequncy to the default 1Hz");
  rate = 1;
} else {
  ROS_INFO_STREAM("The frequency looks good");
}
ros::Rate loop_rate(rate);

ROS_DEBUG_STREAM_ONCE("Frequency rate is set at: " << rate);

ros::ServiceServer server = n.advertiseService("change_base_output_string",
                                                  changeString);

// publishes the data
int count = 0;
while(ros::ok()) {
  std_msgs::String msg;
  std::string txt;
  txt = txt1 + std::to_string(count);
  msg.data = txt;

  ROS_INFO("%s", msg.data.c_str());

  chatter_pub.publish(msg);

  ros::spinOnce();

  loop_rate.sleep();
  ++count;
}
return 0;
}
