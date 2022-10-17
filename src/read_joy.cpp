#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
using namespace std;

sensor_msgs::Joy last_joy;

void callback(const sensor_msgs::Joy& joy_msg) {
  last_joy = joy_msg;
  if(last_joy.buttons[1]==1)
    ROS_INFO("Button A pressed");
  if(last_joy.axes[2]!=0)
    ROS_INFO("right stick up/down : %f",last_joy.axes[2]);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "read_joy_node");
  ros::NodeHandle nh;
  ros::Subscriber joy_sub = nh.subscribe("joy", 10, callback);
  ros::spin();
  return 0;
}
