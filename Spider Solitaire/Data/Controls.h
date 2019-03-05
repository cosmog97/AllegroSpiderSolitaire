/*
La classe definisce alcune funzioni che ritornano
booleane in modo da affettuare i controlli sulle
posizioni del mouse al momento in cui vengono
invocate nel main. Altre funzioni vengono
spiegate direttamente in esse
*/

#include "Menu.h"
using namespace std;

bool onTableGame (int sx, float res_x, bool b_down)  //controlla se il mouse è in una posizione valida fra 10 colonne di carte
{
	if ((sx >= 7 * res_x && sx <= 1607 * res_x) && b_down)
	{
		return true;
	}
	return false;
}


bool controllaSucCarte (Card sup, Card inf)  //date due carte, controlla se sono dello stesso seme, una successiva all'altra ed entrambe scoperte
{
	if (inf.getSeme() == sup.getSeme() && inf.getValore() == sup.getValore() - 1 && inf.getCoperta() == false && sup.getCoperta() == false)
	{
		return true;
	}
	return false;
}
bool controllaSucCarte2 (Card sup, Card inf) // date due carte, controlla se sono dello stesso seme ed entrambe scoperte
{
	if (inf.getValore() == sup.getValore() - 1 && inf.getCoperta() == false && sup.getCoperta() == false)
	{
		return true;
	}
	return false;
}

unsigned getNumRandom (unsigned k)  //dato k, ritorna un numero compreso fra 0 e k-1
{
	unsigned v = rand() % k;
	return v;
}

int trovaColonna(int sx, float res_x)  //serve ad individuare la colonna su cui è posizionato il mouse
{
	int x1 = 7*res_x, x2 = 167*res_x;
	for(int i = 1; i < 11; i++)
	{
		if (sx < x2 && sx > x1)
			return i;
		x1 = x2;
		x2 += 160 *res_x;
	}
	return 0;
}

void creaColonne (Deck& deck, GameManager& spider)  //carica nei vector di GameManager le carte in modalità random, scoprendo l'ultima inserita sul tavolo
{
			for (unsigned lo = 0; lo < 4; lo++)
				for (unsigned go = 0; go < 6; go++)
					{
						unsigned conttemp = getNumRandom(deck.sizeMazzo());
						Card temp = deck.trovaCarta(conttemp);
						if (go == 5)
						{
							temp.setCoperta (false);
						}
						spider.push_backCartaCol (temp, lo + 1);
						deck.eliminaCarta(conttemp);
					}
			for (unsigned la = 4; la < 10; la++)
				for (unsigned ga = 0; ga < 5; ga++)
					{
						unsigned conttemp2=getNumRandom(deck.sizeMazzo());
						Card temp2 = deck.trovaCarta(conttemp2);
						if (ga == 4)
						{
								temp2.setCoperta (false);
						}
						spider.push_backCartaCol (temp2, la+1);
						deck.eliminaCarta(conttemp2);
						}
			for (unsigned le = 10; le < 15; le++)
				for (unsigned ge = 0; ge < 10; ge++)
					{
						unsigned conttemp3=getNumRandom(deck.sizeMazzo());
						Card temp3 = deck.trovaCarta(conttemp3);
						spider.push_backCartaCol(temp3, le+1);
						deck.eliminaCarta(conttemp3);
					}
}


bool controlloUnSemeM (int temp_x, int temp_y, float res_x, float res_y, Menu & menu, bool modmenu[])
{
	if (temp_x >=  menu.getX () * res_x        &&     //unseme
		temp_x <=  (menu.getX() + 600) * res_x  &&
		temp_y >= menu.getY1()  * res_y   &&
		temp_y <= (menu.getY1() + 90) * res_y &&
		modmenu[0] == false && modmenu[1] == false)
	{
		return true;
	}
	return false;
}

bool controlloDueSemiM (int temp_x, int temp_y, float res_x, float res_y, Menu & menu, bool modmenu[])
{
	if (temp_x >= menu.getX() * res_x       &&    //duesemi
		temp_x <= (menu.getX() + 600) * res_x &&
		temp_y >= menu.getY2()  * res_y   &&
		temp_y <= (menu.getY2() + 90)  * res_y && 
		modmenu[0] == false && modmenu[1] == false)
	{
		return true;
	}
	return false;
}

bool controlloQuattroSemiM (int temp_x, int temp_y, float res_x, float res_y, Menu & menu, bool modmenu[])
{
	if (temp_x >= menu.getX() * res_x  &&     //4 semi
		temp_x <= (menu.getX() + 600) * res_x   &&
		temp_y >= menu.getY3()  *res_y    &&
		temp_y <= (menu.getY3() + 90) *res_y && 
		modmenu[0] == false && modmenu[1] == false)
	{
		return true;
	}
	return false;
}

bool controlloCreditsM (int temp_x, int temp_y, float res_x, float res_y, Menu & menu, bool modmenu[])
{
	if (temp_x >= menu.getX() * res_x  &&
		temp_x <= (menu.getX() + 600) * res_x   &&
		temp_y >= menu.getY4()  *res_y    &&
		temp_y <= (menu.getY4() + 90) *res_y 
		&& modmenu[0] == false)
	{
		return true;
	}
	return false;
}

