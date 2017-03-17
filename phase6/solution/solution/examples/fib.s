fib:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$fib.size, %esp
#FUNCTION BODY
#IF
#LOGICALOR
#EQUAL
	movl	8(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	cmpl	$0, %eax
	jne	.L4
#EQUAL
	movl	8(%ebp), %eax
	cmpl	$1, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	$0, %eax
.L4:
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	cmpl	$0, %eax
	je	.L3
#RETURN
	movl	$1, %eax
	jmp	.L1
	jmp	.L2
.L3:
.L2:
#RETURN
#SUB
	movl	8(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -16(%ebp)
	pushl	-16(%ebp)
	call	fib
	addl	$4, %esp
	movl	%eax, -20(%ebp)
#SUB
	movl	8(%ebp), %eax
	subl	$2, %eax
	movl	%eax, -24(%ebp)
	pushl	-24(%ebp)
	call	fib
	addl	$4, %esp
	movl	%eax, -28(%ebp)
#ADD
	movl	-20(%ebp), %eax
	addl	-28(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	jmp	.L1
.L1:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	fib
	.set	fib.size, 32

main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
#ADDRESS
	leal	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
	pushl	-8(%ebp)
#ADDRESS
#STRING
	leal	.L7, %eax
	movl	%eax, -12(%ebp)
	pushl	-12(%ebp)
	call	scanf
	addl	$8, %esp
	movl	%eax, -16(%ebp)
	pushl	-4(%ebp)
	call	fib
	addl	$4, %esp
	movl	%eax, -20(%ebp)
	pushl	-20(%ebp)
#ADDRESS
#STRING
	leal	.L8, %eax
	movl	%eax, -24(%ebp)
	pushl	-24(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -28(%ebp)
.L6:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 28

.L7:	.asciz "%d"
.L8:	.asciz "%d\n"
