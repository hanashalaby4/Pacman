#pragma once
#include <array>

#include "Global.h"


bool mapCollision(bool iCollectPellets, bool iUseDdoor, short x_pos, short y_pos, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& Map);
