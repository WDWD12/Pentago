#include <iostream>
#include <string>


using namespace std;

const int szep = 32; //szerokosc planszy
const int wysp = 21; //wysokosc planszy
const char pion = 0xB3; // │
const char pion2 = 0xBA; //║
const char poziom = 0xc4; // ─
const char poziom2 = 0xCD; //═
const char srodek = 0xC5; // ┼
const char srodek2 = 0xCE; //╬
const char lacznikprawo = 0xC3; // ├
const char laczniklewo = 0xB4; // ┤
const char laczniklewo2 = 0xB9; // ╣
const char lacznikprawo2 = 0xCC; // ╠
const char prawygornyrog = 0xBF; // ┐
const char lewygornyrog = 0xDA;  // ┌
const char lewydolnyrog = 0xC0; // └
const char prawydolnyrog = 0xD9; // ┘
const char lacznikdol = 0xC1;  // ┴
const char lacznikgora = 0xC2;  // ┬
const char lacznikgora2 = 0xCB; // ╦
const char lacznikdol2 = 0xCA; // ╩
const char lewygornyrog2 = 0xC9; // ╔
const char prawygornyrog2 = 0xBB; // ╗
const char lewydolnyrog2 = 0xC8; // ╚
const char prawydolnyrog2 = 0xBC; //╝
const char krzyzyk = 0x58; //X
const char kolko = 0x4F; //O
const char sigma = 0x15; //§
const char slonce = 0x0F; //☼

