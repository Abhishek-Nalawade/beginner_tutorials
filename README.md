# Beginner Tutorials
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
-------

A simple tutorial for for the standard ROS cpp publisher and subscriber setup


## To Build
1) Create a catkin workspace
2) Clone the repository using
https://github.com/Abhishek-Nalawade/beginner_tutorials/tree/main

## To Run
1) Go in catkin workspace directory and type catkin_make
2) source devel/setup.bash
3) roslaunch roslaunch beginner_tutorials tutorial.launch
4) You can also run the publisher and subcriber node separately using two terminals
	a) rosrun beginner_tutorials publisher
	b) rosrun beginner_tutorials subscriber

## Dependencies
1) Ubuntu 18.04
2) ROS Melodic
3) roscpp
4) std_msgs
