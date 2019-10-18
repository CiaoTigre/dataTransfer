
(cl:in-package :asdf)

(defsystem "msgfile-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Core2Voice" :depends-on ("_package_Core2Voice"))
    (:file "_package_Core2Voice" :depends-on ("_package"))
    (:file "VoiceOrder" :depends-on ("_package_VoiceOrder"))
    (:file "_package_VoiceOrder" :depends-on ("_package"))
  ))