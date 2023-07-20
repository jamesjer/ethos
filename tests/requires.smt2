
(declare-sort Int 0)

(declare-const and (-> Bool Bool Bool))
(declare-const i0 Int)
(declare-const i1 Int)

(program select (Int Bool) Bool
  ((f1 Bool) (f2 Bool))
  ; cases
  (
  ((select i0 (and f1 f2)) f1)
  ((select i1 (and f1 f2)) f2)
  )
)

(declare-rule and_elim ((f Bool) (g Bool) (i Int))
   :premises ((and f g))
   :args (i)
   :requires ((i i0))     ; dummy, can only be used if i==i0
   :conclusion (select i f)
)


(declare-fun P () Bool)
(declare-fun Q () Bool)
(assume a0 (and P Q))
(step a1 (select i0 P) :rule and_elim :premises (a0) :args (i0))
