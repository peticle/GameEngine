#include "Vector2.h"

/*** Constructors ***/
Vector2::Vector2() {}

Vector2::Vector2(float x, float y) {}

/*** Operators ***/
Vector2 Vector2::operator+(const Vector2& other) {}

Vector2 Vector2::operator-(const Vector2& other) {}

Vector2 Vector2::operator*(const Vector2& other) {}

Vector2 Vector2::operator/(const Vector2& other) {}

/*** Getters ***/
float Vector2::getX() const {}

float Vector2::getY() const {}

float Vector2::getMagnitude() const {}

/*** Setters ***/
void Vector2::setX(float x) {}

void Vector2::setY(float y) {}

void Vector2::setMagnitude(float magnitude) {}

/*** Static functions ***/
float Vector2::angle(Vector2 vectorA, Vector2 vectorB) {}

float Vector2::distance(Vector2 vectorA, Vector2 vectorB) {}

float Vector2::dot(Vector2 vectorA, Vector2 vectorB) {}

Vector2 Vector2::max(Vector2 vectorA, Vector2 vectorB) {}

Vector2 Vector2::min(Vector2 vectorA, Vector2 vectorB) {}

Vector2 Vector2::reflect(Vector2 vector, Vector2 normal) {}

/*** Public functions ***/
bool Vector2::equals(Vector2 otherVector) {}

void Vector2::normalize() {}

void Vector2::set(float x, float y) {}

std::string Vector2::toString() {}