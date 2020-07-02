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

    double getX()
    {
        return m_x;
    }
    double getY()
    {
        return m_y;
    }

    mirror(double A, double B, double C) {
        double norm = sqrt(A*A + B*B);
        double len = 2*((A/norm)*m_x + (B/norm)*m_y);
        setX(m_x - len*m_x);
        setY(m_y - len*m_y);
    };

private:
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

	Point* getCenter() {
        return m_center;
	};

    mirror(double A, double B, double C) {
        double norm = sqrt(A*A + B*B);
        double len = 2*((A/norm)*m_center->getX() + (B/norm)*m_center->getY());
        Point t = Point(m_center->getX() - len*m_center->getX(), m_center->getY() - len*m_center->getY());
        setCenter(&t);
    };

private:
	Point* m_center;
	double m_radius;
};
