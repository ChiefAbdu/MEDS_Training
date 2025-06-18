    .section .text
    .globl main

main:
    la a0, num         # Load num
    lw a0, 0(a0)
    jal factorial

    la t0, result
    sw a0, 0(t0)       # Store result

    la t5, tohost      # Required by write_tohost
    j write_tohost


factorial:
    addi sp, sp, -8
    sw ra, 0(sp)
    sw a0, 4(sp)

    li t0, 1
    ble a0, t0, base_case

    addi a0, a0, -1
    jal factorial

    lw t1, 4(sp)
    mul a0, a0, t1
    j end_factorial

base_case:
    li a0, 1

end_factorial:
    lw ra, 0(sp)
    addi sp, sp, 8
    jr ra


# DO NOT TOUCH THIS
write_tohost:
    li x1, 1
    sw x1, tohost, t5
    j write_tohost


    .section .data
    .globl num
    .globl result

num:    .word 5
result: .word 0


    .align 12
    .section ".tohost","aw",@progbits
    .align 4
    .global tohost
tohost:     .dword 0

    .align 4
    .global fromhost
fromhost:   .dword 0
