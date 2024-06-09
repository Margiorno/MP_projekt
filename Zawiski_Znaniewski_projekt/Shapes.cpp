#include "Shapes.h"

Shape::Shape(Display* new_display) : display(new_display) {}

void Shape::changeDisplay(Display* new_display)
{
    display = new_display;
};


Circle::Circle(Display* new_display, int new_radius) : Shape(new_display), radius(new_radius)
{
    if (new_radius < 0)
        throw::MyRuntimeExceptions::MyRuntimeError("Promien nie moze byc ujemny");
}

void Circle::draw()
{
    display->drawCircle(radius);
}

Parallelogram::Parallelogram(Display* new_display, int vectorA_x, int vectorA_y, int vectorB_x, int vectorB_y) : Shape(new_display)
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

void Parallelogram::draw()
{
    display->drawParallelogram(vectorA.first, vectorA.second, vectorB.first, vectorB.second);
}

Triangle::Triangle(Display* new_display, int pointA_x, int pointA_y, int pointB_x, int pointB_y) : Shape(new_display)
{
    if ((pointA_x == 0 && pointA_y == 0) || (pointB_x == 0 && pointB_y == 0) || (pointA_x == pointB_x && pointA_y == pointB_y))
        throw::MyRuntimeExceptions::MyRuntimeError("Dwa punkty s¹ identyczne");

    //jak pole jest równe 0, to znaczy, ¿e punkty le¿¹ na jednej linii - s¹ kolinearne
    int area = 0 * (pointA_y - pointB_y) + pointA_x * (pointB_y - 0) + pointB_x * (0 - pointA_y);
    if (!area)
        throw MyRuntimeExceptions::MyRuntimeError("Punkty s¹ kolinearne");

    pointA = { pointA_x,pointA_y };
    pointB = { pointB_x,pointB_y };
};

void Triangle::draw()
{
    display->drawTriangle(pointA.first, pointA.second, pointB.first, pointB.second);
}

ComplexShape::ComplexShape(Display* new_display) : Shape(new_display) {}

void ComplexShape::draw()
{
    for (auto i : collection)
        i->draw();
}

bool ComplexShape::add(Shape* new_shape)
{
    collection.push_back(new_shape);
    return true;
}