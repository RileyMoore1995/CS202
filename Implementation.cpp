#include<iostream>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include"Specification.h"

using namespace std;

card::card()
{
	suit = "suit";
	rank = "rank";
	location = "location";
	value = 0;
}

card::card(const card &c)
{
	suit = c.suit;
	rank = c.rank;
	location = c.location;
	value = c.value;
}

bool card::operator ==(const card &c) const
{
	if(c.suit == suit && c.rank == rank)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool card::operator >(const card &c) const
{
	if(c.value > value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*friend bool card::operator <(const card &c) const
{
	if(c.value < value)
	{
		return true;
	}
	else
	{
		return false;
	}
}*/

card& card::operator =(const card &c)
{
	if (this != &c)
	{
		suit = c.suit;
		rank = c.rank;
		//location = c.location;
		value = c.value;
	}
	return *this;
}

card::~card()
{
	suit = "";
	rank = "";
	location = "";
	value = 0;	
}

ostream &operator<<(ostream &output, card &c)                                    
{ 
	output << c.suit << " " << c.rank << " " << c.location <<  endl;
    return output;            
}

ifstream &operator>>( ifstream  &fin, card &c )
{ 
   	fin >> c.suit >> c.rank;
	if(c.rank == "ace")
	{
		c.value=14;
	}
	if(c.rank == "two")
	{
		c.value=2;
	}
	if(c.rank == "three")
	{
		c.value=3;
	}
	if(c.rank == "four")
	{
		c.value=4;
	}
	if(c.rank == "five")
	{
		c.value=5;
	}
	if(c.rank == "six")
	{
		c.value=6;
	}
	if(c.rank == "seven")
	{
		c.value=7;
	}
	if(c.rank == "eight")
	{
		c.value=8;
	}
	if(c.rank == "nine")
	{
		c.value=9;
	}
	if(c.rank == "ten")
	{
		c.value=10;
	}
	if(c.rank == "jack")
	{
		c.value=11;
	}
	if(c.rank == "queen")
	{
		c.value=12;
	}
	if(c.rank == "king")
	{
		c.value=13;
	}
    return fin;            
}

void card::setLocation(string card)
{
	location = card;
}

void player::setHand(int handPosition, card shuffledDeck)
{
	hand[handPosition]=shuffledDeck;
}

player::player()
{
	first = "first";
	last = "last"; 
	hand = NULL;
	bet = 0.0;
}

player::~player()
{
	delete[]hand;
	first = "";
	last = "";
	hand = NULL;
	bet = 0.0;	
}


ostream &operator<<(ostream &output, player &p)                                    
{ 
	output << p.first << " " << p.last<< " " << p.hand;
    return output;            
}

ifstream &operator>>( ifstream  &fin, player &p )
{ 
    fin >> p.first >> p.last;
    return fin;            
}


