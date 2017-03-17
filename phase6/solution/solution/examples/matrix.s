allocate:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$allocate.size, %esp
#FUNCTION BODY
#MULTIPLY
	movl	8(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -12(%ebp)
	pushl	-12(%ebp)
	call	malloc
	addl	$4, %esp
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -8(%ebp)
#FOR
	movl	$0, %eax
	movl	%eax, -4(%ebp)
.L2:
#LESS THAN
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
	je	.L3
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -24(%ebp)
	movl	-8(%ebp), %eax
	addl	-24(%ebp), %eax
	movl	%eax, -28(%ebp)
#MULTIPLY
	movl	8(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -32(%ebp)
	pushl	-32(%ebp)
	call	malloc
	addl	$4, %esp
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	-28(%ebp), %ecx
	movl	%eax, (%ecx)
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L2
.L3:
#RETURN
	movl	-8(%ebp), %eax
	jmp	.L1
.L1:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	allocate
	.set	allocate.size, 40

initialize:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$initialize.size, %esp
#FUNCTION BODY
#FOR
	movl	$0, %eax
	movl	%eax, -4(%ebp)
.L6:
#LESS THAN
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	$0, %eax
	je	.L7
#FOR
	movl	$0, %eax
	movl	%eax, -8(%ebp)
.L8:
#LESS THAN
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	cmpl	$0, %eax
	je	.L9
#DEREFINDIRECT
#ADD
#DEREF
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	addl	-20(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-28(%ebp)
#MULTIPLY
	movl	-8(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -32(%ebp)
	movl	-28(%ebp), %eax
	addl	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
#ADD
	movl	-4(%ebp), %eax
	addl	-8(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %ecx
	movl	%eax, (%ecx)
#ADD
	movl	-8(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, -8(%ebp)
	jmp	.L8
.L9:
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L6
.L7:
.L5:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	initialize
	.set	initialize.size, 48

display:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$display.size, %esp
#FUNCTION BODY
	movl	$0, %eax
	movl	%eax, -4(%ebp)
#WHILE
.L12:
#LESS THAN
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	cmpl	$0, %eax
	je	.L13
	movl	$0, %eax
	movl	%eax, -8(%ebp)
#WHILE
.L14:
#LESS THAN
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
	je	.L15
#DEREF
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	addl	-24(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -12(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	-8(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -36(%ebp)
	movl	-12(%ebp), %eax
	addl	-36(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-44(%ebp)
	pushl	-44(%ebp)
#ADDRESS
#STRING
	leal	.L16, %eax
	movl	%eax, -48(%ebp)
	pushl	-48(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -52(%ebp)
#ADD
	movl	-8(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, -8(%ebp)
	jmp	.L14
.L15:
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#STRING
	leal	.L17, %eax
	movl	%eax, -64(%ebp)
	pushl	-64(%ebp)
	call	printf
	addl	$4, %esp
	movl	%eax, -68(%ebp)
	jmp	.L12
.L13:
.L11:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	display
	.set	display.size, 68

deallocate:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$deallocate.size, %esp
#FUNCTION BODY
	movl	$0, %eax
	movl	%eax, -4(%ebp)
#WHILE
.L20:
#LESS THAN
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	cmpl	$0, %eax
	je	.L21
#DEREF
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	addl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-20(%ebp)
	pushl	-20(%ebp)
	call	free
	addl	$4, %esp
	movl	%eax, -24(%ebp)
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L20
.L21:
	pushl	8(%ebp)
	call	free
	addl	$4, %esp
	movl	%eax, -32(%ebp)
.L19:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	deallocate
	.set	deallocate.size, 32

main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
#ADDRESS
	leal	-8(%ebp), %eax
	movl	%eax, -12(%ebp)
	pushl	-12(%ebp)
#ADDRESS
#STRING
	leal	.L24, %eax
	movl	%eax, -16(%ebp)
	pushl	-16(%ebp)
	call	scanf
	addl	$8, %esp
	movl	%eax, -20(%ebp)
	pushl	-8(%ebp)
	call	allocate
	addl	$4, %esp
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, -4(%ebp)
	pushl	-8(%ebp)
	pushl	-4(%ebp)
	call	initialize
	addl	$8, %esp
	movl	%eax, -28(%ebp)
	pushl	-8(%ebp)
	pushl	-4(%ebp)
	call	display
	addl	$8, %esp
	movl	%eax, -32(%ebp)
	pushl	-8(%ebp)
	pushl	-4(%ebp)
	call	deallocate
	addl	$8, %esp
	movl	%eax, -36(%ebp)
.L23:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 36

.L16:	.asciz "%d "
.L17:	.asciz "\n"
.L24:	.asciz "%d"
