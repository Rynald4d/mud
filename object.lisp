(eval-when (:compile-toplevel)
  (unless (boundp '*started*)
    (load "util.lisp")))
(ffi:clines "#include \"lisp-internal.h\"")

(in-package :4d)

(defclass obj () ())

(defclass object-prototype (obj)
  ((vnum :initarg :vnum :reader vnum)))

(defmethod print-object ((obj obj) s)
  (format s "#<~a ~d: ~a>"
	  (string-downcase (symbol-name (type-of obj)))
	  (vnum obj)
	  (short-description obj)))

(defmacro object-field (object name type)
  (declare (type symbol type)
	   (type string name))
  `(oneliner ((pointer ,object)) (:pointer-void) ,type
	     ,(format nil "((struct obj_data *)#0)->~a" name)))

(defmethod name ((object obj))
  (object-field object "name" :cstring))

(defmethod short-description ((object obj))
  (object-field object "short_description" :cstring))

(defclass object-instance (obj)
  ((id :initarg :id :reader id)))

(defun obj-rnum-to-vnum (rnum)
  (oneliner (rnum) (:int) :int
	    "obj_index[#0].vnum"))

(defmethod vnum ((object object-instance))
  (object-field object "item_number" :int))

(defun obj-vnum-to-rnum (vnum)
  (oneliner (vnum) (:int) :int
	    "obj_vTor[#0]"))

(defmethod rnum ((object object-prototype))
  (obj-vnum-to-rnum (vnum object)))

(defmethod pointer ((object object-prototype))
  (oneliner ((rnum object)) (:int) :pointer-void
	    "&obj_proto[#0]"))

(defmethod pointer ((object object-instance))
  (oneliner ((id object)) (:int) :pointer-void
	    "object_list[#0]"))

(define-condition object-prototype-not-found (error) ((vnum :initarg :vnum :reader vnum)))

(defmethod object-prototype ((vnum integer))
  (let ((rnum (obj-vnum-to-rnum vnum)))
    (if (= 0 rnum)
	(error 'object-prototype-not-found :vnum vnum)
	(make-instance 'object-prototype :vnum vnum))))

(defun object-prototype-by-rnum (rnum)
  (make-instance 'object-prototype
		 :vnum (obj-rnum-to-vnum rnum)))

(defun all-objects ()
  (let ((objects nil))
    (ffi:c-inline (#'(lambda (id)
		       (push (make-instance 'object-instance :id id) objects))) (:function) :void
"for (olt_it ob = object_list.begin();ob != object_list.end(); ob++)
cl_funcall(2, #0, MAKE_FIXNUM(GET_ID(ob->second)));")
    (reverse objects)))