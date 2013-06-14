
(cl:in-package :asdf)

(defsystem "rosspawn-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "NodeAction" :depends-on ("_package_NodeAction"))
    (:file "_package_NodeAction" :depends-on ("_package"))
    (:file "ListLoaded" :depends-on ("_package_ListLoaded"))
    (:file "_package_ListLoaded" :depends-on ("_package"))
    (:file "ListAvailable" :depends-on ("_package_ListAvailable"))
    (:file "_package_ListAvailable" :depends-on ("_package"))
  ))