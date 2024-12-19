// 等待戈多的两种方式
// 基数+随机数, 如果超过阈值, 则等到了
#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;

class wait_godo
{
public:
    int base = 0;               // 基数
    int threshold = 100;        // 阈值
    int rand_area[2] = {0, 10}; // 随机数范围

    virtual bool wait(int wait_time) = 0; // 等待函数, 返回是否等到了
};

class wait_godo_quickly : public wait_godo // 快速等待, 直接减少等待时间
{
public:
    void quick_wait()
    {
        threshold -= 4; // 增加基数
    }
    bool wait(int wait_time)
    {
        base += rand() % (rand_area[1] - rand_area[0]) + rand_area[0];
        if (base >= threshold)
        {
            cout << "快速等待:[" << string(threshold, '#') << ']' << endl;
            return true;
        }
        cout << "快速等待:[" << string(base, '#') << string(threshold - base, '_') << ']' << endl;
        return false;
    }
};

class wait_godo_lucky : public wait_godo // 幸运等待, 等待的效果提高
{
public:
    void lucky_wait()
    {
        rand_area[0] += 1;
        rand_area[1] += 2;
    }
    bool wait(int wait_time)
    {
        base += rand() % (rand_area[1] - rand_area[0]) + rand_area[0];
        if (base >= threshold)
        {
            cout << "幸运等待:[" << string(threshold, '#') << ']' << endl;
            return true;
        }
        cout << "幸运等待:[" << string(base, '#') << string(threshold - base, '_') << ']' << endl;
        return false;
    }
};

class target
{
public:
    virtual bool execute(int wait_time) = 0; // 适配完成后的接口: 传入等待时间, 返回是否等到了
};

class adapter_quickly : public target
{
private:
    // 要被包装的对象的指针
    wait_godo_quickly *wgq;

public:
    // 构造的时候就传进要被包装的东西
    adapter_quickly(wait_godo_quickly *wgq)
    {
        this->wgq = wgq;
        srand(time(NULL)); // 随机数种子
    }

    // 开等就是了, 会根据之前传的数据类型决定怎么等
    bool execute(int wait_time)
    {
        wgq->quick_wait();
        return wgq->wait(wait_time);
    }
};

class adapter_lucky : public target
{
private:
    // 要被包装的对象的指针
    wait_godo_lucky *wgl;

public:
    // 构造的时候就传进要被包装的东西
    adapter_lucky(wait_godo_lucky *wgl)
    {
        this->wgl = wgl;
        srand(time(NULL)); // 随机数种子
    }

    // 开等就是了, 会根据之前传的数据类型决定怎么等
    bool execute(int wait_time)
    {
        wgl->lucky_wait();
        return wgl->wait(wait_time);
    }
};