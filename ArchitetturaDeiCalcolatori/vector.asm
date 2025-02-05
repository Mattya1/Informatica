.globl main

.eqv DIM 10

.data
V: .byte 1,2,3,4,5,6,7,8,9,10
b: .string "The sum is "

.macro exit (%x)
li a7, 93
li a0, %x
ecall
.end_macro

.macro print_str (%x)
li a7, 4
la a0, %x
ecall
.end_macro

.macro print_int (%x)
li a7, 1
mv a0, %x
ecall
.end_macro

.macro print (%x)
print_str(b)
print_int(%x)
.end_macro


.text
main:

#inserire qui
la t0, V
lb s0, 0(t0) 

lb t1, 1(t0)
add s0, s0, t1

lb t1, 2(t0)
add s0, s0, t1

lb t1, 3(t0)
add s0, s0, t1

lb t1, 4(t0)
add s0, s0, t1

lb t1, 5(t0)
add s0, s0, t1

lb t1, 6(t0)
add s0, s0, t1

lb t1, 7(t0)
add s0, s0, t1

lb t1, 8(t0)
add s0, s0, t1

lb t1, 9(t0)
add s0, s0, t1


print(s0)

exit(0)
