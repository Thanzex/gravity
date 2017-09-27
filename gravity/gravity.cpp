// gravity.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>
//#include <string>
#include <iostream>
#include <cmath>
#include "Vector.h"
#include "Force.h"
#include "Planet.h"
#include "Calcs.h"
using namespace std;

const int N = 3;


int main()
{

	sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "SFML works!");
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FPS);


	int i = 0;
	std::vector<Planet> a = { /*Planet(Vector(10.0f, 21.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 100.0f, 10.0f) ,\
							Planet(Vector(100.0f, 100.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 10.0f, 10.0f) ,\
							Planet(Vector(100.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f), 10.0f, 10.0f) */};

		while (window.isOpen())
		{
			sf::Event event;
			/*cout << "\n  x: " << a[0].position.x << "  y: " << a[0].position.y << "  z: " << a[0].position.z;
			cout << "\t Bx: " << a[1].position.x << "  y: " << a[1].position.y << "  z: " << a[1].position.z;
			cout << "\t Cx: " << a[2].position.x << "  y: " << a[2].position.y << "  z: " << a[2].position.z;*/
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(window);
				localPosition.x = map_(localPosition.x, 0, WINWIDTH, PLAYFIELDMINX, PLAYFIELDMAXX);
				localPosition.y = map_(localPosition.y, 0, WINHEIGHT, PLAYFIELDMINY, PLAYFIELDMAXY);
				a.push_back(Planet(Vector(localPosition.x, localPosition.y, 0), Vector(0.0f, 0.0f, 0.0f), 10.0f, 10.0f));
			}
			for (i = 0; i < a.size(); i++)
			{
				for (int j = 0; j < a.size(); j++)
				{
					if (j != i) a[i].Addforce(Gravity(a[i], a[j]));
				}
			}
			for (auto& b : a)
			{
				b.Update();
			}

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			for (auto& planet : a)
			{
				window.draw(planet.shape);
			}
			window.display();
		}

}