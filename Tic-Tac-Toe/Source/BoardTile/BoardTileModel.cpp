#include "../../Header/BoardTile/BoardTileModel.h"
#include "../../Header/BoardTile/BoardTileConfig.h"

namespace BoardTile
{
	BoardTileModel::BoardTileModel(BoardTileType type)
	{
		board_tile_type = type;
	}

	BoardTileModel::~BoardTileModel()
	{

	}

	void BoardTileModel::initialize(sf::Vector2f position)
	{
		board_tile_position = position;
	}


	BoardTileType BoardTileModel::getBoardTileType()
	{
		return board_tile_type;
	}

	sf::Vector2f BoardTileModel::getBoardTilePosition()
	{
		return board_tile_position;
	}

}