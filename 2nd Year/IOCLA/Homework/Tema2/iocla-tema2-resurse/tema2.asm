%include "include/io.inc"

extern atoi
extern printf
extern exit

; Functions to read/free/print the image.
; The image is passed in argv[1].
extern read_image
extern free_image
; void print_image(int* image, int width, int height);
extern print_image

; Get image's width and height.
; Store them in img_[width, height] variables.
extern get_image_width
extern get_image_height

section .data
	use_str db "Use with ./tema2 <task_num> [opt_arg1] [opt_arg2]", 10, 0
        task2_message db "C'est un proverbe francais.", 0
section .bss
    task:       resd 1
    img:        resd 1
    img_width:  resd 1
    img_height: resd 1
    task3_message: resd 1 
    task3_index: resd 1
    task4_message: resd 1
    task4_index: resd 1
    task5_index: resd 1
    
section .text
global main

    ;function that applies xor on every value in the string to find "revient"
bruteforce_singlebyte_xor:
    push ebp
    mov ebp, esp
    xor edx, edx ;represents key
    mov edi, [img]

    ;reinitialize height and width registers when trying a new key
next_key:
    xor ebx, ebx ;line
    xor ecx, ecx ;column
    
next_byte:          
    ;calculates the adress of the next byte and puts it in eax
    push ecx  
    push edx
    mov eax, [img_width]
    mul ebx
    add eax, ecx
    mov ecx, eax
    mov eax, [edi + 4 * ecx] 
    pop edx
    
    xor eax, edx ;applies xor between the byte value and current key
    
    ;checks if the byte value is the ascii code for 'r'
    ;then checks if the next letters are the one in "revient"
    ;if not jumps to the initializer for the next byte
    cmp eax, "r"
    jne verify_dimensions

    inc ecx
    mov eax, [edi + 4 * ecx]
    xor eax, edx
    cmp eax, "e"
    jne verify_dimensions
    
    inc ecx
    mov eax, [edi + 4 * ecx]
    xor eax, edx
    cmp eax, "v"
    jne verify_dimensions
    
    inc ecx
    mov eax, [edi + 4 * ecx]
    xor eax, edx
    cmp eax, 'i'
    jne verify_dimensions
    
    inc ecx
    mov eax, [edi + 4 * ecx]
    xor eax, edx
    cmp eax, 'e'
    jne verify_dimensions
    
    inc ecx
    mov eax, [edi + 4 * ecx]
    xor eax, edx
    cmp eax, 'n'
    jne verify_dimensions
    
    inc ecx
    mov eax, [edi + 4 * ecx]
    xor eax, edx
    cmp eax, 't'
    jne verify_dimensions
    
    ;this is for when the function is applied in task 2
    ;just to find the line, without printing the results
    mov eax, [task]
    cmp eax, 2
    je end_without_print
    
    ;if it is task 1 and it finds revient it jumps to print
    jmp print_values
    
    ;increments the registers for the index for the next byte
verify_dimensions:
    pop ecx
    inc ecx
    cmp ecx, [img_width]
    jl next_byte
    
    inc ebx
    mov ecx, 0
    cmp ebx, [img_height]
    jl next_byte

    ;if not all the keys where applied, it tries the next one
    inc edx
    cmp edx, 255
    jle next_key
    
    ;prints the message, the key and the line
print_values:
    push edx
    push ebx
    mov eax, [img_width]
    mul ebx
    mov ebx, eax
    mov eax, [edi + 4 * ebx] ;first character of the line
    pop ebx
    pop edx
    xor eax, edx
    
    xor ecx, ecx
next_char:      ;prints the line until it finds null terminator
    PRINT_CHAR eax
    inc ecx
    push edx
    push ebx
    ;calculates the adress of the next byte
    mov eax, [img_width]
    mul ebx
    add eax, ecx
    mov ebx, eax
    mov eax, [edi + 4 * ebx]
    pop ebx
    pop edx
    
    xor eax, edx
    cmp eax, 0
    jne next_char
    
    NEWLINE
    PRINT_DEC 4, edx ;key
    NEWLINE
    PRINT_DEC 4, ebx ;line
    NEWLINE

    ;just for task2 so it finds the values but doesn't print them
end_without_print:
    leave
    ret

    ;function that resolves task2
