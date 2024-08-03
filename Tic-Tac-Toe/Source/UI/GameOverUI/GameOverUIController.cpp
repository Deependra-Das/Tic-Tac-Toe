#include "../../Header/UI/GameOverUI/GameOverUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicsService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Event/EventService.h"

namespace UI
{
    namespace GameOverUI
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;

        GameOverUIController::GameOverUIController()
        {
            createImage();
            createButtons();
        }

        GameOverUIController::~GameOverUIController()
        {
            destroy();
        }

        void GameOverUIController::initialize()
        {
            initializeBackgroundImage();
            initializeGameOverImage();
            initializeButtons();
            registerButtonCallback();
        }

        void GameOverUIController::createImage()
        {
            background_image = new ImageView();
            gameover_image_view = new ImageView();
            gameover_text_image_view = new ImageView();
        }

        void GameOverUIController::createButtons()
        {
            restart_button = new ButtonView();
            menu_button = new ButtonView();

        }

        void GameOverUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_image_alpha);
        }

        void GameOverUIController::initializeGameOverImage()
        {
            gameover_image_view->initialize(Config::draw_no_winner_texture, gameover_image_width, gameover_image_height, sf::Vector2f(0, gameover_image_y_position));
            gameover_image_view->setCentreAlinged();
            gameover_image_view->setImageAlpha(120);
            gameover_text_image_view->initialize(Config::draw_text_image, gameover_text_image_width, gameover_text_image_height, sf::Vector2f(0, gameover_text_image_y_position));
            gameover_text_image_view->setCentreAlinged();
        }


        void GameOverUIController::initializeButtons()
        {
            restart_button->initialize("Restart Button", Config::try_again_button_texture, button_width, button_height, sf::Vector2f(0, restart_button_y_position));
            menu_button->initialize("Menu Button", Config::menu_button_texture, button_width, button_height, sf::Vector2f(0, menu_button_y_position));

            restart_button->setCentreAlinged();
            menu_button->setCentreAlinged();
        }

        void GameOverUIController::registerButtonCallback()
        {
            restart_button->registerCallbackFuntion(std::bind(&GameOverUIController::RestartButtonCallback, this));
            menu_button->registerCallbackFuntion(std::bind(&GameOverUIController::MenuButtonCallback, this));

        }

        void GameOverUIController::RestartButtonCallback()
        {
            ServiceLocator::getInstance()->getGameplayService()->restart();
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void GameOverUIController::MenuButtonCallback()
        {
            ServiceLocator::getInstance()->getGameplayService()->restart();
            GameService::setGameState(GameState::MAINMENU);

        }

        void GameOverUIController::restartGameplay()
        {
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void GameOverUIController::update()
        {
            background_image->update();
            gameover_image_view->update();
            gameover_text_image_view->update();
            restart_button->update();
            menu_button->update();
        }

        void GameOverUIController::render()
        {
            background_image->render();
            gameover_image_view->render();
            gameover_text_image_view->render();
            restart_button->render();
            menu_button->render();
        }

        void GameOverUIController::show()
        {
            background_image->show();
            gameover_image_view->show();
            gameover_text_image_view->show();
            restart_button->show();
            menu_button->show();

        }

        void GameOverUIController::destroy()
        {
            delete (restart_button);
            delete (menu_button);
            delete (gameover_image_view);
            delete (gameover_text_image_view);
            delete (background_image);
     
        }

        void GameOverUIController::setGameOverTexture(sf::String image_texture, sf::String text_texture)
        {
            gameover_image_view->setTexture(image_texture);
            gameover_text_image_view->setTexture(text_texture);

        }
    }
}