#pragma once

#include "../../Header/BoardTile/BoardTileConfig.h"

namespace BoardTile
{
	class BoardTileView;
	class BoardTileModel;
	enum class BoardTileType;

	class BoardTileController
	{
	protected:
		BoardTileView* board_tile_view;
		BoardTileModel* board_tile_model;

		virtual void destroy();

	public:
		BoardTileController(BoardTileType type);
		virtual ~BoardTileController();

		void initialize(sf::Vector2f position);
		void update();
		void render();

		BoardTileType getBoardTileType();

		sf::Vector2f getBoardTilePosition();

	};
}