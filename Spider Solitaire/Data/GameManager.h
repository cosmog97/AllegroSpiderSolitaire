/*
Astrazione delle 10 colonne del gioco
e dei 5 mazzi rimanenti
*/


#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Deck.h"
#include <list>
using namespace std;

class GameManager 
{
	public:
		GameManager ()
		{
			
		}

		GameManager (const GameManager & right)
		{
			colonna1 = right.colonna1;
			colonna2 = right.colonna2;
			colonna3 = right.colonna3;
			colonna4 = right.colonna4;
			colonna5 = right.colonna5;
			colonna6 = right.colonna6;
			colonna7 = right.colonna7;
			colonna8 = right.colonna8;
			colonna9 = right.colonna9;
			colonna10 = right.colonna10;
			mazzo1 = right.mazzo1;
			mazzo2 = right.mazzo2;
			mazzo3 = right.mazzo3;
			mazzo4 = right.mazzo4;
			mazzo5 = right.mazzo5;
			
		}
		
		vector<Card> getColonna(int col) //data l'indice colonna, ritorna il vector relativo
		{
			switch(col)
			{
				case 1:
					{
						return colonna1;
						break;
					}
				case 2:
					{
						return colonna2;
						break;
					}
				case 3:
					{
						return colonna3;
						break;
					}
				case 4:
					{
						return colonna4;
						break;
					}
				case 5:
					{
						return colonna5;
						break;
					}
				case 6:
					{
						return colonna6;
						break;
					}
				case 7:
					{
						return colonna7;
						break;
					}
				case 8:
					{
						return colonna8;
						break;
					}
				case 9:
					{
						return colonna9;
						break;
					}
				case 10:
					{
						return colonna10;
						break;
					}
				default:
					break;
			}
		}
		
		bool push_backCartaCol (Card carta, unsigned numcol)  //inserisce in ultima posizione una carta in numcol vector
		{
			switch (numcol)
			{
				case 1:
					{
						colonna1.push_back(carta);
						return true;
					}
				case 2:
					{
						colonna2.push_back(carta);
						return true;
					}
				case 3:
					{
						colonna3.push_back(carta);
						return true;
					}
				case 4:
					{
						colonna4.push_back(carta);
						return true;
					}
				case 5:
					{
						colonna5.push_back(carta);
						return true;
					}
				case 6:
					{
						colonna6.push_back(carta);
						return true;
					}
				case 7:
					{
						colonna7.push_back(carta);
						return true;
					}
				case 8:
					{
						colonna8.push_back(carta);
						return true;
					}
				case 9:
					{
						colonna9.push_back(carta);
						return true;
					}
				case 10:
					{
						colonna10.push_back(carta);
						return true;
					}
				case 11:
					{
						mazzo1.push_back(carta);
						return true;
					}
				case 12:
					{
						mazzo2.push_back(carta);
						return true;
					}
				case 13:
					{
						mazzo3.push_back(carta);
						return true;
					}	
				case 14:
					{
						mazzo4.push_back(carta);
						return true;
					}
				case 15:
					{
						mazzo5.push_back(carta);
						return true;
					}
				default:
					return false;
			}
		}
		
		void eraseCartaColPos ( unsigned numcol, unsigned pos) //cancella una carta, dato il numero di colonna e posizione in essa
		{
			switch (numcol)
			{
				case 1:
					{
						vector<Card>:: iterator it=colonna1.begin()+pos;
						colonna1.erase(it);
						break;
					}
				case 2:
					{
						vector<Card>:: iterator it=colonna2.begin()+pos;
						colonna2.erase(it);
						break;
					}
				case 3:
					{			
						vector<Card>:: iterator it=colonna3.begin()+pos;
						colonna3.erase(it);
						break;
					}
				case 4:
					{
						vector<Card>:: iterator it=colonna4.begin()+pos;
						colonna4.erase(it);
						break;
					}
				case 5:
					{
						vector<Card>:: iterator it=colonna5.begin()+pos;
						colonna5.erase(it);
						break;
					}
				case 6:
					{
						vector<Card>:: iterator it=colonna6.begin()+pos;
						colonna6.erase(it);
						break;
					}
				case 7:
					{
						vector<Card>:: iterator it=colonna7.begin()+pos;
						colonna7.erase(it);
						break;
					}
				case 8:
					{
						vector<Card>:: iterator it=colonna8.begin()+pos;
						colonna8.erase(it);
						break;
					}
				case 9:
					{
						vector<Card>:: iterator it=colonna9.begin()+pos;
						colonna9.erase(it);
						break;
					}	
				case 10:
					{
						vector<Card>:: iterator it=colonna10.begin()+pos;
						colonna10.erase(it);
						break;
					}
				default:
					{
						break;
					}
			}
		}
		
