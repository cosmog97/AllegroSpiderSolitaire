/*
Contiene le funzioni di disegno,
oltre alla gestione del gioco
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>   
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "GameManager.h"
#include "Controls.h"
#include "Sounds.h"

using namespace std;


int inizializzaAllegro ()
{
	if (!al_init())
	{
 		al_show_native_message_box(NULL, "Spider Solitaire", "Attenzione", "ALLEGRO5 non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!al_init_image_addon())
	{
    	al_show_native_message_box(NULL, "Spider Solitaire", "Errore", "al_init_image_addon non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_WARN);
   		return -1;
   	}
	if (!al_init_primitives_addon())
	{
		al_show_native_message_box(NULL, "Spider Solitaire", "Errore", "al_init_primitives_addon non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}
	if (!al_init_font_addon())
	{
		al_show_native_message_box(NULL, "Spider Solitaire", "Errore", "al_init_font_addon non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}
	if (!al_init_ttf_addon())
	{
		al_show_native_message_box(NULL, "Spider Solitaire", "Errore", "al_init_ttf_addon non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}
	if (!al_install_mouse())
	{
		al_show_native_message_box(NULL, "Spider Solitaire", "Errore", "al_install_mouse non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}
	if (!al_install_keyboard())
	{
		al_show_native_message_box(NULL, "Spider Solitaire", "Errore", "al_install_keyboard non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}
	if (!al_install_audio())
	{
		al_show_native_message_box(NULL, "Spider Solitaire", "Errore", "al_install_audio non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}
	if (!al_init_acodec_addon())
	{
		al_show_native_message_box(NULL, "Spider Solitaire", "Errore", "al_init_acodec_addon non è stato inizializzato correttamente.", "Esci", ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}
}

/* int distruggiAllegro () 
{
	al_destroy_display(display);
	return 0;
}*/
string toString (int d)
{
	string s;
	stringstream ss;
	ss << d;  //metto il numero nello stream
	ss >> s; // metto lo stream nello string
	return s;
}

void drawMenuButtons (Buttons & buttons, Sounds & sounds, bool buttons_on[], bool menu_on[])
{
	    	buttons.drawExitButtonM (buttons_on[0]);
			buttons.drawRegoleButtonM (menu_on[4]);
			
			if (sounds.getAudio ())
			{
				buttons.drawAudioButtonM (buttons_on[1]);
			}
					
			else
			{
				buttons.drawNoAudioButtonM (buttons_on[1]);
			}
					
			if (sounds.getMusic ())
			{
				buttons.drawMusicButtonM (buttons_on[2]);
			}
					
			else
			{
				buttons.drawNoMusicButtonM (buttons_on[2]);
			}	
					
			for (int i = 0 ; i < 5; i++)
			{
				buttons_on[i] = false;
			}
}


void drawGameButtons (Buttons & buttons, Sounds & sounds, bool buttons_on[], ALLEGRO_BITMAP* onpause, bool regoleb)
{
					if (buttons.getOnPause ())
					{
						al_draw_bitmap(onpause, 0,0,0);
					}

					buttons.drawIndietroButton (buttons_on[4]);
					buttons.drawExitButton (buttons_on[0]);
					
					buttons.drawRegoleButton (regoleb);

					if (sounds.getAudio ())
					{
						buttons.drawAudioButton (buttons_on[1]);
					}
					else
					{
						buttons.drawNoAudioButton (buttons_on[1]);
					}
					
					if (sounds.getMusic ())
					{
						buttons.drawMusicButton (buttons_on[2]);
					}
					else
					{
						buttons.drawNoMusicButton (buttons_on[2]);
					}	
					
					if (buttons.getOnPause ())
					{
						buttons.drawPlayButton (buttons_on[3]);
					}
					else
					{
						buttons.drawPauseButton (buttons_on[3]);
					}
}

void azzeraButtons (bool buttons_on[])
{
	for (int i = 0 ; i < 5; i++)
	{
	  buttons_on[i] = false;
	}

}

