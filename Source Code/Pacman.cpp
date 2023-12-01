#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Global.h"
#include "Pacman.h"
#include "MapCollision.h"

Pacman::Pacman() : 
	animationOver(0),
	dead(0),
	direction(0),
	energizerTimer(0),
	position({0,0})
	{} //initializer list

bool Pacman::getAnimationOver() {

	return animationOver;

}

bool Pacman::getDead() {

	return dead;

}

unsigned char Pacman::getDirection() {

	return direction;

}

unsigned short Pacman::getEnergizerTimer() {

	return energizerTimer;

}

void Pacman::draw(bool Victory, sf::RenderWindow& Window) {

	unsigned char frame = static_cast<unsigned char>(floor(animationTimer / static_cast<float>(PACMAN_ANIMATION_SPEED)));

	sf::Sprite sprite;

	sf::Texture texture;

	sprite.setPosition(position.x, position.y);

	if (dead || Victory) {  //when the game ends, show the death animation

		if (animationTimer < PACMAN_DEATH_FRAMES * PACMAN_ANIMATION_SPEED) {

			animationTimer++;

			texture.loadFromFile("Images/PacmanDeath16" + std::to_string(CELL_SIZE) + ".png");

			sprite.setTexture(texture);
			sprite.setTextureRect(sf::IntRect(CELL_SIZE * frame, 0, CELL_SIZE, CELL_SIZE));

			Window.draw(sprite);
		}
		else {

			animationOver = 1;

		}

	}
	else { //pacman is moving and alive

		texture.loadFromFile("Images/Pacman16" + std::to_string(CELL_SIZE) + ".png");

		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(CELL_SIZE * frame, CELL_SIZE * direction, CELL_SIZE, CELL_SIZE));

		Window.draw(sprite);

		animationTimer = (1 + animationTimer) % (PACMAN_ANIMATION_FRAMES * PACMAN_ANIMATION_SPEED);
	}

}

void Pacman::reset() { //when the game ends

	animationOver = 0;
	dead = 0;

	direction = 0;

	animationTimer = 0;
	energizerTimer = 0;

}

void Pacman::setAnimationTimer(unsigned short AnimationTimer) {
	 
	animationTimer = AnimationTimer;

}

void Pacman::setDead(bool Dead) {

	dead = Dead;

	if (dead) { //if pacman is dead, we start from the beginning.

		animationTimer = 0;

	}

}

void Pacman::setPosition(short x_pos, short y_pos) {

	position = { x_pos, y_pos };

}

void Pacman::update(unsigned char Level, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& Map) { //function controlling pacman's movement

	std::array<bool, 4> walls{};
	walls[0] = mapCollision(0, 0, PACMAN_SPEED + position.x, position.y, Map);
	walls[1] = mapCollision(0, 0, position.x, position.y - PACMAN_SPEED, Map);
	walls[2] = mapCollision(0, 0, position.x - PACMAN_SPEED, position.y, Map);
	walls[3] = mapCollision(0, 0, position.x, PACMAN_SPEED + position.y, Map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { //not allowed to move right if pacman collides with a wall

		if (!walls[0]) {

			direction = 0;
			
		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) //not allowed to move up if pacman collides with a wall
	{
		if (0 == walls[1])
		{

			direction = 1;

		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //not allowed to move left if pacman collides with a wall
	{
		if (0 == walls[2])
		{

			direction = 2;

		}
	}

	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) //not allowed to move down if pacman collides with a wall
	{
		if (0 == walls[3])
		{

			direction = 3;

		}
	}

	if (!walls[direction])
	{
		switch (direction)
		{
		case 0:
		{
			position.x += PACMAN_SPEED;

			break;
		}
		case 1:
		{
			position.y -= PACMAN_SPEED;

			break;
		}
		case 2:
		{
			position.x -= PACMAN_SPEED;

			break;
		}
		case 3:
		{
			position.y += PACMAN_SPEED;
		}
		}
	}

	if (-CELL_SIZE >= position.x) //if pacman exits through one of the sides
	{
		position.x = CELL_SIZE * MAP_WIDTH - PACMAN_SPEED;
	}
	else if (CELL_SIZE * MAP_WIDTH <= position.x)
	{
		position.x = PACMAN_SPEED - CELL_SIZE;
	}

	if (1 == mapCollision(1, 0, position.x, position.y, Map)) //when pacman eats an energizer
	{
		
		energizerTimer = static_cast<unsigned short>(ENERGIZER_DURATION / pow(2, Level));
	}
	else
	{
		energizerTimer = std::max(0, energizerTimer - 1);
	}

}

Position Pacman::getPosition() {

	return position;

}

