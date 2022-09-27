#pragma once
#include "Window.h"
#include <SFML/Graphics.hpp>
#include "World.h"
#include "Snake.h"

class Game
{
public:
	Game();
	~Game();
	sf::Time GetElapsed();
	void RestartClock();
	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
private:
	sf::Clock m_clock;
	sf::Time m_elapsed;
	Window m_window;
	World m_world;
	Snake m_snake;
	float timespent;
	float timestep = 750;
};

