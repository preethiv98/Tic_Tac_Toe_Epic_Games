#include "Game.h"
#include <iostream>
#include <list>
#include <vector>

void Game::PlayerInput()
{
	int size = 0;
	for (int i = 0; i < board.size(); i++)
		size += board[i].size();
	if (playerOneTurn)
	{
		std::cout << std::endl;
		std::cout << "Player 1's Turn! " << std::endl;
		std::cout << std::endl;
		std::cout << "Type in a number or -1 to undo: ";
		std::cin >> num;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Player 2's Turn! " << std::endl;
		std::cout << std::endl;
		std::cout << "Type in a number or -1 to undo: ";
		std::cin >> num;
	}
	
	if (num == -1)
	{
		Undo();
		putDown = true;
	}
	if (moveCount == 1)
	{
		//Reset();
		boardMoves.push_back(board);
		//putDown = false;
		//moveCount++;
		
	}
	if (std::cin.fail() || num > size || num == 0 || num < -1)
	{

	std::cout << std::endl;
		std::cout << "Invalid input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		InitBoard(boardMoves.back());
		//PlayerInput();
		std::cout << std::endl;
	}
	else
	{
		for (int i = 0; i < boardMoves.back().size(); i++)
		{
			for (int j = 0; j < boardMoves.back()[0].size(); j++)
			{
				if (num == ((int)(boardMoves.back()[i][j]) - 48))
				{
					if (playerOneTurn)
					{
						//lastNumPlayerOne = board[i][j];
						std::vector<std::vector<char>> newBoard = boardMoves.back();
						newBoard[i][j] = 'X';
						boardMoves.push_back(newBoard);
						playerOneTurn = false;
						
						putDown = true;
						//std::cout << "This is p1 turn and put down is" << " " << putDown << std::endl;
						InitBoard(boardMoves.back());
						moveCount++;
						break;
					}
					else
					{
						//lastNumPlayerTwo = board[i][j];
						std::vector<std::vector<char>> newBoard = boardMoves.back();
						newBoard[i][j] = 'O';
						boardMoves.push_back(newBoard);
						playerOneTurn = true;
					
						putDown = true;
						//std::cout << "This is p2 turn and put down is" << " " << putDown << std::endl;
						InitBoard(boardMoves.back());
						moveCount++;
						break;
					}
				}

			}
		}
		//std::cout << putDown << std::endl;
		if (!putDown)
		{
		std::cout << std::endl;
			std::cout << "Spot already filled! " << std::endl;
			std::cout << std::endl;
			InitBoard(boardMoves.back());
			//PlayerInput();
			std::cout << std::endl;
		
			
		}
		putDown = false;
		
	}
	
	
}

void Game::InitBoard(std::vector<std::vector<char>> arr)
{
	std::cout << "  PLAYER 1 - [X]   PLAYER 2 - [O]        \n" << std::endl;
	std::cout << std::endl;
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
		{
			
			std::cout << "     " <<  arr[i][j];

		}
		std::cout << std::endl;
	}
}

void Game::DrawBoard(std::vector<std::vector<char>> arr)
{
	int count = 0;
	int size = 0;
	for (int i = 0; i < board.size(); i++)
		size += board[i].size();

	int square = sqrt(size);

	std::cout << "  PLAYER 1 - [X]   PLAYER 2 - [O]        \n" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < arr[0].size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{

		/*	if (arr[i][j] % square == 0 && square <= arr[i][j])
			{
				std::cout << "   |   " << std::endl;
				std::cout << "----------------------------------" * 3 << std::endl;
			}*/
			
			if (i == 0 && j == 0)
			{
				std::cout << "          |     |     " << std::endl;
				std::cout << "       " << arr[i][j] << "  |  " << arr[i][j + 1] << "  |  " << arr[i][j + 2] << std::endl;
			}
			else if (i == 1 && j == 0)
			{
				std::cout << "     _____|_____|_____" << std::endl;
				std::cout << "          |     |     " << std::endl;
				std::cout << "       " << arr[i][j] << "  |  " << arr[i][j + 1] << "  |  " << arr[i][j + 2] << std::endl;
			}
			else if ((i == arr[0].size() - 1) && j == 0)
			{
				std::cout << "     _____|_____|_____" << std::endl;
				std::cout << "          |     |     " << std::endl;
				std::cout << "       " << arr[i][j] << "  |  " << arr[i][j + 1] << "  |  " << arr[i][j + 2] << std::endl;
				std::cout << "          |     |     " << std::endl << std::endl << std::endl;
			}
			
			
			
		}
	}


	////std::cout << "PLAYER - 1 [X] PLAYER - 2 [O]" << std::endl;
	//std::cout << std::endl;
	//std::cout << std::endl;
	//std::cout << "     |     |     \n";
	//std::cout << "tt  " << board[0][0] << "  | " << board[0][1] << "  |  " << board[0][2] << "\n";
	//std::cout << "tt_____|_____|_____n";
	//std::cout << "tt     |     |     n";
	//std::cout << "tt  " << board[1][0] << "  | " << board[1][1] << "  |  " << board[1][2] << "\n";
	//std::cout << "tt_____|_____|_____n";
	//std::cout << "tt     |     |     n";
	//std::cout << "tt  " << board[2][0] << "  | " << board[2][1] << "  |  " << board[2][2] << "\n";
	//std::cout << "tt     |     |     n";
}

