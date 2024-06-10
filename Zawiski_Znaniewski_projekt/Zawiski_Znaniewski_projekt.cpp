#include "Shapes.h"
#include "Circle.h"
#include "Triangle.h"
#include "Parallelogram.h"


int main()
{
    try
    {
        Display* w1 = new GraphicalDisplay();
        Display* w2 = new TextDisplay();
        Shape* o1 = new Triangle<int>(w1, 30, 20, 20, -20);
        Shape* o2 = new Parallelogram<int>(w1, 30, 20, 20, -20);
        Shape* o3 = new Circle<int>(w1, 25);

        ComplexShape* o4 = new ComplexShape(w1);
        o4->add(o1);
        o4->add(o2);
        o4->add(o3);
        o4->draw();
        o1->draw();
        o2->draw();
        o3->draw();
        o1->changeDisplay(w2);
        o2->changeDisplay(w2);
        o3->changeDisplay(w2);
        o4->changeDisplay(w2);
        o4->draw();
        o1->draw();
        o2->draw();
        o3->draw();
        delete o1;
        delete o2;
        delete o3;
        delete o4;
        delete w2;
        delete w1;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        std::cin.get();
    }
    
}