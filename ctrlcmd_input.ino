#include <Wire.h>
#include <ros.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
#include <std_msgs/Int32.h>

int throttle = 40;
Servo servo_steer;
Servo servo_throttle;
ros::NodeHandle nh;

void steer_callback(const std_msgs::Int32& cmd_msg){
  // servo_throttle.write(100);
  int steer = cmd_msg.data;
  servo_steer.write(steer);
}

ros::Subscriber<std_msgs::Int32> sub("deliverycar_cmd", steer_callback);

void setup(){
  nh.getHardware()->setBaud(9600);
  servo_steer.attach(5);
  // servo_throttle.attach(6);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(10);
}
