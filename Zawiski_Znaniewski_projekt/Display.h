#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class Display
{
public:
    virtual void drawTriangle(int a1, int a2, int a3, int a4) = 0;
    virtual void drawCircle(int r) = 0;
    virtual void drawParallelogram(int a1, int a2, int b1, int b2) = 0;

    friend class Shape;
    Display() {};
};

class TextDisplay : public Display
{
public:
    void drawTriangle(int a1, int a2, int a3, int a4) override;
    void drawCircle(int r) override;
    void drawParallelogram(int a1, int a2, int b1, int b2) override;
    TextDisplay() {};
};

class GraphicalDisplay : public Display
{
private:
    void drawLine(int x1, int y1, int x2, int y2, std::vector<std::vector<bool>>& canvas);
    std::vector<std::vector<bool>> makeEmptyCanvas(int height, int width);
    void fillCanvas(std::vector<std::vector<bool>>& canvas);
    void displayCanvas(std::vector<std::vector<bool>> canvas, char letter);

    std::vector<std::vector<bool>> makeTriangleCanvas(int a1, int a2, int a3, int a4);
    std::vector<std::vector<bool>> makeCircleCanvas(int r);
    std::vector<std::vector<bool>> makeParallelogramCanvas(int a1, int a2, int b1, int b2);
public:
    void drawTriangle(int a1, int a2, int a3, int a4) override;
    void drawCircle(int r) override;
    void drawParallelogram(int a1, int a2, int b1, int b2) override;
    GraphicalDisplay() {};
};

#endif
