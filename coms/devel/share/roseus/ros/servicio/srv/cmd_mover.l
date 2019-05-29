;; Auto-generated. Do not edit!


(when (boundp 'servicio::cmd_mover)
  (if (not (find-package "SERVICIO"))
    (make-package "SERVICIO"))
  (shadow 'cmd_mover (find-package "SERVICIO")))
(unless (find-package "SERVICIO::CMD_MOVER")
  (make-package "SERVICIO::CMD_MOVER"))
(unless (find-package "SERVICIO::CMD_MOVERREQUEST")
  (make-package "SERVICIO::CMD_MOVERREQUEST"))
(unless (find-package "SERVICIO::CMD_MOVERRESPONSE")
  (make-package "SERVICIO::CMD_MOVERRESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))




(defclass servicio::cmd_moverRequest
  :super ros::object
  :slots (_header _comando ))

(defmethod servicio::cmd_moverRequest
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:comando __comando) "")
    )
   (send-super :init)
   (setq _header __header)
   (setq _comando (string __comando))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:comando
   (&optional __comando)
   (if __comando (setq _comando __comando)) _comando)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _comando
    4 (length _comando)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _comando
       (write-long (length _comando) s) (princ _comando s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _comando
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _comando (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass servicio::cmd_moverResponse
  :super ros::object
  :slots (_respuesta ))

(defmethod servicio::cmd_moverResponse
  (:init
   (&key
    ((:respuesta __respuesta) "")
    )
   (send-super :init)
   (setq _respuesta (string __respuesta))
   self)
  (:respuesta
   (&optional __respuesta)
   (if __respuesta (setq _respuesta __respuesta)) _respuesta)
  (:serialization-length
   ()
   (+
    ;; string _respuesta
    4 (length _respuesta)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _respuesta
       (write-long (length _respuesta) s) (princ _respuesta s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _respuesta
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _respuesta (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass servicio::cmd_mover
  :super ros::object
  :slots ())

(setf (get servicio::cmd_mover :md5sum-) "0d7c1320405ff716cbb9ed56b1e4bf4b")
(setf (get servicio::cmd_mover :datatype-) "servicio/cmd_mover")
(setf (get servicio::cmd_mover :request) servicio::cmd_moverRequest)
(setf (get servicio::cmd_mover :response) servicio::cmd_moverResponse)

(defmethod servicio::cmd_moverRequest
  (:response () (instance servicio::cmd_moverResponse :init)))

(setf (get servicio::cmd_moverRequest :md5sum-) "0d7c1320405ff716cbb9ed56b1e4bf4b")
(setf (get servicio::cmd_moverRequest :datatype-) "servicio/cmd_moverRequest")
(setf (get servicio::cmd_moverRequest :definition-)
      "Header header
string comando

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
---
string respuesta

")

(setf (get servicio::cmd_moverResponse :md5sum-) "0d7c1320405ff716cbb9ed56b1e4bf4b")
(setf (get servicio::cmd_moverResponse :datatype-) "servicio/cmd_moverResponse")
(setf (get servicio::cmd_moverResponse :definition-)
      "Header header
string comando

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
---
string respuesta

")



(provide :servicio/cmd_mover "0d7c1320405ff716cbb9ed56b1e4bf4b")


