#pragma once

#include "../../Header/UI/Interface/IUIController.h"


namespace UI
{
	class UIService
	{
	private:

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