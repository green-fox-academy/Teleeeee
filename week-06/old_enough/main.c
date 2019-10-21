#include <stdio.h>
#include <stdlib.h>

char* oldEnough(int age)
{
    if(age >= 18){
      return "Old enough!";
    }else{
        return  "Not old enough!";
    }
}

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int userAge;

    scanf("%d", &userAge);

    printf("%s", oldEnough(userAge));

    return 0;
}