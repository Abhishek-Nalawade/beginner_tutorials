# Beginner Tutorials
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
-------

A simple tutorial for the standard ROS cpp publisher and subscriber setup


## To Build
1) Create a catkin workspace
2) Clone the repository using

```
git clone https://github.com/Abhishek-Nalawade/beginner_tutorials/tree/main
```

## To Run
1) Go in catkin workspace directory and type catkin_make clean && catkin_make
2) source devel/setup.bash
3) roslaunch roslaunch beginner_tutorials tutorial.launch arg1:=1
3) Or for default argument use roslaunch roslaunch beginner_tutorials tutorial.launch
4) You can also run the publisher and subcriber nodes separately using two terminals\
	a) rosrun beginner_tutorials publisher\
	b) rosrun beginner_tutorials subscriber

## Service
To change the output string that is being published
1) Open a new terminal and navigate to catkin_ws
2 source devel/setup.bash
3) rosservice call /change_base_output_string "New string "

## Dependencies
1) Ubuntu 18.04
2) ROS Melodic
3) roscpp
4) std_msgs
