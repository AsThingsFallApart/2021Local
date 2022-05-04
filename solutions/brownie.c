

/*
   UCF 2021 (Fall) "Practice" Local Programming Contest
   Problem: brownie
*/

#include <stdio.h>

/* ************************************************************ */

int main(void)
{
   int   j;
   int   num_of_students_in_practice, num_of_brownies, 
         num_of_groups, num_of_students_in_group;

   scanf("%d %d", &num_of_students_in_practice, &num_of_brownies);

   scanf("%d", &num_of_groups);
   for ( j = 1;  j <= num_of_groups;  ++j )
   {
	   scanf("%d", &num_of_students_in_group);
	   
	   while ( num_of_brownies <= num_of_students_in_group )
		   num_of_brownies *= 2;

       num_of_brownies -= num_of_students_in_group;

       printf("%d %d\n", num_of_students_in_group, num_of_brownies);

   }/* end for ( j ) */

   return(0);

}/* end main */

/* ************************************************************ */

