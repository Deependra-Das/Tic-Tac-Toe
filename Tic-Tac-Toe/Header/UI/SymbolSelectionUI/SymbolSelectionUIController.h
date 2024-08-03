#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"
#include "../../Player/PlayerModel.h"

namespace UI
{
	namespace SymbolSelectionUI
	{
		enum class PlayerSymbol;

		class SymbolSelectionUIController : public Interface::IUIController
		{
		private:

			const float select_button_width = 640.f;
			const float select_button_height = 640.f;

			const float button_height = 72.0f;
			const float button_width = 320.0f;

			const float select_button_y_position = 220;
			const float select_X_button_x_position = 295;
			const float select_O_button_x_position = 985.f;
			const float menu_button_y_position = 908.f;

			const float background_image_alpha = 90.0f;

			UIElement::ImageView* background_image;
			UIElement::ButtonView* continue_button;
			UIElement::ButtonView* select_X_button;
			UIElement::ButtonView* select_O_button;

			Player::PlayerSymbol selected_symbol;
			Player::PlayerSymbol not_selected_symbol;
			bool check_selected;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();
			void ContinueButtonCallback();
			void SelectXButtonCallback();
			void SelectOButtonCallback();
			void destroy();

		public:
			SymbolSelectionUIController();
			~SymbolSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};
	}
}