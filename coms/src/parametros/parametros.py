#! /usr/bin/env python2

import rospy
import time
import random


def main():
    rospy.init_node('nodo')
    while not rospy.is_shutdown():
        max = rospy.get_param('/vel_max')
        #rospy.set_param('/vel_max')
        #rospy.has_param('/vel_max')
        #rospy.delete_param('/vel_max')
        n = random.uniform(0, max)
        print n
        time.sleep(1)


if __name__ == '__main__':
    main()
