#pragma once

#include <SFML/Graphics.hpp>

namespace BoardTile
{
	enum class BoardTileType
	{
		Blank,
		Flagged_X,
		Flagged_O,
		Win_X,
		Win_O,
	};

}
