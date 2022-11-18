#include <ros/ros.h>
#include <pigpiod_if2.h>

#include <std_msgs/Int16.h>
int pi,duty=0;

void cb_Motor0(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,16,abs(data->data));
  if(data->data >0){
    gpio_write(pi,20,1);
  }else{
    gpio_write(pi,20,0);
  }
}

void cb_Motor1(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,16,abs(data->data));
  if(data->data >0){
    gpio_write(pi,20,1);
  }else{
    gpio_write(pi,20,0);
  }
}

void cb_Motor2(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,16,abs(data->data));
  if(data->data >0){
    gpio_write(pi,20,1);
  }else{
    gpio_write(pi,20,0);
  }
}

void cb_Motor3(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,16,abs(data->data));
  if(data->data >0){
    gpio_write(pi,20,1);
  }else{
    gpio_write(pi,20,0);
  }
}

void cb_Motor4(const std_msgs::Int16::ConstPtr &data){
  set_PWM_dutycycle(pi,16,abs(data->data));
  if(data->data >0){
    gpio_write(pi,20,1);
  }else{
    gpio_write(pi,20,0);
  }
}

void cb_LED1(const std_msgs::Bool::ConstPtr &data){
  if(data->data == 1){
    gpio_write(pi,26,1);
  }else{
    gpio_write(pi,26,0);
  }
}

void cb_LED2(const std_msgs::Bool::ConstPtr &data){
  if(data->data == 1){
    gpio_write(pi,26,1);
  }else{
    gpio_write(pi,26,0);
  }
}

void cb_LED3(const std_msgs::Bool::ConstPtr &data){
  if(data->data == 1){
    gpio_write(pi,26,1);
  }else{
    gpio_write(pi,26,0);
  }
}
int main(int argc, char** argv){
  ros::init(argc, argv, "gpio");
  pi = pigpio_start(NULL,NULL);
  ros::NodeHandle nh;
  set_mode(pi, 16, PI_OUTPUT);
  set_PWM_frequency(pi,16,1000);
  ros::Subscriber sub_led=nh.subscribe("/motor0", 5, cb_Motor0);
  ros::Subscriber sub_led=nh.subscribe("/motor1", 5, cb_Motor1);
  ros::Subscriber sub_led=nh.subscribe("/motor2", 5, cb_Motor2);
  ros::Subscriber sub_led=nh.subscribe("/motor3", 5, cb_Motor3);
  ros::Subscriber sub_led=nh.subscribe("/motor4", 5, cb_Motor4);
  ros::Subscriber sub_led=nh.subscribe("/denjiben1", 5, cb_LED1);
  ros::Subscriber sub_led=nh.subscribe("/denjiben2", 5, cb_LED2);
  ros::Subscriber sub_led=nh.subscribe("/denjiben3", 5, cb_LED3);
  ros::spin();
  return 0;
}
