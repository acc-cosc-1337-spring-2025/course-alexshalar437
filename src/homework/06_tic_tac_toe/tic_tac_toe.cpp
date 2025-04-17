#include "tic_tac_toe.h"
#include <iostream>
#include <cmath>

// Конструктор для инициализации доски
TicTacToe::TicTacToe(int size) : pegs(size * size, " "), board_size(size) {}

// Начало новой игры
void TicTacToe::start_game(std::string first_player) {
    if (first_player == "X" || first_player == "O") {
        player = first_player;
        clear_board();
    }
}

// Отметить позицию на доске
void TicTacToe::mark_board(int position) {
    if (position >= 1 && position <= pegs.size() && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        set_next_player();
    }
}

// Отобразить доску
void TicTacToe::display_board() const {
    for (int i = 0; i < pegs.size(); i++) {
        std::cout << pegs[i];
        if ((i + 1) % board_size == 0)
            std::cout << "\n";
        else
            std::cout << " | ";
    }
}

// Проверка завершения игры
bool TicTacToe::game_over() {
    if (check_column_win() || check_row_win() || check_diagonal_win()) {
        set_winner();
        return true;
    } else if (check_board_full()) {
        winner = "C"; // Ничья
        return true;
    }
    return false;
}

// Проверка, заполнена ли доска
bool TicTacToe::check_board_full() const {
    for (const auto& peg : pegs) {
        if (peg == " ") return false;
    }
    return true;
}

// Установить победителя
void TicTacToe::set_winner() {
    winner = (player == "X") ? "O" : "X"; // Игрок уже переключился
}

// Получить победителя
std::string TicTacToe::get_winner() const {
    return winner;
}

// Проверка победы по столбцам
bool TicTacToe::check_column_win() {
    for (int col = 0; col < board_size; col++) {
        bool win = true;
        for (int row = 0; row < board_size; row++) {
            if (pegs[row * board_size + col] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }
    return false;
}

// Проверка победы по строкам
bool TicTacToe::check_row_win() {
    for (int row = 0; row < board_size; row++) {
        bool win = true;
        for (int col = 0; col < board_size; col++) {
            if (pegs[row * board_size + col] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }
    return false;
}

// Проверка победы по диагоналям
bool TicTacToe::check_diagonal_win() {
    // Главная диагональ
    bool win = true;
    for (int i = 0; i < board_size; i++) {
        if (pegs[i * board_size + i] != player) {
            win = false;
            break;
        }
    }
    if (win) return true;

    // Побочная диагональ
    win = true;
    for (int i = 0; i < board_size; i++) {
        if (pegs[i * board_size + (board_size - 1 - i)] != player) {
            win = false;
            break;
        }
    }
    return win;
}

// Очистить доску
void TicTacToe::clear_board() {
    pegs.assign(pegs.size(), " ");
}

// Переключить игрока
void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
    for (size_t i = 0; i < game.pegs.size(); i++) {
        out << game.pegs[i];
        if ((i + 1) % game.board_size == 0)
            out << "\n";
        else
            out << " | ";
    }
    return out;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& in, TicTacToe& game) {
    int position;
    std::cout << "Player " << game.get_player() << ", enter position (1-" << game.pegs.size() << "): ";
    in >> position;
    game.mark_board(position);
    return in;
}