encrypt_message:
    push ebp
    mov ebp, esp
    
    mov edi, [img]
    push edx
    push ebx
    ;calculates number of pixels
    mov eax, [img_height]
    mov ebx, [img_width]
    mul ebx
    mov ecx, eax
    pop ebx
    pop edx    
    
    push ecx ; number of pixels
    ;decrypts the whole matrix by applying xor on every byte
decrypt_matrix:  
    xor [edi + 4 * (ecx - 1)], edx 
    loop decrypt_matrix    
    
    ;calculates adress of the first byte to write
    push edx
    inc ebx
    mov eax, [img_width]
    mul ebx
    mov ecx, 4
    mul ecx
    pop edx
    mov ebx, eax
    xor ecx, ecx
    
    ;moves every character of the message in the matrix
write_char:       
    mov eax, [task2_message + ecx]
    mov byte[edi + ebx], al
    inc ecx
    add ebx, 4
    cmp eax, 0
    jne write_char
    
    ;calculates new key
    mov eax, edx
    mov ecx, 2
    mul ecx
    add eax, 3
    mov ecx, 5
    div ecx
    sub eax, 4
    mov edx, eax
    
    pop ecx ; number of pixels
    ;encrypts the whole matrix with the new key
encrypt_matrix:
    xor [edi + 4 * (ecx - 1)], edx
    loop encrypt_matrix

    ;writes the image
    push dword[img_height]
    push dword[img_width]
    push edi
    call print_image
    add esp, 12
    
    leave
    ret
    
    ;function that resolves task3
morse_encrypt:
    push ebp
    mov ebp, esp
    
    ;initialize registers with needed adresses
    mov esi, [task3_message]
    mov edi, [img]
    mov edx, [task3_index]
    xor ecx, ecx
    
    ;moves one character of the message in al
    ;then jumps to the relative label
encrypt_letter:
    mov al, byte[esi + ecx]
    
    cmp al, 'A'
    je encrypt_A
    
    cmp al, 'B'
    je encrypt_B
    
    cmp al, 'C'
    je encrypt_C
    
    cmp al, 'D'
    je encrypt_D
    
    cmp al, 'E'
    je encrypt_E
    
    cmp al, 'F'
    je encrypt_F
    
    cmp al, 'G'
    je encrypt_G
    
    cmp al, 'H'
    je encrypt_H
    
    cmp al, 'I'
    je encrypt_I
    
    cmp al, 'J'
    je encrypt_J
    
    cmp al, 'K'
    je encrypt_K
    
    cmp al, 'L'
    je encrypt_L
    
    cmp al, 'M'
    je encrypt_M
    
    cmp al, 'N'
    je encrypt_N
    
    cmp al, 'O'
    je encrypt_O
    
    cmp al, 'P'
    je encrypt_P
    
    cmp al, 'Q'
    je encrypt_Q
    
    cmp al, 'R'
    je encrypt_R
    
    cmp al, 'S'
    je encrypt_S
    
    cmp al, 'T'
    je encrypt_T
    
    cmp al, 'U'
    je encrypt_U
    
    cmp al, 'V'
    je encrypt_V
    
    cmp al, 'W'
    je encrypt_W
    
    cmp al, 'X'
    je encrypt_X
    
    cmp al, 'Y'
    je encrypt_Y
    
    cmp al, 'Z'
    je encrypt_Z
    
    cmp al, '0'
    je encrypt_0
    
    cmp al, '1'
    je encrypt_1
    
    cmp al, '2'
    je encrypt_2
    
    cmp al, '3'
    je encrypt_3
    
    cmp al, '4'
    je encrypt_4
    
    cmp al, '5'
    je encrypt_5
    
    cmp al, '6'
    je encrypt_6
    
    cmp al, '7'
    je encrypt_7
    
    cmp al, '8'
    je encrypt_8
    
    cmp al, '9'
    je encrypt_9
    
    cmp al, ','
    je encrypt_comma
    
    ;each label encrypts the relative letter in morse code
    ;and at the same time writting the relative characters in the matrix
    ;after, jumps to the label for the next character
encrypt_A:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_B:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_C:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_D:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_E:
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_F:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_G:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_H:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_I:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_J:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_K:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_L:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_M:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_N:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_O:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_P:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_Q:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_R:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_S:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_T:
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_U:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_V:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_W:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_X:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_Y:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_Z:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_0:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_1:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_2:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_3:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_4:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    jmp verify_next_char
    
