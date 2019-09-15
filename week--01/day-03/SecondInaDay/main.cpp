#include <iostream>


int main() {
   int CurrentHours = 14;
   int CurrentMinutes = 34;
   int CurrentSecond = 42;

   int RemainingSeconds = ((24 - CurrentHours) * 60 * 60) + ((60 - CurrentMinutes) * 60) + (60 - CurrentSecond);
   std::cout << "There are " <<  RemainingSeconds << " seconds left! " << std::endl;

   return 0;

}