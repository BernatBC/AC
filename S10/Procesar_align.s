.text
	.align 16
	.globl procesar
	.type	procesar, @function
	ones: .byte 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	zeros: .byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo

movl 8(%ebp), %eax				#%eax = @mata
movl 12(%ebp), %ebx				#%ebx = @matb
movl 16(%ebp), %ecx
imul %ecx, %ecx						#%ecx = n^2
movl $0, %esi							#%esi = iterador = 0
movdqa ones, %xmm1
movdqa zeros, %xmm2
for:
cmpl %ecx, %esi
jge fifor         #jumps if (%esi >= %ecx)

movdqa (%eax, %esi), %xmm0  	# mata[valor]
pand %xmm1, %xmm0
pcmpgtb %xmm2, %xmm0
movdqa %xmm0, (%ebx, %esi)   	# assignem al pixel

addl $16, %esi
jmp for
fifor:

# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
