    .section .rodata     ;
    .global Msg          ;
    ;.type Msg, @object      ; 
    ;.align 4                // If need to assign alignment.

Msg:
    .incbin "msg.txt"
Msg_end:
    .global MsgSize
    ;.type   MsgSize, @object ; 

    ;.align 4                // If need to assign alignment.
MsgSize:
    .int Msg_end - Msg
