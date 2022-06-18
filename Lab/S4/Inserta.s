 .text
	.align 4
	.globl Insertar
	.type Insertar,@function
Insertar:
        # Aqui viene vuestro codigo
        pushl %ebp
        movl %esp, %ebp
        pushl %ebx
        pushl %esi
        subl $4, %esp

        movl $0, %esi               #i
        movl $-1, -4(%ebp)          #lug
        movl $0, %ebx               #12i

        movl 16(%ebp), %ecx
        movl 8(%ebp), %edx
do:
if1:    cmpl %ecx, 4(%edx, %ebx)
        jle else1

        movl %esi, -4(%ebp)
        jmp fi_do

else1:  incl %esi
        addl $12, %ebx
        cmpl  $0x80000000, 4(%edx, %ebx)
        jne do
fi_do:

if2:    cmpl  $0x80000000, 4(%edx, %ebx)
        jne else2

        movl %esi, -4(%ebp)
        jmp fi_if2

else2:
while:  cmpl  $0x80000000, 4(%edx, %ebx)
        je fi_while

        incl %esi
        addl $12, %ebx
        jmp while
fi_while:
fi_if2:
        movl %esi, %eax
for:    cmpl %eax, -4(%ebp)
        jg fi_for

        movl (%edx, %ebx), %ecx
        movl %ecx, 12(%edx, %ebx)
        movl 4(%edx, %ebx), %ecx
        movl %ecx, 16(%edx, %ebx)
        movl 8(%edx, %ebx), %ecx
        movl %ecx, 20(%edx, %ebx)

        decl %eax
        subl $12, %ebx
        jmp for
fi_for:
        pushl -4(%ebp)
        pushl 20(%ebp)
        pushl 16(%ebp)
        pushl 12(%ebp)
        pushl 8(%ebp)
        call Asignar
        addl $20, %esp

        movl %esi, %eax
        incl %eax

        addl $4, %esp
        popl %ebx
        popl %esi
        movl %ebp, %esp
        popl %ebp
        ret
