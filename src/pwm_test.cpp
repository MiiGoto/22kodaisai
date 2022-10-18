#include <ros/ros.h>
#include <pigpiod_if2.h>

#include <std_msgs/Bool.h>
int pi,duty=0;

void cb_LED(const std_msgs::Bool::ConstPtr &data){
  if(data->data == 1){
    //gpio_write(pi,26,1);
    set_PWM_dutycycle(pi,26,125);
  }else{
    set_PWM_dutycycle(pi,26,0);
  }
}

int main(int argc, char** argv){
  ros::init(argc, argv, "gpio");
  pi = pigpio_start(NULL,NULL);
  ros::NodeHandle nh;
  set_mode(pi, 26, PI_OUTPUT);
  set_PWM_frequency(pi,26,1000);
  ros::Subscriber sub_led=nh.subscribe("/led", 5, cb_LED);
  ros::spin();
  return 0;
}
