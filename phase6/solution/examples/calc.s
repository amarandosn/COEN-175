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
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, c
	jmp	.L2
.L3:
.L2:
#WHILE
.L4:
#LOGICALAND
	pushl	c
	call	isspace
	addl	$4, %esp
	movl	%eax, -20(%ebp)
#NOT EQUAL
	movl	c, %eax
	cmpl	LF, %eax
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -24(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
	je	.L6
	movl	-24(%ebp), %eax
	cmpl	$0, %eax
.L6:
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	cmpl	$0, %eax
	je	.L5
	call	getchar
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, c
	jmp	.L4
.L5:
#IF
#NOT
	pushl	c
	call	isdigit
	addl	$4, %esp
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -40(%ebp)
	movl	-40(%ebp), %eax
	cmpl	$0, %eax
	je	.L8
	movl	c, %eax
	movl	%eax, -8(%ebp)
	movl	$0, %eax
	movl	%eax, c
#RETURN
	movl	-8(%ebp), %eax
	jmp	.L1
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
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	cmpl	$0, %eax
	je	.L10
#SUB
#ADD
#MULTIPLY
	movl	-4(%ebp), %eax
	imull	$10, %eax
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	addl	c, %eax
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	subl	$48, %eax
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	%eax, -4(%ebp)
	pushl	c
	call	getchar
	addl	$4, %esp
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, c
	jmp	.L9
.L10:
	movl	-4(%ebp), %eax
	movl	%eax, lexval
#RETURN
	movl	NUM, %eax
	jmp	.L1
.L1:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	lexan
	.set	lexan.size, 60

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
	je	.L14
	pushl	lookahead
#ADDRESS
#STRING
	leal	.L15, %eax
	movl	%eax, -8(%ebp)
	pushl	-8(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -12(%ebp)
	pushl	$1
	call	exit
	addl	$4, %esp
	movl	%eax, -16(%ebp)
	jmp	.L13
.L14:
.L13:
	call	lexan
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, lookahead
.L12:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	match
	.set	match.size, 20

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
	je	.L19
	pushl	LPAREN
	call	match
	addl	$4, %esp
	movl	%eax, -12(%ebp)
	call	expr
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -4(%ebp)
	pushl	RPAREN
	call	match
	addl	$4, %esp
	movl	%eax, -20(%ebp)
#RETURN
	movl	-4(%ebp), %eax
	jmp	.L17
	jmp	.L18
.L19:
.L18:
	movl	lexval, %eax
	movl	%eax, -4(%ebp)
	pushl	NUM
	call	match
	addl	$4, %esp
	movl	%eax, -24(%ebp)
#RETURN
	movl	-4(%ebp), %eax
	jmp	.L17
.L17:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	factor
	.set	factor.size, 24

term:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$term.size, %esp
#FUNCTION BODY
	call	factor
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
#WHILE
.L22:
#LOGICALOR
#EQUAL
	movl	lookahead, %eax
	cmpl	MUL, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	cmpl	$0, %eax
	jne	.L24
#EQUAL
	movl	lookahead, %eax
	cmpl	DIV, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
.L24:
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	$0, %eax
	je	.L23
#IF
#EQUAL
	movl	lookahead, %eax
	cmpl	MUL, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	cmpl	$0, %eax
	je	.L26
	pushl	MUL
	call	match
	addl	$4, %esp
	movl	%eax, -28(%ebp)
#MULTIPLY
	call	factor
	movl	%eax, -32(%ebp)
	movl	-4(%ebp), %eax
	imull	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L25
.L26:
	pushl	DIV
	call	match
	addl	$4, %esp
	movl	%eax, -40(%ebp)
#DIVIDE
	call	factor
	movl	%eax, -44(%ebp)
	movl	-4(%ebp), %eax
	movl	-44(%ebp), %ecx
	cltd
	idivl	%ecx
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -4(%ebp)
.L25:
	jmp	.L22
.L23:
#RETURN
	movl	-4(%ebp), %eax
	jmp	.L21
.L21:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	term
	.set	term.size, 48

expr:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$expr.size, %esp
#FUNCTION BODY
	call	term
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
#WHILE
.L29:
#LOGICALOR
#EQUAL
	movl	lookahead, %eax
	cmpl	ADD, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	cmpl	$0, %eax
	jne	.L31
#EQUAL
	movl	lookahead, %eax
	cmpl	SUB, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
.L31:
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	$0, %eax
	je	.L30
#IF
#EQUAL
	movl	lookahead, %eax
	cmpl	ADD, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	cmpl	$0, %eax
	je	.L33
	pushl	ADD
	call	match
	addl	$4, %esp
	movl	%eax, -28(%ebp)
#ADD
	call	term
	movl	%eax, -32(%ebp)
	movl	-4(%ebp), %eax
	addl	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L32
.L33:
	pushl	SUB
	call	match
	addl	$4, %esp
	movl	%eax, -40(%ebp)
#SUB
	call	term
	movl	%eax, -44(%ebp)
	movl	-4(%ebp), %eax
	subl	-44(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -4(%ebp)
.L32:
	jmp	.L29
.L30:
#RETURN
	movl	-4(%ebp), %eax
	jmp	.L28
.L28:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	expr
	.set	expr.size, 48

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
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, lookahead
#WHILE
.L36:
#NOT EQUAL
#NEGATE
	movl	$1, %eax
	negl	%eax
	movl	 %eax, -12(%ebp)
	movl	lookahead, %eax
	cmpl	-12(%ebp), %eax
	setne	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	cmpl	$0, %eax
	je	.L37
	call	expr
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, -4(%ebp)
	pushl	-4(%ebp)
#ADDRESS
#STRING
	leal	.L38, %eax
	movl	%eax, -24(%ebp)
	pushl	-24(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -28(%ebp)
#WHILE
.L39:
#EQUAL
	movl	lookahead, %eax
	cmpl	LF, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	cmpl	$0, %eax
	je	.L40
	pushl	LF
	call	match
	addl	$4, %esp
	movl	%eax, -36(%ebp)
	jmp	.L39
.L40:
	jmp	.L36
.L37:
.L35:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 36

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
.L15:	.asciz "syntax error at %d\n"
.L38:	.asciz "%d\n"
