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

  int i = 0;

  int64_t countBalancedPermutations = 0;
  int64_t baseConsonant = 1;
  int64_t baseVowel = 1;
  int countVowels = 0;
  int countConsonants = 0;
  int countQuestionMarks = 0;
  int necessaryVowelsForBalance = 0;
  int necessaryConsonantsForBalance = 0;

  string givenString = "";
  cin >> givenString;

  // variable 'questionMarkExists' will be the index of the first question mark found
  size_t questionMarkExists = givenString.find("?");

  // two edge cases when givenString has no '?' chars:
  // if 'givenString' does not include any question mark characters
  if(questionMarkExists == string::npos) {
    // calculate ratio of consonants to vowels
    for(char x : givenString) {
      switch(x) {
      case 'a':
        countVowels++;
        break;
      case 'e':
        countVowels++;
        break;
      case 'i':
        countVowels++;
        break;
      case 'o':
        countVowels++;
        break;
      case 'u':
        countVowels++;
        break;
      case 'y':
        countVowels++;
        break;
      default:
        countConsonants++;
        break;
      }
    }

    cout << "countVowels: " << countVowels << "\n";
    cout << "countConsonants: " << countConsonants << "\n";

    // case: givenString has no question marks and is unbalanced
    if(countVowels != countConsonants) {
      cout << countBalancedPermutations;
    }
    // case: givenString has no questions marks and is BALANCED
    else {
      countBalancedPermutations = 1;
      cout << countBalancedPermutations;
    }
  }

  // handle when givenString has AT LEAST one question mark
  else {
    // two possible cases: (1) length of givenString is odd, (2) length is even
    // case(1): givenString is odd
    if(givenString.length() % 2 != 0) {

    }

    // case(2): givenString is even
    else {
      // calculate number of possible different vowel/consonant combinations
      for(char x : givenString) {
        switch(x) {
        case 'a':
          countVowels++;
          break;
        case 'e':
          countVowels++;
          break;
        case 'i':
          countVowels++;
          break;
        case 'o':
          countVowels++;
          break;
        case 'u':
          countVowels++;
          break;
        case 'y':
          countVowels++;
          break;
        case '?':
          countQuestionMarks++;
          break;
        default:
          countConsonants++;
          break;
        }
      }

      necessaryConsonantsForBalance = (givenString.length() / 2) - countConsonants;
      necessaryVowelsForBalance = (givenString.length() / 2) - countVowels;

      // power function as a for loop to avoid messing with int64_t data type mismatches
      for(i = 0; i < necessaryConsonantsForBalance; i++) {
        baseConsonant *= 20;
//        cout << "baseConsonant: " << baseConsonant << "\n";
      }

      for(i = 0; i < necessaryVowelsForBalance; i++) {
        baseVowel *= 6;
//        cout << "baseVowel: " << baseVowel << "\n";

      }

      countBalancedPermutations = baseVowel * baseConsonant;
    }


//    cout << "givenString.length(): " << givenString.length() << "\n";
//    cout << "questionMarkExists: " << questionMarkExists << "\n";
//    cout << "countVowels: " << countVowels << "\n";
//    cout << "countConsonants: " << countConsonants << "\n";
//    cout << "countQuestionMarks: " << countQuestionMarks << "\n";
//    cout << "neccessaryConsonantsForBalance: " << necessaryConsonantsForBalance << "\n";
//    cout << "necessaryVowelsForBalance: " << necessaryVowelsForBalance << "\n";
//    cout << "baseConsonant: " << baseConsonant << "\n";
//    cout << "baseVowel: " << baseVowel << "\n";
//    cout << "countBalancedPermutations: " << countBalancedPermutations << "\n";
  }

  cout << countBalancedPermutations << "\n";

  return 0;
}
