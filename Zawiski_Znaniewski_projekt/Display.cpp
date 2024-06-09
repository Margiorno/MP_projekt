#include "Display.h"


// Funkcje TextDisplay (do zrobiena, ale wrzucam zeby bylo)
void TextDisplay::drawTriangle(int a1, int a2, int a3, int a4) {
    std::cout << "Drawing Triangle in TextDisplay with points: ("
        << a1 << "," << a2 << "), (" << a3 << "," << a4 << ")" << std::endl;
}

void TextDisplay::drawCircle(int r) {
    std::cout << "Drawing Circle in TextDisplay with radius: " << r << std::endl;
}

void TextDisplay::drawParallelogram(int a1, int a2, int b1, int b2) {
    std::cout << "Drawing Parallelogram in TextDisplay with vectors: ("
        << a1 << "," << a2 << "), (" << b1 << "," << b2 << ")" << std::endl;
}

void GraphicalDisplay::drawLine(int x1, int y1, int x2, int y2, std::vector<std::vector<bool>>& canvas)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        if (x1 >= 0 && x1 < canvas[0].size() && y1 >= 0 && y1 < canvas.size()) {
            canvas[y1][x1] = true;
        }
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

std::vector<std::vector<bool>> GraphicalDisplay::makeEmptyCanvas(int height, int width)
{
    return std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
}

void GraphicalDisplay::fillCanvas(std::vector<std::vector<bool>>& canvas)
{
    for (auto& row : canvas)
    {
        auto begin = std::find(row.begin(), row.end(), true);
        if (begin != row.end())
        {
            auto end = std::find(row.rbegin(), row.rend(), true).base();//pocz¹tek r sprawia ¿e odwraca siê wektor, nastêpnie znajduje pierwsze wyst¹pienie w nowym wektorze. base() sprawia, ¿e wracamy do pocz¹rkowej wartoœci
            std::fill(begin, end, true);
        }
    }
}

void GraphicalDisplay::displayCanvas(std::vector<std::vector<bool>> canvas, char letter)
{
    for (std::vector<bool> row : canvas) {
        for (bool element : row) {
            if (element)
                std::cout << letter;
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<bool>> GraphicalDisplay::makeTriangleCanvas(int a1, int a2, int a3, int a4)
{
    // Wartoœci pozosta³ych wierzcho³ków
    int x0 = 0, y0 = 0;

    //tutaj szukamy punktów skrajnych
    int minX = std::min({ x0, a1, a3 });
    int minY = std::min({ x0, a2, a4 });
    int maxX = std::max({ x0, a1, a3 });
    int maxY = std::max({ x0, a2, a4 });

    //tutaj szukamy wymiarów p³ótna
    int width = maxX - minX + 1;
    int height = maxY - minY + 1;

    //tworzymy tutaj przestrzeñ robocz¹ do pracy
    std::vector<std::vector<bool>> canvas = makeEmptyCanvas(height, width);

    //anonimowa funkcja która s³u¿y do dostosowania wspó³rzêdnych
    auto adjust = [&](int& x, int& y)
    {
        x -= minX;
        y -= minY;
    };

    adjust(x0, y0);
    adjust(a1, a2);
    adjust(a3, a4);

    drawLine(x0, y0, a1, a2, canvas); // Rysowanie linii od pocz¹tku do pierwszego punktu
    drawLine(a1, a2, a3, a4, canvas); // Rysowanie linii od pierwszego punktu do drugiego punktu
    drawLine(a3, a4, x0, y0, canvas); // Rysowanie linii od drugiego punktu do pocz¹tku

    //wype³nianie pól miêdzy liniami
    fillCanvas(canvas);
    
    return canvas;
}

std::vector<std::vector<bool>> GraphicalDisplay::makeCircleCanvas(int r)
{
    //tutaj szukamy wymiarów p³ótna.(œrednica x œrednica)
    int diameter = 2 * r + 1;

    //tworzymy tutaj przestrzeñ robocz¹ do pracy
    std::vector<std::vector<bool>> canvas = makeEmptyCanvas(diameter, diameter);

    //wspo³rzêdne œrodka ko³a
    int cx = r, cy = r;

    //tworzymy ko³o
    for (int y = -r; y <= r; ++y)
    {
        for (int x = -r; x <= r; ++x)
        {
            if (x * x + y * y <= r * r)//wzór na ko³o w uk³adnie wspó³rzêdnych
            {
                canvas[cy + y][cx + x] = true;
            }
        }
    }

    return canvas;
}

std::vector<std::vector<bool>> GraphicalDisplay::makeParallelogramCanvas(int a1, int a2, int b1, int b2)
{
    // Wartoœci pozosta³ych wierzcho³ków
    int x0 = 0, y0 = 0;
    int c1 = a1 + b1, c2 = a2 + b2;

    // Szukanie punktów skrajnych
    int minX = std::min({ 0, a1, b1, a1 + b1 });
    int minY = std::min({ 0, a2, b2, a2 + b2 });
    int maxX = std::max({ 0, a1, b1, a1 + b1 });
    int maxY = std::max({ 0, a2, b2, a2 + b2 });

    // Szukanie wymiarów p³ótna
    int width = maxX - minX + 1;
    int height = maxY - minY + 1;

    // Tworzenie przestrzeni roboczej do pracy
    std::vector<std::vector<bool>> canvas = makeEmptyCanvas(height, width);

    // Anonimowa funkcja do dostosowywania wspó³rzêdnych
    auto adjust = [&](int& x, int& y)
        {
            x -= minX;
            y -= minY;
        };
    
    adjust(x0, y0);
    adjust(a1, a2);
    adjust(b1, b2);
    adjust(c1, c2);


    drawLine(x0, y0, a1, a2, canvas);   // Rysowanie linii od pocz¹tku do pierwszego punktu
    drawLine(x0, y0, b1, b2, canvas);   // Rysowanie linii od pocz¹tku do drugiego punktu
    drawLine(a1, a2, c1, c2, canvas);   // Rysowanie linii od pierwszego punktu do sumy wektorów
    drawLine(b1, b2, c1, c2, canvas);   // Rysowanie linii od drugiego punktu do sumy wektorów

    // Wype³nianie pól miêdzy liniami
    fillCanvas(canvas);

    return canvas;
}


void GraphicalDisplay::drawTriangle(int a1, int a2, int a3, int a4)
{
    std::vector<std::vector<bool>> canvas = makeTriangleCanvas(a1, a2, a3, a4);
    displayCanvas(canvas, 't');
}

void GraphicalDisplay::drawCircle(int r) 
{    
    std::vector<std::vector<bool>> canvas = makeCircleCanvas(r);
    displayCanvas(canvas, 'c');
}

void GraphicalDisplay::drawParallelogram(int a1, int a2, int b1, int b2)
{
    std::vector<std::vector<bool>> canvas = makeParallelogramCanvas(a1, a2, b1, b2);
    displayCanvas(canvas, 'p');
}
