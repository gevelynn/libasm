global _ft_strcmp

section .text
_ft_strcmp:
				xor rax, rax
				xor rdx, rdx
				xor rcx, rcx
loop:
				mov al, byte[rdi + rcx]
				mov dl, byte[rsi + rcx]
				sub al, dl
				jne return
				cmp dl, 0
				je return
				inc rcx
				jmp loop
return:
				ret
