#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Player
{
	using namespace Global;

	int PlayerModel::player_lives;

	PlayerModel::PlayerModel()
	{

	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		player_lives = max_player_lives;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

}
