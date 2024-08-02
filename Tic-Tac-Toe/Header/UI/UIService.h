#pragma once

#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/SymbolSelectionUI/SymbolSelectionUIController.h"

namespace UI
{
	class UIService
	{
	private:
		SymbolSelectionUI::SymbolSelectionUIController* symbol_selection_ui_controller;

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
	};
}