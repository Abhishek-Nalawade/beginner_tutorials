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

int main(int argc, char **argv) {
ros::init(argc, argv, "talker");
ros::NodeHandle n;
ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
ros::Rate loop_rate(10);

int count = 0;
while(ros::ok()) {
  std_msgs::String msg;
  std::string txt;
  txt = "Hi there " + std::to_string(count);
  msg.data = txt;
  std::cout<<"HERE "<<argv[1]<<"\n";
  ROS_INFO("%s", msg.data.c_str());

  chatter_pub.publish(msg);

  ros::spinOnce();

  loop_rate.sleep();
  ++count;
}
return 0;
}
