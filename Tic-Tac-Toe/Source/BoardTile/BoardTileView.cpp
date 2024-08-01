#include "../../Header/BoardTile/BoardTileView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/BoardTile/BoardTileController.h"
#include"../../Header/BoardTile/BoardTileConfig.h"
#include "../../Header/Global/Config.h"

namespace BoardTile
{
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;

	BoardTileView::BoardTileView()
	{
		createUIElements();
	}

	BoardTileView::~BoardTileView()
	{
		destroy();
	}


	void BoardTileView::createUIElements()
	{
		board_tile_image = new ImageView();
	}

	void BoardTileView::initialize(BoardTileController* controller)
	{
		board_tile_controller = controller;
		initializeImage();
	}

	void BoardTileView::initializeImage()
	{
		board_tile_image->initialize(getBoardTileTexturePath(), board_tile_sprite_width, board_tile_sprite_height, board_tile_controller->getBoardTilePosition());
	}

	void BoardTileView::update()
	{
		updateBoardTileImage();
		board_tile_image->update();
	}

	void BoardTileView::render()
	{
		board_tile_image->render();
	}

	const sf::Sprite& BoardTileView::getTileSprite()
	{
		return board_tile_image->getSprite();

	}

	void BoardTileView::updateBoardTileImage()
	{
		board_tile_image->setTexture(getBoardTileTexturePath());
	}


	sf::String BoardTileView::getBoardTileTexturePath()
	{
		switch (board_tile_controller->getBoardTileType())
		{
		case::BoardTile::BoardTileType::Blank:
			return Config::blank_tile_texture_path;

		case::BoardTile::BoardTileType::Flagged_X:
			return Config::flagged_X_tile_texture_path;

		case::BoardTile::BoardTileType::Flagged_O:
			return Config::flagged_O_tile_texture_path;

		case::BoardTile::BoardTileType::Win_X:
			return Config::win_X_tile_texture_path;

		case::BoardTile::BoardTileType::Win_O:
			return Config::win_O_tile_texture_path;
		}
	}

	void BoardTileView::destroy()
	{
		delete(board_tile_image);
	}



}