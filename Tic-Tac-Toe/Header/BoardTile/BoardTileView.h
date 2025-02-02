#pragma once

#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace BoardTile
{
	enum class BoardTileType;
	class BoardTileController;

	class BoardTileView
	{
	private:
		const float board_tile_sprite_height = 250.0f;
		const float board_tile_sprite_width = 250.0f;

		BoardTileController* board_tile_controller;
		UI::UIElement::ImageView* board_tile_image;

		void createUIElements();
		void initializeImage();
		sf::String getBoardTileTexturePath();
		void updateBoardTileImage();

		void destroy();

	public:
		BoardTileView();
		~BoardTileView();

		void initialize(BoardTileController* controller);
		void update();
		void render();

		const sf::Sprite& getTileSprite();

	};

}


