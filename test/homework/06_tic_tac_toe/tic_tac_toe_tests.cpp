#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <cassert>
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
int main() {
    TicTacToe game;

    // Start game with "X"
    game.start_game("X");
    assert(game.get_player() == "X");

    // Mark board positions and check game over status
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(3);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);
    game.mark_board(6);
    game.mark_board(9);
    game.mark_board(8);
    
    assert(game.game_over() == true);

    std::cout << "All test cases passed!\n";
    return 0;
}