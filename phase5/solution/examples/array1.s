	.comm	 a,40,4
.globl main
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
#FUNCTION BODY
	movl	$10, -4(%ebp)
	pushl	-4(%ebp)
	call	init_array
	pushl	-4(%ebp)
	call	print_array
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	pop		%ebp
	ret
