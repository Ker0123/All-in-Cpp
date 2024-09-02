#include <iostream>

template <typename T>
class Vector2 {
public:
    T x;
    T y;

    Vector2(T xVal = 0, T yVal = 0);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector2<U>& vec);
};

