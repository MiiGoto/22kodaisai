#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Int16.h>
using namespace std;

sensor_msgs::Joy last_joy;
std_msgs::Int16 motor_data;

ros::Publisher motor_pub;

void callback(const sensor_msgs::Joy& joy_msg) {
  last_joy = joy_msg;
  if(last_joy.buttons[4]==0){//L1が押されてない->無効化
    ROS_INFO("motor disabled");
    motor_data.data=0;
  }
  else{
    motor_data.data=last_joy.axes[1]*255;
    ROS_INFO("Motor Power : %.0f",last_joy.axes[1]*255);
  }
  motor_pub.publish(motor_data);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "joy2motor_node");
  ros::NodeHandle nh;
  ros::Subscriber joy_sub = nh.subscribe("joy", 10, callback);
  motor_pub = nh.advertise<std_msgs::Int16>("motor0", 10);
  ros::spin();
  return 0;
}