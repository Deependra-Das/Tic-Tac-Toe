#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Player/PlayerModel.h"

namespace Player
{
	enum class PlayerState;
	class PlayerView;

	class PlayerController
	{
	private:

		PlayerModel* player_model;
		PlayerView* player_view;

		void processPlayerInput();
		void processTileClick(sf::Vector2f position);

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		void reset();

		sf::Vector2f getPlayerPosition();

		PlayerSymbol getPlayerSymbol();
		void setPlayerSymbol(PlayerSymbol symbol);

	};
}