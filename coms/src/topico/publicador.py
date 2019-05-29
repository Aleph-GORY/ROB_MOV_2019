#! /usr/bin/env python2

import random
import time

import rospy
from std_msgs.msg import Float32

def main():
    rospy.init_node('publicador')
    topico = rospy.Publisher('/bateria', Float32)
    while not rospy.is_shutdown():
        n = random.uniform(0, 100)
        topico.publish(n)
        time.sleep(0.1)

if __name__ == '__main__':
    main()
