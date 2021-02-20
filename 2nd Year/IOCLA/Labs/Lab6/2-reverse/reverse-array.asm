%include "io.inc"

section .data

%define ARRAY_LEN 7

    input dd 122, 184, 199, 242, 263, 845, 911
    output times ARRAY_LEN dd 0

section .text
global CMAIN
CMAIN:

    ; TODO push the elements of the array on the stack
    ; TODO retrieve the elements (pop) from the stack into the output array
    mov ecx, ARRAY_LEN
    mov ebx, 0
inp:
    mov edx, [input + ebx * 4]
    inc ebx
    push edx
    loop inp
    
    mov ebx, 0
    mov ecx, ARRAY_LEN
outp:
    pop edx
    mov [output + ebx * 4], edx
    inc ebx
    loop outp   
    
    PRINT_STRING "Reversed array:"
    NEWLINE
    xor ecx, ecx
print_array:
    PRINT_UDEC 4, [output + 4 * ecx]
    NEWLINE
    inc ecx
    cmp ecx, ARRAY_LEN
    jb print_array

    xor eax, eax
    ret
