; Auto-generated. Do not edit!


(cl:in-package rosspawn-srv)


;//! \htmlinclude ListLoaded-request.msg.html

(cl:defclass <ListLoaded-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ListLoaded-request (<ListLoaded-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ListLoaded-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ListLoaded-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosspawn-srv:<ListLoaded-request> is deprecated: use rosspawn-srv:ListLoaded-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ListLoaded-request>) ostream)
  "Serializes a message object of type '<ListLoaded-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ListLoaded-request>) istream)
  "Deserializes a message object of type '<ListLoaded-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ListLoaded-request>)))
  "Returns string type for a service object of type '<ListLoaded-request>"
  "rosspawn/ListLoadedRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ListLoaded-request)))
  "Returns string type for a service object of type 'ListLoaded-request"
  "rosspawn/ListLoadedRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ListLoaded-request>)))
  "Returns md5sum for a message object of type '<ListLoaded-request>"
  "3d07bfda1268b4f76b16b7ba8a82665d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ListLoaded-request)))
  "Returns md5sum for a message object of type 'ListLoaded-request"
  "3d07bfda1268b4f76b16b7ba8a82665d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ListLoaded-request>)))
  "Returns full string definition for message of type '<ListLoaded-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ListLoaded-request)))
  "Returns full string definition for message of type 'ListLoaded-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ListLoaded-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ListLoaded-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ListLoaded-request
))
;//! \htmlinclude ListLoaded-response.msg.html

(cl:defclass <ListLoaded-response> (roslisp-msg-protocol:ros-message)
  ((nodes
    :reader nodes
    :initarg :nodes
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass ListLoaded-response (<ListLoaded-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ListLoaded-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ListLoaded-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosspawn-srv:<ListLoaded-response> is deprecated: use rosspawn-srv:ListLoaded-response instead.")))

(cl:ensure-generic-function 'nodes-val :lambda-list '(m))
(cl:defmethod nodes-val ((m <ListLoaded-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosspawn-srv:nodes-val is deprecated.  Use rosspawn-srv:nodes instead.")
  (nodes m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ListLoaded-response>) ostream)
  "Serializes a message object of type '<ListLoaded-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'nodes))))
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
   (cl:slot-value msg 'nodes))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ListLoaded-response>) istream)
  "Deserializes a message object of type '<ListLoaded-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'nodes) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'nodes)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ListLoaded-response>)))
  "Returns string type for a service object of type '<ListLoaded-response>"
  "rosspawn/ListLoadedResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ListLoaded-response)))
  "Returns string type for a service object of type 'ListLoaded-response"
  "rosspawn/ListLoadedResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ListLoaded-response>)))
  "Returns md5sum for a message object of type '<ListLoaded-response>"
  "3d07bfda1268b4f76b16b7ba8a82665d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ListLoaded-response)))
  "Returns md5sum for a message object of type 'ListLoaded-response"
  "3d07bfda1268b4f76b16b7ba8a82665d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ListLoaded-response>)))
  "Returns full string definition for message of type '<ListLoaded-response>"
  (cl:format cl:nil "string[] nodes~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ListLoaded-response)))
  "Returns full string definition for message of type 'ListLoaded-response"
  (cl:format cl:nil "string[] nodes~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ListLoaded-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'nodes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ListLoaded-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ListLoaded-response
    (cl:cons ':nodes (nodes msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ListLoaded)))
  'ListLoaded-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ListLoaded)))
  'ListLoaded-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ListLoaded)))
  "Returns string type for a service object of type '<ListLoaded>"
  "rosspawn/ListLoaded")