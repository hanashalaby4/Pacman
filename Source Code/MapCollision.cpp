#include <array>
#include <cmath>

#include "MapCollision.h"

bool mapCollision(bool iCollectPellets, bool iUseDoor, short x_pos, short y_pos, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& Map) {

	bool output = 0;

	//getting current position of pacman
	float cellX = x_pos / static_cast<float>(CELL_SIZE);
	float cellY = y_pos / static_cast<float>(CELL_SIZE);

	//characters cannot be in more than 4 cells at once
	for (unsigned char i = 0; i < 4; i++) {

		short x = 0;
		short y = 0;

		switch (i) {
			case 0: { //top left cell

				x = static_cast<short>(floor(cellX));
				y = static_cast<short>(floor(cellY));

				break;

			}
			case 1: { //top right cell

				x = static_cast<short>(ceil(cellX));
				y = static_cast<short>(floor(cellY));

				break;

			}
			case 2: { // bottom left cell

				x = static_cast<short>(floor(cellX));
				y = static_cast<short>(ceil(cellY));

				break;

			}
			case 3: { //bottom right cell

				x = static_cast<short>(ceil(cellX));
				y = static_cast<short>(ceil(cellY));

			}
		}

		//making sure pacman does not exit the map
		if (0 <= x && 0 <= y && MAP_HEIGHT > y && MAP_WIDTH > x) {
			if (!iCollectPellets) {

				if (Cell::Wall == Map[x][y]) {

					output = 1;

				}
				else if (!iUseDoor && Cell::Door == Map[x][y]) {

					output = 1;

				}

			}
			else {
				if (Cell::Energizer == Map[x][y]) {

					output = 1;

					Map[x][y] = Cell::Empty;

				} else if (Cell::Pellet == Map[x][y]) {

					Map[x][y] = Cell::Empty;
				}
			}
		}
	}

	return output;
	
}