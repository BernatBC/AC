 .text
	.align 4
	.globl Asignar
	.type Asignar,@function
Asignar:
        imul $12, 20(%esp), %eax
        movl 4(%esp), %edx
        movl 8(%esp), %ecx
        movl %ecx, (%edx, %eax)
        movl 12(%esp), %ecx
        movl %ecx, 4(%edx, %eax)
        movl 16(%esp), %ecx
        movl %ecx, 8(%edx, %eax)
        ret
