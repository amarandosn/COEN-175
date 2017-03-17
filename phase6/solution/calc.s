lexan:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$lexan.size, %esp
#FUNCTION BODY
#IF
#EQUAL
	movl	c, %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	$0, %eax
	je	.L3
	call	getchar
	movl	%eax, 
	movl	, %eax
	movl	%eax, c
	jmp	.L2
.L3:
.L2:
#WHILE
.L4:
	pushl	c
	call	isspace
	addl	$4, %esp
	movl	%eax, 
#NOT EQUAL
	movl	c, %eax
	cmpl	LF, %eax
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
#LOGICALAND
	movl	, %eax
	cmpl	$0, %eax
	je	.L6
	movl	-16(%ebp), %eax
	cmpl	$0, %eax
.L6:
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
	je	.L5
	call	getchar
	movl	%eax, 
	movl	, %eax
	movl	%eax, c
	jmp	.L4
.L5:
#IF
	pushl	c
	call	isdigit
	addl	$4, %esp
	movl	%eax, 
#NOT
	movl	, %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -24(%ebp)
	movl	-24(%ebp), %eax
	cmpl	$0, %eax
	je	.L8
	movl	c, %eax
	movl	%eax, -8(%ebp)
	movl	$0, %eax
	movl	%eax, c
#RETURN
	movl	-8(%ebp), %eax
	jmp	.L0
	jmp	.L7
.L8:
.L7:
	movl	$0, %eax
	movl	%eax, -4(%ebp)
#WHILE
.L9:
	pushl	c
	call	isdigit
	addl	$4, %esp
	movl	%eax, 
	movl	, %eax
	cmpl	$0, %eax
	je	.L10
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$10, %eax
	movl	%eax, -28(%ebp)
#ADD
	movl	-28(%ebp), %eax
	addl	c, %eax
	movl	%eax, -32(%ebp)
#SUB
	movl	-32(%ebp), %eax
	subl	$48, %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -4(%ebp)
	pushl	c
	call	getchar
	addl	$4, %esp
	movl	%eax, 
	movl	, %eax
	movl	%eax, c
	jmp	.L9
.L10:
	movl	-4(%ebp), %eax
	movl	%eax, lexval
#RETURN
	movl	NUM, %eax
	jmp	.L0
.L0:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	lexan
	.set	lexan.size, 36

match:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$match.size, %esp
#FUNCTION BODY
#IF
#NOT EQUAL
	movl	lookahead, %eax
	cmpl	8(%ebp), %eax
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	cmpl	$0, %eax
	je	.L13
	pushl	lookahead
