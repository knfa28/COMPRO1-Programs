/*******************************************************************************
Program name: Odometer

Programmed by: Kurt Aquino
Section: S21A

Last Updated: 06/25/2013
*******************************************************************************/

#include<stdio.h>

/* displays stars */
void stars()
{
     printf("*******************************************************\n");
}

/* asks for user input */
void getInputs(float *fSpeed, float *fSeconds)
{
      printf("Please input the speed in km/h: ");
      scanf("%f", fSpeed);
      printf("Please input the time in seconds: ");
      scanf("%f", fSeconds);
}

/* converts given speed to meters per second */
float toMetersperSec(float fSpeed)
{
      float fSpeed2;
      fSpeed2 = fSpeed * 1000 / 3600;
      return fSpeed2;
}

/* calculates the distance travelled */
float computeDistance(float fSpeed2, float fSeconds)
{
      float fDistance;
      fDistance = fSpeed2 * fSeconds;
      return fDistance;
}

int main ()
{
    /* variable declaration */
    float fSpeed, fSeconds, fSpeed2, fDistance;
    
    /* diplays stars */
    stars();
    
    /* calls the function to get inputs */
    getInputs(&fSpeed, &fSeconds);
    
    /* calls functions as variables */
    fSpeed2 = toMetersperSec(fSpeed);
    fDistance = computeDistance(fSpeed2, fSeconds);
    
    /* displays the results */
    printf("\nComputing distance... Done!\n\n"
           "%.2f km/h is equivalent to: %.2f meters per second\n"
           "The racecar has travelled: %.2f meters!\n\n"
           "Thank You!\n",
           fSpeed, fSpeed2, fDistance);
   
   /* displays stars */
   stars();
          
   return 0;
}

