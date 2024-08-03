#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace MainMenuUI
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;

        MainMenuUIController::MainMenuUIController()
        {
            createImage();
            createButtons();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            destroy();
        }

        void MainMenuUIController::initialize()
        {
            initializeBackgroundImage();
            initializeGameLogoImage();
            initializeButtons();
            registerButtonCallback();
        }

        void MainMenuUIController::createImage()
        {
            background_image = new ImageView();
            game_logo_view = new ImageView();
        }

        void MainMenuUIController::createButtons()
        {
            play_easy_button = new ButtonView();
            play_hard_button = new ButtonView();
            quit_button = new ButtonView();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

             background_image->initialize(Config::background_main_menu_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
             background_image->setImageAlpha(background_image_alpha);
        }

        void MainMenuUIController::initializeGameLogoImage()
        {
            game_logo_view->initialize(Config::game_logo_texture_path, game_logo_width, game_logo_height, sf::Vector2f(0, game_logo_y_position));
            game_logo_view->setCentreAlinged();
        }

        void MainMenuUIController::initializeButtons()
        {
            play_easy_button->initialize("Play Easy Button", Config::play_easy_button_texture, button_width, button_height, sf::Vector2f(0, play_easy_button_y_position));
            play_hard_button->initialize("Play Hard Button", Config::play_hard_button_texture, button_width, button_height, sf::Vector2f(0, play_hard_button_y_position));
            quit_button->initialize("Quit Button", Config::quit_button_texture, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

            play_easy_button->setCentreAlinged();
            play_hard_button->setCentreAlinged();
            quit_button->setCentreAlinged();
        }

        void MainMenuUIController::registerButtonCallback()
        {
            play_easy_button->registerCallbackFuntion(std::bind(&MainMenuUIController::playEasyButtonCallback, this));
            play_hard_button->registerCallbackFuntion(std::bind(&MainMenuUIController::playHardButtonCallback, this));
            quit_button->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
        }

        void MainMenuUIController::playEasyButtonCallback()
        {
            ServiceLocator::getInstance()->getGameplayService()->setGameMode(Gameplay::GameMode::EASY);
            GameService::setGameState(GameState::SELECTION);
        }

        void MainMenuUIController::playHardButtonCallback()
        {
            ServiceLocator::getInstance()->getGameplayService()->setGameMode(Gameplay::GameMode::HARD);
            GameService::setGameState(GameState::SELECTION);
        }


        void MainMenuUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicsService()->getGameWindow()->close();
        }

        void MainMenuUIController::update()
        {
            background_image->update();
            game_logo_view->update();
            play_easy_button->update();
            play_hard_button->update();
            quit_button->update();
        }

        void MainMenuUIController::render()
        {
            background_image->render();
            game_logo_view->render();
            play_easy_button->render();
            play_hard_button->render();
            quit_button->render();
        }

        void MainMenuUIController::show()
        {
            background_image->show();
            game_logo_view->show();
            play_easy_button->show();
            play_hard_button->show();
            quit_button->show();

        }

        void MainMenuUIController::destroy()
        {
            delete (play_easy_button);
            delete (play_hard_button);
            delete (quit_button);
            delete (background_image);
            delete (game_logo_view);
        }
    }
}