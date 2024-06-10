#include "Shapes.h"

Shape::Shape(Display* new_display) : display(new_display) {}

void Shape::changeDisplay(Display* new_display)
{
    display = new_display;
};

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