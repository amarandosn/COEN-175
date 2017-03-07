.globl towers
towers:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0, %esp
#FUNCTION BODY
	pushl	20(%ebp)
	pushl	24(%ebp)
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	call_towers
	pushl	20(%ebp)
	pushl	16(%ebp)
	call	print_move
	pushl	16(%ebp)
	pushl	20(%ebp)
	pushl	24(%ebp)
	pushl	12(%ebp)
	call	call_towers
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	pop		%ebp
	ret
.globl main
main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
#FUNCTION BODY
	movl	$3, -4(%ebp)
	pushl	-4(%ebp)
	call	print
	pushl	$3
	pushl	$2
	pushl	$1
	pushl	-4(%ebp)
	call	towers
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	pop		%ebp
	ret
