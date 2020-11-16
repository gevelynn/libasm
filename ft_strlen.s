global _ft_strlen

section .text
_ft_strlen:
				xor rax, rax
loop:
				cmp byte[rdi + rax], 0
				je	return
				inc rax
				jmp	loop
return:			
				ret

