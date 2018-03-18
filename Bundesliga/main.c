#include <stdio.h>
#include "bundesliga.h"


void main()
{
	struct Tabellen_Struct t[ANZ];
	struct Ergebnis_Struct e[ANZ/2];
	LiesTabelle("Tabelle.txt", t);

	LiesErgebnis("Ergebnis.txt", e);

	TabelleAusgeben (t);
	printf ("Ergebnisse:\n");
	ErgebnisAusgeben ( e);
	TabelleAktualisieren(t,e);
	printf ("Aktualisierte Tabelle:\n");
	TabelleAusgeben (t);



}