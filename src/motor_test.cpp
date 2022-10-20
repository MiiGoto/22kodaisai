#include <ros/ros.h>
#include <pigpiod_if2.h>

#include <std_msgs/Int16.h>
int pi,duty=0;

void cb_Motor(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,16,abs(data->data));
  if(data->data >0){
    gpio_write(pi,20,1);
  }else{
    gpio_write(pi,20,0);
  }
}

int main(int argc, char** argv){
  ros::init(argc, argv, "gpio");
  pi = pigpio_start(NULL,NULL);
  ros::NodeHandle nh;
  set_mode(pi, 16, PI_OUTPUT);
  set_PWM_frequency(pi,16,1000);
  ros::Subscriber sub_led=nh.subscribe("/motor0", 5, cb_Motor);
  ros::spin();
  return 0;
}
