#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



struct virus
{
char signature[25] ;
char status[20] ;
int size ;
} v[2] = {
"Yankee Doodle", "Deadly", 1813,
"Dark Avenger", "Killer", 1795
} ;
main( )
{
int i ;
for ( i = 0 ; i <=1 ; i++ )
printf ( "\n%s %s", signature, status ) ;

}