encrypt_5:
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_6:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_7:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_8:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_9:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    jmp verify_next_char
    
encrypt_comma:
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '.'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    mov byte[edi + 4 * edx], '-'
    inc edx
    
    ;verifies if the next character in the string is not null terminator
    ;if not, encrypts it
verify_next_char:
    mov al, byte[esi + ecx + 1]
    cmp al, 0
    je end_encrypt
    
    ;after every encrypted letter, insert space
    inc ecx
    mov byte[edi + 4 * edx], ' '
    inc edx
    jmp encrypt_letter
    
    ;when it finds null terminator, insert it and write image
end_encrypt:
    mov byte[edi + 4 * edx], 0
    
    push dword[img_height]
    push dword[img_width]
    push edi
    call print_image
    add esp, 12

    leave
    ret

    ;resolves task4
lsb_encode:
    push ebp
    mov ebp, esp

    ;initialize registers with needed adresses
    mov edi, [img]
    mov esi, [task4_message]
    mov edx, [task4_index]
    dec edx
    
    xor ebx, ebx
    ;takes one character from the message string
encode_letter:
    mov al, byte[esi + ebx]
    
    ;for each bit in the byte it shifts it left and right so it remains
    ;something like 0000000x - on the LSB position
    ;then removes the LSB of the value from the matrix and adds the
    ;previous calculated value
    xor ecx, ecx
for_each_bit:
    push eax
    shl al, cl
    shr al, 7
    shr byte[edi + 4 * edx], 1
    shl byte[edi + 4 * edx], 1
    add byte[edi + 4 * edx], al
    inc edx
    pop eax
    inc ecx
    cmp ecx, 7
    jle for_each_bit
   
    ;if current character wasn't null terminator it goes to the next byte
    ;else it writes image
    inc ebx
    cmp al, 0
    jne encode_letter
    
    push dword[img_height]
    push dword[img_width]
    push dword[img]
    call print_image
    add esp, 12
    
    leave
    ret

    ;function used to resolve task 5
lsb_decode:
    push ebp
    mov ebp, esp
    
    ;initialize needed adresses
    mov edi, [img]
    mov edx, [task5_index]
    
    ;reinitialize registers for next letter
next_letter:
    xor ebx, ebx 
    mov ecx, 8
    
    ;for a sequence of 8 bytes, take the LSB of each and
    ;recreate the original byte by appending the bits
    ;by shifting them to left and adding the next bit
decode_letter:
    mov al, byte[edi + 4 * edx]
    shl bl, 1 
    shl al, 7
    shr al, 7
    xor bl, al
    dec ecx
    inc edx
    cmp ecx, 0
    jg decode_letter
    
    shr bl, 1
    ;if last recontructed byte was null terminator jump to end
    ;else decode next letter
    cmp bl, 0
    je end
    PRINT_CHAR bl ;print letter
    jne next_letter
    
end:    
    leave
    ret

    ;function used to resolve task 6
blur:
    push ebp
    mov ebp, esp
    
    mov edi, [img]
    
    mov ebx, 1 ;start from line 1, not 0
next_line:
    mov ecx, 1 ;reinitalize column to 1, not 0
    
parse_matrix:
    ;saves indices on stack
    push ebx
    push ecx
    ;gets the current element and puts it in eax
    mov eax, [img_width]
    mul ebx
    mov edx, eax
    add edx, ecx
    mov eax, [edi + 4 * edx]
    
    ;gets the upper element and adds it in eax
    push eax
    mov eax, ebx
    dec eax
    push ecx
    mov ecx, [img_width]
    mul ecx
    pop ecx
    mov edx, eax
    add edx, ecx
    pop eax
    add eax, [edi + 4 * edx]
    
    ;gets the lower element and adds it in eax
    push eax
    mov eax, ebx
    inc eax
    push ecx
    mov ecx, [img_width]
    mul ecx
    pop ecx
    mov edx, eax
    add edx, ecx
    pop eax
    add eax, [edi + 4 * edx]
    
    ;gets the left element and adds it in eax
    push eax
    mov eax, [img_width]
    mul ebx
    mov edx, eax
    add edx, ecx
    dec edx
    pop eax
    add eax, [edi + 4 * edx]
    
    ;gets the right element and adds it in eax
    push eax
    mov eax, [img_width]
    mul ebx
    mov edx, eax
    add edx, ecx
    inc edx
    pop eax
    add eax, [edi + 4 * edx]
    
    ;divides by 5 - arithmetic mean of the 5 elements 
    mov ecx, 5
    div cl
    
    ;restores indices
    pop ecx
    pop ebx
    ;puts the current arithmetic mean on the stack
    ;at the and of the loop all the means will be on the stack
    push eax
    
    ;increments the column
    inc ecx
    mov edx, [img_width]
    dec edx
    cmp ecx, edx
    jl parse_matrix
    
    ;increments the line
    inc ebx
    mov edx, [img_height]
    dec edx
    cmp ebx, edx
    jl next_line
    
    ;parses the matrix in the opposite order, in order to
    ;write the elements saved on the stack in the correct order
    sub ebx, 1 ;starts from the second last line
