#include <cstdio>
#include <ctime>

#ifndef _CONIO2_H
#define _CONIO2_H

#define BLACK		0
#define BLUE		1
#define GREEN		2
#define CYAN		3
#define RED			4
#define MAGENTA		5
#define BROWN		6
#define LIGHTGRAY	7
#define DARKGRAY	8
#define LIGHTBLUE	9
#define LIGHTGREEN	10
#define LIGHTCYAN	11
#define LIGHTRED	12
#define LIGHTMAGENTA	13
#define YELLOW		14
#define WHITE		15

#define _NOCURSOR	0
#define _SOLIDCURSOR	1
#define _NORMALCURSOR	2

#ifndef EOF
#define EOF		-1
#endif

#define LASTMODE	-1
#define C80		3
#define C4350		8
#define FULLSCREEN	0x8000

extern int _wscroll;		// 1 = enable scroll
				// 0 = disable scroll

struct text_info {
	unsigned char curx;
	unsigned char cury;
	unsigned short attribute;
	unsigned short normattr;
	unsigned char screenwidth;
	unsigned char screenheight;
	};

// ---------------------------------------
void wyswietlanieTablicy ();
#define odstepMenuB 45
#define odstepMenuG 3
#define odstepBok 3
#define odstepGora 3
#define poczx 3
#define poczy 3

extern char tab [9][9];
extern int tabStart [9][9];
extern char kom[10][10][10];
extern int i;
extern int j;
extern int k;
extern int x;
extern int y;
extern int ostWiersz;
extern int ostKolumna;
extern int kwadrat;
extern int zn;
extern int ruch;
extern char aktualna;
extern int zaznacz;
extern int undo[500][5];
extern int licznik, maxlicznik;

int sprawdzKomorke (int fi, int fj, char fliczba, int pokaz);
void komunikat (char f_tekst[100]);
void ktoryKwadrat (int fi, int fj);
int fczas( clock_t czas );
void save ();
void load ();
int podpowiedz (int fi, int fj);
int podpowiedzJedn ();

// ----------------------------------------

#ifdef __cplusplus
extern "C" {
#endif
void gotoxy(int x, int y);
int wherex(void);
int wherey(void);
void _setcursortype(int cur_t);

void textattr(int newattr);
void textbackground(int newcolor);
void textcolor(int newcolor);

void clreol(void);
void clrscr(void);
void delline(void);
void insline(void);

int getch(void);
int getche(void);
int kbhit(void);
int ungetch(int ch);

int cputs(const char *str);
int putch(int c);

int gettext(int left, int top, int right, int bottom, void *dest);
int movetext(int left, int top, int right, int bottom, int destleft, int desttop);
int puttext(int left, int top, int right, int bottom, void *source);

void gettextinfo(struct text_info *info);

void textmode(int mode);

// bonus functions
void settitle(const char *title);
#ifdef __cplusplus
}
#endif

#endif
