#include "catch.hpp"
#include"Game.cpp"

#include <iostream>



TEST_CASE("Create_Game_Object")
{
	Game *game = new Game();
	REQUIRE(game != NULL);
}

TEST_CASE("Check_win_condition")
{
	Game* game = new Game();
	REQUIRE(game.Check(1) == 1);
}