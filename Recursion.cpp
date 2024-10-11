//Erfan Sadri P1 Recursion
//Programming Excersice 2

#include <iostream>
using namespace std;

void printStars(int number, int stars);

int main() {
  int number;
  cout << "Enter the number of stars: ";
  cin >> number;
  printStars(number, 0);
  return 0;
}

void printStars(int number, int stars) {
  int i;
  
  for(i=0; i<stars; i++)
    cout<<"*";
    cout<<endl;
  
  
  if(stars==number)
    return;
  
  printStars(number,stars + 1);
 
  for(i=0; i<stars; i++) 
    cout<<"*";
    cout<<endl;
  }


//Programming Excersice 4

#include <iostream>
using namespace std;

int sumSquares (int number) {
  if (number == 0) {
    return 0;
  } else {
    return number * number + sumSquares(number - 1);
  }
}

int main () {
  int number;

  cout << "Enter a number (non-negative): ";
  cin >> number;

  if (number < 0) {
      cout << "Please enter that is a non-negative integer." << endl;
  } else {
      int result = sumSquares(number);
      cout << "The sum of squares from 0 to " << number << " is: " << result << endl;
  }

  return 0;
}
