#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Player/PlayerModel.h"

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Global;
        using namespace Player;
        using namespace UI::UIElement;

        GameplayUIController::GameplayUIController() { createUIElements(); }

        GameplayUIController::~GameplayUIController() { destroy(); }

        void GameplayUIController::initialize()
        {
            initializeImage();
            initializeText();
        }

        void GameplayUIController::createUIElements()
        {
            container_image = new ImageView();
            turn_text = new TextView();
        }

        void GameplayUIController::initializeImage()
        {         
            container_image->initialize(Config::turn_cross_image, container_width, container_height, sf::Vector2f(container_x_position, container_y_position));
            container_image->setCentreAlinged();
        }

        void GameplayUIController::initializeText()
        {
            sf::String lives_remaining_string = "YOUR TURN";
            turn_text->initialize(lives_remaining_string, sf::Vector2f(turn_text_x_position, turn_text_y_position), FontType::Rajdhani, font_size, text_color);
            turn_text->setsetCentreAlingedText();
        }

        void GameplayUIController::update()
        {
            container_image->update();
            turn_text->update();
        }

        void GameplayUIController::render()
        {
            container_image->render();
            turn_text->render();
        }

        void GameplayUIController::show()
        {
        }

        void GameplayUIController::updateTurnText(sf::String current_turn_text)
        {
            turn_text->setText(current_turn_text);
        }

        void GameplayUIController::updateContainerImage(sf::String current_turn_image)
        {
            container_image->setTexture(current_turn_image);
        }

        void GameplayUIController::destroy()
        {
            delete(turn_text);
            delete(container_image);
        }
    }
}