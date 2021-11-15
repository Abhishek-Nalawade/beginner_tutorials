# Beginner Tutorials
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
-------

A simple tutorial for the standard ROS cpp publisher and subscriber setup


## To Build
1) Create a catkin workspace
2) Clone the repository using

```
git clone https://github.com/Abhishek-Nalawade/beginner_tutorials
```

## To Run
1) Go in catkin workspace directory and type ```catkin_make clean && catkin_make```
2) ```source devel/setup.bash```
3) ```roslaunch roslaunch beginner_tutorials tutorial.launch arg1:=1```
3) Or for default argument use ```roslaunch roslaunch beginner_tutorials tutorial.launch```
4) You can also run the publisher and subcriber nodes separately using two terminals\
	a) ```rosrun beginner_tutorials publisher```\
	b) ```rosrun beginner_tutorials subscriber```

## ROS Service
To change the output string that is being published
1) Open a new terminal and navigate to catkin_ws
2) ```source devel/setup.bash```
3) ```rosservice call /change_base_output_string "New string "```


##Inspect TF Frames

```1) cd catkin_ws```
```2) source devel/setup.bash```
```3) rosrun tf tf_echo /world /talk```
```4) rosrun tf view_frames```
```5) evince frames.pdf```
```6) rosrun rqt_tf_tree rqt_tf_tree```

##Rosbag
The rosbag recording is disabled by default.

To generate a new rosbag file type

```roslaunch beginner_tutorials launcher.launch rosbagEnable:=true```

A bag file will be saved in Results directory. To play the ROS bag file, terminate the talker and listener nodes, and type the following in a new terminal.

```rosrun beginner_tutorials listener```

Open new terminal, and navigate to Results directory.

cd cakin_ws/src/beginner_tutorials/Results
rosbag play bag.bag


Inspecting the bag

To inspect a recorded bag file: cd into the resutls directory where rosbags are stored and type

```rosbag info recordedbag.bag```



## Dependencies
1) Ubuntu 18.04
2) ROS Melodic
3) roscpp
4) std_msgs
5) message_generation
