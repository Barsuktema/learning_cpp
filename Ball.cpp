#include "Ball.hpp"
#include <cmath>
#include "Painter.hpp"
#include <iostream>

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    Ball::velocity=velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    
    return {Ball::velocity};
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    painter.draw(getCenter(),getRadius(),Ball::color);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    Ball::point = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    return {Ball::point};
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    return Ball::radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {

    return {M_PI * Ball::radius * Ball::radius * Ball::radius * 4. / 3.};
}
