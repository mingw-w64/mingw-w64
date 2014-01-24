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


;; =====================================================================
;;                Proof for a section in mpdecimal.c
;; =====================================================================

;; _mpd_check_exp()

; adjexp < emin, exp >= etiny
(defthm subnormal-fits-prec
  (implies (and (integerp exp) (integerp digits)
                (integerp emin) (integerp prec)
                (integerp shift)
                (= adjexp (+ exp digits -1))
                (= etiny (+ emin (- prec) 1))
                (< adjexp emin)
                (>= exp etiny))
            (< digits prec)))

; adjexp < emin, exp < etiny
(defthm scale-to-etiny-shift>0
  (implies (and (integerp exp) (integerp digits)
                (integerp emin) (integerp prec)
                (integerp shift)
                (= etiny (+ emin (- prec) 1))
                (< exp etiny)
                (= shift (- etiny exp)))
            (< 0 shift)))

(defthm scale-to-etiny-result-fits-prec
  (implies (and (integerp exp) (integerp digits)
                (integerp emin) (integerp prec)
                (integerp shift)
                (= adjexp (+ exp digits -1))
                (= etiny (+ emin (- prec) 1))
                (< adjexp emin)
                (= shift (- etiny exp)))
            (< (- digits shift) prec)))

; adjexp <= emax, exp > etop
(defthm scale-to-etop-shift>0
  (implies (and (integerp exp) (integerp digits)
                (integerp emax) (integerp prec)
                (integerp shift)
                (= etop (+ emax (- prec) 1))
                (> exp etop)
                (= shift (- exp etop)))
            (< 0 shift)))

(defthm scale-to-etop-result-fits-prec
  (implies (and (integerp exp) (integerp digits)
                (integerp emax) (integerp prec)
                (integerp shift)
                (= etop (+ emax (- prec) 1))
		(= adjexp (+ exp digits -1))
                (<= adjexp emax)
                (= shift (- exp etop)))
            (<= (+ digits shift) prec)))

(defthm scale-to-etop-underflow-impossible
  (implies (and (integerp exp) (integerp emax)
                (integerp emin) (integerp prec)
                (= etiny (+ emin (- prec) 1))
                (= etop (+ emax (- prec) 1))
                (< exp etiny)
                (> exp etop))
           (< emax emin)))


