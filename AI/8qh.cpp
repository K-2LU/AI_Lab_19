#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int heuristic(const vector<int>& board) {
    int n = board.size();
    int attacking_pairs = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (board[i] == board[j] || abs(board[i] - board[j]) == j - i) {
                attacking_pairs++;
            }
        }
    }

    return attacking_pairs;
}

void printBoard(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (board[i] == j ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

void hillClimb(vector<int>& board) {
    int n = board.size();
    int currentAttacks = heuristic(board);

    while (currentAttacks > 0) {
        // Make a copy of the current board
        vector<int> nextBoard = board;

        // Randomly select a queen and move it to a different row in the same column
        int randomQueen = rand() % n;
        int randomRow = rand() % n;

        nextBoard[randomQueen] = randomRow;

        // Calculate the heuristic for the new board
        int nextAttacks = heuristic(nextBoard);

        // If the new board has fewer attacks, accept the move; otherwise, discard it
        if (nextAttacks < currentAttacks) {
            board = nextBoard;
            currentAttacks = nextAttacks;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int n = 8; // Number of queens
    vector<int> board(n);

    // Initialize the board with a random placement of queens in each column
    for (int i = 0; i < n; ++i) {
        board[i] = rand() % n;
    }

    cout << "Initial board:" << endl;
    printBoard(board);

    int initialAttacks = heuristic(board);

    hillClimb(board);

    cout << "Final board:" << endl;
    printBoard(board);

    int finalAttacks = heuristic(board);

    cout << "Initial attacks: " << initialAttacks << endl;
    cout << "Final attacks: " << finalAttacks << endl;

    return 0;
}
