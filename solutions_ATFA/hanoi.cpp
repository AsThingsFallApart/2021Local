/* hanoi.cpp
 * given the number of disks, d, and the dimensions of the grid, n,
 * calculate the minimum number of moves necessary to transfer all disks
 * from the top-left peg to the bottom-right peg.
 */

// game rules:
//  1. for a peg (r, c) at row r and column c, you may only move the TOP-MOST DISK
//     from (r,c) to peg (r + 1, c) (DOWN) or peg (r, c + 1) (RIGHT),
//     in a single move and only if such a pair of pegs exists.
//  2. only pegs (1, 1) and/or (n, n) may have more than one disk at any time.
//     That is to say, all other pegs except the start and end peg can only have ONE DISK AT A TIME.
//  3. Larger disks can not be placed on smaller disks

// hint: RECURSION
// if it's not possible to move the disks from (1,1) to (n,n), print "impossible"

#include <iostream>
using namespace std;

int main() {
  // variable 'd' represents number of disks
  int d = 0;
  // variable 'n' represents number of rows and number of columns
  int n = 0;
  cin >> d >> n;
//  cout << "d: " << d << ", n: " << n << "\n";

  int i = 0;
  int j = 0;

  int minimumNecessaryMoves = 0;

  // generate a nxn grid visualization 4fun
//  cout << "A " << n << "x" << n << " Hanoi grid (row, column):\n\n";
//  for(i = 1; i <= n; i++) {
//    for(j = 1; j <= n; j++) {
//      cout << "(" << i << "," << j << ")\t";
//    }
//    cout << "\n\n";
//  }

  // for a hanoi grid to be solvable, a PATH consisting of free pegs from peg (1, 1) to peg (n, n)
  // needs to exist.
  // A path is calculated with the last disk in mind; meaning, all other pegs are occupied
  // by disks on top of the last disk by the time a path is calculated.
  // A path is calculated by ((n * 2) - 2).
  // Pragmatically, a path is equal to the length of a row times the length of a column
  // subtracted by 2 to account for starting at (1, 1) instead of (0, 0)
  int freePegs = (n * n) - d;
  int freePegsNecessaryForPath = ((n * 2) - 2);
  bool pathPossible = false;

  if(freePegs < freePegsNecessaryForPath) {
    pathPossible = false;
  }
  else {
    pathPossible = true;
  }

  // case: hanoi grid is impossible to solve
  if(pathPossible == false){
    cout << "impossible" << "\n";
  }

  // "down-right-stack algorithm"
  // it takes ((n * 2) - 2) moves to move to a disk from peg (1, 1) to peg (n, n)
  // (n * 2) represents the length of one column times the length of one row
  // (- 2) represents starting at peg (1, 1); 1 row and 1 column already included in moves
  else {
    minimumNecessaryMoves = ((n * 2) - 2) * d;

    cout << minimumNecessaryMoves << "\n";
  }

  return 0;
}
