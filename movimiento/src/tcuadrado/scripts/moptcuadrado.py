#! /usr/bin/env python2

import random
import time

import rospy
from std_msgs.msg import Empty
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Pose
from nav_msgs.msg import Odometry

theta_global = 0.0

def pose_function(data):
    global theta_global
    theta_global = data.pose.pose.orientation.z

def main():
    global theta_global
    rospy.init_node('masterOfPuppetsTCuadrado')
    #topico = rospy.Publisher('/turtle1/cmd_vel', Twist)

    vel_out = rospy.Publisher('/mobile_base/commands/velocity', Twist)
    reset = rospy.Publisher('/mobile_base/commands/reset_odometry', Empty)
    rospy.Subscriber('/odom', Odometry, pose_function)

    vel = Twist()
    e = Empty()

    #inicializacion de vel
    vel.linear.x = 0.0
    vel.linear.y = 0.0
    vel.linear.z = 0.0
    vel.angular.x = 0.0
    vel.angular.y = 0.0
    vel.angular.z = 0.0

    while not rospy.is_shutdown():
        #inicializamos theta
        reset.publish(e)
        vel.linear.x = 0.0
        vel_out.publish(vel)
        time.sleep(0.5)
        #girar 90 grados
        vel.angular.z = 0.5

        x =  0.0
        print("TODO BIEN")

        while x < 0.7 :
            vel_out.publish(vel)
            print(theta_global)
            x = theta_global
            #if x < 0:
            #    x = x + 6.283185307
            time.sleep(0.005)


        print("Flag de 90")

        vel.angular.z = 0.0
        vel.linear.x = 0.3

        vel_out.publish(vel)

        time.sleep(1)



if __name__ == '__main__':
    main()
