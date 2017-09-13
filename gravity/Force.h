#pragma once
class Force : public Vector
{
public:
	Force(float, float, float);
	Force(Vector);
	Force() {};
	Vector force;

private:

};

Force::Force(float x, float y, float z)
{
	force.set(Vector(x,y,z));
}

inline Force::Force(Vector a)
{
	force.set(a);
}
