data segment
  crlf db 0dh, 0ah,'$'
data ends

assume cs:code, ds:data
code segment

start:
   mov ax,data
   mov ds,ax
   xor bx,bx
   xor cx,cx
   mov ah,01
   int 21h
   sub al,'0'
   mov cl,al

next:
   inc bx
   push cx
   call star
   pop cx
   loop next

   mov ah,4ch
   int 21h

star:
   mov cx,bx
   call println

printstar:
   mov dl,'*'
   mov ah,02
   int 21h
   loop printstar

   ret

println:
   lea dx,crlf
   mov ah,9
   int 21h
   ret


code ends
   end start
