#include "Vector2.hpp"

template<FloatType N> Vector2<N> Vector2<N>::operator-(Vector2<N> other) {
    return Vector2<N>(this->x - other.x, this->y - other.y);
}

template<FloatType N> void Vector2<N>::operator-=(Vector2<N> other) {
    this->x -= other.x;
    this->y -= other.y;
}

template<FloatType N> Vector2<N> Vector2<N>::operator+(Vector2<N> other) {
    return Vector2<N>(this->x + other.x, this->y + other.y);
}

template<FloatType N> void Vector2<N>::operator+=(Vector2<N> other) {
    this->x += other.x;
    this->y += other.y;
}

template class Vector2<float>;