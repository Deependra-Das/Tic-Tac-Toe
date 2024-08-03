#pragma once

#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/SymbolSelectionUI/SymbolSelectionUIController.h"
#include "../../Header/UI/GameOverUI/GameOverUIController.h"
#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"

namespace UI
{
	class UIService
	{
	private:
		SymbolSelectionUI::SymbolSelectionUIController* symbol_selection_ui_controller;
		GameOverUI::GameOverUIController* game_over_ui_controller;
		MainMenuUI::MainMenuUIController* main_menu_ui_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;

		void createControllers();
		void initializeControllers();
		void destroyControllers();

		Interface::IUIController* getCurrentUIController();


	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();

		void setGameOverTexture(sf::String image_texture, sf::String text_texture);
		void updateTurnText(sf::String current_turn_text);
		void updateContainerImage(sf::String current_turn_image);
	};
}