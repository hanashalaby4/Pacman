#pragma once
#include <SFML\Graphics.hpp>
#include "Global.h"


class Pacman {

	bool animationOver; //for when pacman dies.

	bool dead; //flag for death.

	unsigned char direction; //to check pacman's direction of motion.

	unsigned short animationTimer; 
	unsigned short energizerTimer; //for when pacman gets energized.

	Position position; //current position of pacman on the map.

public:
	Pacman();

	bool getAnimationOver();
	bool getDead();
	
	unsigned char getDirection();

	unsigned short getEnergizerTimer();

	void draw(bool Victory, sf::RenderWindow& Window);
	void reset();
	void setAnimationTimer(unsigned short AnimationTimer);
	void setDead(bool Dead);
	void setPosition(short x_pos, short y_pos);
	void update(unsigned char Level, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& Map);

	Position getPosition();
};
