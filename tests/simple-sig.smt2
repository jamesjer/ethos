
(declare-const = (-> (! Type :var T :implicit) T T Bool))

(declare-const false Bool)
(declare-const not (-> Bool Bool))

(declare-rule eq-symm ((T Type) (x T) (y T))
  :premises ((= x y))
  :args ()
  :conclusion (= y x))
  
(declare-rule contra ((p Bool))
  :premises (p (not p))
  :args ()
  :conclusion false
)


(declare-const or (-> Bool Bool Bool) :right-assoc)

(program flip 
  ((T Type) (x T) (y T))
  (Bool) Bool
  (
  ((flip (= x y)) (= y x))
  )
)

(declare-rule eq-symm-flip 
  ((T Type) (x T) (y T) (eq Bool))
  :premises ((= x y))
  :args (eq)
  :requires (((flip (= x y)) eq))
  :conclusion eq
)
