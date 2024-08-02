#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace Interface;
	using namespace UIElement;
	using namespace SymbolSelectionUI;

	UIService::UIService()
	{
		symbol_selection_ui_controller = nullptr;
		createControllers();
	}

	UIService::~UIService()
	{
		destroyControllers();
	}

	void UIService::createControllers()
	{
		symbol_selection_ui_controller = new SymbolSelectionUIController();
	}

	void UIService::initialize()
	{
		UI::UIElement::TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		symbol_selection_ui_controller->initialize();
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
		default:
			return nullptr;
		}
	}

	void UIService::destroyControllers()
	{
	}

}