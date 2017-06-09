#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>

// Manage the vectors in 2 dimensions
class Vector2 {
public:

	/*** Constructors ***/

	Vector2();
	Vector2(float x, float y);

	/*** Operators ***/

	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	Vector2 operator/(const Vector2& other);

	/*** Getters ***/

	float getX() const;
	float getY() const;
	float getMagnitude() const;
	Vector2 getNormalized() const;

	/*** Setters ***/

	void setX(float x);
	void setY(float y);
	void setMagnitude(float magnitude);

	/*** Static functions ***/

	// Return the angle in degrees between two vectors
	// param vectorA The first vector
	// param vectorB The second vector
	// return The angle in degrees between the two vectors
	static float angle(Vector2 vectorA, Vector2 vectorB);

	// Return the distance between two vectors
	// param vectorA The first vector
	// param vectorB The second vector
	// return The distance between the two vectors
	static float distance(Vector2 vectorA, Vector2 vectorB);

	// Return the dot product of two vectors
	// param vectorA The first vector
	// param vectorB The second vector
	// return The dot product of the two vectors
	static float dot(Vector2 vectorA, Vector2 vectorB);

	// Return a vector made of the largest components of two vectors
	// param vectorA The first vector
	// param vectorB The second vector
	// return A vector made of the largest components of the two vectors
	static Vector2 max(Vector2 vectorA, Vector2 vectorB);

	// Return a vector made of the smallest components of two vectors
	// param vectorA The first vector
	// param vectorB The second vector
	// return A vector made of the smallest components of the two vectors
	static Vector2 min(Vector2 vectorA, Vector2 vectorB);

	// Return a vector who's the reflection of a given vector
	// param vector The vector to reflect
	// param normal The normal
	// return The reflection of the vector
	static Vector2 reflect(Vector2 vector, Vector2 normal);

	/*** Public functions ***/

	// Return if two vectors are equals
	// param otherVector The other vector
	// return The result of the comparison of the two vectors
	bool equals(Vector2 other);

	// Normalize this vector
	void normalize();

	// Set the two components of this vector
	// param x The component x
	// param y The component y
	void set(float x, float y);

	// Return a description of this vector
	// return The description of this vector
	std::string toString();

private:

	/*** Variables ***/

	float x;
	float y;
	float magnitude;

	/*** Private functions ***/

	// Calculate the magnitude of this vector
	// return The magnitude of this vector
	float calcMagnitude();
};

#endif // VECTOR2_H