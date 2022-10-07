;
; IS_Program4.scm
; ECE-399 Programming Paradigms
; Professor Sable
; Created by Nishat Ahmed on 8/4/22.
;

;function to remove element in a list, given index
(define (remove-ith i l)
       (cond
            ((null? l)
                '())
            ((or (< i 0) (>= i (length l))) ;invalid indices case
                l)
            ((= i 0)
               (cdr l))
            ((and (> i 0) (< i (length l)))
                (cons (car l)(remove-ith (- i 1) (cdr l))))
                           
        )
)

;function to get element in a list, given index
(define (get-ith i l)
       (cond
            ((null? l)
                '())
            ((or (< i 0) (>= i (length l))) ;invalid indices case
                '())
            ((= i 0)
               (car l))
            ((and (> i 0) (< i (length l)))
                (get-ith (- i 1) (cdr l)))
        )
)

;function to combine elements in a list, given a list of indices
(define (combine-elements il l)
    (map (lambda(i) (get-ith i l)) il)
)
