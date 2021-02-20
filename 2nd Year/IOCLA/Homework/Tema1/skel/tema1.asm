%include "includes/io.inc"

extern getAST
extern freeAST

section .bss
    ; La aceasta adresa, scheletul stocheaza radacina arborelui
    root: resd 1

section .data
    operations_nr dd 0
    helper dw 0
section .text   
global main

    ;functie care tranforma un string de cifre in numar
char_to_int:
    push ebp
    mov ebp, esp
    
    ;in edi este pus parametrul dat functiei - stringul
    mov edi, [esp + 8]
    xor eax, eax
    
    ;se parcurge fiecare byte din string
while:
    movzx esi, byte[edi]
    inc edi
    
    ;daca este null inseamna ca string-ul s-a terminat
    cmp esi, 0x00
    je end
    
    ;se verifica daca primul byte este minus, in caz ca numarul e negativ
    cmp esi, 45
    jne positive_nr
    mov ecx, 1
    jmp while

    ;se scade 48 pentru a transforma valoarea din ascii in valoarea din baza 10 a cifrei
positive_nr:    
    sub esi, 48
    add eax, esi
    
    ;daca urmatorul byte este null, string-ul s-a terminat
    cmp byte[edi], 0x00
    je end
    
    ;se inmulteste cu 10 pentru a trece la urmatoarea cifra corect
    mov ebx, 10
    mul ebx
    jmp while
    
    ;se inmulteste cu -1 daca numarul e negativ
end:
    cmp ecx, 1
    jne positive_end
    mov ebx, -1
    imul ebx
positive_end:
    leave
    ret

main:
    mov ebp, esp; for correct debugging
    ; NU MODIFICATI
    push ebp
    mov ebp, esp
    
    ; Se citeste arborele si se scrie la adresa indicata mai sus
    call getAST
    mov [root], eax
    
    ; Implementati rezolvarea aici:
    xor ecx, ecx
    xor edx, edx
    
    mov eax, [root]
    mov ebx, [eax]
    
    ;am interpretat arborele ca un "vector" de adrese, la fiecare 32 de bytes aflandu-se un nod
    ;se calculeaza mai intai numarul de bytes folositi de noduri
calculate_operations_nr:
    add edx, 32
    cmp dword[ebx + edx], 0x00
    jne calculate_operations_nr
    mov [operations_nr], edx
    
    ;se parcurge fiecare nod in ordine inversa introducerii
    xor edx, edx
    mov ecx, [operations_nr]
    sub ecx, 32
do_operations:
    mov edx, ebx
    add edx, ecx
    
    ;se verifica mai intai daca este operator
    cmp byte[edx], 43
    je add_numbers
    
    cmp byte[edx + 1], 0x00
    jne is_number
    cmp byte[edx], 45
    je substract
    
    cmp byte[edx], 42
    je multiply
    
    cmp byte[edx], 47
    je divide  
    
    ;daca nu este se tranforma string-ul in numar si se pune in stiva
is_number:    
    push ebx
    push ecx
    push edx
    call char_to_int
    pop edx
    pop ecx
    pop ebx
    push eax
    jmp repeat

    ;pentru fiecare operatie se extrag 2 numere din stiva si se efectueaza operatia
    ;rezultatul este pus inapoi pe stiva
add_numbers:    
    pop eax
    pop edx
    add eax, edx
    push eax
    jmp repeat
     
substract:
    pop eax
    pop edx
    sub eax, edx
    push eax
    jmp repeat

multiply:
    pop eax
    pop edx
    imul edx
    push eax
    jmp repeat

    ;helper ajuta la salvarea adresei din ebx, pentru a putea parcurge arborele incontinuare
divide:
    mov [helper], ebx
    pop eax
    cdq
    pop ebx
    idiv ebx
    push eax
    mov ebx, [helper]
    jmp repeat

    ;la trecerea prin fiecare nod se scad 32 de bytes si se opreste atunci cand se termina toate nodurile
repeat:
    sub ecx, 32
    cmp ecx, 0
    jge do_operations
    
    ;in eax este pusa valoarea finala stocata pe stiva, si apoi este afisata
    pop eax
    PRINT_DEC 4, eax
    NEWLINE
    ; NU MODIFICATI
    ; Se elibereaza memoria alocata pentru arbore
    push dword [root]
    call freeAST
    
    xor eax, eax
    leave
    ret