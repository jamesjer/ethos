
(include "./simple-sig-2.smt2")

(declare-sort Int 0)
(declare-fun a () Int)
(declare-fun b () Int)
(assume a1 (= a b))
(step a2 (= b a) :rule eq-symm-flip :premises (a1))
