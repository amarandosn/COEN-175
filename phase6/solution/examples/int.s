main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
	movl	$100, %eax
	movl	%eax, -4(%ebp)
	movl	$30, %eax
	movl	%eax, -8(%ebp)
	movl	$2, %eax
	movl	%eax, -12(%ebp)
#ADD
#ADD
	movl	-4(%ebp), %eax
	addl	-8(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	addl	-12(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	movl	%eax, -16(%ebp)
#SUB
#SUB
	movl	-4(%ebp), %eax
	subl	-8(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	subl	-12(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -20(%ebp)
#MULTIPLY
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	-8(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	imull	-12(%ebp), %eax
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, -24(%ebp)
#ADD
#DIVIDE
	movl	-4(%ebp), %eax
	movl	-8(%ebp), %ecx
	cltd
	idivl	%ecx
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	addl	-12(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, -28(%ebp)
#SUB
#REMAINDER
	movl	-4(%ebp), %eax
	movl	-8(%ebp), %ecx
	cltd
	idivl	%ecx
	movl	%edx, -68(%ebp)
	movl	-68(%ebp), %eax
	subl	-12(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, -32(%ebp)
	pushl	-16(%ebp)
#ADDRESS
#STRING
	leal	.L2, %eax
	movl	%eax, -76(%ebp)
	pushl	-76(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -80(%ebp)
	pushl	-20(%ebp)
#ADDRESS
#STRING
	leal	.L3, %eax
	movl	%eax, -84(%ebp)
	pushl	-84(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -88(%ebp)
	pushl	-24(%ebp)
#ADDRESS
#STRING
	leal	.L4, %eax
	movl	%eax, -92(%ebp)
	pushl	-92(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -96(%ebp)
	pushl	-28(%ebp)
#ADDRESS
#STRING
	leal	.L5, %eax
	movl	%eax, -100(%ebp)
	pushl	-100(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -104(%ebp)
	pushl	-32(%ebp)
#ADDRESS
#STRING
	leal	.L6, %eax
	movl	%eax, -108(%ebp)
	pushl	-108(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -112(%ebp)
.L1:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 112

.L2:	.asciz "%d\n"
.L3:	.asciz "%d\n"
.L4:	.asciz "%d\n"
.L5:	.asciz "%d\n"
.L6:	.asciz "%d\n"
