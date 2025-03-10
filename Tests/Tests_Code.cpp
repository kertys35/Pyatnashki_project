#include "catch.hpp"
#include "Game.cpp"

TEST_CASE("Create_Game_Object")
{
	Game *game = new Game();
	REQUIRE(game != NULL);
}