#include <cstdlib>
#include <iostream>
#include "conio2.h"
#include<windows.h>

using namespace std;

int ile_wierszy = 9;  
int ile_kolumn = 9;   
char tab [9][9];
int tabStart [9][9];
int zaznacz = 0;


void wyswietlanieTablicy ()

{
	
	system("CLS"); // powoduje odswierzanie a nie dopisywanie
	textcolor(7);	

	for (int i = 0; i < odstepGora; i++) cout << endl;

	// gora planszy
	for (int i = 0; i < odstepBok; i++) cout << ' ';
	cout << (char)201 << (char)205 << (char)205 << (char)205 << 
		(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
		(char)205 << (char)205 << (char)205 << (char)203 << (char)205 << 
		(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
		(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
		(char)203 << (char)205 << (char)205 << (char)205 << (char)205 << 
		(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
		(char)205 << (char)205 << (char)187 <<endl;
	
	
	for (int l=0; l<ile_kolumn; l++)
	{
		for (int k=0; k<ile_wierszy/3; k++)
		  {
			  for (int i = 0; i < odstepBok; i++) cout << ' ';
			  cout << (char)186; // ||
			  for (int i=0; i<ile_wierszy; i++)
			  {
					
					if (k % 2 == 1) 
						{
							// oznaczKolor	
							if (zaznacz == 1 && tab [i][l] == aktualna)
							{
								textcolor(12);
								cout << " " << tab [i][l] << " ";							
								textcolor(7);
							}
							
							else 
							{							
								cout << " " << tab [i][l] << " ";
							}
						}

					else cout << "   ";
				  
					if (i % 3 == 2) cout << (char)186; // ||
					else cout << (char)179; // |
		
			  }
			  cout << endl;
		
			  
		  }
		//  dol planszy
		if (l==8) 
		{
			for (int i = 0; i < odstepBok; i++) cout << ' ';
				cout << (char)200 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)202 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)202 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)188 <<endl;
				
		}

		// ==== wiersz srodkowy
		else if (l % 3 == 2) 
		{
			for (int i = 0; i < odstepBok; i++) cout << ' ';
				cout << (char)204 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)206<< 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)206<< (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)205 << (char)205 << 
					(char)205 << (char)205 << (char)205 << (char)185 <<endl;
				
				
		}

		// ---- wiersz srodkowy
		else 
		{
			for (int i = 0; i < odstepBok; i++) cout << ' ';
			cout << (char)186 << (char)196 << (char)196 << (char)196 << 
				(char)197 << (char)196 << (char)196 << (char)196 << (char)197 << 
				(char)196 << (char)196 << (char)196 << (char)186<< (char)196 << 
				(char)196 << (char)196 << (char)197 << (char)196 << (char)196 << 
				(char)196 << (char)197 << (char)196 << (char)196 << (char)196 << 
				(char)186<< (char)196 << (char)196 << (char)196 << (char)197 << 
				(char)196 << (char)196 << (char)196 << (char)197 << (char)196 << 
				(char)196 << (char)196 << (char)186 <<endl;
			
		}
		
	}
	
	zaznacz = 0;


}

