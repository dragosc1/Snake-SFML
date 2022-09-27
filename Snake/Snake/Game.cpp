#include "Game.h"
#include "Window.h"
#include "Snake.h"
#include "World.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)), m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600)) {
}

Game::~Game() {
}

sf::Time Game::GetElapsed(){
	return m_elapsed;
}

void Game::RestartClock() {
	m_elapsed = m_clock.restart();
}

void Game::HandleInput() {
	m_window.Update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& m_snake.GetPhysicalDirection() != Direction::Down)
	{
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& m_snake.GetPhysicalDirection() != Direction::Up)
	{
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& m_snake.GetPhysicalDirection() != Direction::Right)
	{
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& m_snake.GetPhysicalDirection() != Direction::Left)
	{
		m_snake.SetDirection(Direction::Right);
	}
}

void Game::Update() {
	m_window.Update(); // Update window events.
	if (timespent >= timestep) {
		m_snake.Tick();
		m_world.Update(m_snake);
		if (m_snake.HasLost()) { m_snake.Reset(); }
		timespent = 0;
	}
	else timespent++;
}

void Game::Render() {
	m_window.BeginDraw(); // Clear.
	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());
	m_window.EndDraw(); // Display.
}

Window* Game::GetWindow() {
	return &m_window;
}
