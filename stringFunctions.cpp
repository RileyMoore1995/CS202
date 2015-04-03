#include<iostream>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include"stringFunctions.h"

using namespace std;

void stringCopy(char *destination, char *source) //a simple string copy function
{
	char *destinationHome = destination;
	char *sourceHome = source;
	while(*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	destination = destinationHome;
	source = sourceHome;
}

void stringConcat(char *destination, char *source)
{
	while(*destination != '\0')
	{
		destination++;
	}
	while(*source != '\0')
	{
		(*destination) = (*source);
		source++;
		destination++;
	}
		*destination = '\0';
}

int stringCompare(char *stringOne, char *stringTwo)
{
	int x = 1;
	while((*stringOne) != '\0')
	{
		if (*stringOne != *stringTwo)
		{
		x = 0;
		}
	stringOne++;
	stringTwo++;
	}
	return x;
}

int stringLength(char *string)
{
	int i=0;
	while((*string) != '\0')
	{
		string++;
		i++;
	}
	return i;
}







