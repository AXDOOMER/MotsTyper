/* Copyright (c) Alexandre-Xavier Labont�-Lamoureux  2016-2017 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#ifdef _WIN32
#include <windows.h>
#endif

/* http://h-deb.clg.qc.ca/Sujets/AuSecours/Afficher--Accents.html */

using namespace std;

int main()
{
	// Chargement
	ifstream fichier;
	fichier.open("mots.txt");

	// Storage des mots
	vector<string> v;

	// Lecture des lignes du fichier
	string ligne;
	while (getline(fichier, ligne))
	{
		v.push_back(ligne);
	}

	// Fermeture du fichier et initialisation du RNG
	fichier.close();
	srand((unsigned int)time(NULL));

	// Boucle principale
	while (true)
	{
		string s = v.at(rand() % v.size());
#ifdef _WIN32
		// Conversion pour console
		vector<char> v(s.size() + 1);
		AnsiToOem(s.c_str(), &v[0]);
		s = string(begin(v), end(v));
#endif
		// Affichage
		cout << s << endl;

		// Le joueur doit retaper le string affich�
		string t;
		do
		{
			getline(cin, t);
#ifdef _WIN32
			t += '\0';
#endif
		} while (t != s);
	}

}