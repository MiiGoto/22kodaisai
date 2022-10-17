#include <ros/ros.h>
#include <pigpiod_if2.h>

#include <std_msgs/Bool.h>

void cb_LED(const std_msgs::Bool::ConstPtr &data){
  if(data->data == 1){
    gpio_write(pi,26,1);
  }else{
    gpio_write(pi,26,0);
  }
}

int main(int argc, char** argv){
  ros::init(argc, argv, "gpio");
  int pi = pigpio_start(NULL,NULL);
  ros::NodeHandle nh;
  ros::Subscriber sub_led=nh.subscribe("/led", 5, cb_LED);
  ros::spin();
  return 0;
}
