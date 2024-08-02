#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView()
	{
		createUIElements();
	}

	PlayerView::~PlayerView()
	{
		destroy();
	}

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;
		initializeImage();
	}

	void PlayerView::createUIElements()
	{
		player_image = new ImageView();
	}

	void PlayerView::initializeImage()
	{
		player_image->initialize(getPlayerTexturePath(), player_sprite_width, player_sprite_height, player_controller->getPlayerPosition());
	}

	void PlayerView::update()
	{
		player_image->setPosition(player_controller->getPlayerPosition());
		player_image->setTexture(getPlayerTexturePath());
		player_image->update();
	}

	void PlayerView::render()
	{
		player_image->render();
	}

	sf::String PlayerView::getPlayerTexturePath()
	{
		switch (player_controller->getPlayerSymbol())
		{
		case::Player::PlayerSymbol::PLAYER_X:
			return Config::player_X_texture;

		case::Player::PlayerSymbol::PLAYER_O:
			return Config::player_O_texture;

		}

	}

	void PlayerView::destroy()
	{
		delete(player_image);
	}

}