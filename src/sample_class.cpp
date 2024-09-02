#include "sample_class.h"

// 构造函数定义
template <typename T>
Vector2<T>::Vector2(T xVal, T yVal) : x(xVal), y(yVal) {}

// 定义模板友元函数
template <typename U>
std::ostream& operator<<(std::ostream& os, const Vector2<U>& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

// 显式实例化
template class Vector2<int>;
template std::ostream& operator<< <int>(std::ostream& os, const Vector2<int>& vec);
