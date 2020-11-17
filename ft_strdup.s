global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

section .text

_ft_strdup:
				push rsi
				push rdi
				call _ft_strlen
				mov rdi, rax
				inc rdi
				call _malloc
				cmp rax, 0
				je return_error
				mov rdi, rax
				pop rsi
				call _ft_strcpy
				pop rsi
				ret
return_error:
				pop rdi
				pop rsi
				ret
