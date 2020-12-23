data segment
   F12 DW 0
data ends

assume cs:code, ds:data
code segment

start:
   mov ax,data
   mov ds,ax
   xor ax,ax
   mov ax,12

   call calc

   mov ah,4ch
   int 21h
   ret

calc:
   mov cl,2
   sal ax,cl
   add ax,7
   mov F12,ax
   ret

code ends
   end start
