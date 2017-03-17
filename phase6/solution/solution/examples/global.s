foo:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$foo.size, %esp
#FUNCTION BODY
#ADD
	movl	x, %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, x
#RETURN
#ADD
	movl	x, %eax
	addl	$1, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	jmp	.L1
.L1:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	foo
	.set	foo.size, 8

main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
	movl	$65, %eax
	movl	%eax, x
	pushl	x
	call	putchar
	addl	$4, %esp
	movl	%eax, -4(%ebp)
	call	foo
	movl	%eax, -8(%ebp)
	pushl	-8(%ebp)
	call	putchar
	addl	$4, %esp
	movl	%eax, -12(%ebp)
	pushl	x
	call	putchar
	addl	$4, %esp
	movl	%eax, -16(%ebp)
	pushl	$10
	call	putchar
	addl	$4, %esp
	movl	%eax, -20(%ebp)
.L3:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 20

	.data
	.comm	x, 4, 4
