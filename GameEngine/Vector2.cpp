#include "Vector2.h"

/*** Constructors ***/
Vector2::Vector2() {
	set(0, 0);
	magnitude = 0;
}

Vector2::Vector2(float x, float y) {
	set(x, y);
	magnitude = calcMagnitude();
}

/*** Operators ***/
Vector2 Vector2::operator+(const Vector2& other) {
	return Vector2(getX() + other.getX(), getY() + other.getY());
}

Vector2 Vector2::operator-(const Vector2& other) {
	return Vector2(getX() - other.getX(), getY() - other.getY());
}

Vector2 Vector2::operator*(const Vector2& other) {
	return Vector2(getX() * other.getX(), getY() * other.getY());
}

Vector2 Vector2::operator/(const Vector2& other) {
	return Vector2(getX() / other.getX(), getY() / other.getY());
}

/*** Getters ***/
float Vector2::getX() const {
	return x;
}

float Vector2::getY() const {
	return y;
}

float Vector2::getMagnitude() const {
	return magnitude;
}

/*** Setters ***/
void Vector2::setX(float x) {
	this->x = x;
}

void Vector2::setY(float y) {
	this->y = y;
}

void Vector2::setMagnitude(float magnitude) {
	this->magnitude = magnitude;
}

/*** Static functions ***/
float Vector2::angle(Vector2 vectorA, Vector2 vectorB) {}

float Vector2::distance(Vector2 vectorA, Vector2 vectorB) {}

float Vector2::dot(Vector2 vectorA, Vector2 vectorB) {}

Vector2 Vector2::max(Vector2 vectorA, Vector2 vectorB) {}

Vector2 Vector2::min(Vector2 vectorA, Vector2 vectorB) {}

Vector2 Vector2::reflect(Vector2 vector, Vector2 normal) {}

/*** Public functions ***/
bool Vector2::equals(Vector2 other) {

	// Check if the vectors are equals
	if (getX() == other.getX() && getY() == other.getY())
		return true;

	return false;
}

void Vector2::normalize() {}

void Vector2::set(float x, float y) {
	setX(x);
	setY(y);
}

std::string Vector2::toString() {
	return "Vector2 : x(" + std::to_string(getX()) + "), y(" + std::to_string(getY()) + ")";
}

/*** Private functions ***/
float Vector2::calcMagnitude() {
	return sqrt(pow(getX(), 2) + pow(getY(), 2));
}