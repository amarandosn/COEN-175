0
.globl main
FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
FUNCTION BODY
	movl	x, $1
	movl	y, $2
	movl	z, $3
	pushl	x
	pushl	y
	pushl	z
	call	print
FUNCTION EPILOGUE
	movl	%ebp, %esp
	pop		%ebp
	ret
