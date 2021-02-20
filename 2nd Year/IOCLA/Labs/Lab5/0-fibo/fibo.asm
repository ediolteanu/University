%include "io.inc"
section .data
    N dd 9 ; compute the sum of the first N fibonacci numbers
    var dd 0 
section .text
global CMAIN
CMAIN:
    push ebp
    mov ebp, esp

    ; TODO: calculate the sum of first N fibonacci numbers
    ;       (f(0) = 0, f(1) = 1)
    ;       store the sum in eax
    ;       use loop instruction 
    mov ebx, 0
    mov edx, 1
    mov ecx, [N]
    sub ecx, 2
    

sum:
    add ebx, edx
    mov [var], ebx
    mov ebx, edx
    mov edx, [var]
    add eax, edx 
    loop sum
    
    PRINT_STRING "Sum first "
    PRINT_DEC 4, [N]
    PRINT_STRING " fibo is "
    PRINT_UDEC 4, eax

    xor eax, eax
    leave
	ret
