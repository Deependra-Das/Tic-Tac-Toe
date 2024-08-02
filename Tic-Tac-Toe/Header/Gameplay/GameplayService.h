#pragma once

#include "../../Header/Gameplay/GameplayController.h"
#include "../Player/PlayerModel.h"
#include "../BoardTile/BoardTileConfig.h"
namespace Gameplay
{
	enum class GameStatus
	{
		UNPLAYED,
		WON,
		LOSS,
		DRAW,
	};

	enum class MoveTurn
	{
		Player_1,
		Player_2,

	};

	class GameplayService
	{
	private:
		GameplayController* gameplay_Controller;
		GameStatus current_game_status;
		MoveTurn current_move_turn;
		Player::PlayerSymbol player_two;

		std::vector<BoardTile::BoardTileType> board;
		const int board_size = 9;

		void initializeBoard();
		void getBasicAIMove();
		void processGameplay();

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void restart();

		BoardTile::BoardTileType getPlayerToTile(Player::PlayerSymbol symbol);
		int checkValidMove(sf::Vector2f mouse_position);

		void makeMove(int index);

		void setPlayerTwoSymbol(Player::PlayerSymbol symbol);

		MoveTurn getMoveTurn();

		bool checkWinning(std::vector<BoardTile::BoardTileType> board, BoardTile::BoardTileType tile_type);
		bool checkBoardForBlankTiles(std::vector<BoardTile::BoardTileType> board);
		int findBestMove(std::vector<BoardTile::BoardTileType> board);
		int minimax(std::vector<BoardTile::BoardTileType> board, bool isMaximizing);
		void markWinningTiles(std::vector<BoardTile::BoardTileType> board, Player::PlayerSymbol player_type);

		BoardTile::BoardTileType getWinnerTiles(Player::PlayerSymbol symbol);
	};
}