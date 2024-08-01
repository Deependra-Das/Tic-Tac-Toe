#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../header/Global/Config.h"
#include<algorithm>


namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Time;
	using namespace Main;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView();;
	}

	PlayerController::~PlayerController()
	{
		delete(player_model);
		delete(player_view);
	}

	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

		sf::Vector2i mouse_position = sf::Vector2i(sf::Mouse::getPosition(*game_window));
		sf::Vector2f mouseCoord{ game_window->mapPixelToCoords(mouse_position) };

		mouseCoord.x -= 100; mouseCoord.y -= 100;
		player_model->setPlayerPosition(mouseCoord);

		if (event_service->pressedLeftMouseButton())
		{
			processTileClick(mouseCoord);
		}

	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	void PlayerController::update()
	{

		processPlayerInput();

		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();

	}

	void PlayerController::reset()
	{
		player_model->reset();
	}

	void PlayerController::processTileClick(sf::Vector2f mouse_position)
	{
		ServiceLocator::getInstance()->getBoardTileService()->clickedOnBoardTile(mouse_position);
	}


	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

}