void drawTimer (ALLEGRO_FONT* font_timer, int timer)
{
	
	int secv = timer % 60;
	int minv = (timer/60) % 60;
	
	
	string sec = toString (secv);
	string min = toString (minv);
	string zero = "0";
	
	if (secv >= 0 && secv <= 9)
	{
		sec = zero + sec;
	}
	
	if (minv >= 0 && minv <= 9)
	{
		min = zero + min;
	}
	
	string t = ":";
	string s = min+t+sec;
	const char* time= s.c_str();
	al_draw_text(font_timer,  al_map_rgb(254,254,254), 1702, 410, 0, "TEMPO");
	al_draw_text(font_timer,  al_map_rgb(254,254,254), 1712, 460, 0, time);
	
	
}

void drawFinalTime (ALLEGRO_FONT* font_timer, int timer)
{
	
	int secv = timer % 60;
	int minv = (timer/60) % 60;
	
	
	string sec = toString (secv);
	string min = toString (minv);
	string zero = "0";
	
	if (secv >= 0 && secv <= 9)
	{
		sec = zero + sec;
	}
	
	if (minv >= 0 && minv <= 9)
	{
		min = zero + min;
	}
	
	string t = " minuti e ";
	string n = " secondi";
	string s = min+t+sec+n;
	const char* time= s.c_str();
	
	al_draw_text(font_timer,  al_map_rgb(0,0,0), 710, 470, 0, time);
	
	
}

void drawVittoria (Buttons & buttons, bool win_on[], bool vittoria)
{
	buttons.setOnPause (true);
	buttons.drawSchermataVittoria(vittoria);
	buttons.drawTornaAlMenu (win_on[0]);
	buttons.drawRicominciaPartita (win_on[1]);
	for (unsigned i = 0; i < 2; i++)
	{
		if (win_on[i])
		{
			win_on [i] = false;
		}
	}
}

void stampaMazzi (ALLEGRO_BITMAP* cover, bool stampamazzi, int nummazzi, Buttons & buttons, Sounds & sounds, bool buttons_on[], ALLEGRO_BITMAP* onpause, bool regoleb, ALLEGRO_FONT* font_timer, int timer)
{
	if (stampamazzi)
	{
		int posizione_x = (1920-25-124);
		int posizione_y = 875;
		int dis = 30;
		for (int i = 0; i < nummazzi; i++)
		{
			drawTimer(font_timer, timer);
			drawGameButtons(buttons, sounds, buttons_on, onpause, regoleb);
			al_draw_bitmap(cover, posizione_x, posizione_y, 0);
			posizione_x -= dis;
		}
	}
}

void disegnaColonne (ALLEGRO_BITMAP* im [][13], ALLEGRO_BITMAP* cover, GameManager gmanager)  //disegna le carte sulle 10 colonne
{
	int posizionecolonna = 25;
	int poscol = 160;
	int poscard = 36;
	int sovrapposizionecarta = 25;
	for (unsigned j = 1; j < 11; j++)
	{
		for (unsigned i = 0; i < gmanager.getSizeCol(j); i++)
			{
				Card temp(gmanager.ritornaCarta(j,i));
				int val = temp.getValore() -1;
				int sem = temp.getSeme() -1;
				bool cov = temp.getCoperta();
				bool vis = temp.getVisibile();
				if (cov && vis)
				{
						al_draw_bitmap(cover, posizionecolonna, sovrapposizionecarta, 0);
				} 
				else if (cov == false && vis)
				{
						al_draw_bitmap(im[sem][val], posizionecolonna, sovrapposizionecarta, 0);
				}
				sovrapposizionecarta += poscard;
				
			}
		sovrapposizionecarta = 25;
		posizionecolonna += poscol;
	}
}

