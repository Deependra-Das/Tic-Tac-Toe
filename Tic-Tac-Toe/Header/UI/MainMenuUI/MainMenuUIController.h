#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace MainMenuUI
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			const float game_logo_width = 336.f;
			const float game_logo_height = 448.f;

			const float button_height = 72.0f;
			const float button_width = 320.0f;

			const float game_logo_y_position = 220.f;
			const float play_easy_button_y_position = 750.f;
			const float play_hard_button_y_position = 850.f;
			const float quit_button_y_position = 950.f;

			const float background_image_alpha = 90.0f;

			UIElement::ImageView* background_image;
			UIElement::ImageView* game_logo_view;
			UIElement::ButtonView* play_easy_button;
			UIElement::ButtonView* play_hard_button;
			UIElement::ButtonView* quit_button;

			void createImage();
			void createButtons();
			void initializeGameLogoImage();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();

			void playEasyButtonCallback();
			void playHardButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};
	}
}