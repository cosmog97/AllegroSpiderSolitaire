
//Astrazione della carta del mazzo da gioco,
//avente un valore da 1 a 10, uno dei quattro semi
//una booleana per simboleggiare se è coperta sul tavolo
//e un'altra per settarne la visualizzazione sul tavolo

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card
{
	public:
		Card()
			{
				valore = 1;
			 	seme=1;
			 	coperta = true;
				visibile = true;
			}
		Card (unsigned val, unsigned sem, bool coper, bool vis, int x, int y)
			{
				valore = val;
				seme=sem;
				coperta = coper; 
				visibile = vis;
			}
		Card (const Card & right)
			{ 
				valore = right.valore;
			 	seme=right.seme;
				coperta = right.coperta;
				visibile = right.visibile;
			}
			
		void setValore (unsigned val)
			{ valore=val;}
		void setSeme (unsigned sem)
			{ seme=sem;}
		void setCoperta (bool cop)
			{ coperta=cop;}
		void setVisibile (bool vis)
			{ visibile=vis;}

	
		unsigned getValore() 
		{return valore;}
		unsigned getSeme() 
		{return seme;}
		bool getCoperta() 
		{return coperta;}
		bool getVisibile()
		{return visibile;}	
	
	private:
		unsigned valore; //da 1 a 13
		unsigned seme;  // {picche=1, cuori=2 quadri=3 fiori=4}
		bool coperta;
		bool visibile;

};

#endif