struct gracze {
	string imie;
	char token;
};
//wywołanie funckji przed ich wystapiniem 
void ktogra(int rodzajgracza, gracze tablica[]);
void pauza();
void swapzetonow(char q[3][3], char w[3][3], char a[3][3], char s[3][3], char zetonwczesniej, char zetonteraz);
void goraramki(){//rysowanie 1 wiersza ramki
	cout << lewygornyrog2 << poziom2;
	for (int i = 1; i < szep; i++)
		if (i == szep / 2)
			cout << lacznikgora2;
		else
		{
			cout << poziom2;
		}
	cout << poziom2 << prawygornyrog2;
	cout << endl;
}
void gora_tabeli() {//rysowanie gory tabeli
	cout << pion2 << lewygornyrog;
	for (int i = 1; i <= (szep / 2) - 2; i++)
		if (i % (((szep / 2) - 1) / 3) == 0)
			cout << lacznikgora;
		else
		{
			cout << poziom;
		}
	cout << prawygornyrog << pion2 << lewygornyrog;
	for (int i = 1; i <= (szep / 2) - 2; i++)
		if (i % (((szep / 2) - 1) / 3) == 0)
			cout << lacznikgora;
		else
		{
			cout << poziom;
		}
	cout << prawygornyrog << pion2 << endl;
}
void kreski_poziome(char tab1[3][3], char tab2[3][3], int numerwiersza) {//rysowanie srodkowej czesci planszy wraz z jej uzupelnieniem 
	cout << pion2 << pion;
	int pomoc = 0;
	for (int i = 1; i < (szep / 2) - 1; i++)
		if (i % (((szep / 2) - 1) / 3) == 0) {
			cout << pion;
			pomoc += 1;
		}
		else
		{
			cout << tab1[numerwiersza][pomoc];
		}
	cout << pion << pion2;
	cout << pion;
	pomoc = 0;
	for (int i = 1; i < (szep / 2) - 1; i++)
		if (i % (((szep / 2) - 1) / 3) == 0) {
			cout << pion;
			pomoc += 1;
		}
		else
		{
			cout << tab2[numerwiersza][pomoc];
		}
	cout << pion << pion2 << endl;
}
void krzyze_poziome() {//rysowanie kresek oddzielajacych kwadraty na planszy
	cout << pion2 << lacznikprawo;
	for (int i = 1; i < (szep / 2) - 1; i++)
		if (i % (((szep / 2) - 1) / 3) == 0)
			cout << srodek;
		else
		{
			cout << poziom;
		}
	cout << laczniklewo << pion2;
	cout << lacznikprawo;
	for (int i = 1; i < (szep / 2) - 1; i++)
		if (i % (((szep / 2) - 1) / 3) == 0)
			cout << srodek;
		else
		{
			cout << poziom;
		}
	cout << laczniklewo << pion2 << endl;
}
void dol_tabeli() {//rysowanie dolnej czesci tabeli
	cout << pion2 << lewydolnyrog;
	for (int i = 1; i < (szep / 2) - 1; i++)
		if (i % (((szep / 2) - 1) / 3) == 0)
			cout << lacznikdol;
		else
		{
			cout << poziom;
		}
	cout << prawydolnyrog << pion2;
	cout << lewydolnyrog;
	for (int i = 1; i < (szep / 2) - 1; i++)
		if (i % (((szep / 2) - 1) / 3) == 0)
			cout << lacznikdol;
		else
		{
			cout << poziom;
		}
	cout << prawydolnyrog << pion2 << endl;
}
void przerwa_pozioma() {//srodek tabeli (oddzielenie ruchowych czesci)
	cout << lacznikprawo2;
	for (int i = 0; i < szep; i++)
		if (i == szep / 2)
			cout << srodek2;
		else
		{
			cout << poziom2;
		}
	cout << poziom2 << laczniklewo2 << endl;
}
void dolramki() {//rysowanie dolnej czesci ramki
	cout << lewydolnyrog2 << poziom2;
	for (int i = 1; i < szep; i++)
		if (i == szep / 2)
			cout << lacznikdol2;
		else
		{
			cout << poziom2;
		}
	cout << poziom2 << prawydolnyrog2 << endl;
}
void plansza_kik(char q[3][3], char w[3][3], char a[3][3], char s[3][3],int rodzajgracza,gracze tablica[]) {//funkcja rysujaca cala plansze i wyswietlajaca graczy i zetony 
	goraramki();
	gora_tabeli();
	kreski_poziome(q, w, 0);
	krzyze_poziome();
	kreski_poziome(q, w, 1);
	krzyze_poziome();
	kreski_poziome(q, w, 2);
	dol_tabeli();
	przerwa_pozioma();
	gora_tabeli();
	kreski_poziome(a, s, 0);
	krzyze_poziome();
	kreski_poziome(a, s, 1);
	krzyze_poziome();
	kreski_poziome(a, s, 2);
	dol_tabeli();
	dolramki();
	ktogra(rodzajgracza,tablica);//tutaj wypisuje gracza i zeton
}
void menu() {//wyswietlanie mozliwych akcji wykonywanych przez program
	cout << "q,w,a,s - wybor czesci planszy odpowiednio: lewej gornej, prawej gornej, lewej dolnej, prawej dolnej" << endl;
	cout << "1..9 - wybor pola na czesci planszy jak na klawiaturze numerycznej tj. 1 to dolne lewe pole" << endl;
	cout << "z,x - obrot odpowiednio: zgodnie z ruchem wskazowek zegara, odwrotnie do ruchu wskazowek" << endl;
	cout << "p  pauza" << endl;
	cout << "v zamiana zetonow" << endl;
}
void dzialanietablicy(char tab[3][3],char q[3][3], char w[3][3], char a[3][3], char s[3][3], gracze tablica[], int rodzajgracza,char pozycja) {
	//funkcja ktora sprawdza czy w dane miejsce na planszy mozemy wpisac nowy zeton oraz pozwala wybrac miejsce na ktorym chcemy polozyc zeton
	if (pozycja == '1' and tab[2][0] == ' ')
		tab[2][0] = tablica[rodzajgracza].token;
	else if (pozycja == '2' and tab[2][1] == ' ')
		tab[2][1] = tablica[rodzajgracza].token;
	else if (pozycja == '3' and tab[2][2] == ' ')
		tab[2][2] = tablica[rodzajgracza].token;
	else if (pozycja == '4' and tab[1][0] == ' ')
		tab[1][0] = tablica[rodzajgracza].token;
	else if (pozycja == '5' and tab[1][1] == ' ')
		tab[1][1] = tablica[rodzajgracza].token;
	else if (pozycja == '6' and tab[1][2] == ' ')
		tab[1][2] = tablica[rodzajgracza].token;
	else if (pozycja == '7' and tab[0][0] == ' ')
		tab[0][0] = tablica[rodzajgracza].token;
	else if (pozycja == '8' and tab[0][1] == ' ')
		tab[0][1] = tablica[rodzajgracza].token;
	else if (pozycja == '9' and tab[0][2] == ' ')
		tab[0][2] = tablica[rodzajgracza].token;
	else
	{
		system("cls");
		cout << "Zla pozycja, podaj nowa (cyfry od 1 do 9 lub p): " << endl;
		cin >> pozycja;
		dzialanietablicy(tab,q,w,a,s, tablica, rodzajgracza, pozycja);
	}
}
int tura(int& rodzajgracza) {//funkcja ktora co obrot while zmienia strukture na 2 gracza
	if (rodzajgracza == 1) 
		rodzajgracza = 0;
	else { 
		rodzajgracza = 1; 
	}
	return rodzajgracza;

}
void pauza() {//funkcja pozwalajaca zatrzymac gre podczas wykonywanego ruchu
	char pauza;
	system("cls");
	cout << "PAUZA aby kontynuwac nacisnij P: " << endl;
	cin >> pauza;
	while (pauza !='P')
	{
		system("cls");
		cout << "Zly znak podaj poprawny (P): " << endl;
		cin >> pauza;
	}
	if (pauza == 'P')
		system("cls");
}
void wymianazetonow(char q[3][3], char w[3][3], char a[3][3], char s[3][3],int rodzajgracza, gracze tablica[]) {
	//zamiana zetonow graczy podczas gry  
	int tab = rodzajgracza;
	tab = tura(tab);
	char zetonwczesniej = tablica[rodzajgracza].token;
	string zetongracza;
	char zetongracza2 = tablica[tab].token;
	char tokeny[4] = { kolko,krzyzyk,sigma,slonce };
	system("cls");
	cout << "Wybierz zeton(1,4): "<< endl;
	for (int i = 0; i < 4; i++)
		if (tokeny[i] != zetongracza2)
			cout << i+1 << ": " << tokeny[i] << endl;
	cin >> zetongracza;
	while (zetongracza[0] < '1' or zetongracza[0] > '4' or zetongracza.size() != 1 or tokeny[zetongracza[0] - '1'] == zetongracza2) {
		cout << "Zly zeton wybierz poprawny(1,4): " << endl;
		cin >> zetongracza;
	}
	tablica[rodzajgracza].token = tokeny[zetongracza[0] - '1'];
	char zetonteraz = tablica[rodzajgracza].token;
	swapzetonow(q, w, a, s, zetonwczesniej, zetonteraz);
	system("cls");
}
void swapzetonow(char q[3][3], char w[3][3], char a[3][3], char s[3][3],char zetonwczesniej, char zetonteraz) {
	//podmaina zetoonow na tablicy na nowe wybrane podczas gry 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (q[i][j] == zetonwczesniej)
				q[i][j] = zetonteraz;
			if (w[i][j] == zetonwczesniej)
				w[i][j] = zetonteraz;
			if (a[i][j] == zetonwczesniej)
				a[i][j] = zetonteraz;
			if (s[i][j] == zetonwczesniej)
				s[i][j] = zetonteraz;
		}
	}
}
void czyszczenietab(char q[3][3], char w[3][3], char a[3][3], char s[3][3]) {//funkcja wpisujaca do 4 tablic 3x3 spacje aby mozna bylo je wypelnic zetonami
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			q[i][j] = ' ';
			w[i][j] = ' ';
			a[i][j] = ' ';
			s[i][j] = ' ';
		}
	}
}
gracze wyborzetonu(gracze tablica[]) {
	//funkcja pozwalajaca graczom wybranie zetonow i zapobiegajaca wybraniu zetonu juz zajetego 
	char tab[4] = {kolko,krzyzyk,sigma,slonce};
	string zetongracza;
	char poprzeton;
	int zetongracza1, zetongracza2;
	int rodzajgracza = 0;
	cout << tablica[0].imie << " Wybierz jeden z zetonow (podaj nr): " << endl;
	for (int i = 0; i < 4; i++)
		cout << i + 1 << ":" << tab[i] << endl;
	cin >> zetongracza;
	while (zetongracza[0] < '1' or zetongracza[0] > '4' or zetongracza.size() != 1) {
		system("cls");
		cout << "Zly token wybierz inny(od 1 do 4): ";
		cin >> zetongracza;
	}
	poprzeton = zetongracza[0];
	zetongracza1 = zetongracza[0]-'1';
	tablica[0].token = tab[zetongracza1];

	cout << tablica[1].imie << " Wybierz jeden z zetonow (podaj nr):" << endl;
	for (int i = 0; i < 4; i++)
		if (i != zetongracza1)
			cout << i + 1 << ":" << tab[i] << endl;
	cin >> zetongracza;
	while (zetongracza[0] == poprzeton or zetongracza[0] < '1' or zetongracza[0] > '4' or zetongracza.size() != 1) {
		system("cls");
		cout << "Zly token wybierz inny (od 1 do 4): ";
		cin >> zetongracza;
	}
	zetongracza2 = zetongracza[0] - '1';
	tablica[1].token = tab[zetongracza2];
	for (int i = 0; i < 2; i++)
		return tablica[i];
}
bool wygrana(char q[3][3], char w[3][3], char a[3][3], char s[3][3], int rodzajgracza, gracze tablica[]) {
	int warunkewygranej = 0;
	int ilew = 0;
	int ilek = 0;
	int iles = 0;
	for (int i = 0; i < 3; i++) {//sprawdzenie wygranej dla 1 i 2 cwiartki po wierszach 
		for (int j = 0; j < 3; j++) {
			if (q[i][j] == tablica[rodzajgracza].token) {
				ilew += 1;
				if (ilew > warunkewygranej) {
					warunkewygranej = ilew;
				}
			}
			else
			{
				ilew = 0;
			}
			if (w[i][j] == tablica[rodzajgracza].token) {
				ilew += 1;
				if (ilew > warunkewygranej) {
					warunkewygranej = ilew;
				}
			}
			else
			{
				ilew = 0;
			}
			//sprawdzenie wygranej dla 1 i 3 cwiartki po kolumnach 
			if (q[j][i] == tablica[rodzajgracza].token) {
				ilek += 1;
				if (ilek > warunkewygranej) {
					warunkewygranej = ilek;
				}
			}
			else
			{
				ilek = 0;
			}
			if (a[j][i] == tablica[rodzajgracza].token) {
				ilek += 1;
				if (ilek > warunkewygranej) {
					warunkewygranej = ilek;
				}
			}
			else
			{
				ilek = 0;
			}
		}
		//sprawdzenie wygranej dla 1 i 4 cwiartki po skosie 
		if (q[i][i] == tablica[rodzajgracza].token) {
			iles += 1;
			if (iles > warunkewygranej) {
				warunkewygranej = iles;
			}
		}
		else
		{
			iles = 0;
		}
		if (s[i][i] == tablica[rodzajgracza].token) {
			iles += 1;
			if (iles > warunkewygranej) {
				warunkewygranej = iles;
			}
		}
		else
		{
			iles = 0;
		}
		ilew = 0;
		ilek = 0;
	}
	iles = 0;
	for (int i = 0; i < 3; i++) {//sprawdzenie wygranej dla 3 i 4 cwiartki po wierszach
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == tablica[rodzajgracza].token) {
				ilew += 1;
				if (ilew > warunkewygranej) {
					warunkewygranej = ilew;
				}
			}
			else
			{
				ilew = 0;
			}
			if (s[i][j] == tablica[rodzajgracza].token) {
				ilew += 1;
				if (ilew > warunkewygranej) {
					warunkewygranej = ilew;
				}
			}
			else
			{
				ilew = 0;
			}
			//sprawdzenie wygranej dla 2 i 4 cwiartki po kolumnach
			if (w[j][i] == tablica[rodzajgracza].token) {
				ilek += 1;
				if (ilek > warunkewygranej) {
					warunkewygranej = ilek;
				}
			}
			else
			{
				ilek = 0;
			}
			if (s[j][i] == tablica[rodzajgracza].token) {
				ilek += 1;
				if (ilek > warunkewygranej) {
					warunkewygranej = ilek;
				}
			}
			else
			{
				ilek = 0;
			}
		}
		//sprawdzenie wygranej dla 2 i 3 cwiartki po skosie
		if (w[i][i] == tablica[rodzajgracza].token) {
			iles += 1;
			if (iles > warunkewygranej) {
				warunkewygranej = iles;
			}
		}
		else
		{
			iles = 0;
		}
		if (a[i][i] == tablica[rodzajgracza].token) {
			iles += 1;
			if (iles > warunkewygranej) {
				warunkewygranej = iles;
			}
		}
		else
		{
			iles = 0;
		}
		ilew = 0;
		ilek = 0;
	}
	iles = 0;
	if (warunkewygranej >= 5)
		return true;
	//sprawdzanie po skosie w momencie gdy ciag nachodzi na 3 cwiartki
	else if (q[0][1] == tablica[rodzajgracza].token and q[1][2] == tablica[rodzajgracza].token and w[2][0] == tablica[rodzajgracza].token and s[0][1] == tablica[rodzajgracza].token and s[1][2] == tablica[rodzajgracza].token) return true;
	else if (q[1][0] == tablica[rodzajgracza].token and q[2][1] == tablica[rodzajgracza].token and a[0][2] == tablica[rodzajgracza].token and s[1][0] == tablica[rodzajgracza].token and s[2][1] == tablica[rodzajgracza].token) return true;
	else if (w[0][1] == tablica[rodzajgracza].token and w[1][0] == tablica[rodzajgracza].token and q[2][2] == tablica[rodzajgracza].token and a[0][1] == tablica[rodzajgracza].token and a[1][0] == tablica[rodzajgracza].token) return true;
	else if (w[1][2] == tablica[rodzajgracza].token and w[2][1] == tablica[rodzajgracza].token and s[0][0] == tablica[rodzajgracza].token and a[1][2] == tablica[rodzajgracza].token and a[2][1] == tablica[rodzajgracza].token) return true;
	else
	{
		return false;
	}
}
void ktoracyfra(char tab[3][3], char q[3][3], char w[3][3], char a[3][3], char s[3][3], int rodzajgracza, gracze tablica[]) {
	//funkcja pozwalajaca wpisac cyfre czyli miejsce na wybranej cwiartce gdzie pojawi sie zeton
	string cyfra;
	cout << "Wybierz pozycje w ktorej ma sie poajwic token (1.9): " << endl;
	cin >> cyfra;
	if (cyfra[0] == 'p' and cyfra.size() == 1) {
		pauza();
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktoracyfra(tab, q, w, a, s, rodzajgracza, tablica);
	}
	else if (cyfra[0] == 'v' and cyfra.size() == 1) {
		wymianazetonow(q, w, a, s, rodzajgracza, tablica);
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktoracyfra(tab, q, w, a, s, rodzajgracza, tablica);
	}
	else if (cyfra.size() != 1) {
		system("cls");
		ktoracyfra(tab, q, w, a, s, rodzajgracza, tablica);
	}
	else
	{
		dzialanietablicy(tab, q, w, a, s, tablica, rodzajgracza, cyfra[0]);
	}
	
}
void ktoracwiartka(char q[3][3], char w[3][3], char a[3][3], char s[3][3], int rodzajgracza, gracze tablica[]) {
	//funkcja ktora pozwala wybrac cwiartke do ktorej chdemy wpisac token
	string litera;
	cout << "Wybierz czesc w ktora chcesz wpisac znak: " << endl;
	cin >> litera;
	if (litera[0] == 'q' and litera.size() == 1)
		ktoracyfra(q,q,w,a,s,rodzajgracza, tablica);
	else if (litera[0] == 'w' and litera.size() == 1)
		ktoracyfra(w,q,w,a,s,rodzajgracza, tablica);
	else if (litera[0] == 'a' and litera.size() == 1)
		ktoracyfra(a,q,w,a,s,rodzajgracza, tablica);
	else if (litera[0] == 's' and litera.size() == 1)
		ktoracyfra(s,q,w,a,s,rodzajgracza, tablica);
	else if (litera[0] == 'p' and litera.size() == 1)  {
		pauza();
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktoracwiartka(q, w, a, s, rodzajgracza, tablica);
	}
	else if (litera[0] == 'v' and litera.size() == 1) {
		wymianazetonow(q, w, a, s, rodzajgracza, tablica);
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktoracwiartka(q, w, a, s, rodzajgracza, tablica);
	}
	else
	{	
		system("cls");
		cout << "Nieprawidlowa litera! Podaj poprawna(q,w,a,s,p,v): " << endl;
		ktoracwiartka(q, w, a, s, rodzajgracza, tablica);
	}
}
void ktogra(int rodzajgracza, gracze tablica[]) {
	//funkcja pobierajaca za struktury dane o imieniu i zetonie 
	cout << "Tura: " << tablica[rodzajgracza].imie << endl;
	cout << "Zeton: " << tablica[rodzajgracza].token << endl;
}
void obrotl(char tab[3][3]) {
	//obrot ruchomej czesci planszy w lewo o 90 stopni przez podmiane wartosci 
	char zamiana1 = tab[2][0];
	char zamiana2 = tab[2][1];
	char zamiana3 = tab[2][2];
	char zamiana4 = tab[1][0];
	char zamiana5 = tab[1][1];
	char zamiana6 = tab[1][2];
	char zamiana7 = tab[0][0];
	char zamiana8 = tab[0][1];
	char zamiana9 = tab[0][2];

	tab[0][2] = zamiana3;
	tab[1][2] = zamiana2;
	tab[2][2] = zamiana1;
	tab[0][1] = zamiana6;
	tab[1][1] = zamiana5;
	tab[2][1] = zamiana4;
	tab[0][0] = zamiana9;
	tab[1][0] = zamiana8;
	tab[2][0] = zamiana7;
}
void obrotp(char tab[3][3]) {
	//obrot ruchomej czesci planszy w prawo o 90 stopni przez podmiane wartosci 
	char zamiana1 = tab[2][0];
	char zamiana2 = tab[2][1];
	char zamiana3 = tab[2][2];
	char zamiana4 = tab[1][0];
	char zamiana5 = tab[1][1];
	char zamiana6 = tab[1][2];
	char zamiana7 = tab[0][0];
	char zamiana8 = tab[0][1];
	char zamiana9 = tab[0][2];

	tab[0][2] = zamiana7;
	tab[1][2] = zamiana8;
	tab[2][2] = zamiana9;
	tab[0][1] = zamiana4;
	tab[1][1] = zamiana5;
	tab[2][1] = zamiana6;
	tab[0][0] = zamiana1;
	tab[1][0] = zamiana2;
	tab[2][0] = zamiana3;
}
void ktorastrona(char tab[3][3], char q[3][3], char w[3][3], char a[3][3], char s[3][3], int rodzajgracza, gracze tablica[]) {
	//funkcja pobierajaca znak i wywolujaca obrot planszy 
	string strona;
	cout << "W ktora strone chcesz obrocic z-lewo x-prawo: " << endl;
	cin >> strona;
	if (strona[0] == 'z' and strona.size() == 1)
		obrotp(tab);
	else if (strona[0] == 'x' and strona.size() == 1)
		obrotl(tab);
	else if (strona[0] == 'p' and strona.size() == 1) {
		pauza();
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktorastrona(tab, q, w, a, s, rodzajgracza, tablica);
	}
	else if (strona[0] == 'v' and strona.size() == 1) {
		wymianazetonow(q, w, a, s, rodzajgracza, tablica);
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktorastrona(tab, q, w, a, s, rodzajgracza, tablica);
	}
	else
	{
		system("cls");
		cout << "Zla litera!Podaj poprawna(z,x,p,v)" << endl;
		ktorastrona(tab, q, w, a, s, rodzajgracza, tablica);
	}
}
void coobracasz(char q[3][3], char w[3][3], char a[3][3], char s[3][3],int rodzajgracza,gracze tablica[]) {
	//funkcja wybierajaca cwiartki do obrotu 
	string litera;
	cout << "Ktora cwiartke chcesz obrocic: " << endl;
	cin >> litera;
	if (litera[0] == 'q' and litera.size() == 1)
		ktorastrona(q, q, w, a, s, rodzajgracza, tablica);
	else if (litera[0] == 'w' and litera.size() == 1)
		ktorastrona(w,q, w, a, s, rodzajgracza, tablica);
	else if (litera[0] == 'a' and litera.size() == 1)
		ktorastrona(a, q, w, a, s, rodzajgracza, tablica);
	else if (litera[0] == 's' and litera.size() == 1)
		ktorastrona(s, q, w, a, s, rodzajgracza, tablica);
	else if (litera[0] == 'p' and litera.size() == 1) {
		pauza();
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		coobracasz(q, w, a, s, rodzajgracza, tablica);
	}
	else if (litera[0] == 'v' and litera.size() == 1) {
		wymianazetonow(q, w, a, s, rodzajgracza, tablica);
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		coobracasz(q, w, a, s, rodzajgracza, tablica);
	}
	else
	{
		system("cls");
		cout << "Zla litera! Podaj poprawna(q,w,a,s,p,v): " << endl;
		coobracasz(q,w,a,s,rodzajgracza,tablica);
	}
}
void kik() {
	//funkcja do gry w kolko i krzyzyk
	gracze tablica[2];
	char q[3][3];
	char w[3][3];
	char a[3][3];
	char s[3][3];
	int rodzajgracza = 1;
	czyszczenietab(q, w, a, s);//wstawianie spacji do tab
	cout << "Podaj imie gracza1: ";
	cin >> tablica[0].imie;
	cout << "Podaj imie gracza2: ";
	cin >> tablica[1].imie;
	system("cls");
	wyborzetonu(tablica);
	cout << tablica[0].imie << ' ' << tablica[0].token << endl;
	cout << tablica[1].imie << ' ' << tablica[1].token << endl;
	while (wygrana(q, w, a, s, rodzajgracza, tablica) == false) {
		system("cls");
		tura(rodzajgracza);
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktoracwiartka(q, w, a, s, rodzajgracza, tablica);//miejsce wpisanie zetonu
	}
	system("cls");
	plansza_kik(q, w, a, s, rodzajgracza, tablica);
	cout << "Wygrales: " << tablica[rodzajgracza].imie;
}
void pentago(){
	// funkcja zaczynajaca gre w pentago
	gracze tablica[2];
	char q[3][3];
	char w[3][3];
	char a[3][3];
	char s[3][3];
	int rodzajgracza = 1;
	czyszczenietab(q, w, a, s);//wstawianie spacji do tab
	cout << "Podaj imie gracza1: ";
	cin >> tablica[0].imie;
	cout << "Podaj imie gracza2: ";
	cin >> tablica[1].imie;
	system("cls");
	wyborzetonu(tablica);
	cout << tablica[0].imie << ' ' << tablica[0].token << endl;
	cout << tablica[1].imie << ' ' << tablica[1].token << endl;
	while (wygrana(q, w, a, s, rodzajgracza, tablica) == false) {
		system("cls");
		tura(rodzajgracza);
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktoracwiartka(q, w, a, s, rodzajgracza, tablica);//miejsce wpisanie zetonu
		system("cls");
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		coobracasz(q, w, a, s,rodzajgracza,tablica);//miejsce obrotu cwiartki
	}
	system("cls");
	plansza_kik(q, w, a, s,rodzajgracza,tablica);
	cout << "Wygrales: " << tablica[rodzajgracza].imie;

}
void predeftab() {
	//funkcja wczytujaca rozpoczeta gre 
	gracze tablica[2];
	int rodzajgracza = 1;
	tablica[0].imie = "czerwony";
	tablica[1].imie = "niebieski";
	tablica[0].token = sigma;
	tablica[1].token = slonce;
	char q[3][3] = { {' ',slonce,' '},{sigma, sigma, slonce},{' ',sigma,' '} };
	char w[3][3] = { {' ',sigma,' '},{sigma,slonce,' '},{' ',' ',' '} };
	char a[3][3] = { {sigma,sigma,' '},{slonce,' ',sigma},{' ',slonce,' '} };
	char s[3][3] = { {' ',' ',' '},{' ', slonce,' '},{' ',slonce,slonce} };//wypelnienie recznie tablicy
	while (wygrana(q, w, a, s, rodzajgracza, tablica) == false) {
		system("cls");
		tura(rodzajgracza);
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		ktoracwiartka(q, w, a, s, rodzajgracza, tablica);//miejsce wpisanie zetonu
		system("cls");
		plansza_kik(q, w, a, s, rodzajgracza, tablica);
		coobracasz(q, w, a, s, rodzajgracza, tablica);//miejsce obrotu cwiartki
	}
	plansza_kik(q, w, a, s, rodzajgracza, tablica);
	cout << "Wygrales: " << tablica[rodzajgracza].imie;
}
void wcograsz() {
	//funkcja poczatkowa gdzaie wybiera sie gre lub menu 
	string gra;
	cout << "W co chcesz zagrac? 1. Kolko i krzyzyk / 2. Pentago /o. predeftab/m. menu : " << endl;
	cin >> gra;
	if (gra[0] == '1' and gra.size() == 1)
		kik();
	else if (gra[0] == '2' and gra.size() == 1)
		pentago();
	else if (gra[0] == 'o' and gra.size() == 1)
		predeftab();
	else if (gra[0] == 'm' and gra.size() == 1) {
		menu();
		wcograsz();
	}
	else
	{
		system("cls");
		cout << "Podaj poprawny numer z zakresu 1/2 lub o/m " << endl;
		wcograsz();
	}
}
int main() {
	wcograsz();
	return 0;
}
