#pragma once

#include <math.h>

class Vector2D {
public:
	Vector2D(float x, float y): x(x), y(y){}

	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }

	float length() { return sqrt(x * x + y * y); }

	Vector2D operator+(const Vector2D& a) const {
		return Vector2D(x + a.x, y + a.y);
	}

	friend Vector2D& operator+=(Vector2D& a, const Vector2D& b) {
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	Vector2D operator*(float scalar) {
		return Vector2D(x * scalar, y * scalar);
	}

	Vector2D& operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2D operator-(const Vector2D& a) const {
		return Vector2D(x - a.x, y - a.y);
	}

	friend Vector2D& operator-=(Vector2D& a, const Vector2D& b) {
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	Vector2D operator/(float scalar) {
		return Vector2D(x / scalar, y / scalar);
	}

	Vector2D& operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	void normalize() {
		float l = length();
		if (l > 0) {
			(*this) *= 1 / l;
		}
	}

private:
	float x, y;
};