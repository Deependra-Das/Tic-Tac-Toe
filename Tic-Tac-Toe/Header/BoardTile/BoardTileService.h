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
		std::vector<BoardTileController*> flagged_BoardTile_list;
		std::vector<sf::Vector2f> board_tile_position_list;

		const int board_row_col_size = 3;
		const float board_tile_x_pos = 520.f;
		const float board_tile_y_pos = 100.f;
		const float board_tile_offset = 300.f;

		void destroy();
		void destroyFlaggedBoardTiles();

	public:
		BoardTileService();
		virtual ~BoardTileService();

		void initialize();
		void update();
		void render();
		void reset();

		BoardTileController* spawnBoardTile(sf::Vector2f);
		void destroyBoardTile(BoardTileController* BoardTile_controller);

	};
}