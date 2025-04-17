#define CATCH_CONFIG_MAIN
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "catch.hpp"
// OR
#include <catch.hpp>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test win by first column 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> board = std::make_unique<TicTacToe4>();
    board->start_game("X");
    board->mark_board(1);
    board->mark_board(2);
    board->mark_board(5);
    board->mark_board(6);
    board->mark_board(9);
    board->mark_board(10);
    board->mark_board(13);
    REQUIRE(board->game_over() == true);
    REQUIRE(board->get_winner() == "X");
}