;
; Copyright (c) 2008-2010 Stefan Krah. All rights reserved.
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
;
; 1. Redistributions of source code must retain the above copyright
;    notice, this list of conditions and the following disclaimer.
;
; 2. Redistributions in binary form must reproduce the above copyright
;    notice, this list of conditions and the following disclaimer in the
;    documentation and/or other materials provided with the distribution.
;
; THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
; ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
; ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
; FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
; OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
; HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
; LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
; OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
; SUCH DAMAGE.
;


(in-package "ACL2")

(include-book "arithmetic/top-with-meta" :dir :system)
(include-book "arithmetic-2/floor-mod/floor-mod" :dir :system)


;; =====================================================================
;;            Proofs for several functions in umodarith.h
;; =====================================================================


;; =====================================================================
;;                          Helper theorems
;; =====================================================================

(defthm elim-mod-m<x<2*m
  (implies (and (<= m x)
                (< x (* 2 m))
                (rationalp x) (rationalp m))
           (equal (mod x m)
                  (+ x (- m)))))

(defthm modaux-1a
  (implies (and (< x m) (< 0 x) (< 0 m)
                (rationalp x) (rationalp m))
           (equal (mod (- x) m)
                  (+ (- x) m))))

(defthm modaux-1b
  (implies (and (< (- x) m) (< x 0) (< 0 m)
                (rationalp x) (rationalp m))
           (equal (mod x m)
                  (+ x m)))
  :hints (("Goal" :use ((:instance modaux-1a
                                   (x (- x)))))))

(defthm modaux-1c
  (implies (and (< x m) (< 0 x) (< 0 m)
                (rationalp x) (rationalp m))
           (equal (mod x m)
                  x)))

(defthm modaux-2a
  (implies (and (< 0 b) (< b m)
		(natp x) (natp b) (natp m)
		(< (mod (+ b x) m) b))
	   (equal (mod (+ (- m) b x) m)
		  (+ (- m) b (mod x m)))))

(defthm modaux-2b
  (implies (and (< 0 b) (< b m)
		(natp x) (natp b) (natp m)
		(< (mod (+ b x) m) b))
	   (equal (mod (+ b x) m)
		  (+ (- m) b (mod x m))))
  :hints (("Goal" :use (modaux-2a))))

(defthm linear-mod-1
  (implies (and (< x m) (< b m)
                (natp x) (natp b)
                (rationalp m))
         (equal (< x (mod (+ (- b) x) m))
                (< x b)))
  :hints (("Goal" :use ((:instance modaux-1a
                                   (x (+ b (- x))))))))

(defthm linear-mod-2
  (implies (and (< 0 b) (< b m)
                (natp x) (natp b)
                (natp m))
           (equal (< (mod x m)
                     (mod (+ (- b) x) m))
                  (< (mod x m) b))))

(defthm linear-mod-3
  (implies (and (< x m) (< b m)
                (natp x) (natp b)
                (rationalp m))
           (equal (<= b (mod (+ b x) m))
                  (< (+ b x) m)))
  :hints (("Goal" :use ((:instance elim-mod-m<x<2*m
                                   (x (+ b x)))))))

(defthm modaux-2c
  (implies (and (< 0 b) (< b m)
                (natp x) (natp b) (natp m)
                (<= b (mod (+ b x) m)))
           (equal (mod (+ b x) m)
                  (+ b (mod x m))))
  :hints (("Subgoal *1/8''" :use (linear-mod-3))))

(defthm mod-m-b
  (implies (and (< 0 x) (< 0 b) (< 0 m)
                (< x b) (< b m)
                (natp x) (natp b) (natp m))
           (equal (mod (+ (mod (- x) m) b) m)
                  (mod (- x) b))))


;; =====================================================================
;;                          addmod, submod
;; =====================================================================

(defun addmod (a b base m)
  (let* ((s (mod (+ a b) m))
         (s (if (< s a) (mod (- s base) m) s))
         (s (if (>= s base) (mod (- s base) m) s)))
        s))

(defthmd addmod-correct
  (implies (and (< 0 base) (< base m)
		(< a base) (<= b base)
                (natp base) (natp m)
                (natp a) (natp b))
           (equal (addmod a b base m)
                  (mod (+ a b) base)))
  :hints (("Goal" :cases ((<= m (+ a b))))
          ("Subgoal 2.1'" :use ((:instance elim-mod-m<x<2*m
                                           (x (+ a b))
                                           (m base))))))


