#pragma once

#include <SFML/Graphics.hpp>

namespace Global
{
	class Config
	{
	public:
		static const sf::String background_texture_path;
		static const sf::String background_main_menu_texture_path;
		static const sf::String game_logo_texture_path;
		static const sf::String blank_tile_texture_path;
		static const sf::String flagged_X_tile_texture_path;
		static const sf::String flagged_O_tile_texture_path;
		static const sf::String win_X_tile_texture_path;
		static const sf::String win_O_tile_texture_path;
		static const sf::String player_X_texture;
		static const sf::String player_O_texture;
		static const sf::String winner_cross_texture;
		static const sf::String winner_circle_texture;
		static const sf::String draw_no_winner_texture;
		static const sf::String win_text_image;
		static const sf::String lose_text_image;
		static const sf::String draw_text_image;
		static const sf::String turn_cross_image;
		static const sf::String turn_circle_image;

		static const sf::String play_easy_button_texture;
		static const sf::String play_hard_button_texture;
		static const sf::String quit_button_texture;
		static const sf::String continue_button_texture;
		static const sf::String menu_button_texture;
		static const sf::String try_again_button_texture;

			
		static const sf::String Rajdhani_font_path;
		static const sf::String bubble_bobble_font_path;
		static const sf::String DS_DIGIB_font_path;

	};
}
