#include <iostream>
#include <cstdlib>
int main()
{
    double num;
    std::cout << "please a number:";
    std::cin >> num;
    //first print the first row
    for (int column = 0; column < num; ++column)
    {
        std::cout << "%";
    }

    std::cout << "\n";

    // Now we're going to print the sides.
    for (int row = 0; row < num/2; ++row)
    {
        // print the left "wall"
        std::cout << "%";

        for (int column = 0; column < num - 2; ++column)
        {
            std::cout << " ";
        }
        // print the right "wall" and a carraige return
        std::cout << "%\n";
        // continue the for loop to print the next row
    }

    // print bottom wall
    for (int column = 0; column < num; ++column)
    {
        std::cout << "%";
    }
    std::cout << "\n";

    return 0;

}
