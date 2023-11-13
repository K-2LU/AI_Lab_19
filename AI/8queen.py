import random

def random_board(n):
    # generates a rndm borad with qns plcd rndmly in each clm
    board = [random.randint(0, n-1) for i in range(n)]
    return board

def hueristic_cost(board):
    # clculte nmbr of attcking qn pairs on brd
    n = len(board)
    attacking_pairs = 0
    
    for i in range(n):  
        for j in range(i+1, n):
            if board[i] == board[j] or abs(board[i] == board[j]) == j - i:
                attacking_pairs+=1
    
    return attacking_pairs

def hill_climb(m, max_iterations):
    current_board = random_board(n)
    print("--------------------")
    print_board(current_board)
    current_cost = hueristic_cost(current_board)
    steps = 0 
    
    for _ in range(max_iterations):
        neighbor_board = current_board[:]
        row_to_move = random.randint(0, n-1)
        new_column = random.randint(0, n-1)
        neighbor_board[row_to_move] = new_column
        neighbor_cost = hueristic_cost(neighbor_board)
        steps += 1
        print("Step ", steps, ":")
        print("")
        print_board(current_board)
        print("")
        
        if neighbor_cost == 0:
            return neighbor_board, steps # solution found
        if neighbor_cost < current_cost:
            current_board = neighbor_board
            current_cost = neighbor_cost
    
    return None, steps

def print_board(board):
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
    n = 8
    max_iterations = 100
    
    solution, steps = hill_climb(n, max_iterations)
    
    if solution:
        print_board(solution)
    else:
        print("No solution found within the max iterations")