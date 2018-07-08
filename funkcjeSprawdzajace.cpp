#include <cstdlib>
#include <iostream>
#include "conio2.h"
#include<windows.h>
#include <cstdio>
#include <ctime>
using namespace std;


int kwadrat ;
int ruch;
char podpJ[9];
int p;

int sprawdzKomorke (int fi, int fj, char fliczba, int pokaz)
//==================================================================================
// Parametry	: pokaz:
//					0 --> nie pokazuj
//					1 --> pokazuj
// Return		:  1 --> mozna wpisac
//				: -2 --> liczba jest w wierszu
//				: -3 --> liczba jest w kolumnie
//				: -4 --> liczba jest w podkwadracie
//==================================================================================
{
	
	// Spr wiersza
	for (int i = 0; i < 9; i++)
	{
		if (tab[i][fj] == fliczba) 
		{
			if (pokaz == 1) komunikat ("Wartosc wystepuje w wierszu. ");
			return -2;
		}

	}

	// Spr kolumny
	for (int j = 0; j < 9; j++)
	{
		if (tab[fi][j] == fliczba) 
		{
			if (pokaz == 1) komunikat ("Wartosc wystepuje w kolumnie. ");
			return -3;
		}

	}
	//return 1;
	// Spr podkwadratu
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j ++)
		{
			if (fi/3==0 && fj/3==0 && i/3==0 && j/3==0 && tab[i][j] == fliczba)
			{ // kw 1
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}
			if (fi/3==1 && fj/3==0 && i/3==1 && j/3==0 && tab[i][j] == fliczba)
			{ // kw 2
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}
			if (fi/3==2 && fj/3==0 && i/3==2 && j/3==0 && tab[i][j] == fliczba)
			{ // kw 3
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}		
			if (fi/3==0 && fj/3==1 && i/3==0 && j/3==1 && tab[i][j] == fliczba)
			{ // kw 4
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}		
			if (fi/3==1 && fj/3==1 && i/3==1 && j/3==1 && tab[i][j] == fliczba)
			{// kw 5
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}		
			if (fi/3==2 && fj/3==1 && i/3==2 && j/3==1 && tab[i][j] == fliczba)
			{ // kw 6
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}		
			if (fi/3==0 && fj/3==2 && i/3==0 && j/3==2 && tab[i][j] == fliczba)
			{ // kw 7
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}		
			if (fi/3==1 && fj/3==2 && i/3==1 && j/3==2 && tab[i][j] == fliczba) 
			{ // kw 8
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}		
			if (fi/3==2 && fj/3==2 && i/3==2 && j/3==2 && tab[i][j] == fliczba) 
			{ // kw 9
			if (pokaz == 1) komunikat ("Wartosc wystepuje w podkwadracie. ");
			return -4;
			}
		}

	}
	return 1;
}

void komunikat (char ftekst[100])
{
	gotoxy (odstepBok + 1, ostWiersz + 3);
	textcolor(4);
	cout << ftekst << endl << endl;
	textcolor(7);
	system ("PAUSE");
	gotoxy(x, y);

}

void ktoryKwadrat (int fi, int fj)
{
	if (fi/3==0 && fj/3==0) kwadrat = 1;
	if (fi/3==1 && fj/3==0) kwadrat = 2;
	if (fi/3==2 && fj/3==0) kwadrat = 3;
	if (fi/3==0 && fj/3==1) kwadrat = 4;
	if (fi/3==1 && fj/3==1) kwadrat = 5;
	if (fi/3==2 && fj/3==1) kwadrat = 6;
	if (fi/3==0 && fj/3==2) kwadrat = 7;
	if (fi/3==1 && fj/3==2) kwadrat = 8;
	if (fi/3==2 && fj/3==2) kwadrat = 9;
}

int fczas( clock_t czas )
{
    return static_cast < double >( czas ) / CLOCKS_PER_SEC;
}

void save ()
{
	FILE *plik; 
	char nazwa[22]; 
	gotoxy (odstepBok + 1, ostWiersz + 3);
	textcolor(2);
	cout << "Podaj nazwe pliku do zapisu: ";
	cin >> nazwa;
	textcolor(7);
	gotoxy(x, y);
	plik=fopen(nazwa,"w"); 
			
	for(int i = 0; i < 9; i++)
	{
        for(int j = 0; j < 9; j++)
		{
             fprintf(plik,"%c",tab[j][i]);
		}
        fprintf(plik,"\n");
	}
	
	fclose(plik);
}

void load ()
{
	FILE *plik; 
	char nazwa[22]; 
	gotoxy (odstepBok + 1, ostWiersz + 3);
	textcolor(2);
	cout << "Podaj nazwe pliku do odczytu: ";
	cin >> nazwa;
	textcolor(7);
	gotoxy(x, y);
	plik=fopen(nazwa,"r"); 
	if(plik == NULL) 
	{
		komunikat("Plik jest pusty, lub nie istnieje. Program zostanie zamkniety..."); 
		exit(1);
	}
	else 
	{
		
		for(int j = 0; j < 9; j++)
		{
			for(int i = 0; i < 10; i++)
			{
				tab[i][j] = fgetc(plik); 
			}
		}
	}
	fclose(plik);	
}

int podpowiedz (int fi, int fj)
{
	gotoxy(odstepMenuB, odstepMenuG + 34);
	textcolor(2);
	cout << "Podpowiedz: ";
	textcolor(7);
	 for (int l = 49; l < 58; l++)
        {
            if (sprawdzKomorke(fi, fj, l, 0) == 1)
            {
				cout << (char)l << ' ';
            }
        }
	 gotoxy(odstepMenuB, odstepMenuG + 35);
	system ("PAUSE");
	gotoxy(x, y);

	return 0;


}

int podpowiedzJedn ()
{
	for (int j = 0; j < 9; j++)
	{
		for ( int i = 0; i < 9; i++)
		{	
			if (tab[i][j] == ' ')
			{
				 for (int l = 49; l < 58; l++)
					{					
							if (sprawdzKomorke(i, j, l, 0) == 1)
						{
							podpJ[p]= (char)l;
							p++;
						}					
					}
			
				 if (p == 1) 
				 {
					 gotoxy(odstepMenuB, odstepMenuG + 34);
					 textcolor(7);
					 cout << "Nacisnij 'p' aby wpisac: " << podpJ[p-1];
					 gotoxy(poczx + odstepBok + i*4, poczy + odstepGora + j*4);
					 int zatwierdz = 0;
					 zatwierdz = getch();
					 if (zatwierdz == 112) 
					 {
							//tab[i][j] = podpJ[p-1];

							if (tab[i][j] == ' ')
								{
									licznik = licznik + 1;
									maxlicznik = licznik;
									undo[licznik][1] = i;
									undo[licznik][2] = j;
									undo[licznik][3] = ' ';
									undo[licznik][4] = x;
									undo[licznik][5] = y;
								}

								tab[i][j] = podpJ[p-1];		

								licznik = licznik + 1;
								maxlicznik = licznik;
								undo[licznik][1] = i;
								undo[licznik][2] = j;
								undo[licznik][3] = podpJ[p-1];
								undo[licznik][4] = x;
								undo[licznik][5] = y;
							return 0;
					 }
					 else return 0;
				 }
			}
			p = 0;
		}
	}
	return 0;
}


