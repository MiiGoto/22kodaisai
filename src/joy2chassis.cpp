#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Int16.h>
using namespace std;

sensor_msgs::Joy last_joy;
std_msgs::Int16 motor1_data;
std_msgs::Int16 motor2_data;
std_msgs::Int16 motor3_data;
std_msgs::Int16 motor4_data;

ros::Publisher motor1_pub;
ros::Publisher motor2_pub;
ros::Publisher motor3_pub;
ros::Publisher motor4_pub;

void callback(const sensor_msgs::Joy& joy_msg) {
  last_joy = joy_msg;
  if(last_joy.buttons[4]==0){
    ROS_INFO("motor disabled");
    motor1_data.data=0;
    motor2_data.data=0;
    motor3_data.data=0;
    motor4_data.data=0;
  }
  else{
    int vx=last_joy.axes[3]*255;
    int vy=last_joy.axes[2]*255;
    int vt=last_joy.axes[0]*255;
    motor1_data.data=vx-vy+vt;
    if(motor1_data.data>255)motor1_data.data=255;
    if(motor1_data.data<-255)motor1_data.data=-255;
    motor2_data.data=vx+vy+vt;
    if(motor2_data.data>255)motor2_data.data=255;
    if(motor2_data.data<-255)motor2_data.data=-255;
    motor3_data.data=-vx+vy+vt;
    if(motor3_data.data>255)motor3_data.data=255;
    if(motor3_data.data<-255)motor3_data.data=-255;
    motor4_data.data=-vx-vy+vt;
    if(motor4_data.data>255)motor4_data.data=255;
    if(motor4_data.data<-255)motor4_data.data=-255;
  }
  motor1_pub.publish(motor1_data);
  motor2_pub.publish(motor2_data);
  motor3_pub.publish(motor3_data);
  motor4_pub.publish(motor4_data);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "joy2chassis_node");
  ros::NodeHandle nh;
  ros::Subscriber joy_sub = nh.subscribe("joy", 10, callback);
  motor1_pub = nh.advertise<std_msgs::Int16>("motor1", 10);
  motor2_pub = nh.advertise<std_msgs::Int16>("motor2", 10);
  motor3_pub = nh.advertise<std_msgs::Int16>("motor3", 10);
  motor4_pub = nh.advertise<std_msgs::Int16>("motor4", 10);
  ros::spin();
  return 0;
}
