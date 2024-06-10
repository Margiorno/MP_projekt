#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shapes.h"

template<typename T>
class Triangle : public Shape
{
private:
    std::pair<T, T> pointA;
    std::pair<T, T> pointB;
public:
    Triangle(Display* new_display, T pointA_x, T pointA_y, T pointB_x, T pointB_y);
    void draw();
};

template<typename T>
Triangle<T>::Triangle(Display* new_display, T pointA_x, T pointA_y, T pointB_x, T pointB_y) : Shape(new_display)
{
    if ((pointA_x == 0 && pointA_y == 0) || (pointB_x == 0 && pointB_y == 0) || (pointA_x == pointB_x && pointA_y == pointB_y))
        throw::MyRuntimeExceptions::MyRuntimeError("Dwa punkty s¹ identyczne");

    //jak pole jest równe 0, to znaczy, ¿e punkty le¿¹ na jednej linii - s¹ kolinearne
    int area = 0 * (pointA_y - pointB_y) + pointA_x * (pointB_y - 0) + pointB_x * (0 - pointA_y);
    if (!area)
        throw MyRuntimeExceptions::MyRuntimeError("Punkty s¹ kolinearne");

    pointA = { pointA_x,pointA_y };
    pointB = { pointB_x,pointB_y };
}

template<typename T>
void Triangle<T>::draw()
{
    display->drawTriangle(static_cast<int>(pointA.first), static_cast<int>(pointA.second), static_cast<int>(pointB.first), static_cast<int>(pointB.second));
}

#endif