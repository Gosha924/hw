	.arch armv8-a
	.file	"4_hw_c_sort.c"
	.text
	.section	.rodata
	.align	3
.LC0:
	.string	"%d "
	.text
	.align	2
	.global	printArray
	.type	printArray, %function
printArray:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	w1, [sp, 20]
	str	wzr, [sp, 44]
	b	.L2
.L3:
	ldrsw	x0, [sp, 44]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	w0, [x0]
	mov	w1, w0
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	bl	printf
	ldr	w0, [sp, 44]
	add	w0, w0, 1
	str	w0, [sp, 44]
.L2:
	ldr	w1, [sp, 44]
	ldr	w0, [sp, 20]
	cmp	w1, w0
	blt	.L3
	mov	w0, 10
	bl	putchar
	nop
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	printArray, .-printArray
	.align	2
	.global	swap
	.type	swap, %function
swap:
.LFB1:
	.cfi_startproc
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, 8]
	str	x1, [sp]
	ldr	x0, [sp, 8]
	ldr	w0, [x0]
	str	w0, [sp, 28]
	ldr	x0, [sp]
	ldr	w1, [x0]
	ldr	x0, [sp, 8]
	str	w1, [x0]
	ldr	x0, [sp]
	ldr	w1, [sp, 28]
	str	w1, [x0]
	nop
	add	sp, sp, 32
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE1:
	.size	swap, .-swap
	.align	2
	.global	lomitoSort
	.type	lomitoSort, %function
lomitoSort:
.LFB2:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x0, [sp, 24]
	str	w1, [sp, 20]
	str	w2, [sp, 16]
	ldr	w1, [sp, 20]
	ldr	w0, [sp, 16]
	cmp	w1, w0
	bge	.L12
	ldrsw	x0, [sp, 16]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	w0, [x0]
	str	w0, [sp, 44]
	ldr	w0, [sp, 20]
	str	w0, [sp, 36]
	ldr	w0, [sp, 20]
	str	w0, [sp, 40]
	b	.L9
.L11:
	ldrsw	x0, [sp, 40]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	w0, [x0]
	ldr	w1, [sp, 44]
	cmp	w1, w0
	blt	.L10
	ldrsw	x0, [sp, 36]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x2, x1, x0
	ldrsw	x0, [sp, 40]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	mov	x1, x0
	mov	x0, x2
	bl	swap
	ldr	w0, [sp, 36]
	add	w0, w0, 1
	str	w0, [sp, 36]
.L10:
	ldr	w0, [sp, 40]
	add	w0, w0, 1
	str	w0, [sp, 40]
.L9:
	ldr	w1, [sp, 40]
	ldr	w0, [sp, 16]
	cmp	w1, w0
	blt	.L11
	ldrsw	x0, [sp, 36]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x2, x1, x0
	ldrsw	x0, [sp, 16]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	mov	x1, x0
	mov	x0, x2
	bl	swap
	ldr	w0, [sp, 36]
	sub	w0, w0, #1
	mov	w2, w0
	ldr	w1, [sp, 20]
	ldr	x0, [sp, 24]
	bl	lomitoSort
	ldr	w0, [sp, 36]
	add	w0, w0, 1
	ldr	w2, [sp, 16]
	mov	w1, w0
	ldr	x0, [sp, 24]
	bl	lomitoSort
	b	.L6
.L12:
	nop
.L6:
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE2:
	.size	lomitoSort, .-lomitoSort
	.align	2
	.global	elemsThatChangePosition
	.type	elemsThatChangePosition, %function
elemsThatChangePosition:
.LFB3:
	.cfi_startproc
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	str	w2, [sp, 12]
	str	wzr, [sp, 40]
	str	wzr, [sp, 44]
	b	.L14
.L16:
	ldrsw	x0, [sp, 44]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	w1, [x0]
	ldrsw	x0, [sp, 44]
	lsl	x0, x0, 2
	ldr	x2, [sp, 16]
	add	x0, x2, x0
	ldr	w0, [x0]
	cmp	w1, w0
	bne	.L15
	ldr	w0, [sp, 40]
	add	w0, w0, 1
	str	w0, [sp, 40]
.L15:
	ldr	w0, [sp, 44]
	add	w0, w0, 1
	str	w0, [sp, 44]
.L14:
	ldr	w1, [sp, 44]
	ldr	w0, [sp, 12]
	cmp	w1, w0
	blt	.L16
	ldr	w0, [sp, 40]
	add	sp, sp, 48
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE3:
	.size	elemsThatChangePosition, .-elemsThatChangePosition
	.section	.rodata
	.align	3
.LC1:
	.string	"\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\260:"
	.align	3
.LC2:
	.string	"%d"
	.align	3
.LC3:
	.string	"%d\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
.LFB4:
	.cfi_startproc
	stp	x29, x30, [sp, -96]!
	.cfi_def_cfa_offset 96
	.cfi_offset 29, -96
	.cfi_offset 30, -88
	mov	x29, sp
	.cfi_def_cfa_register 29
	stp	x19, x20, [sp, 16]
	stp	x21, x22, [sp, 32]
	stp	x23, x24, [sp, 48]
	stp	x25, x26, [sp, 64]
	str	x27, [sp, 80]
	sub	sp, sp, #464
	.cfi_offset 19, -80
	.cfi_offset 20, -72
	.cfi_offset 21, -64
	.cfi_offset 22, -56
	.cfi_offset 23, -48
	.cfi_offset 24, -40
	.cfi_offset 25, -32
	.cfi_offset 26, -24
	.cfi_offset 27, -16
	adrp	x0, :got:__stack_chk_guard;ldr	x0, [x0, :got_lo12:__stack_chk_guard]
	ldr	x1, [x0]
	str	x1, [x29, -8]
	mov	x1, 0
	mov	x0, sp
	mov	x19, x0
	sub	x0, x29, #16384
	str	wzr, [x0, 15948]
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	puts
	b	.L19
