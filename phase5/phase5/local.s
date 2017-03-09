.globl main
main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
#FUNCTION BODY
	movl	$1, -4(%ebp)
	movl	$2, -8(%ebp)
	movl	$3, -12(%ebp)
	pushl	-4(%ebp)
	pushl	-8(%ebp)
	pushl	-12(%ebp)
	call	print
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	pop	%ebp
	ret
