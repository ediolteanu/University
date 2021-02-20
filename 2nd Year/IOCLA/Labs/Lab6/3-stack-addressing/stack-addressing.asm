%include "io.inc"

%define NUM 5

section .text
global CMAIN
CMAIN:
    mov ebp, esp

    ; TODO 1: replace every push by an equivalent sequence of commands
    
    ; pushing an array on the stack
    mov ecx, NUM
push_nums:
    sub esp, 4
    mov [esp], ecx
    loop push_nums

    ; pushing a string on the stack
    sub esp, 4
    mov byte[esp], 0
    sub esp, 4
    mov dword[esp], "mere"
    sub esp, 4
    mov dword[esp], "are "
    sub esp, 4
    mov dword[esp], "Ana "
    

    ; TODO 2: print the stack in "address: value" format in the range of [ESP:EBP]
    ; (from low addresses to high addresses, byte by byte)
    mov eax, esp
print:
    PRINT_STRING "0x"
    PRINT_HEX 4, eax
    PRINT_STRING ":"
    PRINT_UDEC 1, [eax]
    NEWLINE
    inc eax
    cmp eax, ebp
    jne print

    ; TODO 3: print the string byte by byte
    mov eax, esp
    xor edx, edx
print2:
    PRINT_CHAR [eax]
    inc eax
    inc edx
    cmp edx, 12
    je exit
    cmp eax, ebp
    jne print2 
exit:
    ; TODO 4: print the array element by element
    NEWLINE
    mov eax, esp
    add eax, 16
print3:
    PRINT_UDEC 2, [eax]
    PRINT_CHAR " "
    add eax, 4
    cmp eax, ebp
    jne print3
    ; restore the previous value of the EBP (Base Pointer)
    mov esp, ebp

    ; exit without errors
    xor eax, eax
    ret
