#ifndef GAME_H
#define GAME_H
#pragma once
#include <vector>

class Game
{
public:
	int moveCount = 1;
	int num;
	int lastNumPlayerOne;
	int lastNumPlayerTwo;
	bool playerOneTurn = true;
	bool putDown;
	bool gameDraw = false;
	std::vector<std::vector<std::vector<char>>> boardMoves;
	std::vector<std::vector<char>> board;
	void PlayerInput();
	void InitBoard(std::vector<std::vector<char>> arr);
	void DrawBoard(std::vector<std::vector<char>> arr);
	void Reset();
	void Undo();
	bool GameOver();
	bool RowSame(std::vector<std::vector<char>> arr, char x);
	bool ColumnSame(std::vector<std::vector<char>> arr, char x);
	bool DiagonalsSame(std::vector<std::vector<char>> arr, char x);
private:

};

#endif