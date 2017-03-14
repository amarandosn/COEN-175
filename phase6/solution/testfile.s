main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
	movl	$48, %eax
	movl	%eax, -64(%ebp)
#ADD
	movl	$2, %eax
	addl	$3, %eax
	movl	%eax, -68(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, -20(%ebp)
#ADD
	movl	-20(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -72(%ebp)
	pushl	-72(%ebp)
	call	putchar
	addl	$4, %esp
#SUB
	movl	$5, %eax
	subl	$2, %eax
	movl	%eax, -76(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, -24(%ebp)
#ADD
	movl	-24(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -80(%ebp)
	pushl	-80(%ebp)
	call	putchar
	addl	$4, %esp
#DIVIDE
	movl	$9, %eax
	movl	$3, %ecx
	cltd
	idivl	%ecx
	movl	%eax, -84(%ebp)
	movl	-84(%ebp), %eax
	movl	%eax, -28(%ebp)
#ADD
	movl	-28(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -88(%ebp)
	pushl	-88(%ebp)
	call	putchar
	addl	$4, %esp
#REMAINDER
	movl	$8, %eax
	movl	$3, %ecx
	cltd
	idivl	%ecx
	movl	%edx, -92(%ebp)
	movl	-92(%ebp), %eax
	movl	%eax, -32(%ebp)
#ADD
	movl	-32(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -96(%ebp)
	pushl	-96(%ebp)
	call	putchar
	addl	$4, %esp
#MULTIPLY
	movl	$2, %eax
	imull	$3, %eax
	movl	%eax, -100(%ebp)
	movl	-100(%ebp), %eax
	movl	%eax, -36(%ebp)
#ADD
	movl	-36(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -104(%ebp)
	pushl	-104(%ebp)
	call	putchar
	addl	$4, %esp
#LESS THAN
	movl	-32(%ebp), %eax
	cmpl	-36(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	%eax, -40(%ebp)
#NOT
	movl	-40(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -112(%ebp)
#ADD
	movl	-112(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -116(%ebp)
	pushl	-116(%ebp)
	call	putchar
	addl	$4, %esp
#GREATER THAN
	movl	-20(%ebp), %eax
	cmpl	-24(%ebp), %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -120(%ebp)
	movl	-120(%ebp), %eax
	movl	%eax, -44(%ebp)
#NOT
	movl	-44(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -124(%ebp)
#ADD
	movl	-124(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -128(%ebp)
	pushl	-128(%ebp)
	call	putchar
	addl	$4, %esp
#LESS OR EQUAL
	movl	-32(%ebp), %eax
	cmpl	-36(%ebp), %eax
	setle	%al
	movzbl	%al, %eax
	movl	%eax, -132(%ebp)
	movl	-132(%ebp), %eax
	movl	%eax, -48(%ebp)
#NOT
	movl	-48(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -136(%ebp)
#ADD
	movl	-136(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -140(%ebp)
	pushl	-140(%ebp)
	call	putchar
	addl	$4, %esp
#GREATER OR EQUAL
	movl	-20(%ebp), %eax
	cmpl	-24(%ebp), %eax
	setge	%al
	movzbl	%al, %eax
	movl	%eax, -144(%ebp)
	movl	-144(%ebp), %eax
	movl	%eax, -52(%ebp)
#NOT
	movl	-52(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -148(%ebp)
#ADD
	movl	-148(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -152(%ebp)
	pushl	-152(%ebp)
	call	putchar
	addl	$4, %esp
#EQUAL
	movl	-24(%ebp), %eax
	cmpl	-28(%ebp), %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -156(%ebp)
	movl	-156(%ebp), %eax
	movl	%eax, -56(%ebp)
#NOT
	movl	-56(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -160(%ebp)
#ADD
	movl	-160(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -164(%ebp)
	pushl	-164(%ebp)
	call	putchar
	addl	$4, %esp
#NOT EQUAL
	movl	-24(%ebp), %eax
	cmpl	-20(%ebp), %eax
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -168(%ebp)
	movl	-168(%ebp), %eax
	movl	%eax, -60(%ebp)
#NOT
	movl	-60(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -172(%ebp)
#ADD
	movl	-172(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -176(%ebp)
	pushl	-176(%ebp)
	call	putchar
	addl	$4, %esp
	movl	$1, %eax
	movl	%eax, -4(%ebp)
#NEGATE
	movl	-4(%ebp), %eax
	negl	%eax
	movl	 %eax, -180(%ebp)
	movl	-180(%ebp), %eax
	movl	%eax, -8(%ebp)
#NEGATE
	movl	-8(%ebp), %eax
	negl	%eax
	movl	 %eax, -184(%ebp)
	movl	-184(%ebp), %eax
	movl	%eax, -12(%ebp)
#NOT
	movl	-4(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -188(%ebp)
	movl	-188(%ebp), %eax
	movl	%eax, -16(%ebp)
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret

	.globl	main
	.set	main.size, 188