bool controlloExitM (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons)
{
	if(temp_x >= buttons.getXM1 () * res_x &&
	   temp_x <= (buttons.getXM1 () + 100) * res_x &&
       temp_y >= buttons.getYM () * res_y &&
	   temp_y <= (buttons.getYM () + 100)  * res_y)
	{
		return true;
	}
	return false;
}

bool controlloMusicM (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons)
{
	if( temp_x >= buttons.getXM2 () * res_x &&
		temp_x <= (buttons.getXM2 () + 100) * res_x &&
		temp_y >= buttons.getYM () * res_y &&
		temp_y <= (buttons.getYM () + 100)  * res_y )
	{
		return true;
	}
	return false;
}

bool controlloAudioM (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons)
{
	 if( temp_x >= buttons.getXM3 () * res_x &&
			temp_x <= (buttons.getXM3 () + 100) * res_x &&
			temp_y >= buttons.getYM () * res_y &&
			temp_y <= (buttons.getYM () + 100)  * res_y )
	{
		return true;
	}
	return false;
}

bool controlloRegoleM (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons)
{
	if (temp_x >= buttons.getXM4 () * res_x &&
	    temp_x <= (buttons.getXM4 () + 100) * res_x &&
	    temp_y >= buttons.getYM () * res_y &&
	    temp_y <= (buttons.getYM () + 100) * res_y)
	{
		return true;
	}
	return false;
}

bool controlloDistrMazzi (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons, int dimmaz, bool stampamazzo, bool spostamento)
{
	if ((temp_x >= (1771 - dimmaz) * res_x  && temp_x <= 1895 * res_x) && 
		(temp_y >= 875 * res_y && temp_y <= 1055 * res_y) && 
		stampamazzo && spostamento == false && buttons.getOnPause() == false)
	{
		return true;
	}
	return false;
}

bool controlloRitorna (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons)
{
	if(temp_x >= buttons.getX_sx () * res_x &&
	   temp_x <= (buttons.getX_sx () + 100) * res_x &&
	   temp_y >= 150 * res_y &&
	   temp_y <= 275 * res_y  && buttons.getOnPause() == false)
	{
		return true;
	}
	return false;
		
}

bool controlloPause (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons)
{
	if (temp_x >= buttons.getX_dx () * res_x &&
		temp_x <= (buttons.getX_dx () + 100)  * res_x &&
		temp_y >= 150 * res_y &&
		temp_y <= 275 * res_y)
	{
		return true;
	}
	return false;
}

bool controlloMusic (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons)
{
	if (temp_x >= buttons.getX_sx () * res_x &&
		temp_x <= (buttons.getX_sx () + 100) * res_x &&
		temp_y >= 275 * res_y &&
		temp_y <= 375 * res_y)
	{
		return true;
	}
	return false;
}

bool controlloAudio (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons)
{
	if(temp_x >= buttons.getX_dx () * res_x &&
	   temp_x <= (buttons.getX_dx () + 100) * res_x &&
	   temp_y >= 275 * res_y &&
	   temp_y <= 375 * res_y)
	{
		return true;
	}
	return false;
}


bool controlloBackToMenuV (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons, bool vittoria)
{
	if (temp_x >= buttons.getXV1 () * res_x  &&
		temp_x <= (buttons.getXV1 () + 362 ) * res_x &&
		temp_y >= buttons.getYV ()  * res_y &&
		temp_y <= (buttons.getYV () + 86 ) * res_y &&
		vittoria )
	{
		return true;
	}
	return false;
}
	
bool controlloRestartV (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons, bool vittoria)
{
	
	if (temp_x >= buttons.getXV2 () * res_x &&
		temp_x <= (buttons.getXV2 () + 362 ) * res_x &&
		temp_y >= buttons.getYV () * res_y &&
		temp_y <= (buttons.getYV () + 86 ) * res_y &&
		vittoria )
	{
		return true;
	}
	return false;
}

bool controlloExitDialog (Buttons & buttons, int temp_x, int temp_y, float res_x, float res_y) {
	if( temp_x >= buttons.getX_dx () *res_x &&
		temp_x <= (buttons.getX_dx () + 100)*res_x &&
		temp_y >= 25*res_y &&
		temp_y <= 125*res_y ) {
			return true;
		}
	return false;
}

bool controlloSI (int temp_x, int temp_y, float res_x, float res_y, bool exitdialog)
{
	if(temp_x >= 970 * res_x &&   //SI
		temp_x <= (970 + 266 ) * res_x &&
		temp_y >= 613 * res_y &&
		temp_y <= 693 * res_y  &&
		exitdialog) {
			return true;
		}
	return false;
}

bool controlloNO (int temp_x, int temp_y, float res_x, float res_y, bool exitdialog)
{
	if(temp_x >= 684 * res_x &&   //NO
	   temp_x <= (684 + 266) * res_x &&
	   temp_y >= 613 * res_y &&
	   temp_y <= 693 * res_y &&
	   exitdialog) {
		   return true;
	   }
	return false;
}

bool controlloRegole (int temp_x, int temp_y, float res_x, float res_y, Buttons & buttons) {
	if (temp_x >= buttons.getX_sx() * res_x &&
		temp_x <= (buttons.getX_sx() + 100) * res_x &&
		temp_y >= buttons.getY() * res_y &&
		temp_y <= (buttons.getY() + 100) * res_y) {
			return true;
		}
	return false;
}


















