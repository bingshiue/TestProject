/*
 * TestProject.c
 *
 *  Created on: 2014/04/15
 *      Author: bingshiue
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define COUNT 10

int main(int argc,char** argv){
	int idx;

	for(idx=0; idx<COUNT; idx++)
		fprintf(stdout,"New Train Project : %d \n",idx);

	return 0;
}




