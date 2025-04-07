#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "catch.hpp"

TEST_CASE("Test first player X") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test column win") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}