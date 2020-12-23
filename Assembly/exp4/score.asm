; 采用模块化程序设计方法编写出以下各题的源程序并上机调试运行，显示（或打印）出结果�?
; 编写一计算比赛成绩子模块，要求完成以下功能�?
; ①　7名评委，每个评委给分范围为．0�?0分（整数）；
; ②　7名评委给分中，去掉一个最高分和一个最低分，剩�?名评委中的平均分即为参加者的得分（精确到小数点后１位）；
; ③将分数在光标位置处显示出来。�?
;实验四：七个评委打分问题
;让用户输�?�?~10之间的数(若某个数�?位数,再前面补0),
;去掉最高分和最低分后，取平均分�?输出保留一位小�?�?

DATAS SEGMENT
   disp1  db 'Please Input 7 1~2 digit numbers between 00~10',0ah,0dh
          db '(1-digit number with one 0(zero:30h) as prefix):',0ah,0dh,'$' ;10 02 03 10 09 10 08
   in_buf db 21
          db ?
          db 21 dup(?)
   data   db 7 dup(?)
   result db '  . ',0ah,0dh,'$'
DATAS ENDS

STACKS SEGMENT

STACKS ENDS

CODES SEGMENT
    assume cs:codes,ds:datas,ss:stacks
start:
    mov ax,datas
    mov ds,ax

    call parse
    call sum
    call claculate

    mov ah,4ch
    int 21h

claculate:
    mov bl,5
    div bl
    lea bx,result
    mov [bx],al
    add bx,3
    add ah,ah
    mov [bx],ah
    ret




sum:
    lea si,data
    lea di,data
    lea bx,data
    xor ax,ax
    mov cx,7
l2:
    mov dl,[bx]
    add al,dl
    cmp [si],dl
    jbe min
    mov si,bx
min:
    cmp [di],dl
    ja next2
    mov di,bx
next2:
    inc bx
    loop l2
    sub al,[si]
    sub al,[di]
    ret



parse:
    lea dx,in_buf
    mov ah,0ah
    int 21h
    mov cx,7
    lea si,in_buf
    lea di,data
    add si,2
l1:
    mov bl,[si]
    cmp bl,'1'
    je ten
    add si,1
    mov bl,[si]
    sub bl,30h
    mov [di],bl
    add si,2
    add di,1
    jmp next1
ten:
    mov BYTE PTR [di],10
    add si,3
    add di,1
    jmp next1
next1:
    loop l1
    ret

CODES ENDS
    END start