Knight's Tour Solver Using Warnsdorff’s Heuristic
Overview
This program implements a solution to the classic Knight’s Tour problem on a standard 8x8 chessboard. The goal is to move a knight piece so that it visits every square exactly once.
The solution uses Warnsdorff’s heuristic to guide the knight’s moves by selecting the next move with the least onward moves available (lowest accessibility). This approach efficiently finds a valid knight’s tour path.

Features
Uses Warnsdorff’s rule for move selection.
Backtracking is applied if no valid moves are found from the current position.
Visualizes the solution by printing the chessboard with move numbers.
Handles board initialization and accessibility calculation dynamically.
Works on a standard 8x8 chessboard.

How It Works
The knight starts at position (0, 0) (top-left corner).
The program calculates the accessibility for each square (number of valid knight moves from that square).
At each step, the knight moves to the square with the minimum accessibility that is unvisited.
Accessibility values update after each move to reflect the reduced options for future moves.
If the knight covers all 64 squares, the tour is successful.
If no moves are possible and the tour is incomplete, the algorithm backtracks.

Code Structure
board[8][8] — Stores the move number for each square. Zero means unvisited.
accessibility[8][8] — Stores how many moves are possible from each square.
horizontal[] and vertical[] — Arrays defining knight’s 8 possible moves.
isSafe(r, c) — Checks if the position is within the board and unvisited.
updateAccessibility(r, c) — Updates accessibility values after each move.
nextMove(r, c) — Finds the next move with the lowest accessibility.
SolveKnightTour(r, c, moveCount) — Recursively attempts to find a full tour.
countMoves(r, c) — Counts possible knight moves from a position.

main() — Initializes the board and accessibility matrix, then starts the solver.


Notes
The program starts the tour from the top-left corner of the board (0,0).
Warnsdorff’s heuristic greatly improves the chances of finding a solution without excessive backtracking.
This program can be modified to start from different positions or different board sizes by changing constants.
