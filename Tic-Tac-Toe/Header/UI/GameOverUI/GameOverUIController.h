#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace GameOverUI
	{

		class GameOverUIController : public Interface::IUIController
		{
		private:

			const float gameover_image_width = 480.f;
			const float gameover_image_height = 304.f;
			const float gameover_text_image_width = 960.f;
			const float gameover_text_image_height = 160.f;

			const float button_height = 72.0f;
			const float button_width = 320.0f;

			const float gameover_image_y_position = 220.f;
			const float gameover_text_image_y_position = 290.f;
			const float restart_button_y_position = 700.f;
			const float menu_button_y_position = 800.f;

			const float background_image_alpha = 90.0f;

			UIElement::ImageView* background_image;
			UIElement::ImageView* gameover_image_view;
			UIElement::ImageView* gameover_text_image_view;
			UIElement::ButtonView* restart_button;
			UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeGameOverImage();
			void initializeButtons();
			void restartGameplay();
			void registerButtonCallback();

			void RestartButtonCallback();
			void MenuButtonCallback();
			void destroy();

		public:
			GameOverUIController();
			~GameOverUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void setGameOverTexture(sf::String image_texture, sf::String text_texture);

		};
	}
}