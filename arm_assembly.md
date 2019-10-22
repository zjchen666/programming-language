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

## entry 和 #entry 的区别
```cpp
 #entry  - elf 文件编译时 assign的地址
 entry - 当前加载运行的符号位置 相对于PC
```
