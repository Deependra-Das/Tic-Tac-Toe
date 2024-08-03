#include "../../Header/UI/SymbolSelectionUI/SymbolSelectionUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace SymbolSelectionUI
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Player;

        SymbolSelectionUIController::SymbolSelectionUIController()
        {
            createImage();
            createButtons();
        }

        SymbolSelectionUIController::~SymbolSelectionUIController()
        {
            destroy();
        }

        void SymbolSelectionUIController::initialize()
        {
            check_selected = false;
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void SymbolSelectionUIController::createImage()
        {
            background_image = new ImageView();
  
        }

        void SymbolSelectionUIController::createButtons()
        {
            continue_button = new ButtonView();
            select_X_button = new ButtonView();
            select_O_button = new ButtonView();
        }

        void SymbolSelectionUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_image_alpha);
        }


        void SymbolSelectionUIController::initializeButtons()
        {
            continue_button->initialize("Continue Button", Config::continue_button_texture, button_width, button_height, sf::Vector2f(0, menu_button_y_position));
            continue_button->setCentreAlinged();
            continue_button->setImageAlpha(90.f);
            select_X_button->initialize("Select X Button", Config::flagged_X_tile_texture_path, select_button_width, select_button_height, sf::Vector2f(select_X_button_x_position, select_button_y_position));
            select_X_button->setImageAlpha(90.f);
            select_O_button->initialize("Select O Button", Config::flagged_O_tile_texture_path, select_button_width, select_button_height, sf::Vector2f(select_O_button_x_position, select_button_y_position));
            select_O_button->setImageAlpha(90.f);
        }

        void SymbolSelectionUIController::registerButtonCallback()
        {
            continue_button->registerCallbackFuntion(std::bind(&SymbolSelectionUIController::ContinueButtonCallback, this));
            select_X_button->registerCallbackFuntion(std::bind(&SymbolSelectionUIController::SelectXButtonCallback, this));
            select_O_button->registerCallbackFuntion(std::bind(&SymbolSelectionUIController::SelectOButtonCallback, this));

        }


        void SymbolSelectionUIController::ContinueButtonCallback()
        {
            if (check_selected == true)
            {
                GameService::setGameState(GameState::GAMEPLAY);
                ServiceLocator::getInstance()->getPlayerService()->setPlayerSymbol(selected_symbol);
                ServiceLocator::getInstance()->getGameplayService()->setPlayerTwoSymbol(not_selected_symbol);
            }
      
        }

        void SymbolSelectionUIController::SelectXButtonCallback()
        {
            selected_symbol = Player::PlayerSymbol::PLAYER_X;
            not_selected_symbol = Player::PlayerSymbol::PLAYER_O;
            select_X_button->setImageAlpha(255.f);
            select_O_button->setImageAlpha(90.f);
            check_selected = true;
            continue_button->setImageAlpha(255.f);
        }

        void SymbolSelectionUIController::SelectOButtonCallback()
        {
            selected_symbol = Player::PlayerSymbol::PLAYER_O;
            not_selected_symbol = Player::PlayerSymbol::PLAYER_X;
            select_O_button->setImageAlpha(255.f);
            select_X_button->setImageAlpha(90.f);
            check_selected = true;
            continue_button->setImageAlpha(255.f);
        }

        void SymbolSelectionUIController::update()
        {
            background_image->update();
            select_X_button->update();
            select_O_button->update();
            continue_button->update();
        }

        void SymbolSelectionUIController::render()
        {
            background_image->render();
            select_X_button->render();
            select_O_button->render();
            continue_button->render();
        }

        void SymbolSelectionUIController::show()
        {
            background_image->show();
            select_X_button->show();
            select_O_button->show();
            continue_button->show();

        }

        void SymbolSelectionUIController::destroy()
        {
            delete (continue_button);
            delete (background_image);
            delete (select_X_button);
            delete (select_O_button);
        }
    }
}