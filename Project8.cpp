#include<iostream>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>
#include<string>
#include"stringFunctions.h"
#include"Specification.h"
using namespace std;

void UnshuffledDeck(card* Deck); 
void shuffle(card* Deck, card* shuffledDeck);
void ShuffledDeck(card* shuffledDeck);
void printPlayer(player p);
void Deal(card* shuffledDeck, player* players, int num_Players, card* discardPile);
void Test(card a, card b);

int main()
{
	card* Deck = new card[52];
	ifstream fin;
	fin.open("Cards");
	
	for(int i=0; i < 52; i++)
	{
		fin >> Deck[i];
		Deck[i].setLocation("Unshuffled");
	}

	card* shuffledDeck = new card[52];
	card* discardPile = new card[52];
	card* Stock = new card[52];
	int x = 0;
	int num_Players;
	cout << "How many players? (2-8 players)\n";
	cin >> num_Players;
	ifstream p;
	p.open("Players");
	player* players = new player[num_Players];
	
	for(int i=0; i<num_Players;i++)
	{
		p >> players[i];
	}

	//readPlayers();
	srand(time('\0'));

	do
	{
		cout << endl;
		cout<<"Press 1 to shuffle the deck\n";
		cout<<"Press 2 to deal the first round of cards\n";
		cout<<"Press 3 to print out the unshuffled deck\n";
		cout<<"Press 4 to print the shuffled deck\n";
		cout<<"Press 5 to print the players info\n";
		cout<<"Press 6 to test unused functions\n";
		cout<<"Press 7 to quit\n";
		cout<<"\n";
		cin >> x;
		switch(x)
		{
			case 1:
				shuffle(Deck, shuffledDeck);
				break;
			case 2:	
				Deal(shuffledDeck, players, num_Players, discardPile);	
				break;
			case 3:
				UnshuffledDeck(Deck);
				break;
			case 4:
				ShuffledDeck(shuffledDeck);
				break;
			case 5:
				cout << "Which player would you like to print? (Enter a number): ";
				int num;
				cin >> num;
				printPlayer(players[num]);
				break;
			case 6:
				cout<<"Enter the card numbers you wish to compare from the unshuffled deck: " << endl;
				int a,b;
				cin>>a;
				cin>>b;
				Test(Deck[a],Deck[b]);
				break;
		}
	}
	while(x!=7);
	delete[]shuffledDeck;
	delete[]discardPile;
	delete[]Stock;
	return 0;
}

void UnshuffledDeck(card* Deck)
{
	for(int i=0; i<52;i++)
	{
		cout << Deck[i];
	}
}

void ShuffledDeck(card* shuffledDeck)
{
	for(int i=0; i<52;i++)
	{
		cout << shuffledDeck[i];
	}
}

void Deal(card* shuffledDeck, player* players, int num_Players, card* discardPile)
{
	int a = 0;
	for(int handPosition=0;handPosition<5;handPosition++)
	{
		for(int i=0;i<num_Players;i++)
		{
			players[i].setHand(handPosition,shuffledDeck[a]);
			a++;
		}
	}
}

void printPlayer(player p)
{
	cout << p;
}

void shuffle(card* Deck, card* shuffledDeck)
{
	for(int j=0;j<52;j++)
	{
		shuffledDeck[j] = Deck[j];
		shuffledDeck[j].setLocation("shuffled");
	}
	for (int i=0; i<52; i++) 
	{
		int r = rand() % 52;
		card temp = shuffledDeck[i]; shuffledDeck[i] = shuffledDeck[r]; shuffledDeck[r] = temp;
	}
}

void Test(card a, card b)
{
	cout<<"Greater than operator test: " << endl;
	if(a>b)
	{
		cout<<"the first card is greater then the second" << endl;
	}	
	else
	{
		cout<<"The first card is not greater then the second" <<endl;
	}
	/*
	cout<<"Less than operator test: " << endl;
	if(a<b)
	{
		cout<<"The first card is less then the second" << endl;
	}
	else
	{
		cout<<"The first card is not less then the second" << endl;
	}*/
}












