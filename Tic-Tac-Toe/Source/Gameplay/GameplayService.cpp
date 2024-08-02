#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/BoardTile/BoardTileConfig.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;
	using namespace Event;
	using namespace BoardTile;
	using namespace Player;

	GameplayService::GameplayService()
	{
		gameplay_Controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		delete(gameplay_Controller);
		gameplay_Controller = nullptr;
	}

	void GameplayService::initialize()
	{
		gameplay_Controller->initialize();
		initializeBoard();
	
	}

	void GameplayService::update()
	{
		processGameplay();
		gameplay_Controller->update();
	}

	void GameplayService::render()
	{
		gameplay_Controller->render();
	}

	void GameplayService::restart()
	{
	}

	void GameplayService::initializeBoard()
	{
		for (int i = 0; i < board_size; i++)
		{
			board.push_back(BoardTile::BoardTileType::Blank);
		}

		current_game_status = GameStatus::UNPLAYED;
		current_move_turn = MoveTurn::Player_1;
	}

	int GameplayService::checkValidMove(sf::Vector2f mouse_position)
	{
		return ServiceLocator::getInstance()->getBoardTileService()->clickedOnBoardTile(mouse_position);

	}

	void GameplayService::makeMove(int index)
	{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(index, getPlayerToTile(ServiceLocator::getInstance()->getPlayerService()->getPlayerSymbol()));

			board[index]= getPlayerToTile(ServiceLocator::getInstance()->getPlayerService()->getPlayerSymbol());

			if (checkWinning(board, getPlayerToTile(ServiceLocator::getInstance()->getPlayerService()->getPlayerSymbol())))
			{
				current_game_status = GameStatus::WON;
			}
			else 
			{
				current_move_turn = MoveTurn::Player_2;
			}

	}

	BoardTile::BoardTileType GameplayService::getPlayerToTile(PlayerSymbol symbol)
	{
		switch (symbol)
		{
		case::Player::PlayerSymbol::PLAYER_X:
			return BoardTile::BoardTileType::Flagged_X;

		case::Player::PlayerSymbol::PLAYER_O:
			return BoardTile::BoardTileType::Flagged_O;
		}
	}

	BoardTile::BoardTileType GameplayService::getWinnerTiles(PlayerSymbol symbol)
	{
		switch (symbol)
		{
		case::Player::PlayerSymbol::PLAYER_X:
			return BoardTile::BoardTileType::Win_X;

		case::Player::PlayerSymbol::PLAYER_O:
			return BoardTile::BoardTileType::Win_O;
		}
	}

	bool GameplayService::checkWinning(std::vector<BoardTile::BoardTileType> board, BoardTile::BoardTileType tile_type)
	{
		if (
			(board[0] == tile_type && board[1] == tile_type && board[2] == tile_type) ||
			(board[3] == tile_type && board[4] == tile_type && board[5] == tile_type) ||
			(board[6] == tile_type && board[7] == tile_type && board[8] == tile_type) ||
			(board[0] == tile_type && board[3] == tile_type && board[6] == tile_type) ||
			(board[1] == tile_type && board[4] == tile_type && board[7] == tile_type) ||
			(board[2] == tile_type && board[5] == tile_type && board[8] == tile_type) ||
			(board[0] == tile_type && board[4] == tile_type && board[8] == tile_type) ||
			(board[2] == tile_type && board[4] == tile_type && board[6] == tile_type)
			) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	int GameplayService::findBestMove(std::vector<BoardTile::BoardTileType> board)
	{
		int bestMove = -1;
		int bestScore = -std::numeric_limits<int>::max();

		for (int i = 0; i < 9; ++i)
		{
			if (board[i] == BoardTileType::Blank)
			{
				board[i] = getPlayerToTile(player_two);
				int score = minimax(board, false);
				board[i] = BoardTileType::Blank;
				if (score > bestScore) {
					bestScore = score;
					bestMove = i;
				}
			}
		}
		return bestMove;
	}

	bool GameplayService::checkBoardForBlankTiles(std::vector<BoardTile::BoardTileType> board)
	{
		for (int i = 0; i < board_size; i++)
		{
			if (board[i] == BoardTileType::Blank)
			{
				return true;
			}
		}
		return false;
	}


	int GameplayService::minimax(std::vector<BoardTile::BoardTileType> board, bool isMaximizing)
	{
		if (checkWinning(board, getPlayerToTile(ServiceLocator::getInstance()->getPlayerService()->getPlayerSymbol())))
		{
			return -10;
		}
		else if (checkWinning(board, getPlayerToTile(player_two)))
		{
			return 10;
		}
		else if (checkBoardForBlankTiles(board)==false) 
		{
			return 0;
		}


		if (isMaximizing)
		{
			int bestScore = -std::numeric_limits<int>::max();
			for (int i = 0; i < 9; ++i)
			{
				if (board[i] == BoardTileType::Blank)
				{
					board[i] = getPlayerToTile(player_two);
					int score = minimax(board, false);
					board[i] = BoardTileType::Blank;
					bestScore = std::max(score, bestScore);
				}
			}
			return bestScore;
		}
		else
		{
			int bestScore = std::numeric_limits<int>::max();
			for (int i = 0; i < 9; ++i)
			{
				if (board[i] == BoardTileType::Blank)
				{
					board[i] = getPlayerToTile(ServiceLocator::getInstance()->getPlayerService()->getPlayerSymbol());
					int score = minimax(board, true);
					board[i] = BoardTileType::Blank;
					bestScore = std::min(score, bestScore);
				}
			}
			return bestScore;
		}
	}

	void GameplayService::processGameplay()
	{

		if (checkBoardForBlankTiles(board) == true && current_game_status==GameStatus::UNPLAYED)
		{

			if (current_move_turn == MoveTurn::Player_2)
			{
				int move = findBestMove(board);
				board[move] = getPlayerToTile(player_two);
				ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(move, getPlayerToTile(player_two));

				if (checkWinning(board, getPlayerToTile(player_two)))
				{
					current_game_status = GameStatus::LOSS;
				}
				else
				{
					current_move_turn = MoveTurn::Player_1;
					ServiceLocator::getInstance()->getPlayerService()->reset();

				}

			}

		}
		else if (checkBoardForBlankTiles(board) == false && current_game_status == GameStatus::UNPLAYED)
		{
			current_game_status == GameStatus::DRAW;
		}

		if (current_game_status == GameStatus::WON)
		{
			printf("Player 1 Won");
			markWinningTiles(board, ServiceLocator::getInstance()->getPlayerService()->getPlayerSymbol());
		}
		else if (current_game_status == GameStatus::LOSS)
		{
			printf("Player 2 Won");
			markWinningTiles(board, player_two);
		}
		else if (current_game_status == GameStatus::DRAW)
		{
			printf("DRAW");
		}


	}

	void GameplayService::markWinningTiles(std::vector<BoardTile::BoardTileType> board, PlayerSymbol player_type)
	{
		BoardTileType tile_type = getPlayerToTile(player_type);

		if (board[0] == tile_type && board[1] == tile_type && board[2] == tile_type)
		{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(0, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(1, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(2, getWinnerTiles(player_type));
		}
		if (board[3] == tile_type && board[4] == tile_type && board[5] == tile_type)
		{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(3, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(4, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(5, getWinnerTiles(player_type));
		}
		if (board[6] == tile_type && board[7] == tile_type && board[8] == tile_type)
		{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(6, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(7, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(8, getWinnerTiles(player_type));

		}
		if (board[0] == tile_type && board[3] == tile_type && board[6] == tile_type)
		{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(0, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(3, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(6, getWinnerTiles(player_type));
		}
		if (board[1] == tile_type && board[4] == tile_type && board[7] == tile_type)
		{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(1, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(4, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(7, getWinnerTiles(player_type));

		}
		if (board[2] == tile_type && board[5] == tile_type && board[8] == tile_type)
		{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(2, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(5, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(8, getWinnerTiles(player_type));
		}
		if (board[0] == tile_type && board[4] == tile_type && board[8] == tile_type)
		{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(0, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(4, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(8, getWinnerTiles(player_type));
		}
		if (board[2] == tile_type && board[4] == tile_type && board[6] == tile_type)
		{
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(2, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(4, getWinnerTiles(player_type));
			ServiceLocator::getInstance()->getBoardTileService()->switchBoardTile(6, getWinnerTiles(player_type));
		}

	}


	MoveTurn GameplayService::getMoveTurn()
	{
		return current_move_turn;
	}

	void GameplayService::setPlayerTwoSymbol(Player::PlayerSymbol symbol)
	{
		player_two = symbol;
	}


	
}
