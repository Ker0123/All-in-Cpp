#include <iostream>

using namespace std;

int global_var1 = 10;
int global_var2 = 10;
const int const_global_var = 10;
static int golobal_static_var1 = 10;

void Mem_areas_verify(int arg = 0)
{
    static int static_var1 = 10;
    static int static_var2 = 10;
    printf("全局变量        in\t0x%0.8x\n", &global_var1);
    printf("全局变量        in\t0x%0.8x\n", &global_var2);
    printf("全局变量(const) in\t0x%0.8x\n", &const_global_var);
    printf("静态变量(全局)  in\t0x%0.8x\n", &golobal_static_var1);
    printf("静态变量        in\t0x%0.8x\n", &static_var1);
    printf("静态变量        in\t0x%0.8x\n", &static_var2);
    printf("常量            in\t0x%0.8x\n", &"Hello, World!");
    {
        int local_var1 = 20;
        int local_var2 = 20;
        const int const_local_var = 20;
        printf("局部变量        in\t0x%0.8x\n", &local_var1);
        printf("局部变量        in\t0x%0.8x\n", &local_var2);
        printf("局部变量(const) in\t0x%0.8x\n", &const_local_var);
    }
    printf("函数参数        in\t0x%0.8x\n", &arg);
    int *ptr = new int(10);
    int *ptr2 = new int(20);
    printf("动态内存        in\t0x%0.8x\n", ptr);
    printf("动态内存        in\t0x%0.8x\n", ptr2);
    delete ptr;
    delete ptr2;
}

int main()
{
    cout << "\n\nLast build on : " << __DATE__ << " " << __TIME__ << endl
         << endl;

    Mem_areas_verify(); // 内存分布验证

    return 0;
}