(defun submod (a b base m)
  (let* ((d (mod (- a b) m))
         (d (if (< a d) (mod (+ d base) m) d)))
        d))

(defthmd submod-aux1
  (implies (and (< a (mod (+ a (- b)) m))
                (< 0 m) (< a m) (<= b m)
                (natp m) (natp a) (natp b))
           (< a b))
  :rule-classes :forward-chaining)

(defthmd submod-aux2
  (implies (and (<= (mod (+ a (- b)) m) a)
                (< 0 m) (< a m) (< b m)
                (natp m) (natp a) (natp b))
           (<= b a))
  :rule-classes :forward-chaining)

(defthmd submod-correct
  (implies (and (< 0 base) (< base m)
		(< a base) (<= b base)
                (natp base) (natp m)
                (natp a) (natp b))
           (equal (submod a b base m)
                  (mod (- a b) base)))
  :hints (("Goal" :cases ((<= m (+ a b))))
          ("Subgoal 2.2" :use ((:instance submod-aux1)))
          ("Subgoal 2.2'''" :cases ((and (< 0 (+ a (- b) base))
                                         (< (+ a (- b) base) base))))
          ("Subgoal 2.1" :use ((:instance submod-aux2)))
          ("Subgoal 1.2" :use ((:instance submod-aux1)))
          ("Subgoal 1.1" :use ((:instance submod-aux2)))))


(defun submod-2 (a b base m)
  (let* ((d (mod (- a b) m))
         (d (if (< a b) (mod (+ d base) m) d)))
        d))

(defthm submod-2-correct
  (implies (and (< 0 base) (< base m)
		(< a base) (<= b base)
                (natp base) (natp m)
                (natp a) (natp b))
           (equal (submod-2 a b base m)
                  (mod (- a b) base)))
  :hints (("Subgoal 2'" :cases ((and (< 0 (+ a (- b) base))
                                     (< (+ a (- b) base) base))))))


;; =========================================================================
;;                      ANSI C arithmetic for uint64_t
;; =========================================================================

(defun add (a b)
  (mod (+ a b)
       (expt 2 64)))

(defun sub (a b)
  (mod (- a b)
       (expt 2 64)))

(defun << (w n)
  (mod (* w (expt 2 n))
       (expt 2 64)))

(defun >> (w n)
  (floor w (expt 2 n)))

;; join upper and lower half of a double word, yielding a 128 bit number
(defun join (dw)
  (+ (* (expt 2 64) (car dw)) (cdr dw)))

;; split a 128 bit number into upper and lower half, yielding a double word
(defun split (x)
  (cons (floor x (expt 2 64))
        (mod x (expt 2 64))))

;; join-split is the identity operation
(thm
  (implies (rationalp x)
           (equal (join (split x))
                  x)))


;; =========================================================================
;;                         ext-submod is correct
;; =========================================================================

; a < 2*m, b < 2*m
(defun ext-submod (a b m)
  (let* ((a (if (<= m a) (- a m) a))
         (b (if (<= m b) (- b m) b))
         (d (sub a b))
         (d (if (< a b) (add d m) d)))
        d))

; a < 2*m, b < 2*m
(defun ext-submod-2 (a b m)
  (let* ((a (mod a m))
         (b (mod b m))
         (d (sub a b))
         (d (if (< a b) (add d m) d)))
        d))

(defthmd ext-submod-ext-submod-2-equal
  (implies (and (< 0 m) (< m (expt 2 64))
		(< a (* 2 m)) (< b (* 2 m))
                (natp m) (natp a) (natp b))
           (equal (ext-submod a b m)
                  (ext-submod-2 a b m))))

(defthmd ext-submod-2-correct
  (implies (and (< 0 m) (< m (expt 2 64))
		(< a (* 2 m)) (< b (* 2 m))
                (natp m) (natp a) (natp b))
           (equal (ext-submod-2 a b m)
                  (mod (- a b) m))))



;; =============================================================================
;;                           Fast modular reduction
;; =============================================================================

;; These are the three primes used in the Number Theoretic Transform.
;; A fast modular reduction scheme exists for all of them.
(defmacro p1 ()
  (+ (expt 2 64) (- (expt 2 32)) 1))

(defmacro p2 ()
  (+ (expt 2 64) (- (expt 2 34)) 1))

(defmacro p3 ()
  (+ (expt 2 64) (- (expt 2 40)) 1))


