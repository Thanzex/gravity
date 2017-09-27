#pragma once

Vector Gravity(Planet a, Planet b)
{
	Vector g = Vector::sub(b.position, a.position);								//Direzione
	g.setmag((G*a.mass*b.mass) / Vector::sub(a.position, b.position).sqmod());	//G*(m_1*m_2)/r^2
	return g;
}