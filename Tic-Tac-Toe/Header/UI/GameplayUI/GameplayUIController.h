#pragma once

#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"

namespace UI
{
    namespace GameplayUI
    {
        class GameplayUIController : public Interface::IUIController
        {
        private:
            const int font_size = 48;
            const float turn_text_y_position = 15.f;
            const float turn_text_x_position = 850.f;

            const float container_y_position = 0.f;
            const float container_x_position = 800.f;

            const float container_width = 320.f;
            const float container_height = 120.f;

            const sf::Color text_color = sf::Color::White;

            UI::UIElement::ImageView* container_image;
            UI::UIElement::TextView* turn_text;

            float spacing;

            void createUIElements();
            void initializeImage();
            void initializeText();
            void destroy();

        public:
            GameplayUIController();
            ~GameplayUIController();

            void initialize() override;
            void update() override;
            void render() override;
            void show() override;

            void updateTurnText(sf::String current_turn_text);
            void updateContainerImage(sf::String current_turn_image);

        };
    }
}

