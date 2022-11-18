#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Bool.h>
using namespace std;

sensor_msgs::Joy last_joy;
std_msgs::Bool led_data1;
std_msgs::Bool led_data2;
std_msgs::Bool led_data3;

ros::Publisher led_pub1;
ros::Publisher led_pub2;
ros::Publisher led_pub3;

void callback(const sensor_msgs::Joy& joy_msg) {
  last_joy = joy_msg;
  if(last_joy.buttons[1]==1){
    ROS_INFO("Button A pressed");
    led_data1.data = 1;
  }
  else{
    led_data1.data = 0;
  }
  if(last_joy.buttons[2]==1){
    ROS_INFO("Button Bpressed");
    led_data2.data = 1;
  }
  else{
    led_data2.data = 0;
  }
  if(last_joy.buttons[0]==1){
    ROS_INFO("Button X pressed");
    led_data3.data = 1;
  }
  else{
    led_data3.data = 0;
  }
  led_pub1.publish(led_data1);
  led_pub2.publish(led_data2);
  led_pub3.publish(led_data3);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "joy2led_node");
  ros::NodeHandle nh;
  ros::Subscriber joy_sub = nh.subscribe("joy", 10, callback);
  led_pub1 = nh.advertise<std_msgs::Bool>("denjiben1", 10);
  led_pub2 = nh.advertise<std_msgs::Bool>("denjiben2", 10);
  led_pub3 = nh.advertise<std_msgs::Bool>("denjiben3", 10);
  ros::spin();
  return 0;
}