vector<Card> controllaPosizioneMazzoSel (int colonna, GameManager &gmanager, int sy, float res_y)
{
	Card temp;
	vector<Card> cardtemp;
	vector<Card> cardtemp0;  //size = 0
	if (gmanager.getSizeCol(colonna) == 0)   //se colonna è vuota
		return cardtemp0;
	if (sy > ((gmanager.getSizeCol(colonna) - 1) * 36 + 205) *res_y || sy < 25 * res_y) //se nessuna carta selezionata
		return cardtemp0;
	if (sy > ((gmanager.getSizeCol(colonna) - 1) * 36 + 25) *res_y && sy < ((gmanager.getSizeCol(colonna) - 1) * 36 + 205) * res_y) // ultima carta selezionata
	{
		temp = gmanager.ritornaCarta(colonna, (gmanager.getSizeCol(colonna))-1);
		if (temp.getCoperta() == true)
		{
			gmanager.setCartaCoperta(colonna, (gmanager.getSizeCol(colonna)) - 1, false);
			return cardtemp0;
		}
		cardtemp.push_back(temp);
	    gmanager.eraseCartaColPos (colonna, (gmanager.getSizeCol(colonna)) - 1);
		return cardtemp;
	}
	else //controlla se le carte selezione sono in successione e le restituisce
	{
		int carta = ((sy - 25*res_y) / 36) / res_y;
		for  (int i = carta; i < gmanager.getSizeCol(colonna); i++)
		{
			temp = gmanager.ritornaCarta(colonna, i);  //controllo se la prima carta selezionata è coperta
			if (temp.getCoperta() == true)
				return cardtemp0;
			cardtemp.push_back(temp);
		}
		for (int i = 0; i< cardtemp.size()-1; i++)
		{
			int j=i+1;
			if (!controllaSucCarte(cardtemp[i],cardtemp[j]))
				return cardtemp0;
		}		
	}
	gmanager.eraseFrom(cardtemp.size(), colonna);  //ritorno le carte selezionate, che verranno disegnate sul mouse, e le cancello dalla colonna
	return cardtemp;
}

void drawOnMouse(int sx, int sy, float res_x, float res_y, vector<Card> cardtemp, ALLEGRO_BITMAP* images [][13], int colonnatemp, int sorgx, int coly, int sorgy)
{
	int dy = (25 + 36 * coly);              //disegno delle carte selezionate sul mouse
	int dx = (25 + 160 * (colonnatemp - 1));
	for(int i = 0; i < cardtemp.size(); i++)
	{
		int val = cardtemp[i].getValore() -1;
		int sem = cardtemp[i].getSeme() -1;
		al_draw_bitmap(images[sem][val], ((sx - sorgx)/res_x + dx), ((sy - sorgy)/res_y + dy), 0);
		sy += 36 * res_y;
	}
}

bool onRelease(vector<Card>& carteMouse, GameManager& gmanager, int colonnaI, int colonnaF, ALLEGRO_BITMAP* images [][13], int &semeMazzi, list<GameManager>& gmanagertemp)
{
	int val, sem;   //si occupa di rilasciare le carte dal mouse alla colonna
	Card temp2(carteMouse.front());
	Card temp1(gmanager.ritornaCarta(colonnaF, gmanager.getSizeCol(colonnaF) - 1));
	if (colonnaI == colonnaF || gmanager.getSizeCol(colonnaF) == 0 || controllaSucCarte2 (temp1, temp2))
	{
		if (colonnaI == colonnaF)
			gmanagertemp.pop_back();
		for (int i = 0; i < carteMouse.size(); i++)
		{
			gmanager.push_backCartaCol(carteMouse[i], colonnaF);
		}
	}
	else 
	{
		gmanagertemp.pop_back();
		for (int i = 0; i < carteMouse.size(); i++)
		{
			gmanager.push_backCartaCol(carteMouse[i], colonnaI);
		}
	}
	bool tredici = true;
	if (gmanager.getSizeCol(colonnaF) >= 13)
	{
		Card temp3(gmanager.ritornaCarta(colonnaF, gmanager.getSizeCol(colonnaF) - 1));
		Card temp4;
		if(temp3.getValore() == 1)
		{
			for (int i = gmanager.getSizeCol(colonnaF) - 1; i > gmanager.getSizeCol(colonnaF) - 13; i--)
			{
				temp3 = gmanager.ritornaCarta(colonnaF, i);
				temp4 = gmanager.ritornaCarta(colonnaF, i - 1);
				if (temp3.getValore() != temp4.getValore() - 1 || temp4.getCoperta() || temp3.getSeme() != temp4.getSeme())
					tredici = false;
			}
			if (tredici)
			{
				gmanager.eraseFrom(13, colonnaF);
				carteMouse.clear();
				semeMazzi = temp1.getSeme();
				return true;
			}
		}
	}
	semeMazzi = temp1.getSeme();
	carteMouse.clear();
	return false;
}