;; reduce the double word number hi*2**64 + lo (mod p1)
(defun simple-mod-reduce-p1 (dw)
  (+ (* (expt 2 32) (car dw))
     (- (car dw)) (cdr dw)))

;; reduce the double word number hi*2**64 + lo (mod p2)
(defun simple-mod-reduce-p2 (dw)
  (+ (* (expt 2 34) (car dw))
     (- (car dw)) (cdr dw)))

;; reduce the double word number hi*2**64 + lo (mod p3)
(defun simple-mod-reduce-p3 (dw)
  (+ (* (expt 2 40) (car dw))
     (- (car dw)) (cdr dw)))


; ----------------------------------------------------------
;      The modular reductions given above are correct
; ----------------------------------------------------------

(defthm congruence-p1-aux
  (equal (* (expt 2 64) hi)
         (+ (* (p1) hi)
            (* (expt 2 32) hi)
            (- hi))))

(defthmd congruence-p2-aux
  (equal (* (expt 2 64) hi)
         (+ (* (p2) hi)
            (* (expt 2 34) hi)
            (- hi))))

(defthmd congruence-p3-aux
  (equal (* (expt 2 64) hi)
         (+ (* (p3) hi)
            (* (expt 2 40) hi)
            (- hi))))

(defthmd mod-augment
  (implies (and (rationalp x)
                (rationalp y)
                (rationalp m))
           (equal (mod (+ x y) m)
                  (mod (+ x (mod y m)) m))))

(defthmd simple-mod-reduce-p1-congruent
  (implies (and (integerp (car dw))
                (integerp (cdr dw)))
           (equal (mod (simple-mod-reduce-p1 dw) (p1))
                  (mod (join dw) (p1))))
  :hints (("Goal''" :use ((:instance congruence-p1-aux
                                     (hi (car dw)))
                          (:instance mod-augment
                                     (m (p1))
                                     (x (+ (- (car dw)) (cdr dw) (* (expt 2 32) (car dw))))
                                     (y (* (p1) (car dw))))))))

(defthmd simple-mod-reduce-p2-congruent
  (implies (and (integerp (car dw))
                (integerp (cdr dw)))
           (equal (mod (simple-mod-reduce-p2 dw) (p2))
                  (mod (join dw) (p2))))
  :hints (("Goal''" :use ((:instance congruence-p2-aux
                                     (hi (car dw)))
                          (:instance mod-augment
                                     (m (p2))
                                     (x (+ (- (car dw)) (cdr dw) (* (expt 2 34) (car dw))))
                                     (y (* (p2) (car dw))))))))

(defthmd simple-mod-reduce-p3-congruent
  (implies (and (integerp (car dw))
                (integerp (cdr dw)))
           (equal (mod (simple-mod-reduce-p3 dw) (p3))
                  (mod (join dw) (p3))))
  :hints (("Goal''" :use ((:instance congruence-p3-aux
                                     (hi (car dw)))
                          (:instance mod-augment
                                     (m (p3))
                                     (x (+ (- (car dw)) (cdr dw) (* (expt 2 40) (car dw))))
                                     (y (* (p3) (car dw))))))))


; ---------------------------------------------------------------------
;  We need a number less than 2*p, so that we can use the trick from
;  elim-mod-m<x<2*m for the final reduction.
;  For p1, two modular reductions are sufficient, for p2 and p3 three.
; ---------------------------------------------------------------------

;; p1: the first reduction is less than 2**96
(defthmd simple-mod-reduce-p1-<-2**96
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (natp (car dw)) (natp (cdr dw)))
           (< (simple-mod-reduce-p1 dw)
              (expt 2 96))))

;; p1: the second reduction is less than 2*p1
(defthmd simple-mod-reduce-p1-<-2*p1
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (< (join dw) (expt 2 96))
                (natp (car dw)) (natp (cdr dw)))
           (< (simple-mod-reduce-p1 dw)
              (* 2 (p1)))))


;; p2: the first reduction is less than 2**98
(defthmd simple-mod-reduce-p2-<-2**98
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (natp (car dw)) (natp (cdr dw)))
           (< (simple-mod-reduce-p2 dw)
              (expt 2 98))))

;; p2: the second reduction is less than 2**69
(defthmd simple-mod-reduce-p2-<-2*69
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (< (join dw) (expt 2 98))
                (natp (car dw)) (natp (cdr dw)))
           (< (simple-mod-reduce-p2 dw)
              (expt 2 69))))

