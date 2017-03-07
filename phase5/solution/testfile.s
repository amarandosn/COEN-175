	.comm	 y, 4, 4
	.comm	 z,40,4
	.comm	 x, 4, 4
	.comm	 a,8,4
	.comm	 b,12,4
	.comm	 d,16,4
	.comm	 a1, 4, 4
	.comm	 a2, 4, 4
2
.globl foo
FUNCTION PROLOGUE
	pushl	%rbp
	movl	%rsp, %rbp
	subl	$20, %esp
FUNCTION BODY
	movl	a1, %eax
	movl	%eax, $5
	movl	a2, %eax
	movl	%eax, a1
	pushl	a2post push1hi
	pushl	a1post push0hi
