/*
La classe serve per caricare le immagini di gioco
relative ai tasti/bottoni della GUI, seguite dalle
relative opzioni di disegno, a cui vengono passate
delle booleane per verificare se il bottone è attivo
o al momento non è stato cliccato. Alcuni bottoni
sono relativi al menù, alcuni al gioco.
*/

#ifndef BUTTONS_H
#define BUTTONS_H

#include <string>
#include <iostream>

using namespace std;

class Buttons
{
	public:

		Buttons (ALLEGRO_DISPLAY *display, char nomegioco[])  //costruttore con immagini e controllo caricamento corretto
			{
				exit[0] = al_load_bitmap ("Data/Images/Buttons/Exit/esci_off.png");  //ESCI_OFF
				exit[1] = al_load_bitmap ("Data/Images/Buttons/Exit/esci_on.png");  //ESCI_ON

				exitmenu[0] = al_load_bitmap ("Data/Images/Buttons/Menu/esci_off.png");  //ESCI_OFF_MENU
				exitmenu[1] = al_load_bitmap ("Data/Images/Buttons/Menu/esci_on.png");  //ESCI_ON_MENU
				
				indietro[0] = al_load_bitmap ("Data/Images/Buttons/TearUp/tearup_off.png"); //INDIETRO_ON
				indietro[1] = al_load_bitmap ("Data/Images/Buttons/TearUp/tearup_on.png"); //INDIETRO_OFF
				
				pause[0] = al_load_bitmap ("Data/Images/Buttons/Pause/pause_off.png"); //PAUSE_OFF
				pause[1] = al_load_bitmap ("Data/Images/Buttons/Pause/pause_on.png"); //PAUSE_OFF
				
				play[0] = al_load_bitmap ("Data/Images/Buttons/Play/play_off.png"); //PLAY_OFF
				play[1] = al_load_bitmap ("Data/Images/Buttons/Play/play_on.png"); //PLAY_ON
				
				audio[0] = al_load_bitmap ("Data/Images/Buttons/Audio/audio_off.png"); //AUDIO_OFF
				audio[1] = al_load_bitmap ("Data/Images/Buttons/Audio/audio_on.png"); //AUDIO_ON
				
				noaudio[0] = al_load_bitmap ("Data/Images/Buttons/NoAudio/noaudio_off.png"); //NOAUDIO_OFF
				noaudio[1] = al_load_bitmap ("Data/Images/Buttons/NoAudio/noaudio_on.png"); //NOAUDIO_ON

				music[0] = al_load_bitmap ("Data/Images/Buttons/Music/music_off.png"); //MUSIC_OFF
				music[1] = al_load_bitmap ("Data/Images/Buttons/Music/music_on.png"); //MUSIC_ON
				
				nomusic[0] = al_load_bitmap ("Data/Images/Buttons/NoMusic/nomusic_off.png"); //NOMUSIC_OFF
				nomusic[1] = al_load_bitmap ("Data/Images/Buttons/NoMusic/nomusic_on.png"); //NOMUSIC_ON
				
				regole[0] = al_load_bitmap ("Data/Images/Buttons/Rules/regole_off.png"); //REGOLE_OFF
				regole[1] = al_load_bitmap ("Data/Images/Buttons/Rules/regole_on.png"); //REGOLE_ON

				audiomenu[0] = al_load_bitmap ("Data/Images/Buttons/Menu/audio_off.png"); //AUDIO_OFF_MENU
				audiomenu[1] = al_load_bitmap ("Data/Images/Buttons/Menu/audio_on.png"); //AUDIO_ON_MENU
				
				noaudiomenu[0] = al_load_bitmap ("Data/Images/Buttons/Menu/noaudio_off.png"); //NOAUDIO_OFF_MENU
				noaudiomenu[1] = al_load_bitmap ("Data/Images/Buttons/Menu/noaudio_on.png"); //NOAUDIO_ON_MENU

				musicmenu[0] = al_load_bitmap ("Data/Images/Buttons/Menu/music_off.png"); //MUSIC_OFF_MENU
				musicmenu[1] = al_load_bitmap ("Data/Images/Buttons/Menu/music_on.png"); //MUSIC_ON_MENU
				
				nomusicmenu[0] = al_load_bitmap ("Data/Images/Buttons/Menu/nomusic_off.png"); //NOMUSIC_OFF_MENU
				nomusicmenu[1] = al_load_bitmap ("Data/Images/Buttons/Menu/nomusic_on.png"); //NOMUSIC_ON_MENU
				
				regolemenu[0] = al_load_bitmap ("Data/Images/Buttons/Menu/regole_off.png"); //REGOLE_OFF_MENU
				regolemenu[1] = al_load_bitmap ("Data/Images/Buttons/Menu/regole_on.png"); //REGOLE_ON_MENU
				
				vittoria = al_load_bitmap ("Data/Images/Buttons/schermatavittoria.png");
				
				tornaalmenu[0] = al_load_bitmap ("Data/Images/Buttons/ReturnToMenu/vaialmenu_off.png");
				tornaalmenu[1] = al_load_bitmap ("Data/Images/Buttons/ReturnToMenu/vaialmenu_on.png");
				
				ricominciapartita[0] = al_load_bitmap ("Data/Images/Buttons/GiocaAncora/giocaancora_off.png");
				ricominciapartita[1] = al_load_bitmap ("Data/Images/Buttons/GiocaAncora/giocaancora_on.png");
				
				si[0] = al_load_bitmap ("Data/Images/Buttons/Yes/si_off.png");
				si[1] = al_load_bitmap ("Data/Images/Buttons/Yes/si_on.png");
				
				no[0] = al_load_bitmap ("Data/Images/Buttons/No/no_off.png");
				no[1] = al_load_bitmap ("Data/Images/Buttons/No/no_on.png");
				
				exitdialog = al_load_bitmap ("Data/Images/Buttons/exitdialog2.png");
				
				for (int i=0; i <2 ; i++)
				{
					if(!exit[i])
					{
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine exit[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!exitmenu[i])
					{
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine exitmenu[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!indietro[i])
					{
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine indietro[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!pause[i])
					{
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine pause[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!play[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine play[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!audio[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine audio[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!noaudio[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine noaudio[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!music[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine music[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!nomusic[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine nomusic[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if (!regole[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine regole[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
							
					}
					if(!audiomenu[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine audio[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!noaudiomenu[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine noaudio[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!musicmenu[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine music[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if(!nomusicmenu[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine nomusic[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					}
					if (!regolemenu[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine regole[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
							
					}
					if (!tornaalmenu[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine tornaalmenu[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
							
					}
					if (!ricominciapartita[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine ricominciapartita[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
							
					}
					if (!no[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine no[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
							
					}
					if (!si[i])
					{
							
							al_show_native_message_box(display, nomegioco, "Errore", "Immagine si[] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
							
					}
				}
				
				onpause = false;
				
				x_sx = 1665;
				x_dx = 1778;
				y = 25;
				
				xm1 = 730;
				xm2 = 850;
				xm3 = 970;
				xm4 = 1090;
				ym = 935;
				
				xv1 = 575;
				xv2 = 970;
				yv = 945;
			}
			
	
		int getX_sx ()
		{
			return x_sx;
		}
		
		int getX_dx ()
		{
			return x_dx;
		}
		
		int getY ()
		{
			return y;
		}
		
		int getXM1 ()
		{
			return xm1;
		}
		
		int getXM2 ()
		{
			return xm2;
		}
		
		int getXM3 ()
		{
			return xm3;
		}
		
		int getXM4 ()
		{
			return xm4;
		}
		
		int getYM ()
		{
			return ym;
		}

		void setOnPause (bool set)
		{
			onpause = set;
		}
		
		int getXV1 ()
		{
			return xv1;
		}
		
		int getXV2 ()
		{
			return xv2;
		}
		
		int getYV ()
		{
			return yv;
		}
		
		bool getOnPause ()
		{
			return onpause;
		}

		
		void drawExitButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(exit[1], x_dx, y, 0);
				}
				else
				{
					al_draw_bitmap(exit[0], x_dx, y, 0);
				}
			}
		void drawIndietroButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(indietro[1], x_sx, 154, 0);
				}
				else
				{
					al_draw_bitmap(indietro[0], x_sx, 154, 0);
				}
			}
		void drawPauseButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(pause[1], x_dx, 154, 0);
				}
				else
				{
					al_draw_bitmap(pause[0], x_dx, 154, 0);
				}
			}
		void drawPlayButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(play[1], x_dx, 155, 0);
				}
				else
				{
					al_draw_bitmap(play[0], x_dx, 155, 0);
				}
			}
		void drawAudioButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(audio[1], x_dx, 280, 0);
				}
				else
				{
					al_draw_bitmap(audio[0], x_dx, 280, 0);
				}
			}
		void drawNoAudioButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(noaudio[1], x_dx, 280, 0);
				}
				else
				{
					al_draw_bitmap(noaudio[0], x_dx, 280, 0);
				}
			}
		void drawMusicButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(music[1], x_sx, 280, 0);
				}
				else
				{
					al_draw_bitmap(music[0], x_sx, 280, 0);
				}
			}
		void drawNoMusicButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(nomusic[1], x_sx, 280, 0);
				}
				else
				{
					al_draw_bitmap(nomusic[0], x_sx, 280, 0);
				}
			}
		void drawRegoleButton (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(regole[1], x_sx, y, 0);
				}
				else
				{
					al_draw_bitmap(regole[0], x_sx, y, 0);
				}
			}
		void drawSchermataVittoria (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(vittoria, 0, 0, 0);
				}
			}
		void drawTornaAlMenu (bool visibile)
		{
			if (visibile)
			{
				al_draw_bitmap(tornaalmenu[1], xv1, yv, 0);
			}
			else
			{
				al_draw_bitmap(tornaalmenu[0], xv1, yv, 0);
			}
		}
		void drawRicominciaPartita (bool visibile)
		{
			if (visibile)
			{
				al_draw_bitmap(ricominciapartita[1], xv2, yv, 0); 
			}
			else
			{
				al_draw_bitmap(ricominciapartita[0], xv2, yv, 0); 
			}
		}
		void drawYes (bool visibile)
		{
			if (visibile)
			{
				al_draw_bitmap(si[1], 970, 613, 0); 
			}
			else
			{
				al_draw_bitmap(si[0], 970, 613, 0); 
			}
		}
		void drawNo (bool visibile)
		{
			if (visibile)
			{
				al_draw_bitmap(no[1], 684, 613, 0); 
			}
			else
			{
				al_draw_bitmap(no[0], 684, 613, 0); 
			}
		}
		void drawExitDialog ()
		{
			al_draw_bitmap(exitdialog, (1920/2) - (al_get_bitmap_width(exitdialog)/2), (1080/2) - (al_get_bitmap_height(exitdialog)/2), 0); 
		}
		void drawExitButtonM (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(exitmenu[1], xm1, ym, 0);
				}
				else
				{
					al_draw_bitmap(exitmenu[0], xm1, ym, 0);
				}
			}
		
		void drawAudioButtonM (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(audiomenu[1], xm3, ym, 0);
				}
				else
				{
					al_draw_bitmap(audiomenu[0], xm3, ym, 0);
				}
			}
		void drawNoAudioButtonM (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(noaudiomenu[1], xm3, ym, 0);
				}
				else
				{
					al_draw_bitmap(noaudiomenu[0], xm3, ym, 0);
				}
			}
		void drawMusicButtonM (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(musicmenu[1], xm2, ym, 0);
				}
				else
				{
					al_draw_bitmap(musicmenu[0], xm2, ym, 0);
				}
			}
		void drawNoMusicButtonM (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(nomusicmenu[1], xm2, ym, 0);
				}
				else
				{
					al_draw_bitmap(nomusicmenu[0], xm2, ym, 0);
				}
			}
		void drawRegoleButtonM (bool visibile)
			{
				if (visibile)
				{
					al_draw_bitmap(regolemenu[1], xm4, ym, 0);
				}
				else
				{
					al_draw_bitmap(regolemenu[0], xm4, ym, 0);
				}
			}	
		
	private:
		ALLEGRO_BITMAP* exit[2];
		ALLEGRO_BITMAP* exitmenu[2];
		
		ALLEGRO_BITMAP* indietro[2];
		
		ALLEGRO_BITMAP* pause[2];
		ALLEGRO_BITMAP* play[2];
		bool onpause;
		
		ALLEGRO_BITMAP* audio[2];
		ALLEGRO_BITMAP* noaudio[2];

		ALLEGRO_BITMAP* audiomenu[2];
		ALLEGRO_BITMAP* noaudiomenu[2];

		ALLEGRO_BITMAP* music[2];
		ALLEGRO_BITMAP* nomusic[2];

		ALLEGRO_BITMAP* musicmenu[2];
		ALLEGRO_BITMAP* nomusicmenu[2];

		ALLEGRO_BITMAP* regole[2];
		ALLEGRO_BITMAP* regolemenu[2];
		
		ALLEGRO_BITMAP* vittoria;	
		ALLEGRO_BITMAP* tornaalmenu[2];
		ALLEGRO_BITMAP* ricominciapartita[2];
		
		
		ALLEGRO_BITMAP* si[2]; 
		ALLEGRO_BITMAP* no[2];
		
		ALLEGRO_BITMAP* exitdialog;
		
		
		int x_sx;
		int x_dx;
		int y;
		
		int xm1;
		int xm2;
		int xm3;
		int xm4;
		int ym;
		
		
		int xv1;
		int xv2;
		int yv;

};

#endif
