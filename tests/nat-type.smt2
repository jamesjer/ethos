(declare-sort Nat 0)

(declare-consts <numeral> (! Nat :requires ((alf.is_neg alf.self) false)))

(declare-fun f (Nat) Bool)

(assume @p0 (f 0))
;(assume @p0 (f (alf.neg 1)))
