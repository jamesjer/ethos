(declare-sort Int 0)
(declare-consts <numeral> Int)

(declare-const = (-> (! Type :var T :implicit) T T Bool))
(declare-const + (-> Int Int Int))
(declare-const - (-> Int Int Int))
(declare-const < (-> Int Int Bool))
(declare-const <= (-> Int Int Bool))

(program arith.eval ((S Type) (a Int) (b Int) (z S))
    (S) S
    (
      ((arith.eval (= a b))  (alf.is_eq (arith.eval a) (arith.eval b)))
      ((arith.eval (< a b))  (alf.is_neg (arith.eval (- a b))))
      ((arith.eval (<= a b)) (let ((x (arith.eval (- a b)))) 
                                 (alf.or (alf.is_neg x) (alf.is_zero x))))
      ((arith.eval (+ a b))  (alf.add (arith.eval a) (arith.eval b)))
      ((arith.eval (- a b))  (alf.add (arith.eval a) (alf.neg (arith.eval b))))
      ((arith.eval z)        z)
    )
)

(declare-const BitVec 
  (-> Int Type))

(declare-consts <binary> (BitVec (alf.len alf.self)))
  
(declare-const bvadd (->
  (! Int :var n :implicit)
  (BitVec n)
  (BitVec n)
  (BitVec n)))

(declare-const bvextract (->
  (! Int :var n :implicit)
  (! Int :var h :requires ((arith.eval (<= 0 h)) true) :requires ((arith.eval (< h n)) true))
  (! Int :var l :requires ((arith.eval (<= 0 l)) true) :requires ((arith.eval (< l h)) true))
  (BitVec n)
  (BitVec (arith.eval (+ (- h l) 1)))))

(declare-const bvconcat (->
  (! Int :var n :implicit)
  (! Int :var m :implicit)
  (BitVec n)
  (BitVec m)
  (BitVec (arith.eval (+ n m)))))

(program bv.eval ((T Type) (U Type) (S Type) (a T) (b U) (z S) (h Int) (l Int))
    (S) S
    (
      ((bv.eval (= a b))           (alf.is_eq (bv.eval a) (bv.eval b)))
      ((bv.eval (bvadd a b))       (alf.add (bv.eval a) (bv.eval b)))
      ((bv.eval (bvconcat a b))    (alf.concat (bv.eval a) (bv.eval b)))
      ((bv.eval (bvextract h l a)) (alf.extract h l (bv.eval a)))
      ((bv.eval z)                 z)
    )
)

(declare-rule eval
   ((T Type) (U Type) (a T) (b U))
   :premises ()
   :args (a b)
   :requires (((bv.eval a) (bv.eval b)))
   :conclusion (= a b)
)

(declare-const x (BitVec 3))

(step a2 (= #b0010 (bvextract 3 0 #b11010010)) :rule eval :premises (#b0010 (bvextract 3 0 #b11010010)))
(step a3 (= #b000 (bvadd #b111 #b001)) :rule eval :premises (#b000 (bvadd #b111 #b001)))
