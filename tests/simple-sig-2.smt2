
(declare-const = (-> (! Type :var T :implicit) T T Bool))

(program flip 
  ((T Type) (x T) (y T))
  (Bool) Bool
  (
  ((flip (= x y)) (= y x))
  )
)

(declare-rule eq-symm-flip 
  ((T Type) (x T) (y T))
  :premises ((= x y))
  :args ()
  :conclusion (flip (= x y))
)
