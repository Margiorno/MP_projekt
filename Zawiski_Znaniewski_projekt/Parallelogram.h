#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Shapes.h"

template<typename T>
class Parallelogram : public Shape
{
private:
    std::pair<T, T> vectorA;
    std::pair<T, T> vectorB;
public:
    Parallelogram(Display* new_display, T vectorA_x, T vectorA_y, T vectorB_x, T vectorB_y);
    void draw();
};

template<typename T>
Parallelogram<T>::Parallelogram(Display* new_display, T vectorA_x, T vectorA_y, T vectorB_x, T vectorB_y) : Shape(new_display)
{
    if ((vectorA_x == 0 && vectorA_y == 0) || (vectorB_x == 0 && vectorB_y == 0) || (vectorA_x == vectorB_x && vectorA_y == vectorB_y))
        throw::MyRuntimeExceptions::MyRuntimeError("Dwa punkty s¹ identyczne");

    //wzór na pole to area=(vectorA_x - 0) * (vectorB_y - 0) - (vectorB_x - 0) * (vectorA_x - 0). Poni¿ej wersja skrócona.
    int area = vectorA_x * vectorB_y - vectorB_x * vectorA_x;
    if (!area)
        throw MyRuntimeExceptions::MyRuntimeError("Punkty s¹ kolinearne");

    vectorA = { vectorA_x,vectorA_y };
    vectorB = { vectorB_x,vectorB_y };
};

template<typename T>
void Parallelogram<T>::draw()
{
    display->drawParallelogram(static_cast<int>(vectorA.first), static_cast<int>(vectorA.second), static_cast<int>(vectorB.first), static_cast<int>(vectorB.second));
}

#endif