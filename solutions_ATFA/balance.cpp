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

int determineLetterType(char c);

int main() {

  int i = 0;

  int64_t countBalancedPermutations = 0;
  int64_t possibleConsonants = 1;
  int64_t possibleVowels = 1;
  int substitutedVowels = 0;
  int substitutedConsonants = 0;
  bool fundamentallyBalanceable = true;
  int letterTypePredecessor = 0;
  int letterTypeCurrent = 0;
  int rippleStartIndex = 0;

  string givenString = "";
  cin >> givenString;
  string currentString = "";
  string temp = "";

  // variable 'questionMarkExists' will be the index of the first question mark found
  size_t questionMarkExists = givenString.find("?");

  // two edge cases when givenString has no '?' chars: (1) unbalanced or (2) balanced
  // if 'givenString' does not include any question mark characters
  if(questionMarkExists == string::npos) {

    for(i = 0; i < givenString.length(); i++) {
      if(i == 0) {
        letterTypeCurrent = determineLetterType(givenString[i]);
//        cout << "i: " << i << "\n\tletterTypeCurrent: " << letterTypeCurrent << "\n";
      }
      else {
        letterTypePredecessor = determineLetterType(givenString[i - 1]);
        letterTypeCurrent = determineLetterType(givenString[i]);

//        cout << "i: " << i << "\n\tletterTypeCurrent: " << letterTypeCurrent << "\n";
//        cout << "\tletterTypePredecessor: " << letterTypePredecessor << "\n";
      }

      if(letterTypeCurrent == letterTypePredecessor) {
//        cout << "\n[ FUNDAMENTALLY UNBALANCEABLE ]\n" << "'" << givenString[i] << "'" << " comes after " << "'" << givenString[i - 1] << "'\n";
        fundamentallyBalanceable = false;
        break;
      }
    }


    // case: givenString has no question marks and is unbalanced
    if(fundamentallyBalanceable == false) {
      cout << countBalancedPermutations << "\n";
    }
    // case: givenString has no questions marks and is BALANCED
    else {
      countBalancedPermutations = 1;
      cout << countBalancedPermutations << "\n";
    }
  }

  // handle when givenString has AT LEAST one question mark
  else {

    /* check if givenString is FUNDAMENTALLY BALANCEABLE by
    // constructing a possible permutation at substring length 2.
    // Fill in question marks with vowels or consonants
    // all the while checking if two vowels or two consonants are adjacent
    //  "for all substrings to be balanced at a fundamental level,
    //  consonants and vowels must alternate."
    */

    // test if 'givenString' is balanceable with "RIPPLE-OUT SUBSTITUTION"
    // e. g.
    //    <-----------+----->
    //  " ? ? ? ? ? ? p ? y ? "
    // ripple-out substitution: start at first known letter, then ripple out left until index 0,
    // then ripple out right from index of first known letter to index (givenString.length() - 1)

    // find index of first known letter in 'givenString'
    for(i = 0; i < givenString.length(); i++) {
      if(determineLetterType(givenString[i]) == 1 || determineLetterType(givenString[i]) == 2) {
        rippleStartIndex = i;
//        currentString.push_back(givenString[i]);
        break;
      }
    }

//    cout << "\nrippleStartIndex: " << rippleStartIndex << "\n";


//    cout << "\nRIPPLE LEFT:\n";
    // ripple left towards index 0
    for(i = rippleStartIndex; i >= 0; i--) {
//      cout << "i: " << i << "\n";
      // skip comparing the rippleStartIndex element since its a known constant
      if(i == rippleStartIndex) {
        continue;
      }
//
//      cout << "\tgivenString[i]: " << givenString[i] << "\n";
//      cout << "\tgivenString[i + 1]: " << givenString[i + 1] << "\n";

      // get letter types
      letterTypeCurrent = determineLetterType(givenString[i]);
      letterTypePredecessor = determineLetterType(givenString[i + 1]);
//
//      cout << "\tletterTypeCurrent: " << letterTypeCurrent << "\n";
//      cout << "\tletterTypePredecessor: " << letterTypePredecessor << "\n";

      // substitute if letter type is 3
      if(letterTypeCurrent == 3) {
        // if letter type at index (i + 1) is a vowel
        if(letterTypePredecessor == 2) {
          // the current question mark must become a consonant
          substitutedConsonants++;
          givenString[i] = 'b';

          // for debugging/visualization:
          temp = "b";
        }
        // if letter type at index (i + 1) is a consonant
        else if(letterTypePredecessor == 1) {
          // the current question mark must become a vowel
          substitutedVowels++;
          givenString[i] = 'a';

          temp = "a";
        }
      }
//      else {
//        temp.push_back(givenString[i]);
//      }

      // always add to debugging string
//      temp.append(currentString);
//      currentString = temp;
//      temp = "";
//      cout << "\tcurrentString:" << currentString << "\n";

      if(letterTypeCurrent == letterTypePredecessor) {
//        cout << "\n[ FUNDAMENTALLY UNBALANCEABLE ]\n" << "'" << givenString[i] << "'" << " adjacent to " << "'" << givenString[i + 1] << "'\n";
        fundamentallyBalanceable = false;
        break;
      }
    }
//
//    cout << "\nRIPPLE RIGHT:\n";
    // ripple right towards index (givenString.length() - 1)
    for(i = rippleStartIndex; i < givenString.length(); i++) {
//      cout << "i: " << i << "\n";
      if(i == rippleStartIndex) {
        continue;
      }



      // get letter types
      letterTypeCurrent = determineLetterType(givenString[i]);
      letterTypePredecessor = determineLetterType(givenString[i - 1]);
//
//      cout << "\tletterTypeCurrent: " << letterTypeCurrent << "\n";
//      cout << "\tletterTypePredecessor: " << letterTypePredecessor << "\n";

      // substitute if letter type is 3
      if(letterTypeCurrent == 3) {
        // if letter type at index (i - 1) is a vowel
        if(letterTypePredecessor == 2) {
          // the current question mark must become a consonant
          substitutedConsonants++;
          givenString[i] = 'b';

          // for debugging/visualization:
          temp = "b";
        }
        // if letter type at index (i - 1) is a consonant
        else if(letterTypePredecessor == 1) {
          // the current question mark must become a vowel
          substitutedVowels++;
          givenString[i] = 'a';

          temp = "a";
        }
      }
//      else {
//        temp.push_back(givenString[i]);
//      }

      // always add to debugging string
      currentString.append(temp);
      temp = "";
//      cout << "\tcurrentString: " << currentString << "\n";

      if(letterTypeCurrent == letterTypePredecessor) {
//        cout << "\n[ FUNDAMENTALLY UNBALANCEABLE ]\n" << "'" << givenString[i] << "'" << " adjacent to " << "'" << givenString[i - 1] << "'\n";
        fundamentallyBalanceable = false;
        break;
      }
    }

    /* if all question marks have successfully been substituted,
     * givenString is balanceable. Calculate total combinations
     * by raising the 6 different options of vowels to the number of vowels,
     * raising the 20 different options of consonants to the number of consonants,
     * and multiply together.
     */

    // power function as a for loop to avoid messing with int64_t data type mismatches
    for(i = 0; i < substitutedConsonants; i++) {
      possibleConsonants *= 20;
  //        cout << "baseConsonant: " << baseConsonant << "\n";
    }

    for(i = 0; i < substitutedVowels; i++) {
      possibleVowels *= 6;
  //        cout << "baseVowel: " << baseVowel << "\n";

    }

    countBalancedPermutations = possibleConsonants * possibleVowels;

//
//    cout << "\ngivenString.length(): " << givenString.length() << "\n";
//    cout << "questionMarkExists: " << questionMarkExists << "\n";
//    cout << "substitutedVowels: " << substitutedVowels << "\n";
//    cout << "subsitutedConsonants: " << substitutedConsonants << "\n";
//    cout << "possibleConsonants: " << possibleConsonants << "\n";
//    cout << "possibleVowels: " << possibleVowels << "\n";
//    cout << "countBalancedPermutations: " << countBalancedPermutations << "\n";

    if(fundamentallyBalanceable == false) {
      cout << 0 << "\n";
    }
    else {
      cout << countBalancedPermutations << "\n";
    }

  }

  return 0;
}


/* input: some char, c
 * output: 1 for consonant, 2 for vowel, 3 for question mark
 */
int determineLetterType(char c) {
  int charType = -1;

  switch(c) {
  case 'a':
    charType = 2;
    break;
  case 'e':
    charType = 2;
    break;
  case 'i':
    charType = 2;
    break;
  case 'o':
    charType = 2;
    break;
  case 'u':
    charType = 2;
    break;
  case 'y':
    charType = 2;
    break;
  case '?':
    charType = 3;
    break;
  default:
    charType = 1;
    break;
  }

  return charType;
}
