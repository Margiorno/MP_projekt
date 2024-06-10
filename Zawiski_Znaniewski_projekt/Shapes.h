#ifndef SHAPES_H
#define SHAPES_H

#include "MyExceptions.h"
#include "Display.h"

class Shape
{
protected:
    Display* display;

public:
    Shape(Display* new_display);
    virtual void draw() = 0;
    virtual void changeDisplay(Display* new_display);
};

class ComplexShape :public Shape
{
private:
    std::vector<Shape*> collection;
public:
    ComplexShape(Display* new_display);
    void draw();
    bool add(Shape* new_shape);
};

#endif