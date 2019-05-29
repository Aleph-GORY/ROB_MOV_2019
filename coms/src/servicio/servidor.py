#! /usr/bn/env python2

import rospy
from std_msgs.msg import String

def mover(solicitud):
    if solicitud.data == 'adelante'
        print 'Me estoy moviendo adelante'
    elif solicitud.data == 'derecha':
        print 'Estoy girando a la derecha'
    elif solicitud.data == 'izquierda'
        print 'Estoy girandoa la izquierda'
    else :
        print 'No entendi'

def main():
    rospy.init_node('servidor')
    servicio = rospy.Service('mover', String, mover)
    rospy.spin()


if __name__ == '__main__':
    main()
