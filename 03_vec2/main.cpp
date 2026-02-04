/*
Vec2
*/

#include <iostream>

class Vec2 {
public:
    int x = 0;
    int y = 0;

    Vec2() {}

    Vec2(float x, float y) 
        : x(x)
        , y(y)
    {
    }

    Vec2 operator + (const Vec2 &vectorToAdd) const 
    {
        return Vec2(x + vectorToAdd.x, y + vectorToAdd.y);
    }

    Vec2& add(const Vec2& vectorToAdd) 
    {
        x += vectorToAdd.x;
        y += vectorToAdd.y;
        return *this;
    }
};

int main()
{
    Vec2 v1 = Vec2(100, 200);
    Vec2 v2 = Vec2(50, 75);
    Vec2 v3 = Vec2(1000, 2000);

    //Vec2 v3 = v1 + v2;
    v3.add(v1).add(v2);

    std::cout << v3.x << " " << v3.y << std::endl;

    return 0;
}