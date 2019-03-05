/*
Astrazione di un mazzo di carte, serve a costuire due mazzi da 54 carte
che successivamente verranno trasferite nelle colonne di GameManager
*/


#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
using namespace std;

class Deck   //mazzo da 104 carte
{
	public:
		Deck () //costruttore di default
		{
			for (unsigned i=0; i<4; i++)
					for (unsigned j=0; j<13; j++)
					{
						bool vero=true;
						Card tempcard(0, i+1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
			for (unsigned i=0; i<4; i++)
					for (unsigned j=0; j<13; j++)
					{
						bool vero=true;
						Card tempcard(0, i+1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
		}
		Deck (int mod)   //crea il mazzo da 104 carte con mod=1 -> 1 seme, mod=2 -> 2 semi; mod=3 -> 4 semi
		{
			if (mod==1)
			{
				for (unsigned i=0; i<4; i++)
					for (unsigned j=0; j<13; j++)
					{
						Card tempcard(j+1, 1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
				for (unsigned i=0; i<4; i++)
					for (unsigned j=0; j<13; j++)
					{
						Card tempcard(j+1, 1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
			}
			else if(mod==2)
			{
				for (unsigned i=0; i<2; i++)
					for (unsigned j=0; j<13; j++)
					{
						Card tempcard(j+1, i+1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
				for (unsigned i=0; i<2; i++)
					for (unsigned j=0; j<13; j++)
					{
						Card tempcard(j+1, i+1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
				for (unsigned i=0; i<2; i++)
					for (unsigned j=0; j<13; j++)
					{
						Card tempcard(j+1, i+1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
				for (unsigned i=0; i<2; i++)
					for (unsigned j=0; j<13; j++)
					{
						Card tempcard(j+1, i+1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
			}
			else if (mod==3)
			{
				for (unsigned i=0; i<4; i++)
					for (unsigned j=0; j<13; j++)
					{
						Card tempcard(j+1, i+1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
				for (unsigned i=0; i<4; i++)
					for (unsigned j=0; j<13; j++)
					{
						Card tempcard(j+1, i+1 , true, true, 0, 0);
						mazzo.push_back(tempcard);
					}
			}
		}
		unsigned sizeMazzo ()
		{
			return mazzo.size();
		}
		void eliminaCarta (unsigned cont) 
		{
			vector<Card>:: iterator it=mazzo.begin()+cont;
			mazzo.erase(it);
		}
		Card trovaCarta (unsigned pos)
		{
			return mazzo[pos];
		}
	private:
		vector<Card> mazzo;
};

#endif
