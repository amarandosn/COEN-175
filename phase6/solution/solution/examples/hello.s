main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
#ADDRESS
#STRING
	leal	.L2, %eax
	movl	%eax, -4(%ebp)
	pushl	-4(%ebp)
	call	printf
	addl	$4, %esp
	movl	%eax, -8(%ebp)
.L1:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 8

.L2:	.asciz "hello world\n"
