#! /usr/bin/env python2

import random
import time

import rospy
from geometry_msgs.msg import Twist

def main():
    rospy.init_node('masterOfPuppets_circulo')
    #topico = rospy.Publisher('/turtle1/cmd_vel', Twist)
    topico = rospy.Publisher('/mobile_base/commands/velocity', Twist)
    vel = Twist()

    vel.linear.y = vel.linear.z = vel.angular.x = vel.angular.y = 0.0

    while not rospy.is_shutdown():

        vel.linear.x = 1.0
        vel.angular.z = 1.0

        topico.publish(vel)
        time.sleep(0.1)

if __name__ == '__main__':
    main()
