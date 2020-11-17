global _ft_strcpy

section .text

_ft_strcpy:
				push rdi
				push rdx
				xor rax, rax
loop:
				cmp byte[rsi + rax], 0
				je	return
				mov dl, byte[rsi + rax]
				mov byte[rdi + rax], dl
				inc rax
				jmp loop
return:
				mov byte[rdi + rax], 0
				mov rax, rdi
				pop rdx
				pop rdi
				ret
