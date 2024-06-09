#ifndef SHAPES_H
#define SHAPES_H

#include "Display.h"
#include <vector>

class Shape
{
protected:
    Display* display;

public:
    Shape(Display* new_display) : display(new_display) {};

    virtual void draw() = 0;

    virtual void changeDisplay(Display* new_display) {
        display = new_display;
    };
};

class Circle :public Shape
{
private:
    int radius;
public:
    Circle(Display* new_display, int new_radius) : Shape(new_display), radius(new_radius) {};

    void draw()
    {
        display->drawCircle(radius);
    }
};

class Parallelogram :public Shape
{
private:
    std::pair<int, int> vectorA;
    std::pair<int, int> vectorB;
public:
    Parallelogram(Display* new_display, int vectorA_x, int vectorA_y, int vectorB_x, int vectorB_y) : Shape(new_display)
    {
        vectorA = { vectorA_x,vectorA_y };
        vectorB = { vectorB_x,vectorB_y };
    };

    void draw()
    {
        display->drawParallelogram(vectorA.first,vectorA.second,vectorB.first,vectorB.second);
    }
};

class Triangle :public Shape
{
private:
    std::pair<int, int> pointA;
    std::pair<int, int> pointB;
public:
    Triangle(Display* new_display, int pointA_x, int pointA_y, int pointB_x, int pointB_y) : Shape(new_display)
    {
        pointA = { pointA_x,pointA_y };
        pointB = { pointB_x,pointB_y };
    };

    void draw()
    {
        display->drawTriangle(pointA.first, pointA.second, pointB.first, pointB.second);
    }
};

class ComplexShape :public Shape
{
private:
    std::vector<Shape*> collection;
public:
    ComplexShape(Display* new_display) : Shape(new_display){};

    void draw()
    {
        for (auto i : collection)
            i->draw();
    }

    bool add(Shape* new_shape)
    {
        collection.push_back(new_shape);
        return true;
    }
};


#endif
