/*
 * Copyright (c) 2016-2017 Alexandre-Xavier Labonté-Lamoureux
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>     /* srand, rand, exit, EXIT_FAILURE */
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
		exit(EXIT_FAILURE);
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
			ligne.erase(ligne.size() - 1);
		}

		if (ligne.length() > 0)
		{
			v.push_back(ligne);
		}
	}

	if (v.size() == 0)
	{
		cerr << "Fichier vide" << endl;
		exit(EXIT_FAILURE);
	}

	// Fermeture du fichier et initialisation du RNG
	fichier.close();
	srand((unsigned int)time(NULL));

	// Boucle principale
	bool pas_termine = true;
	while (pas_termine)
	{
		string s = v.at(rand() % v.size());
#ifdef _WIN32
		// Conversion pour afficher correctement à la console de Windows
		vector<char> a(s.size() + 1);
		AnsiToOem(s.c_str(), &a[0]);
		s = string(a.begin(), a.end());
#endif
		// Affichage
		cout << s << endl;

		// Le joueur doit retaper le string affiché
		string t;
		do
		{
			getline(cin, t);

			if (t.length() == 0)
			{
				pas_termine = false;
				break;
			}
#ifdef _WIN32
			t += '\0';
#endif
		} while (t != s);
	}
}
