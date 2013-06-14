; Auto-generated. Do not edit!


(cl:in-package rosspawn-srv)


;//! \htmlinclude ListAvailable-request.msg.html

(cl:defclass <ListAvailable-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ListAvailable-request (<ListAvailable-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ListAvailable-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ListAvailable-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosspawn-srv:<ListAvailable-request> is deprecated: use rosspawn-srv:ListAvailable-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ListAvailable-request>) ostream)
  "Serializes a message object of type '<ListAvailable-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ListAvailable-request>) istream)
  "Deserializes a message object of type '<ListAvailable-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ListAvailable-request>)))
  "Returns string type for a service object of type '<ListAvailable-request>"
  "rosspawn/ListAvailableRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ListAvailable-request)))
  "Returns string type for a service object of type 'ListAvailable-request"
  "rosspawn/ListAvailableRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ListAvailable-request>)))
  "Returns md5sum for a message object of type '<ListAvailable-request>"
  "fab8de62afa968c87d19b27e6526e661")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ListAvailable-request)))
  "Returns md5sum for a message object of type 'ListAvailable-request"
  "fab8de62afa968c87d19b27e6526e661")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ListAvailable-request>)))
  "Returns full string definition for message of type '<ListAvailable-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ListAvailable-request)))
  "Returns full string definition for message of type 'ListAvailable-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ListAvailable-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ListAvailable-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ListAvailable-request
))
;//! \htmlinclude ListAvailable-response.msg.html

(cl:defclass <ListAvailable-response> (roslisp-msg-protocol:ros-message)
  ((bin_files
    :reader bin_files
    :initarg :bin_files
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass ListAvailable-response (<ListAvailable-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ListAvailable-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ListAvailable-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosspawn-srv:<ListAvailable-response> is deprecated: use rosspawn-srv:ListAvailable-response instead.")))

(cl:ensure-generic-function 'bin_files-val :lambda-list '(m))
(cl:defmethod bin_files-val ((m <ListAvailable-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosspawn-srv:bin_files-val is deprecated.  Use rosspawn-srv:bin_files instead.")
  (bin_files m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ListAvailable-response>) ostream)
  "Serializes a message object of type '<ListAvailable-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'bin_files))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'bin_files))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ListAvailable-response>) istream)
  "Deserializes a message object of type '<ListAvailable-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'bin_files) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'bin_files)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ListAvailable-response>)))
  "Returns string type for a service object of type '<ListAvailable-response>"
  "rosspawn/ListAvailableResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ListAvailable-response)))
  "Returns string type for a service object of type 'ListAvailable-response"
  "rosspawn/ListAvailableResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ListAvailable-response>)))
  "Returns md5sum for a message object of type '<ListAvailable-response>"
  "fab8de62afa968c87d19b27e6526e661")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ListAvailable-response)))
  "Returns md5sum for a message object of type 'ListAvailable-response"
  "fab8de62afa968c87d19b27e6526e661")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ListAvailable-response>)))
  "Returns full string definition for message of type '<ListAvailable-response>"
  (cl:format cl:nil "string[] bin_files~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ListAvailable-response)))
  "Returns full string definition for message of type 'ListAvailable-response"
  (cl:format cl:nil "string[] bin_files~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ListAvailable-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'bin_files) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ListAvailable-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ListAvailable-response
    (cl:cons ':bin_files (bin_files msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ListAvailable)))
  'ListAvailable-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ListAvailable)))
  'ListAvailable-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ListAvailable)))
  "Returns string type for a service object of type '<ListAvailable>"
  "rosspawn/ListAvailable")