previous_line:    
    mov ecx, [img_width]
    sub ecx, 2 ;reinitalize the second last column
write_elements:
    ;get current byte adress
    mov eax, [img_width]
    mul ebx
    mov edx, eax
    add edx, ecx
    
    ;write mean on it's relative byte
    pop eax
    mov byte[edi + 4 * edx], al
    
    ;decrement column
    dec ecx
    cmp ecx, 0
    jg write_elements
    
    ;decrement line
    dec ebx
    cmp ebx, 0
    jg previous_line
    
    ;write image
    push dword[img_height]
    push dword[img_width]
    push edi
    call print_image
    add esp, 12
    
    leave
    ret
    
    
main:
    mov ebp, esp; for correct debugging
    ; Prologue
    ; Do not modify!
    push ebp
    mov ebp, esp

    mov eax, [ebp + 8]
    cmp eax, 1
    jne not_zero_param

    push use_str
    call printf
    add esp, 4

    push -1
    call exit

not_zero_param:
    ; We read the image. You can thank us later! :)
    ; You have it stored at img variable's address.
    mov eax, [ebp + 12]
    push DWORD[eax + 4]
    call read_image
    add esp, 4
    mov [img], eax

    ; We saved the image's dimensions in the variables below.
    call get_image_width
    mov [img_width], eax

    call get_image_height
    mov [img_height], eax

    ; Let's get the task number. It will be stored at task variable's address.
    mov eax, [ebp + 12]
    push DWORD[eax + 8]
    call atoi
    add esp, 4
    mov [task], eax

    ; There you go! Have fun! :D
    mov eax, [task]
    cmp eax, 1
    je solve_task1
    cmp eax, 2
    je solve_task2
    cmp eax, 3
    je solve_task3
    cmp eax, 4
    je solve_task4
    cmp eax, 5
    je solve_task5
    cmp eax, 6
    je solve_task6
    jmp done

solve_task1:
    ;call function to resolve task1
    call bruteforce_singlebyte_xor
    jmp done
    
solve_task2:
    ;call function to find message
    call bruteforce_singlebyte_xor
    ;call function to write the intended response
    call encrypt_message
    jmp done
    
solve_task3:
    ;read arguments from command line and write them in variables in .bss
    mov eax, [ebp + 12]
    mov ebx, [eax + 12]
    mov [task3_message], ebx
    
    push DWORD[eax + 16]
    call atoi
    add esp, 4
    mov [task3_index], eax
    
    ;call function to resolve task3
    call morse_encrypt
    jmp done
    
solve_task4:
    ;read arguments from command line and write them in variables in .bss
    mov eax, [ebp + 12]
    mov ebx, [eax + 12]
    mov [task4_message], ebx
    
    push DWORD[eax + 16]
    call atoi
    add esp, 4
    mov [task4_index], eax
    
    ;call function to resolve task4
    call lsb_encode
    jmp done
    
solve_task5:
    ;read argument from command line and write them in variable in .bss
    mov eax, [ebp + 12]
    push DWORD[eax + 12]
    call atoi
    add esp, 4
    mov [task5_index], eax
    
    ;call function to resolve task5
    call lsb_decode
    jmp done
    
solve_task6:
    ;call function to resolve task6
    call blur  
    jmp done

    ; Free the memory allocated for the image.
done:
    push DWORD[img]
    call free_image
    add esp, 4
    ; Epilogue
    ; Do not modify!
    xor eax, eax
    leave
    ret
    
