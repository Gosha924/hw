	.arch armv8-a
	.file	"sort.c"
	.text
	.align	2
	.global	bubbleSort
	.type	bubbleSort, %function
bubbleSort:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	mov	x29, sp
	.cfi_def_cfa_register 29
	sub	sp, sp, #80
	str	x0, [x29, -56]
	str	w1, [x29, -60]
	adrp	x0, :got:__stack_chk_guard;ldr	x0, [x0, :got_lo12:__stack_chk_guard]
	ldr	x1, [x0]
	str	x1, [x29, -8]
	mov	x1, 0
	mov	x0, sp
	mov	x10, x0
	ldr	w0, [x29, -60]
	sxtw	x1, w0
	sub	x1, x1, #1
	str	x1, [x29, -24]
	sxtw	x1, w0
	mov	x4, x1
	mov	x5, 0
	lsr	x1, x4, 59
	lsl	x9, x5, 5
	orr	x9, x1, x9
	lsl	x8, x4, 5
	sxtw	x1, w0
	mov	x2, x1
	mov	x3, 0
	lsr	x1, x2, 59
	lsl	x7, x3, 5
	orr	x7, x1, x7
	lsl	x6, x2, 5
	sxtw	x0, w0
	lsl	x0, x0, 2
	add	x0, x0, 15
	lsr	x0, x0, 4
	lsl	x0, x0, 4
	and	x1, x0, -65536
	sub	x1, sp, x1
.L2:
	cmp	sp, x1
	beq	.L3
	sub	sp, sp, #65536
	str	xzr, [sp, 1024]
	b	.L2
.L3:
	and	x1, x0, 65535
	sub	sp, sp, x1
	str	xzr, [sp]
	and	x0, x0, 65535
	cmp	x0, 1024
	bcc	.L4
	str	xzr, [sp, 1024]
.L4:
	add	x0, sp, 16
	add	x0, x0, 3
	lsr	x0, x0, 2
	lsl	x0, x0, 2
	str	x0, [x29, -16]
	str	wzr, [x29, -48]
	b	.L5
.L6:
	ldrsw	x0, [x29, -48]
	lsl	x0, x0, 2
	ldr	x1, [x29, -56]
	add	x0, x1, x0
	ldr	w2, [x0]
	ldr	x0, [x29, -16]
	ldrsw	x1, [x29, -48]
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [x29, -48]
	add	w0, w0, 1
	str	w0, [x29, -48]
.L5:
	ldr	w1, [x29, -48]
	ldr	w0, [x29, -60]
	cmp	w1, w0
	blt	.L6
	str	wzr, [x29, -44]
	str	wzr, [x29, -40]
	b	.L7
.L11:
	str	wzr, [x29, -36]
	b	.L8
.L10:
	ldrsw	x0, [x29, -36]
	lsl	x0, x0, 2
	ldr	x1, [x29, -56]
	add	x0, x1, x0
	ldr	w1, [x0]
	ldrsw	x0, [x29, -36]
	add	x0, x0, 1
	lsl	x0, x0, 2
	ldr	x2, [x29, -56]
	add	x0, x2, x0
	ldr	w0, [x0]
	cmp	w1, w0
	ble	.L9
	ldrsw	x0, [x29, -36]
	lsl	x0, x0, 2
	ldr	x1, [x29, -56]
	add	x0, x1, x0
	ldr	w0, [x0]
	str	w0, [x29, -28]
	ldrsw	x0, [x29, -36]
	add	x0, x0, 1
	lsl	x0, x0, 2
	ldr	x1, [x29, -56]
	add	x1, x1, x0
	ldrsw	x0, [x29, -36]
	lsl	x0, x0, 2
	ldr	x2, [x29, -56]
	add	x0, x2, x0
	ldr	w1, [x1]
	str	w1, [x0]
	ldrsw	x0, [x29, -36]
	add	x0, x0, 1
	lsl	x0, x0, 2
	ldr	x1, [x29, -56]
	add	x0, x1, x0
	ldr	w1, [x29, -28]
	str	w1, [x0]
.L9:
	ldr	w0, [x29, -36]
	add	w0, w0, 1
	str	w0, [x29, -36]
.L8:
	ldr	w1, [x29, -60]
	ldr	w0, [x29, -40]
	sub	w0, w1, w0
	sub	w0, w0, #1
	ldr	w1, [x29, -36]
	cmp	w1, w0
	blt	.L10
	ldr	w0, [x29, -40]
	add	w0, w0, 1
	str	w0, [x29, -40]
.L7:
	ldr	w0, [x29, -60]
	sub	w0, w0, #1
	ldr	w1, [x29, -40]
	cmp	w1, w0
	blt	.L11
	str	wzr, [x29, -32]
	b	.L12
.L14:
	ldr	x0, [x29, -16]
	ldrsw	x1, [x29, -32]
	ldr	w1, [x0, x1, lsl 2]
	ldrsw	x0, [x29, -32]
	lsl	x0, x0, 2
	ldr	x2, [x29, -56]
	add	x0, x2, x0
	ldr	w0, [x0]
	cmp	w1, w0
	beq	.L13
	ldr	w0, [x29, -44]
	add	w0, w0, 1
	str	w0, [x29, -44]
.L13:
	ldr	w0, [x29, -32]
	add	w0, w0, 1
	str	w0, [x29, -32]
.L12:
	ldr	w1, [x29, -32]
	ldr	w0, [x29, -60]
	cmp	w1, w0
	blt	.L14
	ldr	w0, [x29, -44]
	mov	sp, x10
	mov	w1, w0
	adrp	x0, :got:__stack_chk_guard;ldr	x0, [x0, :got_lo12:__stack_chk_guard]
	ldr	x3, [x29, -8]
	ldr	x2, [x0]
	subs	x3, x3, x2
	mov	x2, 0
	beq	.L16
	bl	__stack_chk_fail
.L16:
	mov	w0, w1
	mov	sp, x29
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE0:
	.size	bubbleSort, .-bubbleSort
	.ident	"GCC: (Ubuntu 14.2.0-19ubuntu2) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
