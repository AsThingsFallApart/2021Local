// brownie.cpp

// every program can be abstracted into three parts:
// 1. input
// 2. black box
// 3. output

// input is put into some black box and then output comes out
// writing a program involves visualizing the code for each part
// 1. how is the input formatted?
// 1a. following the input format, what code structures can be used to organize the input?
//    e. g. getline native function, cin object, extraction operator, string data type, arrays, vectors
// 2. what logic is requested?
// 2a. what code structures can be used to represent the requested logic?
//    e.g. if statements, loops, arithmetic operators, int data types, iterator variables
// 3. how is the output formatted?
// 3a. following the output format, what code structures can be used to realize that format?
//    e.g. cout object, insertion operator, endl object

/* plan to parse the input: */
// input lines:
// 1. "[# students] [# brownies]"
// 2. "[m number of groups]"
// 2a. int i = 0;
// 2 + m. [number of students in group m - (m - i); i++; ...group m - (m - (m-1))]

/* plan to implement dr. O dividing brownies logic: */
// if([# of brownies remaining] <= [# of students in group]) {
//    // [looping code to divide brownies (multiply by 2) until [# brownies] > [# students in group]]
// }

/* plan to format output: */
// print m number of lines
// each line has two integers:
// "[# of students in a group] [# of brownies left AFTER each student grabs one brownie]"
// grabbing occurs after brownie multiplication, thus:
// numBrowniesRemaining = numBrowniesAfterMultiplication - numStudentsInGroup;

#include <iostream>
using namespace std;

int main() {
  // what happens in int main...? Everything above, I guess.
  // do I not want to do this...?

  int numStudents;
  int numBrownies;
  string inputLine;

  getline(cin, inputLine);
  cout << endl << "inputLine: " << inputLine << endl;

  int i = 0;
  string temp = "";

  for(char c : inputLine) {
    i++;

    if(c == ' ') {
      numStudents = stoi(temp);
      temp = "";
    }
    else if(i == inputLine.length()) {
      temp += c;
      numBrownies = stoi(temp);
    }
    else {
      temp += c;
    }
  }

  cout << endl << "numStudents: " << numStudents << endl;
  cout << "numBrownies: " << numBrownies << endl << endl;

  int numGroups;

  getline(cin, inputLine);
  cout << "inputLine: " << inputLine << endl;
  numGroups = stoi(inputLine);

  cout << "numGroups: " << numGroups << endl << endl;

  // put number of people in each group in a container
  int groups[numGroups];

  for(i = 0; i < numGroups; i++) {
    if(i != (numGroups - 1)) {
      getline(cin, inputLine);
      cout << "inputLine: " << inputLine << endl;
      groups[i] = stoi(inputLine);
      cout << "groups[" << i << "]: " << groups[i] << endl;
    }
    else {
      getline(cin, inputLine);
      cout << "inputLine: " << inputLine << endl;
      groups[i] = stoi(inputLine);
      cout << "groups[" << i << "]: " << groups[i] << endl;
      cin.ignore();
      cout << "inputLine: " << inputLine << endl;
    }
  }

  // this isn't efficient but whatever...

  return 0;
}
































