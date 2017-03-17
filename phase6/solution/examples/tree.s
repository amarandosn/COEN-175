insert:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$insert.size, %esp
#FUNCTION BODY
#IF
#NOT
	movl	8(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -4(%ebp)
	movl	-4(%ebp), %eax
	cmpl	$0, %eax
	je	.L3
#MULTIPLY
	movl	$3, %eax
	imull	$4, %eax
	movl	%eax, -8(%ebp)
	pushl	-8(%ebp)
	call	malloc
	addl	$4, %esp
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%ebp)
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	$0, %eax
	imull	$4, %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	addl	-16(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	12(%ebp), %eax
	movl	-20(%ebp), %ecx
	movl	%eax, (%ecx)
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	$1, %eax
	imull	$4, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	addl	-24(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	null, %eax
	movl	-28(%ebp), %ecx
	movl	%eax, (%ecx)
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	$2, %eax
	imull	$4, %eax
	movl	%eax, -32(%ebp)
	movl	8(%ebp), %eax
	addl	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	null, %eax
	movl	-36(%ebp), %ecx
	movl	%eax, (%ecx)
	jmp	.L2
.L3:
#IF
#LESS THAN
#DEREF
#ADD
#MULTIPLY
	movl	$0, %eax
	imull	$4, %eax
	movl	%eax, -40(%ebp)
	movl	8(%ebp), %eax
	addl	-40(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-48(%ebp)
	movl	12(%ebp), %eax
	cmpl	-48(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	cmpl	$0, %eax
	je	.L5
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	$1, %eax
	imull	$4, %eax
	movl	%eax, -56(%ebp)
	movl	8(%ebp), %eax
	addl	-56(%ebp), %eax
	movl	%eax, -60(%ebp)
	pushl	12(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	$1, %eax
	imull	$4, %eax
	movl	%eax, -64(%ebp)
	movl	8(%ebp), %eax
	addl	-64(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-68(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-72(%ebp)
	pushl	-72(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -76(%ebp)
	movl	-76(%ebp), %eax
	movl	-60(%ebp), %ecx
	movl	%eax, (%ecx)
	jmp	.L4
.L5:
#IF
#GREATER THAN
#DEREF
#ADD
#MULTIPLY
	movl	$0, %eax
	imull	$4, %eax
	movl	%eax, -80(%ebp)
	movl	8(%ebp), %eax
	addl	-80(%ebp), %eax
	movl	%eax, -84(%ebp)
	movl	-84(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-88(%ebp)
	movl	12(%ebp), %eax
	cmpl	-88(%ebp), %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -92(%ebp)
	movl	-92(%ebp), %eax
	cmpl	$0, %eax
	je	.L7
#DEREFINDIRECT
#ADD
#MULTIPLY
	movl	$2, %eax
	imull	$4, %eax
	movl	%eax, -96(%ebp)
	movl	8(%ebp), %eax
	addl	-96(%ebp), %eax
	movl	%eax, -100(%ebp)
	pushl	12(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	$2, %eax
	imull	$4, %eax
	movl	%eax, -104(%ebp)
	movl	8(%ebp), %eax
	addl	-104(%ebp), %eax
	movl	%eax, -108(%ebp)
	movl	-108(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-112(%ebp)
	pushl	-112(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -116(%ebp)
	movl	-116(%ebp), %eax
	movl	-100(%ebp), %ecx
	movl	%eax, (%ecx)
	jmp	.L6
.L7:
.L6:
.L4:
.L2:
#RETURN
	movl	8(%ebp), %eax
	jmp	.L1
.L1:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	insert
	.set	insert.size, 116

search:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$search.size, %esp
#FUNCTION BODY
#IF
#NOT
	movl	8(%ebp), %eax
	cmpl	$0, %eax
	sete	%al
	movzbl	%al, %eax
	movl	 %eax, -4(%ebp)
	movl	-4(%ebp), %eax
	cmpl	$0, %eax
	je	.L11
#RETURN
	movl	$0, %eax
	jmp	.L9
	jmp	.L10
.L11:
.L10:
#IF
#LESS THAN
#DEREF
#ADD
#MULTIPLY
	movl	$0, %eax
	imull	$4, %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	addl	-8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-16(%ebp)
	movl	12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	cmpl	$0, %eax
	je	.L13
#RETURN
	pushl	12(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	$1, %eax
	imull	$4, %eax
	movl	%eax, -24(%ebp)
	movl	8(%ebp), %eax
	addl	-24(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-32(%ebp)
	pushl	-32(%ebp)
	call	search
	addl	$8, %esp
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	jmp	.L9
	jmp	.L12
.L13:
.L12:
#IF
#GREATER THAN
#DEREF
#ADD
#MULTIPLY
	movl	$0, %eax
	imull	$4, %eax
	movl	%eax, -40(%ebp)
	movl	8(%ebp), %eax
	addl	-40(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-48(%ebp)
	movl	12(%ebp), %eax
	cmpl	-48(%ebp), %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	cmpl	$0, %eax
	je	.L15
#RETURN
	pushl	12(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	$2, %eax
	imull	$4, %eax
	movl	%eax, -56(%ebp)
	movl	8(%ebp), %eax
	addl	-56(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-64(%ebp)
	pushl	-64(%ebp)
	call	search
	addl	$8, %esp
	movl	%eax, -68(%ebp)
	movl	-68(%ebp), %eax
	jmp	.L9
	jmp	.L14
.L15:
.L14:
#RETURN
	movl	$1, %eax
	jmp	.L9
.L9:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	search
	.set	search.size, 68

preorder:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$preorder.size, %esp
#FUNCTION BODY
#IF
	movl	8(%ebp), %eax
	cmpl	$0, %eax
	je	.L19
#DEREF
#ADD
#MULTIPLY
	movl	$0, %eax
	imull	$4, %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	addl	-8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -4(%ebp)
#DEREF
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-20(%ebp)
	pushl	-20(%ebp)
#ADDRESS
#STRING
	leal	.L20, %eax
	movl	%eax, -24(%ebp)
	pushl	-24(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -28(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	$1, %eax
	imull	$4, %eax
	movl	%eax, -32(%ebp)
	movl	8(%ebp), %eax
	addl	-32(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-40(%ebp)
	pushl	-40(%ebp)
	call	preorder
	addl	$4, %esp
	movl	%eax, -44(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	$2, %eax
	imull	$4, %eax
	movl	%eax, -48(%ebp)
	movl	8(%ebp), %eax
	addl	-48(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-56(%ebp)
	pushl	-56(%ebp)
	call	preorder
	addl	$4, %esp
	movl	%eax, -60(%ebp)
	jmp	.L18
.L19:
.L18:
.L17:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	preorder
	.set	preorder.size, 60

inorder:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$inorder.size, %esp
#FUNCTION BODY
#IF
	movl	8(%ebp), %eax
	cmpl	$0, %eax
	je	.L24
#DEREF
#ADD
#MULTIPLY
	movl	$0, %eax
	imull	$4, %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	addl	-8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -4(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	$1, %eax
	imull	$4, %eax
	movl	%eax, -20(%ebp)
	movl	8(%ebp), %eax
	addl	-20(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-28(%ebp)
	pushl	-28(%ebp)
	call	inorder
	addl	$4, %esp
	movl	%eax, -32(%ebp)
#DEREF
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-36(%ebp)
	pushl	-36(%ebp)
#ADDRESS
#STRING
	leal	.L25, %eax
	movl	%eax, -40(%ebp)
	pushl	-40(%ebp)
	call	printf
	addl	$8, %esp
	movl	%eax, -44(%ebp)
#DEREF
#ADD
#MULTIPLY
	movl	$2, %eax
	imull	$4, %eax
	movl	%eax, -48(%ebp)
	movl	8(%ebp), %eax
	addl	-48(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax,-56(%ebp)
	pushl	-56(%ebp)
	call	inorder
	addl	$4, %esp
	movl	%eax, -60(%ebp)
	jmp	.L23
.L24:
.L23:
.L22:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	inorder
	.set	inorder.size, 60

main:
#FUNCTION PROLOGUE
	pushl	%ebp
	movl	%esp, %ebp
	subl	$main.size, %esp
#FUNCTION BODY
	movl	$0, %eax
	movl	%eax, -48(%ebp)
#WHILE
.L28:
#LESS THAN
	movl	-48(%ebp), %eax
	cmpl	$8, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, -52(%ebp)
	movl	-52(%ebp), %eax
	cmpl	$0, %eax
	je	.L29
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -56(%ebp)
#MULTIPLY
	movl	-48(%ebp), %eax
	imull	$4, %eax
	movl	%eax, -60(%ebp)
	movl	-56(%ebp), %eax
	addl	-60(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-48(%ebp), %eax
	movl	-64(%ebp), %ecx
	movl	%eax, (%ecx)
#ADD
	movl	-48(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -68(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, -48(%ebp)
	jmp	.L28
.L29:
	movl	null, %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -72(%ebp)
#MULTIPLY
	movl	$7, %eax
	imull	$4, %eax
	movl	%eax, -76(%ebp)
	movl	-72(%ebp), %eax
	addl	-76(%ebp), %eax
	movl	%eax, -80(%ebp)
	pushl	-80(%ebp)
	pushl	-4(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -84(%ebp)
	movl	-84(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -88(%ebp)
#MULTIPLY
	movl	$4, %eax
	imull	$4, %eax
	movl	%eax, -92(%ebp)
	movl	-88(%ebp), %eax
	addl	-92(%ebp), %eax
	movl	%eax, -96(%ebp)
	pushl	-96(%ebp)
	pushl	-4(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -100(%ebp)
	movl	-100(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -104(%ebp)
#MULTIPLY
	movl	$1, %eax
	imull	$4, %eax
	movl	%eax, -108(%ebp)
	movl	-104(%ebp), %eax
	addl	-108(%ebp), %eax
	movl	%eax, -112(%ebp)
	pushl	-112(%ebp)
	pushl	-4(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -116(%ebp)
	movl	-116(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -120(%ebp)
#MULTIPLY
	movl	$0, %eax
	imull	$4, %eax
	movl	%eax, -124(%ebp)
	movl	-120(%ebp), %eax
	addl	-124(%ebp), %eax
	movl	%eax, -128(%ebp)
	pushl	-128(%ebp)
	pushl	-4(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -132(%ebp)
	movl	-132(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -136(%ebp)
#MULTIPLY
	movl	$5, %eax
	imull	$4, %eax
	movl	%eax, -140(%ebp)
	movl	-136(%ebp), %eax
	addl	-140(%ebp), %eax
	movl	%eax, -144(%ebp)
	pushl	-144(%ebp)
	pushl	-4(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -148(%ebp)
	movl	-148(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -152(%ebp)
#MULTIPLY
	movl	$2, %eax
	imull	$4, %eax
	movl	%eax, -156(%ebp)
	movl	-152(%ebp), %eax
	addl	-156(%ebp), %eax
	movl	%eax, -160(%ebp)
	pushl	-160(%ebp)
	pushl	-4(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -164(%ebp)
	movl	-164(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -168(%ebp)
#MULTIPLY
	movl	$3, %eax
	imull	$4, %eax
	movl	%eax, -172(%ebp)
	movl	-168(%ebp), %eax
	addl	-172(%ebp), %eax
	movl	%eax, -176(%ebp)
	pushl	-176(%ebp)
	pushl	-4(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -180(%ebp)
	movl	-180(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#DEREFINDIRECT
#ADD
#ADDRESS
	leal	-44(%ebp), %eax
	movl	%eax, -184(%ebp)
#MULTIPLY
	movl	$6, %eax
	imull	$4, %eax
	movl	%eax, -188(%ebp)
	movl	-184(%ebp), %eax
	addl	-188(%ebp), %eax
	movl	%eax, -192(%ebp)
	pushl	-192(%ebp)
	pushl	-4(%ebp)
	call	insert
	addl	$8, %esp
	movl	%eax, -196(%ebp)
	movl	-196(%ebp), %eax
	movl	%eax, -4(%ebp)
#ADDRESS
#STRING
	leal	.L30, %eax
	movl	%eax, -200(%ebp)
	pushl	-200(%ebp)
	call	printf
	addl	$4, %esp
	movl	%eax, -204(%ebp)
	pushl	-4(%ebp)
	call	preorder
	addl	$4, %esp
	movl	%eax, -208(%ebp)
#ADDRESS
#STRING
	leal	.L31, %eax
	movl	%eax, -212(%ebp)
	pushl	-212(%ebp)
	call	printf
	addl	$4, %esp
	movl	%eax, -216(%ebp)
	pushl	-4(%ebp)
	call	inorder
	addl	$4, %esp
	movl	%eax, -220(%ebp)
.L27:
#FUNCTION EPILOGUE
	movl	%ebp, %esp
	popl	%ebp
	ret
	.globl	main
	.set	main.size, 220

	.data
	.comm	null, 4, 4
.L20:	.asciz "%d\n"
.L25:	.asciz "%d\n"
.L30:	.asciz "preorder traversal:\n"
.L31:	.asciz "inorder traversal:\n"
