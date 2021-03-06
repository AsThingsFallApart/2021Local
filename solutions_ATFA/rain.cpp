#include <iostream>
#include <cmath>
#include <iomanip>  // setprecision, fixed
using namespace std;

// notes:
// given two things:
//  1. radius of a circle
//  2. length of a square
// contextually, the circle is below the square and they are coaxial
// rain falls through the square straight down into the circle
// the algorithm should calculate the amount of "skylight rain area" covered by the circle
// is this not just
// skylightRainArea = (squareLength * squareLength) - (M_PI * (circleRadius * circleRadius));
// ...?
// 1/11/22 edit:
// water falls in each unit squared of the square
// skylightRainArea is how much of the square is also the circle
// therefore, skylightRainArea is always a number from
//  0 (the circle is nonexistent) to
//  squareLength * squareLength (the circle covers all the square area)
// I feel like I understand the context better
// Does the algorithm require calculus...?
//  Probably not since these questions are designed to be solved by high schoolers

int main() {
  int squareLength = 0, circleRadius = 0;
  double pi = 3.14159265358979;
  double ninetyDegreesRadian = 1.570796327;
  double skylightRainArea = 0.0;
  double triangleHeight = 0.0;
  double areaTriangle = 0.0;
  double areaSector = 0.0;
  double areaQuadrant = 0.0;
  double theta = 0.0;
  double thetaSector = 0.0;

  cin >> squareLength >> circleRadius;

  double triangleBase = squareLength / 2.0;
  double squareSide = squareLength / 2.0;
  double squareDiagonal = sqrt((squareSide * squareSide) + (squareSide * squareSide));
  int triangleHypo = circleRadius;
  int areaSquare = squareLength * squareLength;
  double areaCircle = pi * (circleRadius * circleRadius);

  // case: circle completely enclosed by square
  // logic: if the circle is completely inside the square,
  // the amount of area covered is all inside the square.
  // No skylightRainArea needs to be pruned...
  if(squareLength / 2.0 >= circleRadius) {
    skylightRainArea = areaCircle;
  }

  // case: square completely enclosed by circle
  // in other words, circle radius longer or equal than longest line in square
  else if(circleRadius >= squareDiagonal) {
    skylightRainArea = areaSquare;
  }

  // case: circle not completely in square; square not completely in circle
  else {
    // pythagorean theorem to get triangleHeight (a.k.a. opposite leg)
    // opposite triangle leg needed for triangleArea and theta
    triangleHeight = sqrt((triangleHypo * triangleHypo) - (triangleBase * triangleBase));
//    cout << "triangleHeight: " << triangleHeight << "\n";

    areaTriangle = 0.5 * (triangleBase * triangleHeight);
//    cout << "areaTriangle: " << areaTriangle << "\n";

    theta = atan2(triangleHeight, triangleBase);
//    cout << "theta: " << theta << "\n";

    thetaSector = ninetyDegreesRadian - (theta * 2);
//    cout << "thetaSector: " << thetaSector << "\n";

    areaSector = (thetaSector / 2) * (circleRadius * circleRadius);
//    cout << "areaSector: " << areaSector << "\n";

    areaQuadrant = areaTriangle * 2 + areaSector;
//    cout << "areaQuadrant: " << areaQuadrant << "\n";

    skylightRainArea = areaQuadrant * 4;
//    cout << "skylightRainArea: " << skylightRainArea << "\n";
  }

  // round to two (100 represents the hundredth place, 1000 for three decimal places, etc) decimal places
  skylightRainArea = round(skylightRainArea * 100) / 100;

  cout << fixed << setprecision(2) << skylightRainArea << "\n";

  return 0;
}
