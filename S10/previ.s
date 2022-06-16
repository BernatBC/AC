1-https://namazso.github.io/x86/
pand: Logical AND
pcmpgtb: Compare Packed Signed Integers for Greater Than
movdqa: Move Aligned Packed Integer Values
movdqu: Move Unaligned Packed Integer Values
emms:	Empty MMX Technology State

2- https://stackoverflow.com/questions/1458573/attribute-in-gnu-c
One use is for enforcing memory alignment on variables and structure members.

3-
pushl	%ebp
movl	%esp, %ebp
pushl	%ebx
pushl	%esi

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

popl	%esi
popl	%ebx
movl %ebp,%esp
popl %ebp
ret


4-
  pushl $immediat
  pushl $0
  pushl $0
  pushl $0
  movdqu (%esp), %xmm0

5-
pushl	%ebp
movl	%esp, %ebp
pushl	%ebx
pushl	%esi

pushl $1
pushl $0
pushl $0
pushl $0

movl 4(%ebp), %eax				#%eax = @mata
movl 8(%ebp), %ebx				#%ebx = @matb
movl 12(%ebp), %ecx
imul %ecx, %ecx						#%ecx = n^2
movl $0, %esi							#%esi = iterador = 0
jmp fi_bucle
bucle:
movdqu (%esp), %xmm0
pand (%eax, %esi), %xmm0		#%xmm0 = mata[i*n+j] & 1
movdqu %xmm0, (%ebx, %esi)
pcmpgtb $0, (%ebx, %esi)			#if (matb[i*n+j]>0)
jle else

movdqu $255, (%ebx, %esi)		#matb[i*n+j]=255
jmp fi_if

else:
movdqu $0, (%ebx, %esi)		#matb[i*n+j]=0
fi_if:
addl $16, %esi
fi_bucle:
cmpl %esi, %ecx
jg bucle

addl $-16, %esp
popl	%esi
popl	%ebx
movl %ebp,%esp
popl %ebp
ret

6-

shll $28, %eax
jne
