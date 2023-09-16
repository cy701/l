assume cs:code   ;判断是不是代码段

code segment    ;汇编代码标准开头
start:  mov ax,cs
        mov ds,ax
        mov si,offset do0    ;源地址 cs代表这个代码段
        mov ax,0
        mov es,ax
        mov di,200h         ;目的地址，0号int就是200h
        mov cx,offset do0end-offset do0  ;长度
        cld  ;正向延展
        rep movsb   ;这个特别重要的指令，写入内存，实现非常复杂

        mov ax,4c00h
        int 21h   ;这个不太清楚，可能与屏幕中断有关，不知道下面为什么还写了一个

do0:    jmp short do0start  ;代码开头不能为字符串，要跳转，我也不知道为什么不能为字符串
        db "hellofault"
do0start:   mov ax,cs
            mov ds,ax
            mov si,202h ;找到写入内存的字符串

            mov ax,0b800h
            mov es,ax
            mov di,12*160+36*2  ;显存随便找一个中间位置

            mov cx,10    ;下面要遍历的字符串长度
s:      mov al,[si]
        mov es:[di],al
        inc si   ;++
        add di,2    ;di+2=di di是loop的偏移
        loop s
        ;s的目的是让偏移si累加1来达到读取字符串的目的，但我不知道为什么s的si累加与上面的函数起作用。
        mov ax,4c00h
        int 21h   ;又来一遍
do0end:nop;不知道什么用
code ends
end start  ;不知道什么用
