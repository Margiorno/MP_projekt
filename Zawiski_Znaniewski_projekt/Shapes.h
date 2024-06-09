#ifndef SHAPES_H
#define SHAPES_H

#include "Display.h"
#include "MyExceptions.h"

class Shape
{
protected:
    Display* display;

public:
    Shape(Display* new_display);
    virtual void draw() = 0;
    virtual void changeDisplay(Display* new_display);
};

class Circle :public Shape
{
private:
    int radius;
public:
    Circle(Display* new_display, int new_radius);
    void draw();
};

class Parallelogram :public Shape
{
private:
    std::pair<int, int> vectorA;
    std::pair<int, int> vectorB;
public:
    Parallelogram(Display* new_display, int vectorA_x, int vectorA_y, int vectorB_x, int vectorB_y);
    void draw();
};

class Triangle :public Shape
{
private:
    std::pair<int, int> pointA;
    std::pair<int, int> pointB;
public:
    Triangle(Display* new_display, int pointA_x, int pointA_y, int pointB_x, int pointB_y);
    void draw();
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
