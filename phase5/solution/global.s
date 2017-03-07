	.comm	 x, 4, 4
	.comm	 y, 4, 4
	.comm	 z, 4, 4
0
.globl foo
FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0, %esp
FUNCTION BODY
	movl	x, $1
	movl	y, $2
	movl	z, $3
FUNCTION EPILOGUE
	movl	%ebp, %esp
	pop		%ebp
	ret
