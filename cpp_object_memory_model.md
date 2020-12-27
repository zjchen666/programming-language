## c++ 虚函数表
https://blog.csdn.net/haoel/article/details/1948051?spm=a2c6h.12873639.0.0.647b4a13efFV1E

## 对象使用内存：
1. 非虚函数， - 不占内存.  
2. 虚函数， - 虚函数表 pointer size。  
3. 静态数据 - 不算对象内存
4. 非静态数据 - 算。
5. 占位符 - size 1
