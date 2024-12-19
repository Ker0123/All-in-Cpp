/**
 * 类名含义: Somthing Manager
 * 功能描述: 单例模式实践. 根据以往的Unity开发经验, 很多管理器会做成单例. 在C#中有很方便的关键字制作单例, 在C++中可能要人工去关注一些东西.
 */

#pragma once

#include <iostream>
#include <string>
#include <thread>
#include "Vector2.h"

class StManager // 当前类模拟一个坐标, 提供函数控制其运动
{
private:
    static StManager *Instance; // 全局惟一单例
    StManager();                // 构造函数私有化
    ~StManager();               // 析构函数私有化

    thread *moveThread; // 运动线程
    bool continueMove;  // 运动标志位

    Vector2<float> pos; // 位置
    Vector2<float> dir; // 方向

public:
    // 获取单例
    static StManager *GetInstance();

    // 运动线程的入口函数
    void move();

    // 改变方向
    void changeDir(Vector2<float> newDir);
    // 获取方向
    Vector2<float> getDir();

    // 打印状态
    void printStatus();
};