/* balance.cpp
 * count the number of ways to replace all '?' with lowercase letters
 * such that the string results in a balanced string
 */

// a balanced string is defined as a string where there is a 1:1 ratio
// of consonants to vowels.

// char vowels[6] = {a, e, i, o, u, y};
// char consonants[20] = {b, c, d, f, g, h, j, k, l, m, n, p, q, r, s, t, v, w, x, z};

// firstAlgorithm:
//  1. given a string, generate the bounds for all possible even-length substrings
//    how: loop through (substringLength = givenString.length() / 2) times
//      why: there are givenString.length()/2 even numbers in givenString.length()
//  2. inside the loop that generates the bounds for all possible even-length substrings,
//  generate the substrings by starting at index 0, then using the bound-generating loop
//  to calculate the max index for that substring
//  e.g. substringUpperBound = substringLowerBound + substringLength - 1;
//  increment substringLowerBound to generate all even-length substrings of length 'substringLength'
//  after each substring is generated, check if it is balanced

// useful 'string' class functions
//  (1) string 'substr(position, count)'
//  (2) string 'find(other_string, position)'

#include <string>
#include <iostream>
using namespace std;

int main() {
  int64_t countBalancedCombos = 0;

  string givenString = "";
  cin >> givenString;

  size_t questionMarkExists = givenString.find("?");

  // two edge cases when givenString has no '?' chars:
  // if 'givenString' does not include any question mark characters
  if(questionMarkExists == string::npos) {
    // check if balanced:
    cout << "no question marks";
  }
  else {
    cout << "question marks found";
  }

  return 0;
}

bool calculateBalance(string inspected) {
  bool balanced = false;
  int countVowels = 0;
  int countConsonants = 0;

  return balanced;
}
