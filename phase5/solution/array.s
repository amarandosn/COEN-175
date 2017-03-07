	.comm	 a,40,4
	.comm	 print_array, 4, 4
0
.globl main
FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
FUNCTION BODY
	movl	n, $10
	pushl	n
	call	init_array
	pushl	n
	call	print_array
FUNCTION EPILOGUE
	movl	%ebp, %esp
	pop		%ebp
	ret
