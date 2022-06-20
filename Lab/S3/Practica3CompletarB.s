.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo

        movl $0, -4(%ebp)
        movl $0, %ebx
        movl 8(%ebp), %edx
for1:   cmpl $3, %ebx
        jge fi_for1

        movl $0, %ecx
for2:   cmpl %ebx, %ecx
        jg fi_for2

        imul $12, %ebx, %eax
        addl %edx, %eax
        movl %ecx, (%edx, %eax, 4)
        addl %ecx, -4(%ebp)

        incl %ecx
        jmp for2
fi_for2:
        addl 12(%ebp), %ebx
        jmp for1

fi_for1:


# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
