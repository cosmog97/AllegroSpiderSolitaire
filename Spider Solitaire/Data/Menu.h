/*
La classe si occupa delle operazioni di disegno nel menù,
oltre che al caricamento delle relative immagini
*/

#ifndef MENU_H
#define MENU_H

#include "Buttons.h"

class Menu
{
	public:
		Menu (ALLEGRO_DISPLAY *display, char nomegioco[])
		{
			sfondomenu = al_load_bitmap ("Data/Images/Menu/sfondomenu.png");
			if (!sfondomenu)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "Immagine sfondomenu.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			creditsimage = al_load_bitmap ("Data/Images/Menu/credits1.png");
			if (!creditsimage)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "Immagine credits.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			regole = al_load_bitmap ("Data/Images/Menu/regole.png");
			if (!regole)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "Immagine regole.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			modalita = al_load_bitmap ("Data/Images/Menu/modalita.png");
			if (!modalita)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "Immagine modalita.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			unseme[0] = al_load_bitmap ("Data/Images/Menu/UnSeme/unseme.png");
			unseme[1] = al_load_bitmap ("Data/Images/Menu/UnSeme/unseme_on.png");
			
			duesemi[0] = al_load_bitmap ("Data/Images/Menu/DueSemi/duesemi.png");
			duesemi[1] = al_load_bitmap ("Data/Images/Menu/DueSemi/duesemi_on.png");
			
			quattrosemi[0] = al_load_bitmap ("Data/Images/Menu/QuattroSemi/quattrosemi.png");
			quattrosemi[1] = al_load_bitmap ("Data/Images/Menu/QuattroSemi/quattrosemi_on.png");
			
			credits[0] = al_load_bitmap ("Data/Images/Menu/Credits/credits.png");
			credits[1] = al_load_bitmap ("Data/Images/Menu/Credits/credits_on.png");
			
			for (int i = 0; i < 2; i++)
			{
				if (!unseme[i])
				{
					al_show_native_message_box(display, nomegioco, "Errore", "Immagine unseme[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					
				}
				
				if (!duesemi[i])
				{
					al_show_native_message_box(display, nomegioco, "Errore", "Immagine duesemi[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					
				}
				
				if (!quattrosemi[i])
				{
					al_show_native_message_box(display, nomegioco, "Errore", "Immagine quattrosemi[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
				}
				
				if (!credits[i])
				{
					al_show_native_message_box(display, nomegioco, "Errore", "Immagine credits[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
				}
			}
			
			x = 660;
			y1 = 400;
			y2 = 520;
			y3 = 640;
			y4 = 780;
		}	
		
		int getX ()
		{
			return x;
		}
		
		int getY1 ()
		{
			return y1;
		}
		
		int getY2 ()
		{
			return y2;
		}
		
		int getY3 ()
		{
			return y3;
		}
		
		int getY4 ()
		{
			return y4;
		}
		
		void drawSfondoMenu ()
		{
			al_draw_bitmap(sfondomenu, 0, 0, 0);
		}
		
		void drawUnSeme (bool isOnMouse)
		{
			if (isOnMouse)
			{
				al_draw_bitmap(unseme[1], x, y1, 0);
			}
			else
			{
				al_draw_bitmap(unseme[0], x, y1, 0);
			}
		}
		
		void drawDueSemi  (bool isOnMouse)
		{
			if (isOnMouse)
			{
				al_draw_bitmap(duesemi[1], x, y2, 0);
			}
			else
			{
				al_draw_bitmap(duesemi[0], x, y2, 0);
			}
		}
		
		void drawQuattroSemi (bool isOnMouse)
		{
			if (isOnMouse)
			{
				al_draw_bitmap(quattrosemi[1], x, y3, 0);
			}
			else
			{
				al_draw_bitmap(quattrosemi[0], x, y3, 0);
			}			
		}

		void drawCredits (bool isOnMouse)
		{
			if (isOnMouse)
			{
				al_draw_bitmap(credits[1], x, y4, 0);
			}
			else
			{
				al_draw_bitmap(credits[0], x, y4, 0);
			}		
		}

		void drawModalita ()
		{
			al_draw_bitmap(modalita, 860, 320, 0);
		}

		void drawCreditsTab ()
		{
			al_draw_bitmap(creditsimage, 0, 0, 0);
		}
		
		void drawRegole ()
		{
			al_draw_bitmap(regole, 0, 0, 0);
		}

	private:
		ALLEGRO_BITMAP* sfondomenu;
		ALLEGRO_BITMAP* creditsimage;
		ALLEGRO_BITMAP* regole;
		ALLEGRO_BITMAP* modalita;
		
		ALLEGRO_BITMAP* unseme[2];
		ALLEGRO_BITMAP* duesemi[2];
		ALLEGRO_BITMAP* quattrosemi[2];
		ALLEGRO_BITMAP* credits[2];
		
		int x;
		int y1;
		int y2;
		int y3;
		int y4;

};

#endif
