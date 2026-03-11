#include <iostream>
#include <cstdlib> // Library for random numbers
#include <ctime>   // Library for random numbers
#include <conio.h> // Library for keyboard controls
#include <windows.h> // Library for drawing and clearing the console
#include <vector> // Library for vectors
using namespace std;

int main() { // Main function

	// VARIABLES!
	int score = 0; // Score
	int height = 12; // Wall height
	int width = 30; // Wall width
	int snakey = height / 2; // Y position of the snake head
	int snakex = width / 2; // X position of the snake head
	srand(time(NULL)); // Random generation
	int foody = rand() % height; // Y position of the food
	int foodx = rand() % width; // X position of the food
	bool gameover = false; // Game state
	char strelice = 'd'; // Movement direction
	vector <int> repx; // Vector for tail on X axis
	vector <int> repy; // Vector for tail on Y axis
	int duzina = 0; // Tail length


	while (!gameover) { // Start of the game

		// DRAWING!
		system("cls"); // Command to clear the console

		for (int i = 0; i <= width; i++) cout << "#"; // Draw top wall
		cout << endl; // New line

		for (int i = 0; i <= height; i++) { // Wall height
			for (int j = 0; j <= width; j++) { // Wall width

				if (j == 0 || j == width) cout << "#"; // Draw side walls

				else if (i == snakey && j == snakex)  // Snake head position
					cout << "O";// Draw snake head

				else { // Tail
					bool rep = false; // Boolean variable for tail
					for (int k = 0; k < repx.size(); k++) { // Loop for tail length
						if (repx[k] == j && repy[k] == i) { // If coordinates match
							rep = true; // Tail detected
							break; // Exit loop
						}
					}

					if (rep) cout << "o"; // Draw tail
					else if (i == foody && j == foodx) cout << "@"; // Draw food
					else  // Empty space
						cout << " ";
				}
			}
			cout << endl; // New line
		}

		for (int i = 0; i <= width; i++)cout << "#"; // Bottom wall
		cout << endl; // New line

		// GAME FUNCTION!
		if (snakey == -1 || snakey == height + 1 || snakex == -1 || snakex == width + 1)  // Touching the wall = lose
			gameover = true; // End game

		if (snakey == foody && snakex == foodx) { // Eating food
			foody = rand() % height; // Random food position on Y axis
			foodx = rand() % width; // Random food position on X axis
			score = score + 10; // Increase score by 10
			duzina++; // Increase tail length
		}

		repx.insert(repx.begin(), snakex); // Head takes the first position on X axis
		repy.insert(repy.begin(), snakey); // Head takes the first position on Y axis

		if (repx.size() > duzina) { // If the tail is too long
			repx.pop_back(); // Remove last part of tail on X axis
			repy.pop_back(); // Remove last part of tail on Y axis
		}

		for (int i = 0; i < duzina; i++) { // If the snake hits its tail
			if (snakey == repy[i + 1] && snakex == repx[i + 1]) 
				gameover = true; // End game
		}

		cout << "Your score: " << score << endl; // Print score

		// CONTROLS
		if (_kbhit()) { // Keyboard input
			char ch = _getch();

			if (ch == 'w')strelice = 'w'; // Up
			if (ch == 's')strelice = 's'; // Down
			if (ch == 'a')strelice = 'a'; // Left
			if (ch == 'd')strelice = 'd'; // Right
		}

		if (strelice == 'w')snakey--; // Move snake up
		if (strelice == 's')snakey++; // Move snake down
		if (strelice == 'a')snakex--; // Move snake left
		if (strelice == 'd')snakex++; // Move snake right

		Sleep(300); // Delay
	}

	cout << "GAME OVER!" << endl; // Print game over
	
}