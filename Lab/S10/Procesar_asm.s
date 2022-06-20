.text
	.align 4
	.globl procesar
	.type	procesar, @function
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
jmp fi_bucle
bucle:
movb $1, %dl
andb (%eax, %esi), %dl		#%dl = mata[i*n+j] & 1
movb %dl, (%ebx, %esi)
cmpb $0, (%ebx, %esi)			#if (matb[i*n+j]>0)
jle else

movb $255, (%ebx, %esi)		#matb[i*n+j]=255
jmp fi_if

else:
movb $0, (%ebx, %esi)		#matb[i*n+j]=0
fi_if:
incl %esi
fi_bucle:
cmpl %esi, %ecx
jg bucle
# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
