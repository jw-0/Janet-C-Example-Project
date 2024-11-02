// rectangle.h
#pragma once
#include <cmath>

class Rectangle
{
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const
    {
        return width * height;
    }

    double perimeter() const
    {
        return 2 * (width + height);
    }

    double diagonal() const
    {
        return std::sqrt(width * width + height * height);
    }

    void set_width(double w)
    {
        width = w;
    }

    void set_height(double h)
    {
        height = h;
    }

    double get_width() const
    {
        return width;
    }

    double get_height() const
    {
        return height;
    }
    
private:
    double width;
    double height;

};
