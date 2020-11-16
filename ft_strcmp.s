global _ft_strcmp

section .text
_ft_strcmp:
				push rdx
				push rcx
				xor rax, rax
				xor rdx, rdx
				xor rcx, rcx
loop:
				cmp byte[rsi + rcx], 0
				je return
				mov byte[rdi + rcx], byte[rsi + rcx]
				inc rcx
				jmp loop
return:
				pop rcx
				pop rdx
				ret
