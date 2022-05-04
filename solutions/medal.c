
/*
   UCF 2021 (Fall) "Practice" Local Programming Contest
   Problem: medal
*/

#include <stdio.h>

#define TRUE  1
#define FALSE 0

int usa_medal[3], russia_medal[3];

/* ************************************************************ */

int main(void)
{
   int   j;
   int   win_by_count, win_by_color;
   int   check_win_by_count(), check_win_by_color();

   for ( j = 0;  j <= 2;  ++j )
      scanf("%d", &usa_medal[j]);
   
   for ( j = 0;  j <= 2;  ++j )
      scanf("%d", &russia_medal[j]);
 
   win_by_count = check_win_by_count();
   win_by_color = check_win_by_color();

   if ( win_by_count && win_by_color )
      printf("both\n");
   else if ( win_by_count )
      printf("count\n");
   else if ( win_by_color )
      printf("color\n");
   else
      printf("none\n");

   return(0);

}/* end of main */

/* ************************************************************ */

int check_win_by_count()
{
   if ( (usa_medal[0] + usa_medal[1] + usa_medal[2]) >
        (russia_medal[0] + russia_medal[1] + russia_medal[2]) )
      return(TRUE);

   return(FALSE);

}/* end of check_win_by_count */

/* ************************************************************ */

int check_win_by_color()
{
   int j;

   for ( j = 0;  j <= 2;  ++j )
      if ( usa_medal[j] > russia_medal[j] )
         return(TRUE);
      else if ( usa_medal[j] < russia_medal[j] )
         return(FALSE);

   return(FALSE);

}/* end of check_win_by_color */

/* ************************************************************ */
