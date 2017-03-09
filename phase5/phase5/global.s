	.comm	 x, 4, 4
	.comm	 y, 4, 4
	.comm	 z, 4, 4
.globl foo
foo:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0, %esp
#FUNCTION BODY
	movl	$1, x
	movl	$2, y
	movl	$3, z
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	pop	%ebp
	ret
