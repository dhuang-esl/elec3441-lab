# fib.s
# ELEC3441 Lab
# Copyright Hayden So 2023
.globl _start
.globl _exit

.text
_start:
    li  a0, 9            # n
    mv  s0, a0           # preserve n for display and checking
    call fib
    mv  s1, a0           # preserve F(n) for display

    # Print: Fibonacci number n is: result
    la  a0, outputStr
    li  a7, 4
    ecall
    mv  a0, s0
    li  a7, 1
    ecall
    la  a0, isStr
    li  a7, 4
    ecall
    mv  a0, s1
    li  a7, 1
    ecall
    j   _exit

_exit:
    li  a7, 10
    ecall

fib:
    ###############################################
    # Function: fib
    # Parameter:
    #  * a0: integer n, 0 <= n <= 46
    # Return F(n) in a0, where F(0)=0 and F(1)=1.
    # Do not modify s0-s11 or sp.
    ###############################################

    ###### BEGIN of your code #############
    # Your code goes here
    ###### END of your code   #############
    ret

.data
outputStr:
.string "Fibonacci number "
isStr:
.string " is: "
