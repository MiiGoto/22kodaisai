#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Bool.h>
using namespace std;

sensor_msgs::Joy last_joy;
std_msgs::Bool led_data;

ros::Publisher led_pub;

void callback(const sensor_msgs::Joy& joy_msg) {
  last_joy = joy_msg;
  if(last_joy.buttons[1]==1){
    ROS_INFO("Button A pressed");
    led_data.data = 1;
  }
  else{
    led_data.data = 0;
  }
  led_pub.publish(led_data);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "joy2led_node");
  ros::NodeHandle nh;
  ros::Subscriber joy_sub = nh.subscribe("joy", 10, callback);
  led_pub = nh.advertise<std_msgs::Bool>("led", 10);
  ros::spin();
  return 0;
}
