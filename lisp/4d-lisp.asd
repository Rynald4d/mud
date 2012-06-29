(require 'asdf)

(asdf:defsystem 4d-lisp
    :components ((:file packages)
		 (:file functions :depends-on ("packages"))
		 (:file util :depends-on ("packages"))
		 (:file init :depends-on ("packages" "util"))
		 (:file hooks :depends-on ("packages" "util"))
		 (:file helpers :depends-on ("packages" "util"))
		 (:file command :depends-on ("packages" "util"))
		 (:file script :depends-on ("packages" "util"))
		 (:file character :depends-on ("packages" "command" "util"))
		 (:file world :depends-on ("packages" "util"))
		 (:file zones :depends-on ("packages" "util"))
		 (:file object :depends-on ("packages" "util"))
		 (:file object-types :depends-on ("packages" "util"))
		 (:file clans :depends-on ("packages" "util"))
		 (:file build-tools :depends-on ("packages" "command" "util"))
		 (:file cowsay :depends-on ("packages" "command" "util"))))
		 