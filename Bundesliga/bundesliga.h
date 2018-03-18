
#define ANZ 18

struct Tabellen_Struct
{
	char Verein[50];
	int Spiele;
	int Siege;
	int Unentschieden;
	int Niederlagen;
	int Tore_Geschossen;
	int Tore_Erhalten;
	int Punkte;
};

struct Ergebnis_Struct
{
	char Verein1[50];
	char Verein2[50];
	int Tore1;
	int Tore2;

};

int LiesTabelle(char filename[], struct Tabellen_Struct t[]);

int LiesErgebnis(char filename[], struct Ergebnis_Struct e[]);

void TabelleAusgeben (struct Tabellen_Struct t[]);

void TabelleAktualisieren(struct Tabellen_Struct t[],struct Ergebnis_Struct e[]);

void ErgebnisAusgeben (struct Ergebnis_Struct e[]);