; Auto-generated. Do not edit!


(cl:in-package msgfile-msg)


;//! \htmlinclude VoiceOrder.msg.html

(cl:defclass <VoiceOrder> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (emotion
    :reader emotion
    :initarg :emotion
    :type cl:string
    :initform "")
   (DrinkName
    :reader DrinkName
    :initarg :DrinkName
    :type cl:string
    :initform "")
   (CupNum
    :reader CupNum
    :initarg :CupNum
    :type cl:string
    :initform "")
   (Temp
    :reader Temp
    :initarg :Temp
    :type cl:string
    :initform "")
   (OrderFinish
    :reader OrderFinish
    :initarg :OrderFinish
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass VoiceOrder (<VoiceOrder>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <VoiceOrder>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'VoiceOrder)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msgfile-msg:<VoiceOrder> is deprecated: use msgfile-msg:VoiceOrder instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <VoiceOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgfile-msg:header-val is deprecated.  Use msgfile-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <VoiceOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgfile-msg:name-val is deprecated.  Use msgfile-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'emotion-val :lambda-list '(m))
(cl:defmethod emotion-val ((m <VoiceOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgfile-msg:emotion-val is deprecated.  Use msgfile-msg:emotion instead.")
  (emotion m))

(cl:ensure-generic-function 'DrinkName-val :lambda-list '(m))
(cl:defmethod DrinkName-val ((m <VoiceOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgfile-msg:DrinkName-val is deprecated.  Use msgfile-msg:DrinkName instead.")
  (DrinkName m))

(cl:ensure-generic-function 'CupNum-val :lambda-list '(m))
(cl:defmethod CupNum-val ((m <VoiceOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgfile-msg:CupNum-val is deprecated.  Use msgfile-msg:CupNum instead.")
  (CupNum m))

(cl:ensure-generic-function 'Temp-val :lambda-list '(m))
(cl:defmethod Temp-val ((m <VoiceOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgfile-msg:Temp-val is deprecated.  Use msgfile-msg:Temp instead.")
  (Temp m))

(cl:ensure-generic-function 'OrderFinish-val :lambda-list '(m))
(cl:defmethod OrderFinish-val ((m <VoiceOrder>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msgfile-msg:OrderFinish-val is deprecated.  Use msgfile-msg:OrderFinish instead.")
  (OrderFinish m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <VoiceOrder>) ostream)
  "Serializes a message object of type '<VoiceOrder>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'emotion))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'emotion))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'DrinkName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'DrinkName))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'CupNum))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'CupNum))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'Temp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'Temp))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'OrderFinish) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <VoiceOrder>) istream)
  "Deserializes a message object of type '<VoiceOrder>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'emotion) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'emotion) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'DrinkName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'DrinkName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'CupNum) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'CupNum) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Temp) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'Temp) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'OrderFinish) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<VoiceOrder>)))
  "Returns string type for a message object of type '<VoiceOrder>"
  "msgfile/VoiceOrder")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'VoiceOrder)))
  "Returns string type for a message object of type 'VoiceOrder"
  "msgfile/VoiceOrder")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<VoiceOrder>)))
  "Returns md5sum for a message object of type '<VoiceOrder>"
  "f3495cb493dec155ce56f80a0b3b1959")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'VoiceOrder)))
  "Returns md5sum for a message object of type 'VoiceOrder"
  "f3495cb493dec155ce56f80a0b3b1959")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<VoiceOrder>)))
  "Returns full string definition for message of type '<VoiceOrder>"
  (cl:format cl:nil "Header header ~%string name~%string emotion~%string DrinkName~%string CupNum~%string Temp~%bool OrderFinish~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'VoiceOrder)))
  "Returns full string definition for message of type 'VoiceOrder"
  (cl:format cl:nil "Header header ~%string name~%string emotion~%string DrinkName~%string CupNum~%string Temp~%bool OrderFinish~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <VoiceOrder>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'name))
     4 (cl:length (cl:slot-value msg 'emotion))
     4 (cl:length (cl:slot-value msg 'DrinkName))
     4 (cl:length (cl:slot-value msg 'CupNum))
     4 (cl:length (cl:slot-value msg 'Temp))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <VoiceOrder>))
  "Converts a ROS message object to a list"
  (cl:list 'VoiceOrder
    (cl:cons ':header (header msg))
    (cl:cons ':name (name msg))
    (cl:cons ':emotion (emotion msg))
    (cl:cons ':DrinkName (DrinkName msg))
    (cl:cons ':CupNum (CupNum msg))
    (cl:cons ':Temp (Temp msg))
    (cl:cons ':OrderFinish (OrderFinish msg))
))
