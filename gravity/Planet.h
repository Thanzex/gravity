#pragma once

using namespace std;

class Planet
{
public:
	Vector position;
	Vector velocity;
	Vector acceleration;
	Vector totalforce;
	float mass;
	float size;

	void Accelerate(Vector);
	void SetPos(Vector);
	void Update();
	void Addforce(Vector);
	void Applyforce();
	Planet() {};
	Planet(Vector);
	Planet(Vector,float,float);
	Planet(Vector, Vector);
	Planet(Vector, Vector, float, float);
	

	sf::CircleShape shape;
	//void Draw();

private:

};


void Planet::Accelerate(Vector acc)
{
	velocity.plus(Vector::mult(acc,TIMESTEP));
}

void Planet::SetPos(Vector pos)
{
	position.set(pos);
}

void Planet::Update()
{
	Planet::Applyforce();
	position.plus((Vector::mult(velocity, TIMESTEP)));
	totalforce.times(0);
	shape.setPosition(map_(position.x, PLAYFIELDMINX, PLAYFIELDMAXX, 0, WINWIDTH), map_(position.y, PLAYFIELDMINY, PLAYFIELDMAXY, 0, WINHEIGHT));
}

 void Planet::Addforce(Vector a)
{
	totalforce.plus(a);
}

 inline void Planet::Applyforce()
 {
	 Vector f = totalforce;
	 f.div(mass);
	 Planet::Accelerate(f);
 }

inline Planet::Planet(Vector a)
{
	position.set(a);
	velocity.set(Vector(0, 0, 0));
	acceleration.set(Vector(0, 0, 0));
	totalforce.set(Vector(0, 0, 0));

	mass = 1;
	size = 1;
}

inline Planet::Planet(Vector p, float m, float s)
{
	position.set(p);
	mass = m;
	size = s;

	velocity.set(Vector(0, 0, 0));
	acceleration.set(Vector(0, 0, 0));
	totalforce.set(Vector(0, 0, 0));
}

inline Planet::Planet(Vector a, Vector b)
{
	position.set(a);
	velocity.set(b);
	mass = 1;
	size = 1;
	acceleration.set(Vector(0, 0, 0));
	totalforce.set(Vector(0, 0, 0));
}

inline Planet::Planet(Vector a, Vector b, float m, float p)
{
	position.set(a);
	velocity.set(b);
	mass = m;
	size = p;
	acceleration.set(Vector(0, 0, 0));
	totalforce.set(Vector(0, 0, 0));
	shape.setRadius(size);
}



