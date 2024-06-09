#include "Shapes.h"

int main()
{
    Display* w1 = new GraphicalDisplay();
    Display* w2 = new TextDisplay();
    Shape* o1 = new Triangle(w1, 3, 2, 3, -2);
    Shape* o2 = new Parallelogram(w1, 3, 2, 2, -2);
    Shape* o3 = new Circle(w1, 3);
    ComplexShape* o4 = new ComplexShape(w1);
    o4->add(o1);
    o4->add(o2);
    o4->add(o3);
    o4->draw();

    o1->draw();
    o2->draw();
    o3->draw();
}
// komentarz zeby zobaczyc czy git dziala