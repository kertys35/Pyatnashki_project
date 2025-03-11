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
	int check = game->Check(1);
	REQUIRE(check == 1);
}

TEST_CASE("Check_win_lose_condition")
{
	Game* game = new Game();
	int check = game->Check(0);
	REQUIRE(check == 0);
}
TEST_CASE("Test_Game_Initialization")
{
	Game* game = new Game();
	int check = game->Initialize();
	REQUIRE(check == 1);
}
TEST_CASE("Test_Movement_Left")
{
	Game* game = new Game();
	int left = 0;
	int check = game->Move(left);
	REQUIRE(check == 14);
}
TEST_CASE("Test_Movement_Right")
{
	Game* game = new Game();
	int right = 1;
	int left = 0;
	game->Move(left);
	int check = game->Move(right);
	REQUIRE(check == 15);
}
TEST_CASE("Test_Movement_Up")
{
	Game* game = new Game();
	int up = 2;
	int check = game->Move(up);
	REQUIRE(check == 11);
}

