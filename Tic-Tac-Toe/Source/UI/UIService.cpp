#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace Interface;
	using namespace UIElement;
	using namespace SymbolSelectionUI;
	using namespace GameOverUI;
	using namespace MainMenuUI;
	using namespace GameplayUI;

	UIService::UIService()
	{
		symbol_selection_ui_controller = nullptr;
		game_over_ui_controller = nullptr;
		main_menu_ui_controller = nullptr;
		gameplay_ui_controller = nullptr;
		createControllers();
	}

	UIService::~UIService()
	{
		destroyControllers();
	}

	void UIService::createControllers()
	{
		symbol_selection_ui_controller = new SymbolSelectionUIController();
		game_over_ui_controller = new GameOverUIController();
		main_menu_ui_controller = new MainMenuUIController();
		gameplay_ui_controller = new GameplayUIController();
	}

	void UIService::initialize()
	{
		UI::UIElement::TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		symbol_selection_ui_controller->initialize();
		game_over_ui_controller->initialize();
		main_menu_ui_controller->initialize();
		gameplay_ui_controller->initialize();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->update();
		}

	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->render();
		}
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
		{
			ui_controller->show();
		}
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SELECTION:
			return symbol_selection_ui_controller;

		case GameState::MAINMENU:
			return main_menu_ui_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		case GameState::GAMEOVER:
			return game_over_ui_controller;

		default:
			return nullptr;
		}
	}

	void UIService::destroyControllers()
	{
	}

	void UIService::setGameOverTexture(sf::String image_texture, sf::String text_texture)
	{
		game_over_ui_controller->setGameOverTexture(image_texture, text_texture);

	}

	void UIService::updateTurnText(sf::String current_turn_text)
	{
		gameplay_ui_controller->updateTurnText(current_turn_text);
	}

	void UIService::updateContainerImage(sf::String current_turn_image)
	{
		gameplay_ui_controller->updateContainerImage(current_turn_image);
	}
}