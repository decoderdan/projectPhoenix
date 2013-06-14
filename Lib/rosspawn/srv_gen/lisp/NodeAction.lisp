; Auto-generated. Do not edit!


(cl:in-package rosspawn-srv)


;//! \htmlinclude NodeAction-request.msg.html

(cl:defclass <NodeAction-request> (roslisp-msg-protocol:ros-message)
  ((node_file_name
    :reader node_file_name
    :initarg :node_file_name
    :type cl:string
    :initform ""))
)

(cl:defclass NodeAction-request (<NodeAction-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NodeAction-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NodeAction-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosspawn-srv:<NodeAction-request> is deprecated: use rosspawn-srv:NodeAction-request instead.")))

(cl:ensure-generic-function 'node_file_name-val :lambda-list '(m))
(cl:defmethod node_file_name-val ((m <NodeAction-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosspawn-srv:node_file_name-val is deprecated.  Use rosspawn-srv:node_file_name instead.")
  (node_file_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NodeAction-request>) ostream)
  "Serializes a message object of type '<NodeAction-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'node_file_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'node_file_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NodeAction-request>) istream)
  "Deserializes a message object of type '<NodeAction-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'node_file_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'node_file_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NodeAction-request>)))
  "Returns string type for a service object of type '<NodeAction-request>"
  "rosspawn/NodeActionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NodeAction-request)))
  "Returns string type for a service object of type 'NodeAction-request"
  "rosspawn/NodeActionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NodeAction-request>)))
  "Returns md5sum for a message object of type '<NodeAction-request>"
  "014964366824ce564884dfdaff1faba6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NodeAction-request)))
  "Returns md5sum for a message object of type 'NodeAction-request"
  "014964366824ce564884dfdaff1faba6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NodeAction-request>)))
  "Returns full string definition for message of type '<NodeAction-request>"
  (cl:format cl:nil "string node_file_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NodeAction-request)))
  "Returns full string definition for message of type 'NodeAction-request"
  (cl:format cl:nil "string node_file_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NodeAction-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'node_file_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NodeAction-request>))
  "Converts a ROS message object to a list"
  (cl:list 'NodeAction-request
    (cl:cons ':node_file_name (node_file_name msg))
))
;//! \htmlinclude NodeAction-response.msg.html

(cl:defclass <NodeAction-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass NodeAction-response (<NodeAction-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NodeAction-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NodeAction-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosspawn-srv:<NodeAction-response> is deprecated: use rosspawn-srv:NodeAction-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NodeAction-response>) ostream)
  "Serializes a message object of type '<NodeAction-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NodeAction-response>) istream)
  "Deserializes a message object of type '<NodeAction-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NodeAction-response>)))
  "Returns string type for a service object of type '<NodeAction-response>"
  "rosspawn/NodeActionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NodeAction-response)))
  "Returns string type for a service object of type 'NodeAction-response"
  "rosspawn/NodeActionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NodeAction-response>)))
  "Returns md5sum for a message object of type '<NodeAction-response>"
  "014964366824ce564884dfdaff1faba6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NodeAction-response)))
  "Returns md5sum for a message object of type 'NodeAction-response"
  "014964366824ce564884dfdaff1faba6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NodeAction-response>)))
  "Returns full string definition for message of type '<NodeAction-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NodeAction-response)))
  "Returns full string definition for message of type 'NodeAction-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NodeAction-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NodeAction-response>))
  "Converts a ROS message object to a list"
  (cl:list 'NodeAction-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'NodeAction)))
  'NodeAction-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'NodeAction)))
  'NodeAction-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NodeAction)))
  "Returns string type for a service object of type '<NodeAction>"
  "rosspawn/NodeAction")