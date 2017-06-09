#include "Vector2.h"

#define PI 3.14159265

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
	return Vector2(x + other.getX(), y + other.getY());
}

Vector2 Vector2::operator-(const Vector2& other) {
	return Vector2(x - other.getX(), y - other.getY());
}

Vector2 Vector2::operator*(const Vector2& other) {
	return Vector2(x * other.getX(), y * other.getY());
}

Vector2 Vector2::operator/(const Vector2& other) {
	return Vector2(x / other.getX(), y / other.getY());
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

Vector2 Vector2::getNormalized() const {
	return Vector2(x / magnitude, y / magnitude);
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
float Vector2::angle(Vector2 vectorA, Vector2 vectorB) {

	// Normalize the two vectors
	vectorA.normalize();
	vectorB.normalize();

	// Return the angle between the two vectors
	return acos(dot(vectorA, vectorB)) * 180.0 / PI;
}

float Vector2::distance(Vector2 vectorA, Vector2 vectorB) {

	// Calculate the distance between the two vectors
	Vector2 minus = vectorA - vectorB;
	return sqrt(pow(minus.x, 2) + pow(minus.y, 2));
}

float Vector2::dot(Vector2 vectorA, Vector2 vectorB) {

	// Calculate the dot productor of the two vectors
	Vector2 prod = vectorA * vectorB;
	return vectorA.x + vectorB.y;
}

Vector2 Vector2::max(Vector2 vectorA, Vector2 vectorB) {}

Vector2 Vector2::min(Vector2 vectorA, Vector2 vectorB) {}

Vector2 Vector2::reflect(Vector2 vector, Vector2 normal) {}

/*** Public functions ***/
bool Vector2::equals(Vector2 other) {

	// Check if the vectors are equals
	if (x == other.getX() && y == other.getY())
		return true;

	return false;
}

void Vector2::normalize() {
	*this = getNormalized();
}

void Vector2::set(float x, float y) {
	setX(x);
	setY(y);
}

std::string Vector2::toString() {
	return "Vector2 : x(" + std::to_string(x) + "), y(" + std::to_string(y) + ")";
}

/*** Private functions ***/
float Vector2::calcMagnitude() {
	return sqrt(pow(x, 2) + pow(y, 2));
}