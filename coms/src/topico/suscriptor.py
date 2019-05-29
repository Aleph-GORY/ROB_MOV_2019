#! /usr/bin/env python2

import rospy
from std_msgs.msg import Float32

def nivel_bateria(data):
    if data.data < 20:
        print 'Nivel bajo'
    elif data.data < 75:
        print 'Nivel medio'
    else :
        print 'Nivel bajo'

def main():
    rospy.init_node("suscriptor")
    rospy.Subscriber('bateria', Float32, nivel_bateria)
    rospy.spin()

if __name__ == '__main__' :
    main()
