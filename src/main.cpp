#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string>

#include "vector2.h"
#include "sample_class.h"
#include "stmanager.h"
#include "twowaytowait.h"

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

int &ref_add_10(int &arg)
{
    arg += 10;
    int &ref_of_arg = arg;
    return ref_of_arg;
}

void Ref_test()
{
    int num = 10;
    int &new_num = ref_add_10(num); // 将num+=10, 并返回引用。
    new_num += 10;                  // 返回的引用再+=10
    cout << "num = " << num << endl;
    cout << "new_num = " << new_num << endl;
}

void Time_test()
{
    // 以秒为单位更新时间显示
    time_t now;
    while (true)
    {
        time(&now);
        cout << ctime(&now) << endl;
        sleep(1);
    }
}

void Vector2_test()
{
    /**
     * 不同方式创建不同类型的向量
     * 操作符重载测试
     * 简单属性计算测试
     */

    Vector2<int> v_int_1(10, 20);
    Vector2<int> v_int_2 = {20, 30};
    cout << "v_int_1 = " << v_int_1 << endl;
    cout << "v_int_2 = " << v_int_2 << endl;

    Vector2<float> v_float_1(1.23f, 4.56f);
    Vector2<float> v_float_2 = v_float_1;
    cout << "v_float_1 = " << v_float_1 << endl;
    cout << "v_float_2 = " << v_float_2 << endl;

    Vector2<double> v_double_1(1.23, 4.56);
    Vector2<double> v_double_2(L_AND_A, 10.0, 60.0);
    cout << "v_double_1 = " << v_double_1 << endl;
    cout << "v_double_2 = " << v_double_2 << endl;
    cout << "v_double_2 : Length = " << v_double_2.length() << ", Angle = " << v_double_2.angle() << endl;
    Vector2<double> v_double_3 = v_double_2.normalize();
    cout << "v_double_2.normalize() = " << v_double_3 << endl;
    cout << "v_double_2.normalize() : Length = " << v_double_3.length() << ", Angle = " << v_double_3.angle() << endl;

    Vector2<int> v_int_t = v_int_1 + v_int_2;
    cout << "v_int_1 + v_int_2 = " << v_int_t << endl;

    v_int_t = v_int_1 - v_int_2;
    cout << "v_int_1 - v_int_2 = " << v_int_t << endl;

    if (v_float_1 == v_float_2)
        cout << "v_float_1 == v_float_2" << endl;
    else
        cout << "v_float_1!= v_float_2" << endl;

    if (v_double_1 != v_double_2)
        cout << "v_double_1 != v_double_2" << endl;
    else
        cout << "v_double_1 == v_double_2" << endl;

    Vector2<float> v_float_t;
    cout << "v_float_1 * 3.0 = " << v_float_1 * 3.0f << endl;

    v_float_t = v_float_1 / 2.0f;
    cout << "v_float_1 / 2.0f = " << v_float_t << endl;

    v_float_1 += v_float_2;
    cout << "v_float_1 += v_float_2 = " << v_float_1 << endl;

    v_double_1 -= {1.0, 2.0};
    cout << "v_double_1 -= {1.0, 2.0} = " << v_double_1 << endl;

    v_double_2 *= 2.0;
    cout << "v_double_2 *= 2.0 = " << v_double_2 << endl;

    cout << "v_double_1 /= 2.0 = " << (v_double_1 /= 2.0) << endl;
}

void Sample_class_test()
{
    Cat c1("Tom", 2);
    Cat c2("Jerry", 3);
    cout << "c1 = " << c1.name << endl;
    cout << "c2 = " << c2.name << endl;
}

void Sample_class_constructor_test()
{
    cout << "func start" << endl;
    ctest1 obj1;
    ctest2 obj2;
    cout << "func end" << endl;
}

// 新环境测试: 将编译工具换成了版本更新的w64devkit, 部分能用环境变量g++的用环境变量
void new_enviroment_test()
{
    cout << "new_enviroment_test start" << endl;
    int a = 10;
    int b = 20;
    int c = a + b;
    cout << "c = " << c << endl;
    cout << "new_enviroment_test end" << endl;
}

// 单例模式测试
void instance_test()
{
    StManager *s1 = StManager::GetInstance();
    StManager *s2 = StManager::GetInstance();
    s1->changeDir(Vector2<float>(3.0f, 4.0f));
    s2->changeDir(Vector2<float>(4.0f, 3.0f));

    unsigned int count = 0;
    float angle = 0;
    while(true)
    {
        if(count++ >= 4294967295)
        {
            s1->printStatus();
            s2->printStatus();
            angle += 15.0f;
            s1->changeDir(Vector2<float>(1,1.0f, angle));
            count = 0;
            cout << "-" << endl;
        }
    }
}

void TwoWayToWait_test()
{
    // 将被包装的对象
    wait_godo_lucky lucky_wait;
    wait_godo_quickly quick_wait;

    // 包装后的对象
    target *after_adapte;

    // 用合适的包装器进行包装, 然后执行
    after_adapte = new adapter_quickly(&quick_wait);
    int spend_teime = 0;
    while(!after_adapte->execute(5))
    {
        Sleep(1000);
        system("cls");
        spend_teime++;
    }
    cout << "spend_teime = " << spend_teime << endl;
    delete after_adapte;

    system("pause");

    after_adapte = new adapter_lucky(&lucky_wait);
    spend_teime = 0;
    while(!after_adapte->execute(5))
    {
        Sleep(1000);
        system("cls");
        spend_teime++;
    }
    cout << "spend_teime = " << spend_teime << endl;
    delete after_adapte;
}

int main()
{
    putchar('\n');
    cout << "==================================================="<<endl;
    cout << "Last build on : " << __DATE__ << " " << __TIME__ << endl;
    cout << "--•START•------------------------------------------"<<endl;

    // Mem_areas_verify(); // 内存分布验证

    // Ref_test(); // 引用传递测试

    // Time_test(); // 时间显示测试

    // Vector2_test(); // 二维向量测试

    // Sample_class_test(); // 类测试

    // Sample_class_constructor_test(); // 类构造函数测试

    // new_enviroment_test(); // 新环境测试

    TwoWayToWait_test();

    cout << "--•END•--------------------------------------------"<<endl;
    putchar('\n');
    return 0;
}
