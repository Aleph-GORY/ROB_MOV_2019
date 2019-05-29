; Auto-generated. Do not edit!


(cl:in-package servicio-srv)


;//! \htmlinclude cmd_mover-request.msg.html

(cl:defclass <cmd_mover-request> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (comando
    :reader comando
    :initarg :comando
    :type cl:string
    :initform ""))
)

(cl:defclass cmd_mover-request (<cmd_mover-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmd_mover-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmd_mover-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name servicio-srv:<cmd_mover-request> is deprecated: use servicio-srv:cmd_mover-request instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <cmd_mover-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader servicio-srv:header-val is deprecated.  Use servicio-srv:header instead.")
  (header m))

(cl:ensure-generic-function 'comando-val :lambda-list '(m))
(cl:defmethod comando-val ((m <cmd_mover-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader servicio-srv:comando-val is deprecated.  Use servicio-srv:comando instead.")
  (comando m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmd_mover-request>) ostream)
  "Serializes a message object of type '<cmd_mover-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'comando))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'comando))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmd_mover-request>) istream)
  "Deserializes a message object of type '<cmd_mover-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'comando) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'comando) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmd_mover-request>)))
  "Returns string type for a service object of type '<cmd_mover-request>"
  "servicio/cmd_moverRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd_mover-request)))
  "Returns string type for a service object of type 'cmd_mover-request"
  "servicio/cmd_moverRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmd_mover-request>)))
  "Returns md5sum for a message object of type '<cmd_mover-request>"
  "0d7c1320405ff716cbb9ed56b1e4bf4b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmd_mover-request)))
  "Returns md5sum for a message object of type 'cmd_mover-request"
  "0d7c1320405ff716cbb9ed56b1e4bf4b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmd_mover-request>)))
  "Returns full string definition for message of type '<cmd_mover-request>"
  (cl:format cl:nil "Header header~%string comando~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmd_mover-request)))
  "Returns full string definition for message of type 'cmd_mover-request"
  (cl:format cl:nil "Header header~%string comando~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmd_mover-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'comando))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmd_mover-request>))
  "Converts a ROS message object to a list"
  (cl:list 'cmd_mover-request
    (cl:cons ':header (header msg))
    (cl:cons ':comando (comando msg))
))
;//! \htmlinclude cmd_mover-response.msg.html

(cl:defclass <cmd_mover-response> (roslisp-msg-protocol:ros-message)
  ((respuesta
    :reader respuesta
    :initarg :respuesta
    :type cl:string
    :initform ""))
)

(cl:defclass cmd_mover-response (<cmd_mover-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmd_mover-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmd_mover-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name servicio-srv:<cmd_mover-response> is deprecated: use servicio-srv:cmd_mover-response instead.")))

(cl:ensure-generic-function 'respuesta-val :lambda-list '(m))
(cl:defmethod respuesta-val ((m <cmd_mover-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader servicio-srv:respuesta-val is deprecated.  Use servicio-srv:respuesta instead.")
  (respuesta m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmd_mover-response>) ostream)
  "Serializes a message object of type '<cmd_mover-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'respuesta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'respuesta))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmd_mover-response>) istream)
  "Deserializes a message object of type '<cmd_mover-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'respuesta) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'respuesta) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmd_mover-response>)))
  "Returns string type for a service object of type '<cmd_mover-response>"
  "servicio/cmd_moverResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd_mover-response)))
  "Returns string type for a service object of type 'cmd_mover-response"
  "servicio/cmd_moverResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmd_mover-response>)))
  "Returns md5sum for a message object of type '<cmd_mover-response>"
  "0d7c1320405ff716cbb9ed56b1e4bf4b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmd_mover-response)))
  "Returns md5sum for a message object of type 'cmd_mover-response"
  "0d7c1320405ff716cbb9ed56b1e4bf4b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmd_mover-response>)))
  "Returns full string definition for message of type '<cmd_mover-response>"
  (cl:format cl:nil "string respuesta~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmd_mover-response)))
  "Returns full string definition for message of type 'cmd_mover-response"
  (cl:format cl:nil "string respuesta~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmd_mover-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'respuesta))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmd_mover-response>))
  "Converts a ROS message object to a list"
  (cl:list 'cmd_mover-response
    (cl:cons ':respuesta (respuesta msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'cmd_mover)))
  'cmd_mover-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'cmd_mover)))
  'cmd_mover-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd_mover)))
  "Returns string type for a service object of type '<cmd_mover>"
  "servicio/cmd_mover")