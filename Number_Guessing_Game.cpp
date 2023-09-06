#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  //statement used to change the random number
  srand((unsigned int) time(NULL));
  
  
  // rand() will return a random int value between 0 and a large number
  // mod 100 will turn that number into a 0-99 range, and +1 shifts that range to 1-100!
  int number = (rand() % 100) + 1; 
  
  
  int guess = 0;
  int turns = 0;
  
  do
  {
    turns++;
    cout << "Enter your Guess : ";
    cin >> guess;
    
    
    if (guess > number)
      cout << "Guess lower!" << endl;
    else if (guess < number)
      cout << "Guess higher!" << endl;
    else
      cout << "You Guessed it right  after "<<turns<<" turns" << endl;
      
    
  } while (guess != number);
   
  return 0;
}