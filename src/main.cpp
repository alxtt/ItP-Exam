//7. Реализовать классы, представляющие геометрические фигуры на
//плоскости - точку, окружность, многоугольник, а также реализовать для
//них полиморфный метод mirror(double A, double B, double C),
//обеспечивающий перемещение объекта в симметричное относительно прямой
//с общим уравнением A*x + B*y + C = 0 положение.


#include <iostream>
#include "Primitive.h"

int main()
{
    Point p = Point(1.0, 1.0);
    p.mirror(0.0, 1.0, 0.0);
    return 0;
}