void disegnaMazziFiniti(bool end[], ALLEGRO_BITMAP* img[], int seme[], int size, float res_x, float res_y) //disegna i mazzi finiti in basso a sinistra
{
	int bordox = 25;
	int bordoy = (1055 - 180);
	int dis = 36;
	for(int i = 0; i < size; i++)
	{
		if (end[i])
		{
			switch (seme[i])
			{
				case 1:
					{
						al_draw_bitmap(img[0], bordox, bordoy, 0);
						break;
					}
				case 2:
					{
						al_draw_bitmap(img[1], bordox, bordoy, 0);
						break;
					}
				case 3:
					{
						al_draw_bitmap(img[2], bordox, bordoy, 0);
						break;
					}
				case 4:
					{
						al_draw_bitmap(img[3], bordox, bordoy, 0);
						break;
					}
			}
			bordox += dis;
		}
	}
}

void transizione (Card temp, int col, int mazzi, int dim, ALLEGRO_BITMAP* images [][13], float res_x, float res_y) //ddisegno animazione dal mazzo in fondo a destra fino alla colonna
{
	int sx = (1920 - 124 + 25 - mazzi * 36);
	int sy = 875;
	int finalsx = (25 + 160 * (col - 1));
	int finalsy = (25 + 36 * (dim + 1));
	int y = 0, x = sx;
	int val = temp.getValore() -1;
	int sem = temp.getSeme() -1;
	while (x >= finalsx)
	{
		y = ((x - finalsx)*(sy - finalsy))/(sx - finalsx) + finalsy;
		al_draw_bitmap(images[sem][val], x, y, 0);
		x -= 100;
	}
	
}

void draw13(ALLEGRO_BITMAP* images [][13], int col, int sem, int val, int mazzi, int dim)
{
	int finalsx = 25 + mazzi * 36;      //disegna l'animazione dalla colonna ai mazzi finiti, dopo aver finito una scala di 13 carte
	int finalsy = 875;
	int sx = 25 + 160 * (col - 1);
	int sy = 25 + 36 * dim;
	int y = sy, x = sx;
	if (sx > finalsx)
	{
		while (y < finalsy)
		{
			y = ((x - finalsx)*(sy - finalsy))/(sx - finalsx) + finalsy;  
		//	cout << " Y = " << y << " e X =  " << x << endl; 
			al_draw_bitmap(images[sem][val], x, y, 0);
			x -= 5;
		}
	}
	else if (sx < finalsx)
	{
		while (y < finalsy)
		{
			y = ((x - finalsx) * (sy - finalsy)) / (sx - finalsx) + finalsy;  
		//	cout << " Y = " << y << " e X =  " << x << endl; 
			al_draw_bitmap(images[sem][val], x, y, 0);
			x += 5;
		}
	}
	else
	{
		while(y < finalsy)
		{
			al_draw_bitmap(images[sem][val], x, y, 0);
			y += 1;
		}
	}
}
bool is13 (int colonnaF, GameManager& gmanager, int &semeMazzi)  //controlla se è stata effettuata una scala di 13 carte
{
	bool tredici = true;
	Card temp3(gmanager.ritornaCarta(colonnaF, gmanager.getSizeCol(colonnaF) - 1));
	Card temp4;
	if(temp3.getValore() == 1)
	{
		for (int i = gmanager.getSizeCol(colonnaF) - 1; i > gmanager.getSizeCol(colonnaF) - 13; i--)
		{
			temp3 = gmanager.ritornaCarta(colonnaF, i);
			temp4 = gmanager.ritornaCarta(colonnaF, i - 1);
			if (temp3.getValore() != temp4.getValore() - 1 || temp4.getCoperta() || temp3.getSeme() != temp4.getSeme())
				tredici = false;
		}
		if (tredici) //se la condizione è verificata, le 13 carte vengono eliminate dalla colonna
		{
			gmanager.eraseFrom(13, colonnaF);
			semeMazzi = temp3.getSeme();
			return true;
		}
		return false;
	}
	return false;
}