.L21:
	sub	x0, x29, #16384
	ldr	w0, [x0, 15948]
	add	w0, w0, 1
	sub	x1, x29, #16384
	str	w0, [x1, 15948]
.L19:
	sub	x0, x29, #16384
	ldr	w0, [x0, 15948]
	cmp	w0, 99
	bgt	.L20
	sub	x1, x29, #408
	sub	x0, x29, #16384
	ldrsw	x0, [x0, 15948]
	lsl	x0, x0, 2
	add	x0, x1, x0
	mov	x1, x0
	adrp	x0, .LC2
	add	x0, x0, :lo12:.LC2
	bl	__isoc99_scanf
	cmp	w0, 1
	beq	.L21
.L20:
	sub	x0, x29, #16384
	ldr	w0, [x0, 15948]
	sxtw	x1, w0
	sub	x1, x1, #1
	sub	x2, x29, #16384
	str	x1, [x2, 15960]
	sxtw	x1, w0
	mov	x22, x1
	mov	x23, 0
	lsr	x1, x22, 59
	lsl	x27, x23, 5
	orr	x27, x1, x27
	lsl	x26, x22, 5
	sxtw	x1, w0
	mov	x20, x1
	mov	x21, 0
	lsr	x1, x20, 59
	lsl	x25, x21, 5
	orr	x25, x1, x25
	lsl	x24, x20, 5
	sxtw	x0, w0
	lsl	x0, x0, 2
	add	x0, x0, 15
	lsr	x0, x0, 4
	lsl	x0, x0, 4
	and	x1, x0, -65536
	sub	x1, sp, x1
.L22:
	cmp	sp, x1
	beq	.L23
	sub	sp, sp, #65536
	str	xzr, [sp, 1024]
	b	.L22
.L23:
	and	x1, x0, 65535
	sub	sp, sp, x1
	str	xzr, [sp]
	and	x0, x0, 65535
	cmp	x0, 1024
	bcc	.L24
	str	xzr, [sp, 1024]
.L24:
	add	x0, sp, 16
	add	x0, x0, 3
	lsr	x0, x0, 2
	lsl	x0, x0, 2
	sub	x1, x29, #16384
	str	x0, [x1, 15968]
	sub	x0, x29, #16384
	str	wzr, [x0, 15952]
	b	.L25
.L26:
	sub	x0, x29, #16384
	ldrsw	x0, [x0, 15952]
	lsl	x0, x0, 2
	sub	x1, x29, #408
	ldr	w2, [x1, x0]
	sub	x0, x29, #16384
	ldr	x0, [x0, 15968]
	sub	x1, x29, #16384
	ldrsw	x1, [x1, 15952]
	str	w2, [x0, x1, lsl 2]
	sub	x0, x29, #16384
	ldr	w0, [x0, 15952]
	add	w0, w0, 1
	sub	x1, x29, #16384
	str	w0, [x1, 15952]
.L25:
	sub	x0, x29, #16384
	ldr	w1, [x0, 15952]
	sub	x0, x29, #16384
	ldr	w0, [x0, 15948]
	cmp	w1, w0
	blt	.L26
	sub	x0, x29, #16384
	ldr	w0, [x0, 15948]
	sub	w1, w0, #1
	sub	x0, x29, #408
	mov	w2, w1
	mov	w1, 0
	bl	lomitoSort
	sub	x0, x29, #408
	sub	x1, x29, #16384
	ldr	w2, [x1, 15948]
	mov	x1, x0
	sub	x0, x29, #16384
	ldr	x0, [x0, 15968]
	bl	elemsThatChangePosition
	sub	x1, x29, #16384
	str	w0, [x1, 15956]
	sub	x0, x29, #16384
	ldr	w1, [x0, 15956]
	adrp	x0, .LC3
	add	x0, x0, :lo12:.LC3
	bl	printf
	mov	w0, 0
	mov	sp, x19
	mov	w1, w0
	adrp	x0, :got:__stack_chk_guard;ldr	x0, [x0, :got_lo12:__stack_chk_guard]
	ldr	x3, [x29, -8]
	ldr	x2, [x0]
	subs	x3, x3, x2
	mov	x2, 0
	beq	.L28
	bl	__stack_chk_fail
.L28:
	mov	w0, w1
	mov	sp, x29
	ldp	x19, x20, [sp, 16]
	ldp	x21, x22, [sp, 32]
	ldp	x23, x24, [sp, 48]
	ldp	x25, x26, [sp, 64]
	ldr	x27, [sp, 80]
	ldp	x29, x30, [sp], 96
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 27
	.cfi_restore 25
	.cfi_restore 26
	.cfi_restore 23
	.cfi_restore 24
	.cfi_restore 21
	.cfi_restore 22
	.cfi_restore 19
	.cfi_restore 20
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 14.2.0-19ubuntu2) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
