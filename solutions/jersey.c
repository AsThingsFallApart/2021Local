
/*
   UCF 2021 (Fall) "Practice" Local Programming Contest
   Problem: jersey
*/

#include <stdio.h>

#define TRUE  1
#define FALSE 0

#define PLAYER_COUNT 10

#define SPECIAL_NUMBER_M 18
#define SPECIAL_NUMBER_Z 17

/* ************************************************************ */

int main(void)
{
   int   player_number, j;
   int   found_m, found_z;
   
   found_m = FALSE;
   found_z = FALSE;
   
   for ( j = 1;  j <= PLAYER_COUNT;  ++j )
   {
	   scanf("%d", &player_number);
	   if ( player_number == SPECIAL_NUMBER_M )
		   found_m = TRUE;
	   else if ( player_number == SPECIAL_NUMBER_Z )
		   found_z = TRUE;
   }
   
   if ( found_m && found_z )
	   printf("both\n");
   else if ( found_m )
	   printf("%d\n", SPECIAL_NUMBER_M);
   else if ( found_z )
	   printf("%d\n", SPECIAL_NUMBER_Z);
   else
	   printf("none\n");

   return(0);

}/* end main */

/* ************************************************************ */

