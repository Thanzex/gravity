#pragma once

class Vector
{
public:
	float x;
	float y;
	float z;

	Vector(float, float, float);
	Vector() {};
	void plus(Vector);
	void set(Vector);
	void minus(Vector);
	void times(float);
	void div(float);
	float sqmod();
	float mod();
	void normalize();
	void setmag(float);

	static float dist(Vector, Vector);
	static Vector sub(Vector, Vector);
	static Vector add(Vector, Vector);
	static Vector mult(Vector, float);
	static Vector frac(Vector, float);



};

Vector::Vector(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
}


void Vector::plus(Vector a)
{
	x += a.x;
	y += a.y;
	z += a.z;
}

void Vector::set(Vector a)
{
	x = a.x;
	y = a.y;
	z = a.z;
}

void Vector::minus(Vector a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;
}

inline void Vector::times(float a)
{
	x *= a;
	y *= a;
	z *= a;
}

inline void Vector::div(float a)
{
	x /= a;
	y /= a;
	z /= a;
}

float Vector::sqmod()
{
	return (pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector::mod()
{
	return sqrt(Vector::sqmod());
}

inline void Vector::normalize()
{
	Vector::times(1 / Vector::mod());
}

inline void Vector::setmag(float a)
{
	Vector::normalize();
	Vector::times(a);
}

float Vector::dist(Vector a, Vector b)
{
	Vector s = Vector::sub(a, b);
	return s.mod();
}

Vector Vector::sub(Vector a, Vector b)
{
	Vector s(a.x - b.x, a.y - b.y, a.z - b.z);
	return s;
}

Vector Vector::add(Vector a, Vector b)
{
	Vector s(a.x + b.x, a.y + b.y, a.z + b.z);
	return s;
}

Vector Vector::mult(Vector a, float b)
{
	Vector s(a);
	s.times(b);
	return s;
}

inline Vector Vector::frac(Vector a, float b)
{
	Vector s(a);
	s.div(b);
	return s;
}
