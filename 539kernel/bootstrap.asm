start:
    mov ax, 07C0h
    mov ds, ax

    mov si, title_string
    call print_string

    mov si, message_string
    call print_string

    call load_kernel_from_disk
    jmp 0900h:0000

load_kernel_from_disk:
    ; Explanation page 84
    mov ax, [curr_sector_to_load]
    sub ax, 2
    mov bx, 512d
    mul bx
    mov bx, ax

    mov ax, 0900h
    mov es, ax

    ; Full explanation page 33
    mov ah, 02h
    mov al, 01h
    mov ch, 0h
    mov cl, [curr_sector_to_load] ; Explanation page 84
    mov dh, 0h
    mov dl, 80h
    int 13h

    jc kernel_load_error

    ; Explanation page 84
    sub byte [number_of_sectors_to_load], 1
    add byte [curr_sector_to_load], 1
    cmp byte [number_of_sectors_to_load], 0

    jne load_kernel_from_disk

    ret

kernel_load_error:
    mov si, load_error_string
    call print_string

    jmp $

print_string:
    ; Full explanation page 35
    mov ah, 0Eh

print_char:
    lodsb

    cmp al, 0
    je printing_finished

    int 10h

    jmp print_char

printing_finished:
    mov al, 10d ; Print new line
    int 10h

    ; Reading current cursor position
    mov ah, 03h
    mov bh, 0
    int 10h

    ; Move the cursor to the beginning
    mov ah, 02h
    mov dl, 0
    int 10h

    ret

title_string                db  'The Bootloader of 539kernel.', 0
message_string              db  'The kernel is loading...', 0
load_error_string           db  'The kernel cannot be loaded', 0
number_of_sectors_to_load   db  15d
curr_sector_to_load         db  2d

times 510-($-$$) db 0
dw 0xAA55