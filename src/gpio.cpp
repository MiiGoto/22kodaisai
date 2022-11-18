#include <ros/ros.h>
#include <pigpiod_if2.h>

#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
int pi,duty=0;

void cb_Motor0(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,13,abs(data->data));
  if(data->data >0){
    gpio_write(pi,6,1);
  }else{
    gpio_write(pi,6,0);
  }
}

void cb_Motor1(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,18,abs(data->data));
  if(data->data >0){
    gpio_write(pi,16,1);
  }else{
    gpio_write(pi,16,0);
  }
}

void cb_Motor2(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,26,abs(data->data));
  if(data->data >0){
    gpio_write(pi,21,1);
  }else{
    gpio_write(pi,21,0);
  }
}

void cb_Motor3(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,19,abs(data->data));
  if(data->data >0){
    gpio_write(pi,20,1);
  }else{
    gpio_write(pi,20,0);
  }
}

void cb_Motor4(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,12,abs(data->data));
  if(data->data >0){
    gpio_write(pi,5,1);
  }else{
    gpio_write(pi,5,0);
  }
}

void cb_LED1(const std_msgs::Bool::ConstPtr &data){
  if(data->data == 1){
    gpio_write(pi,17,1);
  }else{
    gpio_write(pi,17,0);
  }
}

void cb_LED2(const std_msgs::Bool::ConstPtr &data){
  if(data->data == 1){
    gpio_write(pi,27,1);
  }else{
    gpio_write(pi,27,0);
  }
}

void cb_LED3(const std_msgs::Bool::ConstPtr &data){
  if(data->data == 1){
    gpio_write(pi,22,1);
  }else{
    gpio_write(pi,22,0);
  }
}
int main(int argc, char** argv){
  ros::init(argc, argv, "gpio");
  pi = pigpio_start(NULL,NULL);
  ros::NodeHandle nh;
  set_mode(pi, 12, PI_OUTPUT);
  set_PWM_frequency(pi,12,1000);
  set_mode(pi, 13, PI_OUTPUT);
  set_PWM_frequency(pi,13,1000);
  set_mode(pi, 18, PI_OUTPUT);
  set_PWM_frequency(pi,18,1000);
  set_mode(pi, 19, PI_OUTPUT);
  set_PWM_frequency(pi,19,1000);
  set_mode(pi, 26, PI_OUTPUT);
  set_PWM_frequency(pi,26,1000);
  ros::Subscriber sub_led1=nh.subscribe("/motor0", 5, cb_Motor0);
  ros::Subscriber sub_led2=nh.subscribe("/motor1", 5, cb_Motor1);
  ros::Subscriber sub_led3=nh.subscribe("/motor2", 5, cb_Motor2);
  ros::Subscriber sub_led4=nh.subscribe("/motor3", 5, cb_Motor3);
  ros::Subscriber sub_led5=nh.subscribe("/motor4", 5, cb_Motor4);
  ros::Subscriber sub_led6=nh.subscribe("/denjiben1", 5, cb_LED1);
  ros::Subscriber sub_led7=nh.subscribe("/denjiben2", 5, cb_LED2);
  ros::Subscriber sub_led8=nh.subscribe("/denjiben3", 5, cb_LED3);
  ros::spin();
  return 0;
}
