.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo

        movl $1, %ebx
        movl 8(%ebp), %ecx

for:    cmpl %ebx, 12(%ebp)
        jle fi_for

if:     cmpl %eax, (%ecx, %ebx, 4)
        jne fi_if

        movl (%ecx, %ebx, 4), %eax
        movl %ebx, %edx

fi_if:  incl %ebx

        jmp for

fi_for: movl %edx, -4(%ebp)


# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
