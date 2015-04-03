#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class card
{
	public:
			card();
			card(const card&);
			~card();
			card& operator=(const card&);
			void setLocation(string);
			bool operator==(const card&) const;
			bool operator>(const card&) const;
			//friend bool operator<(const card&) const;
			friend ostream& operator<<(ostream&, card&);
            friend ifstream& operator>>(ifstream&, card&);
	
	private:
			string suit;
			string rank;
			string location;
			int value;
};

class player
{
	public:
			player();
			~player();
			void setHand(int, card);
			friend ostream& operator<<(ostream&, player&);
            friend ifstream& operator>>(ifstream&, player&);
			
	private:
			string first,last;
			card* hand;
			float bet;
};