;; p3: the third reduction is less than 2*p2
(defthmd simple-mod-reduce-p2-<-2*p2
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (< (join dw) (expt 2 69))
                (natp (car dw)) (natp (cdr dw)))
           (< (simple-mod-reduce-p2 dw)
              (* 2 (p2)))))


;; p3: the first reduction is less than 2**104
(defthmd simple-mod-reduce-p3-<-2**104
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (natp (car dw)) (natp (cdr dw)))
           (< (simple-mod-reduce-p3 dw)
              (expt 2 104))))

;; p3: the second reduction is less than 2**81
(defthmd simple-mod-reduce-p3-<-2**81
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (< (join dw) (expt 2 104))
                (natp (car dw)) (natp (cdr dw)))
           (< (simple-mod-reduce-p3 dw)
              (expt 2 81))))

;; p3: the third reduction is less than 2*p3
(defthmd simple-mod-reduce-p3-<-2*p3
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (< (join dw) (expt 2 81))
                (natp (car dw)) (natp (cdr dw)))
           (< (simple-mod-reduce-p3 dw)
              (* 2 (p3)))))


; -------------------------------------------------------------------------
;      The simple modular reductions, adapted for compiler friendly C
; -------------------------------------------------------------------------

(defun mod-reduce-p1 (dw)
  (let* ((rh (car dw))
         (rl (cdr dw))
         (a rh)
         (tmp (<< rh 32))
         (rh (>> rh 32))
         (tmp (add rl tmp))
         (rh (if (< tmp rl) (1+ rh) rh))
         (rl (sub tmp a))
         (rh (if (< tmp rl) (1- rh) rh)))
        (cons rh rl)))

(defun mod-reduce-p2 (dw)
  (let* ((rh (car dw))
         (rl (cdr dw))
         (a rh)
         (tmp (<< rh 34))
         (rh (>> rh 30))
         (tmp (add rl tmp))
         (rh (if (< tmp rl) (1+ rh) rh))
         (rl (sub tmp a))
         (rh (if (< tmp rl) (1- rh) rh)))
        (cons rh rl)))

(defun mod-reduce-p3 (dw)
  (let* ((rh (car dw))
         (rl (cdr dw))
         (a rh)
         (tmp (<< rh 40))
         (rh (>> rh 24))
         (tmp (add rl tmp))
         (rh (if (< tmp rl) (1+ rh) rh))
         (rl (sub tmp a))
         (rh (if (< tmp rl) (1- rh) rh)))
        (cons rh rl)))


; -------------------------------------------------------------------------
;     The compiler friendly versions are equal to the simple versions
; -------------------------------------------------------------------------

(in-theory (disable modaux-2a modaux-2b modaux-2c))
(in-theory (disable modaux-1a modaux-1b modaux-1c))

(defthm mod-reduce-p1==simple-mod-reduce-p1
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (natp (car dw)) (natp (cdr dw)))
           (equal (join (mod-reduce-p1 dw))
                  (simple-mod-reduce-p1 dw)))
  :hints (("Goal" :cases ((< 0 (car dw))))
          ("Subgoal 1.2.2'" :use ((:instance modaux-1a
                                             (m (expt 2 64))
                                             (x (+ (car dw)
                                                   (- (mod (+ (cdr dw) (* (expt 2 32) (car dw)))
                                                           (expt 2 64))))))
                                  (:instance modaux-2b
                                             (m (expt 2 64))
                                             (x (* (expt 2 32) (car dw)))
                                             (b (cdr dw)))))
          ("Subgoal 1.2.1'" :use ((:instance modaux-1c
                                             (m (expt 2 64))
                                             (x (+ (- (car dw))
                                                   (mod (+ (cdr dw) (* (expt 2 32) (car dw)))
                                                        (expt 2 64)))))
                                  (:instance modaux-2b
                                             (m (expt 2 64))
                                             (x (* (expt 2 32) (car dw)))
                                             (b (cdr dw)))))
          ("Subgoal 1.1.2'" :use ((:instance modaux-1a
                                             (m (expt 2 64))
                                             (x (+ (car dw)
                                                (- (mod (+ (cdr dw) (* (expt 2 32) (car dw)))
                                                        (expt 2 64))))))
                                  (:instance modaux-2c
                                             (m (expt 2 64))
                                             (x (* (expt 2 32) (car dw)))
                                             (b (cdr dw)))))
          ("Subgoal 1.1.1'" :use ((:instance modaux-1c
                                             (m (expt 2 64))
                                             (x (+ (- (car dw))
                                                   (mod (+ (cdr dw) (* (expt 2 32) (car dw)))
                                                        (expt 2 64)))))
                                  (:instance modaux-2c
                                             (m (expt 2 64))
                                             (x (* (expt 2 32) (car dw)))
                                             (b (cdr dw)))))))


