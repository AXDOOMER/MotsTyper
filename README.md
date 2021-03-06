﻿# MotsTyper

C'est un programme d'entraînement de copier-coller afin de pratiquer la mémoire des mots. 

C'est un bon exemple d'affichage de caractères accentués sous Win32. Par exemple, Windows affiche le caractère `é` d'un string comme `Ú` à la console. Ce programme montre comment y apporter une correction. 

## Compiler

Sur Windows, utilisez Visual Studio. Sur Linux, utilisez g++. 

```
g++ -o MotsTyper Source.cpp
```

Pour compiler sur Linux un exécutable pour Windows, utilisez cette commande:
```
i686-w64-mingw32-g++ -static-libgcc -static-libstdc++ -s -o MotsTyper.exe Source.cpp
```

## Utilisation

Il suffit que de recopier les mots affichés. Si vous utilisez le programme sur Linux, vous devez convertir le fichier mots en UTF-8 avec des fins de ligne Unix/Linux. Il est possible de changer le fichier mots par défaut en entrant le nom d'un autre fichier comme premier paramètre en ligne de commande. 

## Licence

Ce programme est distribué sous la [licence ISC](https://choosealicense.com/licenses/isc/) de l'Internet Systems Consortium. 

