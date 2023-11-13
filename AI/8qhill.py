import random

def random_board(n):
    """Generate a random board with queens placed randomly in each column."""
    board = [random.randint(0, n - 1) for _ in range(n)]
    return board

def heuristic_cost(board):
    """Calculate the number of attacking queen pairs on the board."""
    n = len(board)
    attacking_pairs = 0
    for i in range(n):
        for j in range(i + 1, n):
            if board[i] == board[j] or abs(board[i] - board[j]) == j - i:
                attacking_pairs += 1
    return attacking_pairs

def hill_climb(n, max_iterations):
    """Solve the 8-Queens problem using Hill Climbing with a heuristic function."""
    current_board = random_board(n)
    current_cost = heuristic_cost(current_board)
    steps = 0  # Initialize the step counter

    for _ in range(max_iterations):
        neighbor_board = current_board[:]
        row_to_move = random.randint(0, n - 1)
        new_column = random.randint(0, n - 1)
        neighbor_board[row_to_move] = new_column
        neighbor_cost = heuristic_cost(neighbor_board)
        steps += 1  # Increment the step counter

        if neighbor_cost == 0:
            return neighbor_board, steps  # Solution found
        if neighbor_cost < current_cost:
            current_board = neighbor_board
            current_cost = neighbor_cost

    return None, steps  # No solution found within the given iterations

def print_board(board):
    """Print the chessboard with queens placed."""
    n = len(board)
    for row in range(n):
        line = ""
        for col in range(n):
            if board[col] == row:
                line += "Q "
            else:
                line += ". "
        print(line)

if __name__ == "__main__":
    n = 8  # Number of queens
    max_iterations = 1000  # Maximum iterations for the Hill Climbing algorithm

    solution, steps = hill_climb(n, max_iterations)

    if solution:
        print("Solution found in", steps, "steps:")
        print_board(solution)
    else:
        print("No solution found within the maximum iterations.")
