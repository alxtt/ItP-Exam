#include <math.h>

class Primitive
{
    public:
        virtual mirror(double A, double B, double C) {};
};

class Point: public Primitive
{
public:
    Point(double x, double y) {
        m_x = x;
        m_y = y;
    };
    void setX(double x)
    {
        m_x = x;
    }
    void setY(double y)
    {
        m_y = y;
    }

    mirror(double A, double B, double C) {
        double norm = sqrt(A*A + B*B);
        double len = 2*((A/norm)*m_x + (B/norm)*m_y);
        setX(m_x - len*m_x);
        setY(m_y - len*m_y);
    };

protected:
    double m_x;
    double m_y;
};

class Circle: public Primitive
{
public:
	Circle(Point* center, double radius) {
        m_center = center;
        m_radius = radius;
	};

	void setCenter(Point* p) {
        m_center = p;
	};

    mirror(double A, double B, double C) {
        double norm = sqrt(A*A + B*B);
        double len = 2*((A/norm)*m_x + (B/norm)*m_y);
        setCenter(Point(m_x - len*m_x, m_y - len*m_y));
    };

protected:
	Point* m_center;
	double m_radius;
};
