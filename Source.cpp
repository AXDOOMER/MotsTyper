/* Copyright (c) 2016-2017 Alexandre-Xavier Labonté-Lamoureux */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main(int argc, char* argv[])
{
	// Chargement
	ifstream fichier;
	string source = "mots.txt";

	// Le fichier source peut être changé
	if (argc == 2)
	{
		source = argv[1];
	}
	fichier.open(source.c_str());
	// Vérification à savoir si le fichier a bien pu être chargé
	if (!fichier.good())
	{
		cerr << "Fichier introuvable" << endl;
		return 1;
	}

	// Storage des mots
	vector<string> v;

	// Lecture des lignes du fichier
	string ligne;
	while (getline(fichier, ligne))
	{
		// Ne pas ajouter une ligne vide ou des espaces suivant la fin d'un mot
		while (ligne.length() > 0 && ligne[ligne.size() - 1] == ' ')
		{
			ligne.pop_back();
		}

		if (ligne.length() > 0)
		{
			v.push_back(ligne);
		}
	}

	// Fermeture du fichier et initialisation du RNG
	fichier.close();
	srand((unsigned int)time(NULL));

	// Boucle principale
	while (true)
	{
		string s = v.at(rand() % v.size());
#ifdef _WIN32
		// Conversion pour afficher correctement à la console de Windows
		vector<char> v(s.size() + 1);
		AnsiToOem(s.c_str(), &v[0]);
		s = string(begin(v), end(v));
#endif
		// Affichage
		cout << s << endl;

		// Le joueur doit retaper le string affiché
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
