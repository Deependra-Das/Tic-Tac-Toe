#include "../../Header/BoardTile/BoardTileService.h"
#include "../../Header/BoardTile/BoardTileController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/BoardTile/BoardTileConfig.h"

namespace BoardTile
{
	using namespace Global;
	using namespace Time;

	BoardTileService::BoardTileService()
	{
	}

	BoardTileService::~BoardTileService()
	{
		destroy();
	}

	void BoardTileService::initialize()
	{
		for (int i = 0; i < board_row_col_size; i++)
		{
			for (int j = 0; j < board_row_col_size; j++)
			{
				sf::Vector2f new_position = sf::Vector2f(board_tile_x_pos + (j * board_tile_offset), board_tile_y_pos + ( i * board_tile_offset));

				board_tile_position_list.push_back(new_position);

				spawnBoardTile(new_position);
			}

		}
	

	}

	void BoardTileService::update()
	{
		for (int i = 0; i < board_tile_list.size(); i++)
		{
			board_tile_list[i]->update();
		}

	}

	void BoardTileService::render()
	{
		for (int i = 0; i < board_tile_list.size(); i++)
		{
			board_tile_list[i]->render();
		}
	}

	BoardTileController* BoardTileService::spawnBoardTile(sf::Vector2f position)
	{
		BoardTileController* board_tile_controller = new BoardTileController(BoardTileType::Blank);
		board_tile_controller->initialize(position);

		board_tile_list.push_back(board_tile_controller);
		return board_tile_controller;
	}

	int BoardTileService::clickedOnBoardTile(sf::Vector2f mouse_position)
	{
		int flagged_index = -1;
		for (int i = 0; i < board_tile_list.size(); i++)
		{
			if (board_tile_list[i]->getTileSprite().getGlobalBounds().contains(mouse_position))
			{
				if (board_tile_list[i]->getBoardTileType() == BoardTileType::Blank)
				{
					flagged_index = i;
				}
			}

		}

		return flagged_index;
	}

	void BoardTileService::destroy()
	{
		for (int i = 0; i < board_tile_list.size(); i++)
		{
			delete (board_tile_list[i]);
		}
		board_tile_list.clear();
	}

	void BoardTileService::reset()
	{
		destroy();

	}

	void BoardTileService::switchBoardTile(int index, BoardTileType tile_type)
	{
		board_tile_list[index]->setBoardTileType(tile_type);

	}


}
