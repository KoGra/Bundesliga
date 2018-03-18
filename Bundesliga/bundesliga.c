#include "bundesliga.h"
#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)

int LiesTabelle(char filename[], struct Tabellen_Struct t[])
{
	FILE *fp;
	int i;
	fp = fopen (filename, "r");
	if (fp == NULL)
		return 0;

	for (i=0; i<ANZ; i++)
	{
		fscanf (fp,"%s %d %d %d %d %d %d %d", t[i].Verein, &t[i].Spiele, &t[i].Siege, &t[i].Unentschieden,
			&t[i].Niederlagen, &t[i].Tore_Geschossen, &t[i].Tore_Erhalten, &t[i].Punkte);

	}
	fclose (fp);
	return 1;

}


int LiesErgebnis(char filename[], struct Ergebnis_Struct e[])
{
	FILE *fp;
	int i;
	fp = fopen (filename, "r");
	if (fp == NULL)
		return 0;

	for (i=0; i<ANZ/2; i++)
	{
		fscanf (fp,"%s %s %d %d",e[i].Verein1, e[i].Verein2, &e[i].Tore1, &e[i].Tore2);

	}
	fclose (fp);
	return 1;

}


void TabelleAktualisieren(struct Tabellen_Struct t[],struct Ergebnis_Struct e[])
{
	int i,j;

	for (i=0; i<ANZ/2; i++)
	{
		for (j=0; j<ANZ; j++)
		{
			if (strcmp (t[j].Verein, e[i].Verein1) == 0)
			{

				t[j].Spiele++;
				if (e[i].Tore1 > e[i].Tore2)
				{
					t[j].Siege++;
					t[j].Punkte+=3;
				}
				if (e[i].Tore1 == e[i].Tore2)
				{
					t[j].Unentschieden++;
					t[j].Punkte+=1;
				}
				if (e[i].Tore1 < e[i].Tore2)
				{
					t[j].Niederlagen++;
				}
				t[j].Tore_Geschossen += e[i].Tore1;
				t[j].Tore_Erhalten += e[i].Tore2;
			}

			if (strcmp (t[j].Verein, e[i].Verein2) == 0)
			{
				t[j].Spiele++;
				if (e[i].Tore1 > e[i].Tore2)
				{
					t[j].Niederlagen++;
				}
				if (e[i].Tore1 == e[i].Tore2)
				{
					t[j].Unentschieden++;
					t[j].Punkte+=1;

				}
				if (e[i].Tore1 < e[i].Tore2)
				{
					t[j].Punkte+=3;

					t[j].Siege++;
				}
				t[j].Tore_Geschossen += e[i].Tore2;
				t[j].Tore_Erhalten += e[i].Tore1;
			}
		}
	}


}


void TabelleAusgeben (struct Tabellen_Struct t[])
{
	int i;
	for (i=0; i< ANZ; i++)
	{
		printf ("%25s %3d %3d %3d %3d %3d %3d %3d\n", t[i].Verein, t[i].Spiele, t[i].Siege, t[i].Unentschieden,
			t[i].Niederlagen, t[i].Tore_Geschossen, t[i].Tore_Erhalten, t[i].Punkte);



	}
}



void ErgebnisAusgeben (struct Ergebnis_Struct e[])
{
	int i;
	for (i=0; i< ANZ/2; i++)
	{
		printf ("%25s %25s %3d %3d\n", e[i].Verein1, e[i].Verein2, e[i].Tore1, e[i].Tore2);



	}
}