
(cl:in-package :asdf)

(defsystem "servicio-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "cmd_mover" :depends-on ("_package_cmd_mover"))
    (:file "_package_cmd_mover" :depends-on ("_package"))
  ))