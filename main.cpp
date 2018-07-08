#include <iostream>
#include "conio2.h"
using namespace std;

	
	int x = poczx + odstepBok, y = poczy + odstepGora; // pozycja kursora na ekranie	
	int zn; // znak wybrany z klawiatury
	int attr = 0, ostKolumna = 35 + odstepBok, ostWiersz = 35 + odstepGora;	
	// liczniki tablicy zaw. dane sudoku
	int i = 0;
	int j = 0;
	int k = 0;
	int undo[500][5];
	// zmienna pamietajaca wykonane ruchy
	// 1 wymiar --> nr ruchu
	// 2 wymiar --> is sudoku
	//          --> js sudoku
	//          --> wpisana liczba
	//          --> x kursora
	//          --> y kursora
	//-----------------------
	// licznik ruchow;
	int licznik, maxlicznik;
	char aktualna = '0';
	char komentarz;
	char kom[10][10][10];
	
	
	
int main()
{	
	settitle("Jakub Szymanski");
	textcolor(7);	
	
	for (int i = 0; i < 9; i ++)
	{
		for (int j = 0; j < 9; j++) tab[i][j] = ' ';
	}

	do {
		
		wyswietlanieTablicy ();
		aktualna = tab[i][j];

		gotoxy(odstepMenuB, odstepMenuG + 1);
		cout << "Ilosc ruchow: " << licznik / 2;
		gotoxy(odstepMenuB, odstepMenuG + 3);
		cout << "Czas gry: "<< fczas( clock()) << " sekund";
		gotoxy(odstepMenuB, odstepMenuG + 5);
		cout << "Poloznie: "<< i+1 << ":" << j+1 ;
		cout << ",  Kwadrat: ";
		ktoryKwadrat (i, j);
		cout << kwadrat;
		gotoxy(odstepMenuB, odstepMenuG + 7);
		cputs("Strzalki = Poruszanie");
		gotoxy(odstepMenuB, odstepMenuG + 9);
		cputs("1-9 = Wstawienie lub");
		gotoxy(odstepMenuB, odstepMenuG + 10);
		cputs("nadpisanie cyfry");
		gotoxy(odstepMenuB, odstepMenuG + 12);
		cputs("Backspace = usuniecie cyfry");	
		gotoxy(odstepMenuB, odstepMenuG + 14);
		cputs("U = Undo");	
		gotoxy(odstepMenuB, odstepMenuG + 16);
		cputs("R = Redo");
		gotoxy(odstepMenuB, odstepMenuG + 18);
		cputs("L = Lista mozliwych cyfr");	
		gotoxy(odstepMenuB, odstepMenuG + 20);
		cputs("P = Podpowiedz jednoznaczna");
		gotoxy(odstepMenuB, odstepMenuG + 22);
		cputs("S = zapisanie do pliku");
		gotoxy(odstepMenuB, odstepMenuG + 24);
		cputs("O = odczyt z pliku");
		gotoxy(odstepMenuB, odstepMenuG + 26);
		cputs("K = Edytuj komentarz");	
		gotoxy(odstepMenuB, odstepMenuG + 28);
		cputs("Spacja = Zaznaczenie takich");
		gotoxy(odstepMenuB, odstepMenuG + 29);
		cputs("samych cyfr");
		gotoxy(odstepMenuB, odstepMenuG + 31);
		textcolor(2);
		cout << "Komentarz: ";
		gotoxy(odstepMenuB, odstepMenuG + 32);
		textcolor(7);
		cout << '|';
		for (int k = 0; k < 9; k++) cout << kom[i][j][k] << '|';
	
		gotoxy(odstepMenuB, odstepMenuG + 37);
		cputs("Esc = Wyjscie");			

		gotoxy(x, y);
		textcolor(attr);
		zn = getch();
		
		
		switch (zn)
          {
          case 77 :   // w prawo
                     x = x + 4;
					 i = i ++;
					 if (x > ostKolumna) 
						{
							 x = poczx + odstepBok; 
							 i = 0;
						}						 
					 break;
          case 75 :   // w lewo
                     x = x - 4;
					 i = i --;					 
                     if (x < poczx + odstepBok) 
						{
							x = ostKolumna;
							i = 8;
						}					 
					 break;
          case 72 :   // do gory
                     y = y - 4;
					 j = j --;					 
                     if (y < poczy + odstepGora) 
						 {
							y = ostWiersz;
							j = 8;
						 }

                     break;
          case 80 :   // w dol
                     y = y + 4;
					 j = j ++;					 
					 if (y > ostWiersz) 
						 {
							 y = poczy + odstepGora;
							 j = 0;
						 }					  
                     break;

		  case ' ' :   // oznaczKolor					
					zaznacz = 1;
					break;

			case 8:		//backspace
			
					tab[i][j] = ' ';

					licznik = licznik + 1;
					maxlicznik = licznik;
					undo[licznik][1] = i;
					undo[licznik][2] = j;
					undo[licznik][3] = ' ';
					undo[licznik][4] = x;
					undo[licznik][5] = y;
					break;

			case 49: // 1
			case 50:
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
			case 56:
			case 57: // 9	
				if (sprawdzKomorke (i, j, zn, 1) == 1)
				{	
					licznik = licznik + 1;
					if (tab[i][j] == ' ')
					{
						
						maxlicznik = licznik;
						undo[licznik][1] = i;
						undo[licznik][2] = j;
						undo[licznik][3] = ' ';
						undo[licznik][4] = x;
						undo[licznik][5] = y;
					}
					
					tab[i][j] = zn;		

					licznik = licznik + 1;
					maxlicznik = licznik;
					undo[licznik][1] = i;
					undo[licznik][2] = j;
					undo[licznik][3] = zn;
					undo[licznik][4] = x;
					undo[licznik][5] = y;						
				}				 
				break;
			
			case 117:// undo "u"		
				if (licznik > 1)
					{	
						licznik = licznik - 1;
						tab[undo[licznik][1]][undo[licznik][2]] = undo[licznik][3];
						if (licznik > 1)
						{
							if (undo[licznik][3] == ' ') licznik = licznik - 1;
							tab[undo[licznik][1]][undo[licznik][2]] = undo[licznik][3];			
							i = undo[licznik][1];
							j = undo[licznik][2];
							x = undo[licznik][4];
							y = undo[licznik][5];					
						}
					}
					
				break;
			
			case 114:// redo "r"
				 if (licznik < maxlicznik)
					{
						licznik = licznik + 1;
						tab[undo[licznik][1]][undo[licznik][2]] = undo[licznik][3];
						if (undo[licznik][3] == ' ') licznik = licznik + 1;
						tab[undo[licznik][1]][undo[licznik][2]] = undo[licznik][3];			
						i = undo[licznik][1];
						j = undo[licznik][2];
						x = undo[licznik][4];
						y = undo[licznik][5];			
						
					}
				break;
				
			case 115: // save 's'
				save ();
				break;
				
			case 111: // odczyt 'o'
				load ();
				break;
				
			case 107: // wpisanie komentarza 'k'
				gotoxy(odstepMenuB, odstepMenuG + 31);
				textcolor(2);
				cout << "Komentarz: ";
				textcolor(7);
				for (int k = 0; k < 9; k++)
				{
					
					gotoxy(odstepMenuB + 1 + k*2, odstepMenuG + 32);
					textcolor(7);
					komentarz = getch();
					cout << komentarz;
					kom[i][j][k] = komentarz;	
					
				}
				gotoxy(poczx + odstepBok, poczy + odstepGora);
				break;
				  
			case 108: // podpowiedz 'l'
				podpowiedz (i, j);
				break;

			case 112: // podpowiedz jednoznaczna 'p'
				podpowiedzJedn ();
				break;
          }
		

	} while (zn != 27); //esc
	gotoxy (odstepBok + 1, ostWiersz + 4);
	

	return 0;
}


						
						
						
						
						