#ADDRESS
#STRING
	leal	.L14, %eax
	movl	%eax, -8(%ebp)
	pushl	-8(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, 
	pushl	$1
	call	exit
	addl	$4, %esp
	movl	%eax, 
	jmp	.L12
.L13:
.L12:
	call	lexan
	movl	%eax, 
	movl	, %eax
	movl	%eax, lookahead
.L0:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	match
	.set	match.size, 8

factor:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$factor.size, %esp
#FUNCTION BODY
#IF
#EQUAL
	movl	lookahead, %eax
	cmpl	LPAREN, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	cmpl	$0, %eax
	je	.L17
	pushl	LPAREN
	call	match
	addl	$4, %esp
	movl	%eax, 
	call	expr
	movl	%eax, 
	movl	, %eax
	movl	%eax, -4(%ebp)
	pushl	RPAREN
	call	match
	addl	$4, %esp
	movl	%eax, 
#RETURN
	movl	-4(%ebp), %eax
	jmp	.L0
	jmp	.L16
.L17:
.L16:
	movl	lexval, %eax
	movl	%eax, -4(%ebp)
	pushl	NUM
	call	match
	addl	$4, %esp
	movl	%eax, 
#RETURN
	movl	-4(%ebp), %eax
	jmp	.L0
.L0:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	factor
	.set	factor.size, 8

term:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$term.size, %esp
#FUNCTION BODY
	call	factor
	movl	%eax, 
	movl	, %eax
	movl	%eax, -4(%ebp)
#WHILE
.L19:
#EQUAL
	movl	lookahead, %eax
	cmpl	MUL, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
#EQUAL
	movl	lookahead, %eax
	cmpl	DIV, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
#LOGICALOR
	movl	-8(%ebp), %eax
	cmpl	$0, %eax
	je	.L21
	movl	-12(%ebp), %eax
	cmpl	$0, %eax
.L21:
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	cmpl	$0, %eax
	je	.L20
#IF
#EQUAL
	movl	lookahead, %eax
	cmpl	MUL, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
	je	.L23
	pushl	MUL
	call	match
	addl	$4, %esp
	movl	%eax, 
	call	factor
	movl	%eax, 
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	, %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L22
.L23:
	pushl	DIV
	call	match
	addl	$4, %esp
	movl	%eax, 
	call	factor
	movl	%eax, 
#DIVIDE
	movl	-4(%ebp), %eax
	movl	, %ecx
	cltd
	idivl	%ecx
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -4(%ebp)
.L22:
	jmp	.L19
.L20:
#RETURN
	movl	-4(%ebp), %eax
	jmp	.L0
.L0:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	term
	.set	term.size, 28

expr:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$expr.size, %esp
#FUNCTION BODY
	call	term
	movl	%eax, 
	movl	, %eax
	movl	%eax, -4(%ebp)
#WHILE
.L25:
#EQUAL
	movl	lookahead, %eax
	cmpl	ADD, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
#EQUAL
	movl	lookahead, %eax
	cmpl	SUB, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
#LOGICALOR
	movl	-8(%ebp), %eax
	cmpl	$0, %eax
	je	.L27
	movl	-12(%ebp), %eax
	cmpl	$0, %eax
.L27:
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	cmpl	$0, %eax
	je	.L26
#IF
#EQUAL
	movl	lookahead, %eax
	cmpl	ADD, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
	je	.L29
	pushl	ADD
	call	match
	addl	$4, %esp
	movl	%eax, 
	call	term
	movl	%eax, 
#ADD
	movl	-4(%ebp), %eax
	addl	, %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L28
.L29:
	pushl	SUB
	call	match
	addl	$4, %esp
	movl	%eax, 
	call	term
	movl	%eax, 
#SUB
	movl	-4(%ebp), %eax
	subl	, %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -4(%ebp)
.L28:
	jmp	.L25
.L26:
#RETURN
	movl	-4(%ebp), %eax
	jmp	.L0
.L0:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	expr
	.set	expr.size, 28

main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
	movl	$10, %eax
	movl	%eax, LF
	movl	$40, %eax
	movl	%eax, LPAREN
	movl	$41, %eax
	movl	%eax, RPAREN
	movl	$42, %eax
	movl	%eax, MUL
	movl	$43, %eax
	movl	%eax, ADD
	movl	$45, %eax
	movl	%eax, SUB
	movl	$47, %eax
	movl	%eax, DIV
	movl	$256, %eax
	movl	%eax, NUM
	call	lexan
	movl	%eax, 
	movl	, %eax
	movl	%eax, lookahead
#WHILE
.L31:
#NEGATE
	movl	$1, %eax
	negl	%eax
	movl	 %eax, -8(%ebp)
#NOT EQUAL
	movl	lookahead, %eax
	cmpl	-8(%ebp), %eax
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	$0, %eax
	je	.L32
	call	expr
	movl	%eax, 
	movl	, %eax
	movl	%eax, -4(%ebp)
	pushl	-4(%ebp)
#ADDRESS
#STRING
	leal	.L33, %eax
	movl	%eax, -16(%ebp)
	pushl	-16(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, 
#WHILE
.L34:
#EQUAL
	movl	lookahead, %eax
	cmpl	LF, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
	je	.L35
	pushl	LF
	call	match
	addl	$4, %esp
	movl	%eax, 
	jmp	.L34
.L35:
	jmp	.L31
.L32:
.L0:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 20

	.data
	.comm	ADD, 4, 4
	.comm	SUB, 4, 4
	.comm	MUL, 4, 4
	.comm	DIV, 4, 4
	.comm	NUM, 4, 4
	.comm	LF, 4, 4
	.comm	LPAREN, 4, 4
	.comm	RPAREN, 4, 4
	.comm	lookahead, 4, 4
	.comm	c, 4, 4
	.comm	lexval, 4, 4
.L14:	.asciz "syntax error at %d\n"

.L33:	.asciz "%d\n"

