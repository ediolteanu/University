%include "io.inc"

section .data
source_text: db "ABCABCBABCBABCBBBABABBCBABCBAAACCCB", 0
substring: db "BABC", 0

source_length: resb 0
substr_length: dd 4

print_format: db "Substring found at index: ", 0

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    push ebp
    mov ebp, esp

    ; TODO: Fill source_length with the length of the source_text string.
    ;PRINT_UDEC 4, [source_length]
    ;NEWLINE
    ; Find the length of the string using scasb.
    mov al, 0x00
    mov edi, source_text
    repne scasb
    sub edi, source_text
    dec edi
    mov [source_length], edi

    PRINT_UDEC 4, [source_length]
    NEWLINE
    
    ; TODO: Print the start indices for all occurrences of the substring in source_text
    mov esi, [source_text]
    mov edi, [substring]


    leave
    ret
