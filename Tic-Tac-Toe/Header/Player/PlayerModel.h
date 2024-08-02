#pragma once

#include <SFML/Graphics.hpp>

namespace Player
{
    enum class PlayerSymbol
    {
       PLAYER_X,
       PLAYER_O,
    };

    class PlayerModel
    {
    private:

        friend class PlayerController;

        const int max_player_move = 1;
        static int player_move;
        PlayerSymbol player_symbol;
        sf::Vector2f player_position;

    public:

        PlayerModel();
        ~PlayerModel();

        void initialize();

        void reset();

        sf::Vector2f getPlayerPosition();

        PlayerSymbol getPlayerSymbol();

        void setPlayerSymbol(PlayerSymbol symbol);

        void setPlayerPosition(sf::Vector2f position);

        int getPlayerMovesLeft();

        void decreasePlayerMove();
    
    };
}
