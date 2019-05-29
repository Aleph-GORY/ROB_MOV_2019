#! /usr/bin/env python2

import random
import time

import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import Empty
from nav_msgs.msg import Odometry


def main():
    rospy.init_node('masterOfPuppetsCuadrado')
    #topico = rospy.Publisher('/turtle1/cmd_vel', Twist)

    vel_out = rospy.Publisher('/mobile_base/commands/velocity', Twist)
    reset = rospy.Publisher('/mobile_base/commands/reset_odometry', Empty)
    odom_in = rospy.Suscriber('/odom', Odometry)

    vel = Twist()
    r = Empty()
    odom = Odometry()




    while not rospy.is_shutdown():
        #resetear odometro
        reset.publish(r)
        #inicializamos theta
        theta = 0.0
        #girar 90 grados
        while theta < 1.57079 :
            vel.angular.z = 1.0

        #Camina derecho
        vel.linear.x = 0.5
        vel.linear.y = 0.0
        vel.linear.z = 0.0
        vel.angular.x = 0.0
        vel.angular.y = 0.0
        vel.angular.z = 0.0

        topico.publish(vel)
        time.sleep(1)

        #gira
        vel.linear.x = 0.0
        vel.linear.y = 0.0
        vel.linear.z = 0.0
        vel.angular.x = 0.0
        vel.angular.y = 0.0
        vel.angular.z = 1.57079

        topico.publish(vel)
        time.sleep(1)

        vel.linear.x = 0.0
        vel.linear.y = 0.0
        vel.linear.z = 0.0
        vel.angular.x = 0.0
        vel.angular.y = 0.0
        vel.angular.z = 1.57079

        topico.publish(vel)
        time.sleep(1)


if __name__ == '__main__':
    main()
