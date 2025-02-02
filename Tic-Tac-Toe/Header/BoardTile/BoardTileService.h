#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"

namespace BoardTile
{
	enum class BoardTileType;
	class BoardTileController;

	class BoardTileService
	{
	private:
		std::vector<BoardTileController*> board_tile_list;
		std::vector<sf::Vector2f> board_tile_position_list;

		const int board_row_col_size = 3;
		const float board_tile_x_pos = 565.f;
		const float board_tile_y_pos = 200.f;
		const float board_tile_offset = 270.f;

		void destroy();

	public:
		BoardTileService();
		virtual ~BoardTileService();

		void initialize();
		void update();
		void render();
		void reset();

		BoardTileController* spawnBoardTile(sf::Vector2f);
		bool checkBoardForBlankTiles();
		int clickedOnBoardTile(sf::Vector2f mouse_position);
		bool checkConsecutiveTiles(BoardTileType player_type);
		void switchBoardTile(int index, BoardTileType tile_type);
		std::vector<int> getBlankTilesIndex();
	};
}