#include "vector2.h"

Vector2::Vector2(float _x , float _y) {
    x = _x;
    y = _y;
}

void Vector2::distance(Vector2 begin, Vector2 end) {
    this->x = (end.x - begin.x);
    this->y = (end.y - begin.y);
}

void Vector2::rotation(float angle) {
	float l = this->magnitude();
	this->x = cos(angle) * l;
	this->y = sin(angle) * l;
}

void Vector2::normalize() {
    float m = magnitude();
    if(m != 0){
        *this /= m;
    }
}

void Vector2::limit(float value) {
    if(magnitude() > value){
        normalize();
        Vector2(x,y) *= value;
    }
}

void Vector2::rotate(float angle) {
	float aa = this->getAngle() + angle;
	this->rotation(aa);
}

// handle += Vector2 or float
Vector2& Vector2::operator+=(const Vector2& vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2& Vector2::operator+=(const float vec) {
    x += vec;
    y += vec;
    return *this;
}

// handle -= Vector2 or float
Vector2& Vector2::operator-=(const Vector2& vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2& Vector2::operator-=(const float vec) {
    x -= vec;
    y -= vec;
    return *this;
}

// handle /= Vector2 or float
Vector2& Vector2::operator/=(const Vector2& vec) {
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vector2& Vector2::operator/=(const float vec) {
    x /= vec;
    y /= vec;
    return *this;
}

// handle *= Vector2 or float
Vector2& Vector2::operator*=(const Vector2& vec) {
    x *= vec.x;
    y *= vec.y;
    return *this;
}


Vector2& Vector2::operator*=(const float vec) {
    x *= vec;
    y *= vec;
    return *this;
}

// handle + Vector2 or float
Vector2 Vector2::operator+(const Vector2& vec) {
    return Vector2(x + vec.x, y + vec.y);
}

Vector2 Vector2::operator+(const float vec) {
   return Vector2(x + vec, y + vec);
}

// handle - Vector2 or float
Vector2 Vector2::operator-(const Vector2& vec) {
    return Vector2(x - vec.x, y - vec.y);
}

Vector2 Vector2::operator-(const float vec) {
    return Vector2(x - vec, y - vec);
}

// handle * Vector2 or float
Vector2 Vector2::operator*(const Vector2& vec) {
    return Vector2(x * vec.x, y * vec.y);
}

Vector2 Vector2::operator*(const float vec) {
    return Vector2(x * vec, y * vec);
}

// handle / Vector2 or float
Vector2 Vector2::operator/(const Vector2& vec) {
    return Vector2(x / vec.x, y / vec.y);
}

Vector2 Vector2::operator/(const float vec) {
    return Vector2(x / vec, y / vec);
}

bool Vector2::operator==(const Vector2& vec) {
    return(x == vec.x && y == vec.y);
}

bool Vector2::operator!=(const Vector2& vec) {
    return(x != vec.x || y != vec.y);
}

Vector2::~Vector2(){

}
