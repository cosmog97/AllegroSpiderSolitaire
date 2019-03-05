//La classe si occupa di riprodurre musica di sottofondo
//e suoni del gioco

#ifndef SOUNDS_H
#define SOUNDS_H

class Sounds
{
	public:
		Sounds (ALLEGRO_DISPLAY *display, char nomegioco[])
		{
			tastimenu = al_load_sample("Data/Sounds/tastimenu.wav");
			if (!tastimenu)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "tastimenu non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			tastigenerale = al_load_sample("Data/Sounds/tastigenerali.wav"); 
			if (!tastigenerale)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "tastigenerali non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			
			prendicarta = al_load_sample("Data/Sounds/prendicarta.wav"); 
			if (!prendicarta)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "prendicarta non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			rilasciacarta = al_load_sample("Data/Sounds/rilasciacarta.wav"); 
			if (!rilasciacarta)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "rilasciacarta non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			mossaerrata = al_load_sample("Data/Sounds/mossaerrata.wav"); 
			if (!mossaerrata)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "mossaerrata non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			vittoria = al_load_sample("Data/Sounds/vittoria.wav");
			if (!vittoria)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "vittoria non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			distribuzionemazzo = al_load_sample("Data/Sounds/distrmazzi.wav");
			if (!distribuzionemazzo)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "distrmazzi non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
		
			colonnasonora = al_load_sample("Data/Sounds/allegro.wav");
			if (!colonnasonora)
			{
				al_show_native_message_box(display, nomegioco, "Errore", "colonnasonora non caricato correttamente.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			}
			
			songInstance = al_create_sample_instance (colonnasonora);
			al_set_sample_instance_playmode (songInstance, ALLEGRO_PLAYMODE_LOOP);
			
		
			music_on = true;
			audio_on = true;
			
			gain = 1.0 ;
			pan = 0.0 ;
			speed = 1.0;
			
		}
		
		void playMusic ()
		{
			if (music_on)
			{
				al_reserve_samples (1);
				al_attach_sample_instance_to_mixer (songInstance, al_get_default_mixer());
				al_play_sample_instance(songInstance);
				
			}
		}
		
		void stopMusic ()
		{
			al_reserve_samples (1);
			al_stop_sample_instance(songInstance);
		}
		
		void playTastoMenu ()
		{
			if (audio_on)
			{
				al_reserve_samples (1);
				al_play_sample (tastimenu, gain, pan, speed, ALLEGRO_PLAYMODE_ONCE, 0);
			}
		}
		
		void playTastoGenerale ()
		{
			if (audio_on)
			{
				al_reserve_samples (1);
				al_play_sample (tastigenerale, gain, pan, speed, ALLEGRO_PLAYMODE_ONCE, 0);
			}
		}
		
		void playPrendiCarta ()
		{
			if (audio_on)
			{
				al_reserve_samples (1);
				al_play_sample (prendicarta, gain, pan, speed, ALLEGRO_PLAYMODE_ONCE, 0);
			}
		}
		
		void playRilascioCarta ()
		{
			if (audio_on)
			{
				al_reserve_samples (1);
				al_play_sample (rilasciacarta, gain, pan, speed, ALLEGRO_PLAYMODE_ONCE, 0);
			}
		}
		
		void playMossaErrata ()
		{
			if (audio_on)
			{
				al_reserve_samples (1);
				al_play_sample (mossaerrata, gain, pan, speed, ALLEGRO_PLAYMODE_ONCE, 0);
			}
		}
		
		void playVittoria ()
		{
			if (audio_on)
			{
				al_reserve_samples (1);
				al_play_sample (vittoria, gain, pan, speed, ALLEGRO_PLAYMODE_ONCE, 0);
			}
		}
		
		void playDistrMazzo ()
		{
			if (audio_on)
			{
				al_reserve_samples (1);
				al_play_sample (distribuzionemazzo, gain, pan, speed, ALLEGRO_PLAYMODE_ONCE, 0);
			}
		}
		
		void setAudio (bool audio)
		{
			audio_on = audio;
		}
		
		void setMusic (bool music)
		{
			music_on = music;
		}
		
		bool getAudio ()
		{
			return audio_on;
		}
	
		bool getMusic ()
		{
			return music_on;
		}
		
	private:
	
		ALLEGRO_SAMPLE* tastimenu;
		ALLEGRO_SAMPLE* tastigenerale;
		ALLEGRO_SAMPLE*	prendicarta;
		ALLEGRO_SAMPLE* rilasciacarta;
		ALLEGRO_SAMPLE* mossaerrata;
		ALLEGRO_SAMPLE* vittoria;
		ALLEGRO_SAMPLE* distribuzionemazzo;
		
		ALLEGRO_SAMPLE* colonnasonora;
		ALLEGRO_SAMPLE_INSTANCE* songInstance;
		
		bool music_on;
		bool audio_on;
		
		float gain;
		float pan;
		float speed;

};

#endif
