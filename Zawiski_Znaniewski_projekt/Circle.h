#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shapes.h"

template<typename T>
class Circle : public Shape
{
private:
    T radius;
public:
    Circle(Display* new_display, T new_radius);
    void draw();
};

template<typename T>
Circle<T>::Circle(Display* new_display, T new_radius) : Shape(new_display), radius(new_radius)
{
    if (new_radius < 0)
        throw MyRuntimeExceptions::MyRuntimeError("Promieñ nie mo¿e byæ ujemny");
}

template<typename T>
void Circle<T>::draw()
{
    display->drawCircle(static_cast<int>(radius));
}

#endif