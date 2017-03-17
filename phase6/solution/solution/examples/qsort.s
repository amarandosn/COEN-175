readarray:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$readarray.size, %esp
#FUNCTION BODY
	movl	$0, %eax
	movl	%eax, -4(%ebp)
#WHILE
.L2:
#LESS THAN
	movl	-4(%ebp), %eax
	cmpl	n, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	cmpl	$0, %eax
	je	.L3
#ADDRESS
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -12(%ebp)
	movl	a, %eax
	addl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	pushl	-16(%ebp)
#ADDRESS
#STRING
	leal	.L4, %eax
	movl	%eax, -20(%ebp)
	pushl	-20(%ebp)
	call	scanf
	addl	$8, %esp
	movl	%eax, -24(%ebp)
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L2
.L3:
.L1:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	readarray
	.set	readarray.size, 28

writearray:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$writearray.size, %esp
#FUNCTION BODY
	movl	$0, %eax
	movl	%eax, -4(%ebp)
#WHILE
.L7:
#LESS THAN
	movl	-4(%ebp), %eax
	cmpl	n, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	cmpl	$0, %eax
	je	.L8
#DEREF
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -12(%ebp)
	movl	a, %eax
	addl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-20(%ebp)
	pushl	-20(%ebp)
#ADDRESS
#STRING
	leal	.L9, %eax
	movl	%eax, -24(%ebp)
	pushl	-24(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -28(%ebp)
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L7
.L8:
#ADDRESS
#STRING
	leal	.L10, %eax
	movl	%eax, -36(%ebp)
	pushl	-36(%ebp)
	call	printf
	addl	$4, %esp
	movl	%eax, -40(%ebp)
.L6:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	writearray
	.set	writearray.size, 40

exchange:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$exchange.size, %esp
#FUNCTION BODY
#DEREF
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
#DEREFINDIRECT
#DEREF
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%eax, (%ecx)
#DEREFINDIRECT
	movl	-4(%ebp), %eax
	movl	12(%ebp), %ecx
	movl	%eax, (%ecx)
.L12:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	exchange
	.set	exchange.size, 12

partition:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$partition.size, %esp
#FUNCTION BODY
#DEREF
#ADD
#MULTIPLY
	movl	12(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	addl	-16(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, -12(%ebp)
#SUB
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADD
	movl	16(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -8(%ebp)
#WHILE
.L15:
#LESS THAN
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	cmpl	$0, %eax
	je	.L16
#SUB
	movl	-8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	%eax, -8(%ebp)
#WHILE
.L17:
#GREATER THAN
#DEREF
#ADD
#MULTIPLY
	movl	-8(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -44(%ebp)
	movl	8(%ebp), %eax
	addl	-44(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-52(%ebp)
	movl	-52(%ebp), %eax
	cmpl	-12(%ebp), %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	cmpl	$0, %eax
	je	.L18
#SUB
	movl	-8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, -8(%ebp)
	jmp	.L17
.L18:
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -64(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, -4(%ebp)
#WHILE
.L19:
#LESS THAN
#DEREF
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -68(%ebp)
	movl	8(%ebp), %eax
	addl	-68(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-72(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-76(%ebp)
	movl	-76(%ebp), %eax
	cmpl	-12(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -80(%ebp)
	movl	-80(%ebp), %eax
	cmpl	$0, %eax
	je	.L20
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -84(%ebp)
	movl	-84(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L19
.L20:
#IF
#LESS THAN
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -88(%ebp)
	movl	-88(%ebp), %eax
	cmpl	$0, %eax
	je	.L22
#ADDRESS
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	-8(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -92(%ebp)
	movl	8(%ebp), %eax
	addl	-92(%ebp), %eax
	movl	%eax, -96(%ebp)
	pushl	-96(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -100(%ebp)
	movl	8(%ebp), %eax
	addl	-100(%ebp), %eax
	movl	%eax, -104(%ebp)
	pushl	-104(%ebp)
	call	exchange
	addl	$8, %esp
	movl	%eax, -108(%ebp)
	jmp	.L21
.L22:
.L21:
	jmp	.L15
.L16:
#RETURN
	movl	-8(%ebp), %eax
	jmp	.L14
.L14:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	partition
	.set	partition.size, 108

quicksort:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$quicksort.size, %esp
#FUNCTION BODY
#IF
#GREATER THAN
	movl	16(%ebp), %eax
	cmpl	12(%ebp), %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	cmpl	$0, %eax
	je	.L26
	pushl	16(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	partition
	addl	$12, %esp
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -4(%ebp)
	pushl	-4(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	quicksort
	addl	$12, %esp
	movl	%eax, -16(%ebp)
	pushl	16(%ebp)
#ADD
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -20(%ebp)
	pushl	-20(%ebp)
	pushl	8(%ebp)
	call	quicksort
	addl	$12, %esp
	movl	%eax, -24(%ebp)
	jmp	.L25
.L26:
.L25:
.L24:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	quicksort
	.set	quicksort.size, 24

main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
	movl	$8, %eax
	movl	%eax, n
#MULTIPLY
	movl	n, %eax
	imull	$4, %eax
	movl	%eax, -4(%ebp)
	pushl	-4(%ebp)
	call	malloc
	addl	$4, %esp
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, a
	call	readarray
	movl	%eax, -12(%ebp)
#SUB
	movl	n, %eax
	subl	$1, %eax
	movl	%eax, -16(%ebp)
	pushl	-16(%ebp)
	pushl	$0
	pushl	a
	call	quicksort
	addl	$12, %esp
	movl	%eax, -20(%ebp)
	call	writearray
	movl	%eax, -24(%ebp)
.L28:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 24

	.data
	.comm	n, 4, 4
	.comm	a, 4, 4
.L4:	.asciz "%d"
.L9:	.asciz "%d "
.L10:	.asciz "\n"
