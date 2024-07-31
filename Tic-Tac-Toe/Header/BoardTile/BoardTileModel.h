#pragma once

#include <SFML/Graphics.hpp>

namespace BoardTile
{
	enum class BoardTileType;

	class BoardTileModel
	{
	private:
			sf::Vector2f board_tile_position;
			BoardTileType board_tile_type;
	
	public:

		BoardTileModel(BoardTileType type);
		~BoardTileModel();

		void initialize(sf::Vector2f position);

		BoardTileType getBoardTileType();

		sf::Vector2f getBoardTilePosition();
	};
}
