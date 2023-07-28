(include "./substitution.smt2")

(declare-const a Bool)
(declare-const b Bool)
(declare-const c Bool)
(assume a1 (or a (and a b c a b c) b c (and (not c) b) (and (not a) a) b))
(assume a2 (= a b))
(step a3 (or b (and b b c b b c) b c (and (not c) b) (and (not b) b) b) :rule eq-subs :premises (a1 a2))