void Game::Reset()
{
	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!boardMoves.empty())
			{
				board[i][j] = static_cast<char>(count + 48);

				count++;
		}
			
		}
	}
	//putDown = false;
	moveCount = 1;
	boardMoves.clear();
}

void Game::Undo()
{
	if (moveCount == 1)
	{
		std::cout << "Invalid undo!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		Reset();
		InitBoard(board);
		//putDown = false;
		//PlayerInput();
		
		
	}
	else
	{
		if (playerOneTurn)
		{
			playerOneTurn = false;
		}
		else
		{
			playerOneTurn = true;
		}
		
		moveCount--;
		
		boardMoves.pop_back();
		InitBoard(boardMoves.back());
		std::cin.clear();
		putDown = false;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//PlayerInput();
	}
}

bool Game::GameOver()
{
	if (!boardMoves.empty())
	{
		if (RowSame(boardMoves.back(), 'X'))
		{
			std::cout << "Player 1 has won the game!" << std::endl;
			return true;
		}
		if (RowSame(boardMoves.back(), 'O'))
		{
			std::cout << "Player 2 has won the game! " << std::endl;
			return true;
		}
		if (ColumnSame(boardMoves.back(), 'X'))
		{
			std::cout << "Player 1 has won the game!" << std::endl;
			return true;
		}
		if (ColumnSame(boardMoves.back(), 'O'))
		{
			std::cout << "Player 2 has won the game! " << std::endl;
			return true;
		}
		if (DiagonalsSame(boardMoves.back(), 'X'))
		{
			std::cout << "Player 1 has won the game!" << std::endl;
			return true;
		}
		if (DiagonalsSame(boardMoves.back(), 'O'))
		{
			std::cout << "Player 2 has won the game! " << std::endl;
			return true;
		}
		for (int i = 0; i < boardMoves.back().size(); i++)
		{
			for (int j = 0; j < boardMoves.back()[0].size(); j++)
			{
				if (boardMoves.back()[i][j] != 'X' && boardMoves.back()[i][j] != 'O')
				{
					return false;
				}
			}
		}
		std::cout << std::endl;
		std::cout << "This game is a draw.";
		return true;
}
	return false;
}

bool Game::RowSame(std::vector<std::vector<char>> arr, char x)
{ 
	int count;
	int rowNum = arr.size();
	int colNum = arr[0].size();
	if (rowNum < colNum || rowNum == colNum)
	{
		for (int i = 0; i < rowNum; i++)
		{
			count = 0;
			for (int j = 0; j < colNum; j++)
			{

				if (arr[i][j] == x)
				{
					count++;
				}
				if (count == colNum)
				{
					return true;
				}

			}

		}
		return false;
	}
	if (rowNum > colNum)
	{
		for (int i = 0; i < rowNum; i++)
		{
			count = 0;
			for (int j = 0; j < colNum; j++)
			{

				if (arr[i][j] == x)
				{
					count++;
				}
				if (count == colNum)
				{
					return true;
				}

			}

		}
		return false;
	}

}

bool Game::ColumnSame(std::vector<std::vector<char>> arr, char x)
{
	int count;
	int rowNum = arr.size();
	int colNum = arr[0].size();
	if (rowNum < colNum || rowNum == colNum)
	{
		for (int j = 0; j < colNum; j++)
		{
			count = 0;
			for (int i = 0; i < rowNum; i++)
			{
				
				if (arr[i][j] == x)
				{
					count++;
				}
				if (count == rowNum)
				{
					return true;
				}
				
			}
			
		}
		return false;
	}
	if (rowNum > colNum)
	{
		for (int j = 0; j < colNum; j++)
		{
			count = 0;
			for (int i = 0; i < rowNum; i++)
			{
				
				if (arr[i][j] == x)
				{
					count++;
				}
				if (count == rowNum)
				{
					return true;
				}
				
			}
			
		}
		return false;
		}
		

}

bool Game::DiagonalsSame(std::vector<std::vector<char>> arr, char x)
{
	int val = 0;
	int count = 0;
	int rowNum = arr.size();
	int colNum = arr[0].size();
	if (rowNum > colNum || rowNum == colNum || colNum > rowNum)
	{
		for (int i = 0; i < rowNum; i++)
		{
			//count = 0;
			if (val < colNum)
			{
				if (arr[i][val] == x)
				{
					count++;
				}
				if (count == colNum)
				{
					return true;
				}
				val++;
			}
			
		}

		val = arr[0].size() - 1;
		count = 0;
		for (int i = 0; i < rowNum; i++)
		{
			if (val >= 0)
			{
				if (arr[i][val] == x)
				{
					count++;
				}
				if (count == colNum)
				{
					return true;
				}
				val--;
			}
			
		}
		return false;
	}
	
}

