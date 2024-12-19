#include "stmanager.h"

StManager *StManager::Instance = nullptr; // 全局惟一单例初始化

StManager::StManager()
{
    this->pos = Vector2<float>(0, 0); // 初始化位置
    this->dir = Vector2<float>(0, 0); // 初始化方向

    // 启动线程
    continueMove = true; // 线程控制变量
    moveThread = new std::thread(&StManager::move, this);
}

StManager::~StManager()
{
    continueMove = false; // 停止线程
    moveThread->join();   // 等待线程结束
    delete moveThread;    // 释放线程内存
    Instance = nullptr;   // 释放单例
}

// 获取单例
StManager *StManager::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new StManager();
    }
    return Instance;
}

void StManager::move()
{
    time_t start = time(nullptr); // 记录开始时间
    time_t now = start;           // 记录当前时间
    time_t tick = 1;              // 1秒1运算

    while (continueMove)
    {
        now = time(nullptr);     // 更新当前时间
        if (now - start >= tick) // 时间间隔超过1秒
        {
            start = now; // 记录新的开始时间
            pos += dir;  // 移动坐标
        }
    }
}

void StManager::changeDir(Vector2<float> newDir)
{
    this->dir = newDir;
    return;
}

void StManager::printStatus()
{
    std::cout << "pos: " << pos.x << ", " << pos.y << std::endl;
    std::cout << "dir: " << dir.x << ", " << dir.y << std::endl;
}
