#pragma once

namespace Player
{
	class PlayerController;
	enum class PlayerSymbol;

	class PlayerService
	{
	private:
		PlayerController* player_controller;

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void reset();

		PlayerSymbol getPlayerSymbol();
		void setPlayerSymbol(PlayerSymbol symbol);

	};
}