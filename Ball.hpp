#pragma once
#include "Painter.hpp"
#include "Velocity.hpp"
#include "Color.hpp"

class Ball {
public:
    Color color;
    Velocity velocity;
    Point point;
    double radius;  
    Ball() = default;
    inline Ball(Point p_point, double p_radius, Color p_color, Velocity p_velocity) {
        color = p_color;
        radius = p_radius;
        point = p_point;
        velocity = p_velocity;
    };
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
};
