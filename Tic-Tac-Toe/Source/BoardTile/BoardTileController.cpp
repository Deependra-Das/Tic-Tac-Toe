#include "../../Header/BoardTile/BoardTileController.h"
#include "../../Header/BoardTile/BoardTileView.h"
#include "../../Header/BoardTile/BoardTileModel.h"
#include "../../Header/BoardTile/BoardTileConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace BoardTile
{
	using namespace Global;
	using namespace Time;

	BoardTileController::BoardTileController(BoardTileType type)
	{
		board_tile_model = new BoardTileModel(type);
		board_tile_view = new BoardTileView();
	}

	BoardTileController::~BoardTileController()
	{
		delete(board_tile_model);
		delete(board_tile_view);
	}

	void BoardTileController::initialize(sf::Vector2f position)
	{
		board_tile_model->initialize(position);
		board_tile_view->initialize(this);
	}

	void BoardTileController::update()
	{
		board_tile_view->update();
	}

	void BoardTileController::render()
	{
		board_tile_view->render();
	}

	void BoardTileController::destroy()
	{
		ServiceLocator::getInstance()->getBoardTileService()->destroyBoardTile(this);
	}

	BoardTileType BoardTileController::getBoardTileType()
	{
		return board_tile_model->getBoardTileType();
	}

	sf::Vector2f BoardTileController::getBoardTilePosition()
	{
		return board_tile_model->getBoardTilePosition();
	}
}