(defthm mod-reduce-p2==simple-mod-reduce-p2
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (natp (car dw)) (natp (cdr dw)))
           (equal (join (mod-reduce-p2 dw))
                  (simple-mod-reduce-p2 dw)))
  :hints (("Goal" :cases ((< 0 (car dw))))
          ("Subgoal 1.2.2'" :use ((:instance modaux-1a
                                             (m (expt 2 64))
                                             (x (+ (car dw)
                                                   (- (mod (+ (cdr dw) (* (expt 2 34) (car dw)))
                                                           (expt 2 64))))))
                                  (:instance modaux-2b
                                             (m (expt 2 64))
                                             (x (* (expt 2 34) (car dw)))
                                             (b (cdr dw)))))
          ("Subgoal 1.2.1'" :use ((:instance modaux-1c
                                             (m (expt 2 64))
                                             (x (+ (- (car dw))
                                                   (mod (+ (cdr dw) (* (expt 2 34) (car dw)))
                                                        (expt 2 64)))))
                                  (:instance modaux-2b
                                             (m (expt 2 64))
                                             (x (* (expt 2 34) (car dw)))
                                             (b (cdr dw)))))
          ("Subgoal 1.1.2'" :use ((:instance modaux-1a
                                             (m (expt 2 64))
                                             (x (+ (car dw)
                                                   (- (mod (+ (cdr dw) (* (expt 2 34) (car dw)))
                                                           (expt 2 64))))))
                                  (:instance modaux-2c
                                             (m (expt 2 64))
                                             (x (* (expt 2 34) a))
                                             (b (cdr dw)))))
          ("Subgoal 1.1.1'" :use ((:instance modaux-1c
                                             (m (expt 2 64))
                                             (x (+ (- (car dw))
                                                   (mod (+ (cdr dw) (* (expt 2 34) (car dw)))
                                                        (expt 2 64)))))
                                  (:instance modaux-2c
                                             (m (expt 2 64))
                                             (x (* (expt 2 34) (car dw)))
                                             (b (cdr dw)))))))

(defthm mod-reduce-p3==simple-mod-reduce-p3
  (implies (and (< (car dw) (expt 2 64))
                (< (cdr dw) (expt 2 64))
                (natp (car dw)) (natp (cdr dw)))
           (equal (join (mod-reduce-p3 dw))
                  (simple-mod-reduce-p3 dw)))
  :hints (("Goal" :cases ((< 0 (car dw))))
          ("Subgoal 1.2.2'" :use ((:instance modaux-1a
                                             (m (expt 2 64))
                                             (x (+ (car dw)
                                                   (- (mod (+ (cdr dw) (* (expt 2 40) (car dw)))
                                                      (expt 2 64))))))
                                  (:instance modaux-2b
                                             (m (expt 2 64))
                                             (x (* (expt 2 40) (car dw)))
                                             (b (cdr dw)))))
          ("Subgoal 1.2.1'" :use ((:instance modaux-1c
                                             (m (expt 2 64))
                                             (x (+ (- (car dw))
                                                   (mod (+ (cdr dw) (* (expt 2 40) (car dw)))
                                                          (expt 2 64)))))
                                  (:instance modaux-2b
                                             (m (expt 2 64))
                                             (x (* (expt 2 40) (car dw)))
                                             (b (cdr dw)))))
          ("Subgoal 1.1.2'" :use ((:instance modaux-1a
                                             (m (expt 2 64))
                                             (x (+ (car dw)
                                                   (- (mod (+ (cdr dw) (* (expt 2 40) (car dw)))
                                                           (expt 2 64))))))
                                  (:instance modaux-2c
                                             (m (expt 2 64))
                                             (x (* (expt 2 40) (car dw)))
                                             (b (cdr dw)))))
          ("Subgoal 1.1.1'" :use ((:instance modaux-1c
                                             (m (expt 2 64))
                                             (x (+ (- (car dw))
                                                   (mod (+ (cdr dw) (* (expt 2 40) (car dw)))
                                                        (expt 2 64)))))
                                  (:instance modaux-2c
                                             (m (expt 2 64))
                                             (x (* (expt 2 40) (car dw)))
                                             (b (cdr dw)))))))



