### 跳转指令：  
B: B without link  
BL: B with link  
BLX: B with link and exchange instruction set  
  
The BL and BLX instructions copy the address of the next instruction into LR (R14, the link register).  
The BX and BLX instructions can change __the processor state from ARM to Thumb, or from Thumb to ARM__.  

BLX label always changes the state.  
BX Rm and BLX Rm derive the target state from bit[0] of Rm:  
if bit[0] of Rm is 0, the processor changes to, or remains in, ARM state  
if bit[0] of Rm is 1, the processor changes to, or remains in, Thumb state.  

BL 的跳转是 __相对跳转__

### inline assemble
```cpp
asm(
code    /*汇编指令*/
: output operand list    
: input operand list      
: clobber list            
); 

example 1:
asm(
"mov %[result], %[value], ror #1" 
: [result] "=r" (y) 
: [value] "r" (x)
:
);

example 2:
asm(
"mov %0, %1, ror #1" 
: [result] "=r" (y) 
: [value] "r" (x)
:
);
```

“r” - 将输入变量放入通用寄存器,即eax,ebx,ecx,edx,esi,edi之一   
“m” - 内存变量  
" " - 操作数为内存变量，但寻址方式为自动增量  
“p” - 操作数是一个合法的内存地址（指针）  
“g” - 将输入变量放入eax，ebx，ecx，edx之一,或作为内存变量  
“X” - 操作数可以是任何类型  
“=” - 操作数在指令中是只写的（输出操作数）   
“+” - 操作数在指令中是读写类型的（输入输出操作数）   
跳转时 f表示forward向前，b表示backward向后  

http://www.ethernut.de/en/documents/arm-inline-asm.html

mrs   状态寄存器到通用寄存器  
msr   通用寄存器到状态寄存器  
ldr： 内存到寄存器  
str： 寄存器到内存  

Labels "xb" and "xf", where "x" is a number are a smart extension to the GNU assembly. It branches to the first found label "x" searching "forward" for "f" or "backward" for "b".mov vs ldr  



Note: “#” for mov, “=” for ldr. To define an immediate value
o MOV can only move an 8-bit value (0x00->0xff=255) into a register
while LDR can move a 32-bit value into a register. The immediate value is
prefixed by different characters in mov and ldr: “#” for mov, “=” for ldr.
E.g.
Mov r1,#255 ; ok, 255 is the biggest number you can mov
Mov r1,255 ; is wrong , missing #
Mov r1,#256 ; is wrong, the number is bigger than 255
Mov r1,#0x12340000 ; is wrong, the number is bigger than 255

Ldr r1,=255; you can do this,
Ldr r1,=256; you can do this,
Ldr r1,=0x12345678; you can do this,
是把0x12345678这个立即数存到r1中。
ldr r0, 0x12345678
是把0x12345678这个地址中的值存放到r0中。

o MOV can run faster than LDR.
o LDR can move a data from a memory address to a register, MOV can only
i) move data between two registers or ii) save a 8-bit immediate value to a
register. e.g.

adr 伪指令：
  编译源程序时，汇编器首先计算当前PC值（当前指令位置）到exper的距离,然后用一条ADD或者SUB指令替换这条伪指令，
例如:ADD register,PC,#offset_to_exper。

