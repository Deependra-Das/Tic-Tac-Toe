#pragma once

#include <SFML/Graphics.hpp>

namespace Player
{
    class PlayerModel
    {
    private:

        friend class PlayerController;

        const int max_player_lives = 3;
        static int player_lives;

        sf::Vector2f player_position;

    public:

        PlayerModel();
        ~PlayerModel();

        void initialize();

        void reset();

        sf::Vector2f getPlayerPosition();
        void setPlayerPosition(sf::Vector2f position);

    };
}
