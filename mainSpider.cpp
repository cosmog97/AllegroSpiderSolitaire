#include "Data/Functions.h"
#include "Data/Menu.h"


using namespace std;

const int W_default = 1920;
const int H_default = 1080;
char nomegioco[17] = "Spider Solitaire";
const float FPS = 30.0;
int nummazzi = 5;

int main (int argc, char **argv)
{
    //INIZIALIZZA LE FUNZIONI DI ALLEGRO_____________________________
	int modalitagame = 0;
	srand (time(NULL));
	if (inizializzaAllegro () == -1)
		return 0;
	int DISPLAY_WIDTH;
	int DISPLAY_HEIGHT;
	DISPLAY_WIDTH = W_default;
	DISPLAY_HEIGHT = H_default;
	int res_monitor_x;
	int res_monitor_y;
	float res_x;
	float res_y;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_MONITOR_INFO info;
	ALLEGRO_TRANSFORM ridimensionamento;
	al_get_monitor_info(0,&info);
	res_monitor_x = info.x2 - info.x1;
	res_monitor_y = info.y2 - info.y1;
	res_x = res_monitor_x / (float) DISPLAY_WIDTH;
	res_y = res_monitor_y / (float) DISPLAY_HEIGHT;
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	display = al_create_display(res_monitor_x,res_monitor_y);
	al_set_window_title (display, nomegioco);
	if (!display)
	{
		al_show_native_message_box(display,"Errore", "Attenzione", "Il display non è stato creato correttamente.",NULL,ALLEGRO_MESSAGEBOX_WARN);
		return -1;
	}
	al_identity_transform(& ridimensionamento);
	al_scale_transform(& ridimensionamento,res_x,res_y);
	al_use_transform(& ridimensionamento);
	ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue ();
	al_register_event_source(event_queue, al_get_timer_event_source (timer));
	al_register_event_source(event_queue, al_get_display_event_source (display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	//INIZIALIZZA VARIABILI DEL GIOCO____________________________________________________________________________--
	vector<Card> cartedaspostare;
	list<GameManager> spidertemp;
	int dimmaz = 36 * 4;
	bool buttons_on[5] = {false, false, false, false, false};  //exit, audio, musica, pausa
	bool menu_on[5] = {false, false, false, false, false};   //un seme, due semi, tre semi, credits, showcredits
	bool win_on[2] = {false, false};
	bool exit_on[2] = {false, false};
	bool modmenu [2] = {false, false};  //regole credits
	bool endloop = false;
	bool endmenu = false;
	bool vittoria = false;
	int sx = 0, sy = 0;
	int dx = 0, dy = 0;
	int temp_x = 0, temp_y = 0;
	int domx = 0, domy = 0;
	int colonnatemp, colonnatemp2;
	int coly = 0;
	bool stampamazzo = true;
	bool b_down = false;
	bool b_up = false;
	bool spostamento = false;
	bool rilascio = false;
	unsigned intmazzo = 11;
	bool mazzifiniti[8];
	int sizeMazzifiniti = 0;
	bool tredici = false;
	int semeMazzi = 0;
	int semeEnd[8] = {0,0,0,0,0,0,0,0};
	int sizeEnd = 0;
	for (int i = 0; i < 8; i++)
	{
		mazzifiniti[i] = false;
	}
	ALLEGRO_BITMAP* kappa[4];
	kappa[0] = al_load_bitmap ("Data/Images/1/13.png");
	kappa[1] = al_load_bitmap ("Data/Images/2/13.png");
	kappa[2] = al_load_bitmap ("Data/Images/3/13.png");
	kappa[3] = al_load_bitmap ("Data/Images/4/13.png");
	if(!kappa[0] || !kappa[1] || !kappa[2] || !kappa[3])
	{
    	  	al_show_native_message_box(display, nomegioco, "Errore", "Immagine kappa.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}
	ALLEGRO_BITMAP* images[4][13];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
		{
			string seme=toString(i+1);
			string valore=toString(j+1);
			string hash="/";
			string png=".png";
			string data="Data/Images/";
			string dirtots=data+seme+hash+valore+png;
			const char* dirtot=dirtots.c_str();
			ALLEGRO_BITMAP* temp = al_load_bitmap(dirtot);
			if(!temp)
			{
    	  		al_show_native_message_box(display, nomegioco, "Errore", "Immagine array images[][] non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
				return -1;
			}
			images[i][j] = temp;
		}
	ALLEGRO_BITMAP* cover = al_load_bitmap ("Data/Images/cover.png");
	if(!cover)
	{
    	  	al_show_native_message_box(display, nomegioco, "Errore", "Immagine cover.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}
	ALLEGRO_BITMAP* sfondo = al_load_bitmap ("Data/Images/sfondo2.png");
	if(!sfondo)
	{
    	  	al_show_native_message_box(display, nomegioco, "Errore", "Immagine sfondo.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}
	ALLEGRO_BITMAP* onpause = al_load_bitmap ("Data/Images/onpause.png");
	if(!onpause)
	{
    	  	al_show_native_message_box(display, nomegioco, "Errore", "Immagine onpause.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}
	ALLEGRO_FONT* font_timer = al_load_font ("Data/Fonts/Square.ttf", 50, 0);  //absender1.ttf
	if(!font_timer)
	{
			al_show_native_message_box(display, nomegioco, "Errore", "Font_timer non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}
	ALLEGRO_BITMAP* icon = al_load_bitmap ("Data/Images/icon.png");
	if(!icon)
	{
		al_show_native_message_box(display, nomegioco, "Errore", "Immagine icon.png non caricata correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_set_display_icon(display, icon);
	al_start_timer(timer);
	ALLEGRO_MOUSE_STATE state;
	al_clear_to_color(al_map_rgb(0,0,0));

	Buttons buttons (display,nomegioco);
	Menu menu (display,nomegioco);
	Sounds sounds (display,nomegioco);
	sounds.playMusic ();


	while(!endmenu)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, & ev);

		if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)  // stampa posizioni del mouse
		{
			temp_x = ev.mouse.x;
			temp_y = ev.mouse.y;
		}

		if (controlloUnSemeM (temp_x, temp_y, res_x, res_y, menu, modmenu) || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_1))
		{
			menu_on[0] = true;

			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_1))
			{
				sounds.playTastoMenu ();
				modalitagame = 1;
				endloop = false;
			}
		}

		if (controlloDueSemiM (temp_x, temp_y, res_x, res_y, menu, modmenu) || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_2))
		{
			menu_on[1] = true;

			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_2))
			{
				sounds.playTastoMenu ();
				modalitagame = 2;
				endloop = false;
			}
		}

		if (controlloQuattroSemiM (temp_x, temp_y, res_x, res_y, menu, modmenu)|| 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_3))
		{
			menu_on[2] = true;
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_3))
			{
				sounds.playTastoMenu ();
				modalitagame = 3;
				endloop = false;
			}

		}

		if (controlloCreditsM (temp_x, temp_y, res_x, res_y, menu, modmenu)|| 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_4))
		{
			menu_on[3] = true;
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_4))
			{
				sounds.playTastoMenu ();
				modmenu[1] = true;
			}
		}

		if((controlloExitM (temp_x, temp_y, res_x, res_y, buttons) || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) && !modmenu[0])
		{

			buttons_on[0] = true;
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
			{
				if (modmenu[1])
				{
					sounds.playTastoGenerale();
					modmenu[1] = false;
				}
				else
				{
					sounds.playTastoGenerale();
				    endmenu = true;
				    modalitagame = 0;
				}
			}
		}

	    if (controlloAudioM (temp_x, temp_y, res_x, res_y, buttons)|| 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_M))
		{
			buttons_on[1] = true;
			if (sounds.getAudio())
			{
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN|| 
				ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_M))
				{
					sounds.playTastoGenerale();
					sounds.setAudio (false);
				}
			}
			else
			{
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN|| 
				ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_M))
				{
					sounds.setAudio (true);
				}
			}
		}

		if (controlloMusicM (temp_x, temp_y, res_x, res_y, buttons)|| 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_N))
		{
				buttons_on[2] = true;
				if (sounds.getMusic())
				{
					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
					ev.type == ALLEGRO_EVENT_KEY_DOWN && 
					(ev.keyboard.keycode == ALLEGRO_KEY_N))
					{
						sounds.setMusic (false);
						sounds.stopMusic();
					}
				}
				else
				{
					if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
					ev.type == ALLEGRO_EVENT_KEY_DOWN && 
					(ev.keyboard.keycode == ALLEGRO_KEY_N))
					{
						sounds.setMusic (true);
						sounds.playMusic();
					}
				}
		}

		if (controlloRegoleM (temp_x, temp_y, res_x, res_y, buttons) || 
			ev.type == ALLEGRO_EVENT_KEY_DOWN && (ev.keyboard.keycode == ALLEGRO_KEY_R))
		{
				menu_on[4] = true;
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
					ev.type == ALLEGRO_EVENT_KEY_DOWN && 
					(ev.keyboard.keycode == ALLEGRO_KEY_R))
				{
					if (modmenu[0])
					{
						sounds.playTastoGenerale();
						modmenu[0] = false;
					}
					else
					{
						sounds.playTastoGenerale();
						modmenu[0] = true;
					}
				}
		}
		
		al_start_timer(timer);  //fa iniziare il timer del gioco
		
		if (modalitagame >= 1 && modalitagame <= 3)  //ENTRA NEL LOOP DEL GIOCO
		{
			Deck deck(modalitagame);
			GameManager spider;
			creaColonne (deck, spider);
			int start = al_get_timer_count(timer)/FPS;
			buttons.setOnPause (false);
			endloop = false;
			al_start_timer(timer);
			spidertemp.clear();
			bool exitdialog = false;
			bool regolegame = false;
			bool regoleb = false;
			
			while (!endloop)
			{
				bool ct = true, flip = false;
				int cont = 0;
				
				ALLEGRO_EVENT events;
				al_wait_for_event(event_queue, & events);

				if (events.type == ALLEGRO_EVENT_KEY_DOWN && 
				buttons.getOnPause() == false && !exitdialog &&
				  (events.keyboard.keycode == ALLEGRO_KEY_RCTRL ||
				   events.keyboard.keycode == ALLEGRO_KEY_LCTRL))
				{  //serve per effettuare CTRL + Z in 
					while (ct)
					{
						ALLEGRO_EVENT  events2;
						al_wait_for_event(event_queue, & events2);
						
						if (events2.type == ALLEGRO_EVENT_KEY_UP && events2.keyboard.keycode == ALLEGRO_KEY_Z)
						{	
							cont = 0;
						}
						else if (events2.keyboard.keycode == ALLEGRO_KEY_Z && cont == 0)
						{
							if (spidertemp.size() > 0)
							{
								sounds.playTastoGenerale();
								spider = spidertemp.back();
								spidertemp.pop_back();
								al_draw_bitmap(sfondo, 0, 0, 0);
								disegnaColonne (images, cover, spider);
								disegnaMazziFiniti(mazzifiniti, kappa, semeEnd, sizeMazzifiniti, res_x, res_y);
								stampaMazzi (cover, stampamazzo, nummazzi,buttons, sounds, buttons_on, onpause, regoleb, font_timer, (al_get_timer_count(timer)/FPS) - start);
								drawTimer (font_timer, (al_get_timer_count(timer)/FPS) - start);
								al_flip_display();
								flip = true;
							}
							else
							{
								sounds.playMossaErrata();
							}
							cont++;
						}
						else if(events2.type == ALLEGRO_EVENT_KEY_UP)
						{
							ct = false;
						}
					}
				}

				if(events.type == ALLEGRO_EVENT_MOUSE_AXES || events.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)  // stampa posizioni del mouse
				{
					temp_x = events.mouse.x;
					temp_y = events.mouse.y;
				}

				if ((controlloBackToMenuV (temp_x, temp_y, res_x, res_y, buttons, vittoria)|| 
						events.type == ALLEGRO_EVENT_KEY_DOWN && 
						(events.keyboard.keycode == ALLEGRO_KEY_F)) && vittoria)
				{
					win_on[0] = true;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && 
						(events.keyboard.keycode == ALLEGRO_KEY_F))
					{
						modalitagame = 0;
						vittoria = false;
						endloop = true;
					}
				}
				if ((controlloRestartV (temp_x, temp_y, res_x, res_y, buttons, vittoria) || 
					events.type == ALLEGRO_EVENT_KEY_DOWN && 
					(events.keyboard.keycode == ALLEGRO_KEY_G)) && vittoria)
				{
					win_on[1] = true;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && 
						(events.keyboard.keycode == ALLEGRO_KEY_G))
					{
						vittoria = false;
						endloop = true;
					}
				}

				if(((controlloRegole (temp_x, temp_y, res_x, res_y, buttons) || 
				  (events.type == ALLEGRO_EVENT_KEY_DOWN && 
				   events.keyboard.keycode == ALLEGRO_KEY_R))) && exitdialog == false)
				{
					regoleb = true;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
					   (events.type == ALLEGRO_EVENT_KEY_DOWN && 
				  		events.keyboard.keycode == ALLEGRO_KEY_R))
						{
							if (regolegame)
							{
								sounds.playTastoGenerale();
								buttons.setOnPause (false);
								al_start_timer(timer);
								regolegame = false;
							}
							else
							{
								sounds.playTastoGenerale();
								buttons.setOnPause (true);
								al_stop_timer(timer);
								regolegame = true;
							}
						}
				}

				if(controlloExitDialog (buttons, temp_x, temp_y, res_x, res_y) || 
				  (events.type == ALLEGRO_EVENT_KEY_DOWN && 
				   events.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
				{

					buttons_on[0] = true;

					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
				 	   (events.type == ALLEGRO_EVENT_KEY_DOWN && 
				        events.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
						{
							if (!exitdialog)
							{
								exitdialog = true;
							}
							else
							{
								exitdialog = false;
							//	regolegame = false;
							}
						}
				}

				if(controlloSI (temp_x, temp_y, res_x, res_y, exitdialog) || 
				  ((events.type == ALLEGRO_EVENT_KEY_DOWN && 
				   events.keyboard.keycode == ALLEGRO_KEY_S) && exitdialog))
				{
					exit_on[1] = true;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
				     (events.type == ALLEGRO_EVENT_KEY_DOWN && 
				     events.keyboard.keycode == ALLEGRO_KEY_S))
					{
						endloop = true;
						modalitagame = 0;
						stampamazzo = true;
						intmazzo = 11;
						sizeMazzifiniti = 0;
						sizeEnd = 0;
						nummazzi = 5;
						dimmaz = 36 * 4;
						exitdialog = false;
					}
				}
				
				
				if((controlloNO (temp_x, temp_y, res_x, res_y, exitdialog) || 
				  (events.type == ALLEGRO_EVENT_KEY_DOWN && 
				   events.keyboard.keycode == ALLEGRO_KEY_A)) && exitdialog)
				{
					exit_on[0] = true;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN  || 
				    (events.type == ALLEGRO_EVENT_KEY_DOWN && 
				     events.keyboard.keycode == ALLEGRO_KEY_A))
					{
						buttons.setOnPause (false);
						al_start_timer (timer);
						exitdialog = false;
						regolegame = false;
					}
				}
				
				if(controlloRitorna(temp_x, temp_y, res_x, res_y, buttons) && !exitdialog)
				{

					buttons_on[4] = true;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
						{
							if (spidertemp.size() > 0)
							{
								sounds.playTastoGenerale();
								spider = spidertemp.back();
								spidertemp.pop_back();
							}
							else
							{
								sounds.playMossaErrata();
							}
						}
				}

				if(controlloPause(temp_x, temp_y, res_x, res_y, buttons) || 
			       events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_P))
				{
					if (!regolegame)
					buttons_on[3] = true;
					if (buttons.getOnPause() && !regolegame)
					{
						if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_P))
						{
						
							sounds.playTastoGenerale();
							buttons.setOnPause (false);
							al_start_timer(timer);
						}
					}
					else
					{
						if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_P))
						{
							if (!regolegame) {
								sounds.playTastoGenerale();
							}
							buttons.setOnPause (true);
							al_stop_timer (timer);
						}
					}
				}

				if(controlloAudio(temp_x, temp_y, res_x, res_y, buttons) || 
				events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_N))
				{
					buttons_on[1] = true;
					if (sounds.getAudio())
					{
						if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_N))
						{
							sounds.playTastoGenerale();
							sounds.setAudio (false);
						}
					}
					else
					{
						if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_N))
						{
							sounds.setAudio (true);
						}
					}
				}

				if(controlloMusic(temp_x, temp_y, res_x, res_y, buttons) || 
				events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_M))
				{
					buttons_on[2] = true;
					if (sounds.getMusic())
					{
						if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_M))
						{
							sounds.playTastoGenerale();
							sounds.setMusic (false);
							sounds.stopMusic();
						}
					}
					else
					{
						if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_M))
						{
							sounds.playTastoGenerale();
							sounds.setMusic (true);
							sounds.playMusic();
						}
					}
				}

				if (((controlloDistrMazzi(temp_x, temp_y, res_x, res_y, buttons, dimmaz, stampamazzo, spostamento) || 
					events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_ENTER)))
					&& buttons.getOnPause() == false && !exitdialog)  //aggiungo carte dal mazzo restante //&&spostamento
				{
					if (spider.getSizeCol(intmazzo) != 0 && intmazzo <= 15 && (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || 
						events.type == ALLEGRO_EVENT_KEY_DOWN && (events.keyboard.keycode == ALLEGRO_KEY_ENTER)))
					{
						spidertemp.clear();
						sounds.playDistrMazzo();
						for (unsigned ni = 0; ni < 10; ni++)
						{
							{
								al_rest(0.04);
								unsigned conttemp4 = getNumRandom (spider.getSizeCol(intmazzo));
								Card temp4 = spider.ritornaCarta (intmazzo, conttemp4);
								temp4.setCoperta(false);
								transizione(temp4, ni + 1, nummazzi, spider.getSizeCol(ni + 1), images, res_x, res_y);
								disegnaMazziFiniti(mazzifiniti, kappa, semeEnd, sizeMazzifiniti, res_x, res_y);
								disegnaColonne (images, cover, spider);
								stampaMazzi (cover, stampamazzo, nummazzi, buttons, sounds, buttons_on, onpause, regoleb, font_timer, (al_get_timer_count(timer)/FPS) - start);
								al_flip_display();
								al_draw_bitmap(sfondo, 0, 0, 0);
								spider.push_backCartaCol(temp4, ni + 1);
								spider.eraseCartaCol (temp4, intmazzo);
							}
						}

						if(dimmaz >= 36)
							dimmaz -= 36;
						intmazzo++;
						if (intmazzo == 16)
						{
							stampamazzo = false;
						}
						nummazzi--;
					}
				}

				else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && events.mouse.button == 1 && spostamento == false
						&& buttons.getOnPause() == false && !exitdialog)
				{
					sx = events.mouse.x;
					sy = events.mouse.y;
					domx = sx;
					domy = sy;
					b_down = true;

					if (onTableGame (sx, res_x, b_down))
					{
						colonnatemp = trovaColonna(sx, res_x);
						spidertemp.push_back (spider);
						cartedaspostare = controllaPosizioneMazzoSel (colonnatemp, spider, sy, res_y);
						if (cartedaspostare.size() != 0)
						{
							spostamento = true;
							sounds.playPrendiCarta();
						}
						else
						{
							spostamento = false;
							sounds.playMossaErrata();
						}

					}

				}

				else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && events.mouse.button == 1 && spostamento
						&& buttons.getOnPause() == false)
				{
					dx = events.mouse.x;
					dy = events.mouse.y;
					if (onTableGame (dx, res_x, true))
					{
						colonnatemp2 = trovaColonna(dx, res_x);
						sounds.playRilascioCarta();
					}
					else
					{
						colonnatemp2 = colonnatemp;
						sounds.playRilascioCarta();
					}
					if (colonnatemp2 < 1 || colonnatemp2 > 10)
					{
						colonnatemp2 = colonnatemp;
						sounds.playMossaErrata();
					}
					rilascio = true;

					spostamento = false;
				}



				if (al_is_event_queue_empty(event_queue))  //operazione di disegno e fine coda
				{
					if (!vittoria)
					{
						disegnaMazziFiniti(mazzifiniti, kappa, semeEnd, sizeMazzifiniti, res_x, res_y);
						disegnaColonne (images, cover, spider);
						stampaMazzi (cover, stampamazzo, nummazzi, buttons, sounds, buttons_on, onpause, regoleb, font_timer, (al_get_timer_count(timer)/FPS) - start);
						drawGameButtons (buttons, sounds, buttons_on, onpause, regoleb);
						drawTimer (font_timer, (al_get_timer_count(timer)/FPS) - start);
						azzeraButtons (buttons_on);
						regoleb = false;
					}

					if(spostamento)
					{
						coly = spider.getSizeCol(colonnatemp);
						drawOnMouse(temp_x, temp_y, res_x, res_y, cartedaspostare, images, colonnatemp, domx, coly, domy);
					}

					if(rilascio)
					{
						tredici = onRelease(cartedaspostare, spider, colonnatemp, colonnatemp2, images, semeMazzi, spidertemp);
						colonnatemp = 0;
						if(tredici == false)
							colonnatemp2 = 0;
						rilascio = false;
					}

					if(sizeMazzifiniti == 8)
					{
						vittoria = true;
						stampamazzo = true;
						intmazzo = 11;
						sizeMazzifiniti = 0;
						sizeEnd = 0;
						nummazzi = 5;
						dimmaz = 36 * 4;
						spidertemp.clear();
						al_stop_timer (timer);

					}

					for (int a = 1; a < 11; a++)
					{
						if (spider.getSizeCol(a) >= 13 && spider.ritornaCarta(a, spider.getSizeCol(a) - 1).getValore() == 1)
						{
							colonnatemp2 = a;
							tredici = is13(a, spider, semeMazzi);
							if(tredici && sizeMazzifiniti <= 8)
							{
								cout<<"ENTRATO"<<endl;
								spidertemp.clear();
								for (int i = 0; i < 14; i++)
								{
									if (i == 13)
									{
										al_rest(0.07);
										disegnaColonne (images, cover, spider);
										disegnaMazziFiniti(mazzifiniti, kappa, semeEnd, sizeMazzifiniti, res_x, res_y);
										stampaMazzi (cover, stampamazzo, nummazzi,buttons, sounds, buttons_on, onpause, regoleb, font_timer, (al_get_timer_count(timer)/FPS) - start);
										drawTimer (font_timer, (al_get_timer_count(timer)/FPS) - start);
										al_flip_display();
									}
									else
									{
										disegnaMazziFiniti(mazzifiniti, kappa, semeEnd, sizeMazzifiniti, res_x, res_y);
										draw13(images, colonnatemp2, semeMazzi - 1, i, sizeMazzifiniti, spider.getSizeCol(colonnatemp2) + 13 - i);
										al_rest (0.07);
										stampaMazzi (cover, stampamazzo, nummazzi,buttons, sounds, buttons_on, onpause, regoleb, font_timer, (al_get_timer_count(timer)/FPS) - start);
										drawTimer (font_timer, (al_get_timer_count(timer)/FPS) - start);
										al_flip_display();
									}
								}
								mazzifiniti[sizeMazzifiniti] = true;
								sizeMazzifiniti++;
								semeEnd[sizeEnd] = semeMazzi;
								sizeEnd++;
								tredici = false;
								colonnatemp2 = 0;
							}
						}
					}

					if(tredici && sizeMazzifiniti < 8)
					{
						spidertemp.clear();
						for (int i = 0; i < 14; i++)
						{
							if (i == 13)
							{
								al_rest(0.07);
								disegnaColonne (images, cover, spider);
								disegnaMazziFiniti(mazzifiniti, kappa, semeEnd, sizeMazzifiniti, res_x, res_y);
								stampaMazzi (cover, stampamazzo, nummazzi,buttons, sounds, buttons_on, onpause, regoleb, font_timer, (al_get_timer_count(timer)/FPS) - start);
								drawTimer (font_timer, (al_get_timer_count(timer)/FPS) - start);
								al_flip_display();
							}
							else
							{
								disegnaMazziFiniti(mazzifiniti, kappa, semeEnd, sizeMazzifiniti, res_x, res_y);
								draw13(images, colonnatemp2, semeMazzi - 1, i, sizeMazzifiniti, spider.getSizeCol(colonnatemp2) + 13 - i);
								al_rest (0.07);
								stampaMazzi (cover, stampamazzo, nummazzi,buttons, sounds, buttons_on, onpause, regoleb, font_timer, (al_get_timer_count(timer)/FPS) - start);
								drawTimer (font_timer, (al_get_timer_count(timer)/FPS) - start);
								al_flip_display();
							}
						}
						mazzifiniti[sizeMazzifiniti] = true;
						sizeMazzifiniti++;
						semeEnd[sizeEnd] = semeMazzi;
						sizeEnd++;
						tredici = false;
						colonnatemp2 = 0;
					}
					
					if(flip == false)
					{
						if (regolegame) {
							menu.drawRegole();
						}

						if (exitdialog)
						{
							buttons.drawExitDialog();
							buttons.drawNo(exit_on[0]);
							buttons.drawYes(exit_on[1]);
							for (int i = 0; i < 2; i++)
							{
								exit_on[i] = false;
							}
							
						}
						
						if (vittoria)
						{
							drawVittoria (buttons, win_on, vittoria);
							drawFinalTime(font_timer, (al_get_timer_count(timer)/FPS) - start);
							al_flip_display();
						}

						
						al_flip_display();
					}
					
					
					al_draw_bitmap(sfondo, 0, 0, 0);
					

				}

			}
		}

		if (al_is_event_queue_empty(event_queue))
		{
			menu.drawSfondoMenu();

			if (modmenu[0])
			{
				menu.drawRegole ();
			}

			else if (modmenu[1])
			{
				menu.drawCreditsTab();
			}

			else
			{
				menu.drawUnSeme (menu_on[0]);
				menu.drawDueSemi (menu_on[1]);
				menu.drawQuattroSemi(menu_on[2]);
				menu.drawCredits(menu_on[3]);
				menu.drawModalita ();
			}

			drawMenuButtons(buttons, sounds, buttons_on, menu_on);
			for (int i = 0; i < 5; i++)
			{
				menu_on [i] = false;
			}
			al_flip_display();
		}
	}




	//FINE DEL GIOCO E DISTRUTTORI________________________________
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_font(font_timer);
	al_destroy_bitmap(onpause);
	al_destroy_bitmap(cover);
	al_destroy_event_queue(event_queue);
	return 0;
}
