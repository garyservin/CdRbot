/* 
 * File:   mian.c
 * Author: gary
 *
 * Created on April 15, 2013, 9:59 PM
 */

#include "main.h"

void main ( void )
{
	int i;
	LATC0 = 0;
	TRISC0 = 0;

	for(;;){
		LATC0 = !LATC0;
		for (i=0;i<30000;i++){
		}
	}

}