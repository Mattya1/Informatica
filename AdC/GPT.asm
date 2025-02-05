.data
    arr: .word 0 -1
    arr1: .word 1 -1
    arr2: .word 0 0 2 0 0 -1
    arr3: .word 0 3 0 0 3 0 3 0 -1
    arr4: .word 4 4 0 0 0 0 0 -1
    arr5: .word 5 5 5 0 0 0 5 5 5 -1
    msg: .string " "
    msg2: .string "\n"

    .macro print_str(%x)
        li a7, 4
        la a0, %x
        ecall
    .end_macro

    .macro print_int(%x)
        li a7, 1
        mv a0, %x
        ecall
    .end_macro

.text
    MAIN:
        la s4, arr2        # Load address of arr2
        li t0, -1          # Terminator value

    LOOP:
        lw t2, 0(s4)       # Load current element
        beq t2, t0, end    # If terminator, end loop
        print_int(t2)      # Print current element
        print_str(msg)     # Print space
        beqz t2, shift     # If element is zero, handle shift
        addi s4, s4, 4     # Move to next element
        j LOOP

    shift:
        mv t3, s4          # Current position (zero)
        addi t4, s4, 4     # Next element address

    shift_loop:
        lw t5, 0(t4)       # Load next element
        sw t5, 0(t3)       # Store into current position
        beq t5, t0, LOOP   # If shifted terminator, recheck current
        addi t3, t3, 4     # Move current and next pointers
        addi t4, t4, 4
        j shift_loop

    end:
        print_str(msg2)    # New line after processing
        la s4, arr2        # Reset to start of array for printing

    print_loop:
        lw t2, 0(s4)       # Load element to print
        print_int(t2)      # Print element
        print_str(msg)     # Print space
        addi s4, s4, 4     # Move to next element
        bne t2, t0, print_loop # Continue until terminator

    stop:
        li a7, 10          # Exit syscall
        li a0, 0
        ecall