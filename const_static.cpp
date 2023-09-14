/*
    用const表示只读 (运行时)
    用constexpr表示常量 (编译时)   // c++11
    用static表示静态,生命周期是程序执行时,存储在数据段
*/ 

#include <iostream>
using namespace std;

// 函数可近似看成全局变量，存储在代码段

int g = 0; // 全局变量，全局可见，外部可访问，生命周期为程序执行时，存储在数据段
// int g; // 未初始化就存储在bss段
const int cg = 0; // 全局只读变量，全局可见，外部可访问，生命周期为程序执行时，存储在数据段
static int si = 0; // 静态全局变量，全局可见，外部不可访问，生命周期为程序执行时，存储在数据段
static constexpr int cei = 0; // 显示声明更好，隐式也是static，全局可见，外部不可访问，生命周期程序，存储在数据段
// constexpr int ceii; // error: 常量必须在声明时初始化，这是区分常量与只读变量的一大关键,另外常量在编译时就赋值

int main () {
    // 局部变量从存储上分，分为auto,static,register
    // auto: 普通,存储在栈上或堆上,c++17后只用于自动推断变量类型，取消占位作用
    // static: 静态,存储在数据段
    // register: 寄存器变量,存储在寄存器上(优先，但还要取决于硬件和实现的限制)

    int l = 0; // 局部变量，{}内可见，生命周期为函数，存储在栈
    int* l1 = new int(1); // l1指针局部变量，与普通局部变量一样，但指向的区域放在堆
    const int cl = 0; // 局部只读变量，函数内可见，生命周期为函数，存储在栈
    static int sl = 0; // 静态局部变量，函数内可见，生命周期为函数，存储在数据段
    constexpr int cel = 0+1; // 可用常量表达式声明,用变量声明会报错,eg., x+1，必须初始化
    return 0;
}
