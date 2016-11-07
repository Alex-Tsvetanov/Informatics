#include <iostream>
#include <cstring>
#include<cstdio>

using namespace std;

const int MAXN = 1000 * 1000;
const int MAX_LEN = 31; // maksimalna duljina na chisloto-otgovor(spored uslovieto)

char dp[2][MAXN][MAX_LEN]; // pyrvo systoqnie - ukazva s koi ot poslednite 2 reda na dinamichnata tablica rabotim -
	 					   // za tekushtata duljina ili za predhodnata;
						   // vtoro systoqnie - ostatykyt na chisloto;
						   // tretoto izmerenie e zaradi simvolniq niz, koito se pazi v dinamichnata tablica

char s[MAX_LEN];
char ans[MAX_LEN]; // chisloto-otgovor na zadachata

int n, mod;

int mnLen = MAX_LEN;

bool exists(char* s) {
	 return strlen(s) > 0;
}

void gen(int len)
{
	if (len > 0 && len <= 15 && mod == 0 && len < mnLen) { // namerili sme po-malko chislo
	   mnLen = len;

	   s[len] = '\0';
	   strcpy(ans, s);
    }

	if (len == 15 && ! exists(dp[0][mod])) s[len] = '\0', strcpy(dp[0][mod], s);
	if (len == 15) return;

	int modOld = mod;

	s[len] = '1'; // slagame 1-ca i probvame kakvo shte se sluchi
	mod = (modOld * 10 + 1) % n;
	gen(len + 1);

	s[len] = '2'; // slagame 2-ka i probvame kakvo shte se sluchi
	mod = (modOld * 10 + 2) % n;
	gen(len + 1);
}

int newMod;
bool current = 1, previous = 0;

void tryToAdd(int mod, int t) {
	newMod = (mod * 10 + t) % n;

	strcat(dp[previous][mod], t == 1 ? "1" : "2");

	if (! exists(dp[current][newMod])) {
	   strcpy(dp[current][newMod], dp[previous][mod]);
    } else
		if (strcmp(dp[previous][mod], dp[current][newMod]) == -1) strcpy(dp[current][newMod], dp[previous][mod]);

	dp[previous][mod][ strlen(dp[previous][mod]) - 1 ] = '\0';
}

int main()
{
	scanf("%d", &n);

	if (n % 5 == 0) { // ako n se deli na 5, chisloto-otgovor trqbva da zavyrshva na 0 ili 5, t.e. nqma kak da ima takova
	   cout << "Impossible" << endl;
 	   return 0;
    }

	// pyrvi etap - brute force na chislata s duljina do 15

	gen(0); // funkciq, koqto proverqva vsichki chisla s dyljina do 15 ot razglejdaniq vid,
			// i tyrsi minimalnoto ot tqh, kratno na N (po metoda na pylnoto izcherpvane, tyi kato chislata sa 2^15 ~ 32000 na broi)

	if (strlen(ans)) { // namerili sme otgovor s do 15 cifri - prikluchvame
 	    printf("%s\n", ans);
		return 0;
	}

	// vtori etap - tyrsene na chislo s 16 do 30 cifri chrez dinami. tehnika

	for (int len = 16; len <= 30; len++) {

		for (int mod = 0; mod < n; mod++) // probvame da produljim chisloto s predhodnata dyljina i ostatyk mod
			if (exists(dp[previous][mod])) { // ako takova izobshto ima
				// pyrvo probvame da slojim 1
				tryToAdd(mod, 1);

				// probvame da slojim 2
				tryToAdd(mod, 2);
            }

		if (exists(dp[current][0])) { // namerili sme reshenie, prikluchvame
		   printf("%s\n", dp[current][0]);
		   return 0;
        }

		current = 1 ^ current; // obryshtane na redovete
		previous = 1 ^ previous;
	}

	// ako sme stignali do tuk, znachi chislo s do 30 cifri s iskanoto svoistvo nqma, prikluchvame

	printf("Impossible\n");

	return 0;
}

// asimtotichnata slojnost na algorityma e O(2^15 + 15 * N * MAX_LEN)
