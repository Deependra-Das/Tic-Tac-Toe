#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;

	int PlayerModel::player_move;

	PlayerModel::PlayerModel()
	{

	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::initialize()
	{
		player_symbol = PlayerSymbol::PLAYER_O;
		reset();
	}

	void PlayerModel::reset()
	{
		player_move = max_player_move;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

	PlayerSymbol PlayerModel::getPlayerSymbol()
	{
		return player_symbol;
	}

	int PlayerModel::getPlayerMovesLeft()
	{
		return player_move;
	}

	void PlayerModel::decreasePlayerMove()
	{
		if (player_move > 0)
		{
			player_move -= 1;
		}
	}

	void PlayerModel::setPlayerSymbol(PlayerSymbol symbol)
	{
		player_symbol = symbol;
	}

}