		bool eraseCartaCol (Card carta, unsigned numcol) //cancella le carte dello stesso valore/seme, data una carta e la colonna
		{
			int x = carta.getValore();
			int y = carta.getSeme ();
			switch (numcol)
			{
				case 1:
					{
						for (vector<Card>:: iterator it=colonna1.begin(); it<colonna1.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna1.erase(it);
								return true;
							}
						}
						return false;
					}
				case 2:
					{
						for (vector<Card>:: iterator it=colonna2.begin(); it<colonna2.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna2.erase(it);
								return true;
							}
						}
						return false;
					}
				case 3:
					{
						for (vector<Card>:: iterator it=colonna3.begin(); it<colonna3.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna3.erase(it);
								return true;
							}
						}
						return false;
					}
				case 4:
					{
						for (vector<Card>:: iterator it=colonna4.begin(); it<colonna4.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna4.erase(it);
								return true;
							}
						}
						return false;
					}
				case 5:
					{
						for (vector<Card>:: iterator it=colonna5.begin(); it<colonna5.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna5.erase(it);
								return true;
							}
						}
						return false;
					}
				case 6:
					{
						for (vector<Card>:: iterator it=colonna6.begin(); it<colonna6.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna6.erase(it);
								return true;
							}
						}
						return false;
					}
				case 7:
					{
						for (vector<Card>:: iterator it=colonna7.begin(); it<colonna7.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna7.erase(it);
								return true;
							}
						}
						return false;
					}
				case 8:
					{
						for (vector<Card>:: iterator it=colonna8.begin(); it<colonna8.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna8.erase(it);
								return true;
							}
						}
						return false;
					}
				case 9:
					{
						for (vector<Card>:: iterator it=colonna9.begin(); it<colonna9.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna9.erase(it);
								return true;
							}
						}
						return false;
					}	
				case 10:
					{
						for (vector<Card>:: iterator it=colonna10.begin(); it<colonna10.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								colonna10.erase(it);
								return true;
							}
						}
						return false;
					}
				case 11:
					{
						for (vector<Card>:: iterator it=mazzo1.begin(); it<mazzo1.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								mazzo1.erase(it);
								return true;
							}
						}
						return false;
					}
				case 12:
					{
						for (vector<Card>:: iterator it=mazzo2.begin(); it<mazzo2.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								mazzo2.erase(it);
								return true;
							}
						}
						return false;
					}
				case 13:
					{
						for (vector<Card>:: iterator it=mazzo3.begin(); it<mazzo3.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								mazzo3.erase(it);
								return true;
							}
						}
						return false;
					}	
				case 14:
					{
						for (vector<Card>:: iterator it=mazzo4.begin(); it<mazzo4.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								mazzo4.erase(it);
								return true;
							}
						}
						return false;
					}
				case 15:
					{
						for (vector<Card>:: iterator it=mazzo5.begin(); it<mazzo5.end(); it++)
						{
							if (it->getValore() == x && it->getSeme() == y)
							{
								mazzo5.erase(it);
								return true;
							}
						}
						return false;
					}	
				default:
					return false;
			}
		}
		
		unsigned getSizeCol (unsigned nomcol) //restituisce la size dei vari vector
		{
			switch (nomcol)
			{
				case 1:
					return colonna1.size();
				case 2:
					return colonna2.size();
				case 3:
					return colonna3.size();
				case 4:
					return colonna4.size();
				case 5:
					return colonna5.size();
				case 6:
					return colonna6.size();
				case 7:
					return colonna7.size();
				case 8:
					return colonna8.size();
				case 9:
					return colonna9.size();
				case 10:
					return colonna10.size();
				case 11:
					return mazzo1.size();
				case 12:
					return mazzo2.size();
				case 13:
					return mazzo3.size();
				case 14:
					return mazzo4.size();
				case 15:
					return mazzo5.size();
			}
		}
		
		void setCartaCoperta (int colon, int pos, bool cop)
		{
			switch (colon)
			{
				case 1:
					{
						colonna1[pos].setCoperta (cop);
						break;
					}
				case 2:
					{
						colonna2[pos].setCoperta (cop);
						break;
					}
				case 3:
					{
						colonna3[pos].setCoperta (cop);
						break;
					}						
				case 4:
					{
						colonna4[pos].setCoperta (cop);
						break;
					}
				case 5:
					{
						colonna5[pos].setCoperta (cop);
						break;
					}
				case 6:
					{
						colonna6[pos].setCoperta (cop);
						break;
					}
				case 7:
					{
						colonna7[pos].setCoperta (cop);
						break;
					}
				case 8:
					{
						colonna8[pos].setCoperta (cop);
						break;
					}
				case 9:
					{
						colonna9[pos].setCoperta (cop);
						break;
					}
				case 10:
					{
						colonna10[pos].setCoperta (cop);
						break;
					}
				case 11:
					{
						mazzo1[pos].setCoperta (cop);
						break;
					}
				case 12:
					{
						mazzo2[pos].setCoperta (cop);
						break;
					}
				case 13:
					{
						mazzo3[pos].setCoperta (cop);
						break;
					}
				case 14:
					{
						mazzo4[pos].setCoperta (cop);
						break;
					}
				case 15:
					{
						mazzo5[pos].setCoperta (cop);
						break;
					}
			}
		}
		
		Card ritornaCarta (int colon, int pos) 
		{
			switch (colon)
			{
				case 1:
					return colonna1[pos];
				case 2:
					return colonna2[pos];
				case 3:
					return colonna3[pos];
				case 4:
					return colonna4[pos];
				case 5:
					return colonna5[pos];
				case 6:
					return colonna6[pos];
				case 7:
					return colonna7[pos];
				case 8:
					return colonna8[pos];
				case 9:
					return colonna9[pos];
				case 10:
					return colonna10[pos];
				case 11:
					return mazzo1[pos];
				case 12:
					return mazzo2[pos];
				case 13:
					return mazzo3[pos];
				case 14:
					return mazzo4[pos];
				case 15:
					return mazzo5[pos];
			}
		}
		
		void eraseFrom(int pos, int col)
		{
				switch (col)
			{
				case 1:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna1.pop_back();
						}
						break;
					}
				case 2:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna2.pop_back();
						}
						break;
					}
				case 3:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna3.pop_back();
						}
						break;
					}
				case 4:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna4.pop_back();
						}
						break;
					}
				case 5:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna5.pop_back();
						}
						break;					
					}
				case 6:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna6.pop_back();
						}
						break;
					}
				case 7:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna7.pop_back();
						}
						break;
					}
				case 8:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna8.pop_back();
						}
						break;
					}
				case 9:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna9.pop_back();
						}
						break;
					}
				case 10:
					{
						for (int i = 0; i < pos; i++)
						{
								colonna10.pop_back();
						}
						break;
					}
				default:
					break;
			}
		}
		
	private:
		vector <Card> colonna1;           //1
		vector <Card> colonna2;			  //2
		vector <Card> colonna3;			  //3
		vector <Card> colonna4;			  //4
		vector <Card> colonna5;			  //5
		vector <Card> colonna6;			  //6
		vector <Card> colonna7;			  //7
		vector <Card> colonna8;			  //8
		vector <Card> colonna9;			  //9
		vector <Card> colonna10;		  //10
		vector <Card> mazzo1;             //11
		vector <Card> mazzo2;             //12
		vector <Card> mazzo3;             //13
		vector <Card> mazzo4;             //14
		vector <Card> mazzo5;             //15
};

#endif
