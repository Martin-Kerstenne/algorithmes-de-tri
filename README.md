# Algorithmes de tri

Projet réalisé dans le cadre de la SAÉ S1.02 « Démonstration d'algorithmes » (BUT Informatique).

L'objectif est de **comparer les performances de 6 algorithmes de tri** en C++, selon la taille et le type des données à trier. Les résultats détaillés et leur analyse sont présentés dans le rapport PDF fourni dans le dépôt.

## Algorithmes comparés

Tris quadratiques, en O(n²) :
- Tri par sélection
- Tri par insertion

Tris en O(n log n) :
- `std::sort`
- `std::stable_sort`
- Tri rapide (`quicksort`), pivot en première position
- Tri rapide modifié (`modifquicksort`), pivot choisi aléatoirement

## Données de test

Chaque algorithme est testé sur trois types de vecteurs d'entiers, de taille n allant de 1 000 à 100 000 éléments (par pas de 1 000). Les valeurs sont comprises entre 0 et 1024n.

| Type | Description |
|------|-------------|
| 1 | Vecteur aléatoire, tirage uniforme |
| 2 | Partiellement trié : première moitié quasi-triée (`v[i] = 1024 * i + r`, avec `r` aléatoire entre 0 et 1023), seconde moitié aléatoire |
| 3 | Partiellement inversé : première moitié décroissante (`v[i] = 1024 * (n - i) + r`), seconde moitié aléatoire |

## Mesure du temps

Le temps d'exécution est mesuré en microsecondes avec la bibliothèque `<chrono>`. Les programmes sont compilés avec `g++` et l'option `-Ofast`, sous Linux (Ubuntu).

## Structure du dépôt

```
algorithmes-de-tri/
├── cpp/        sources C++ (un fichier par algorithme + main.cpp)
├── data/       mesures produites par les programmes (fichiers .data)
├── sort.hpp    en-tête commun
├── build.sh    script de compilation
├── plot.sage   script de tracé des courbes (SageMath)
└── Rapport sae S1-02 Martin Kerstenne.pdf
```

## Compilation et utilisation

Sous Linux, depuis la racine du dépôt :

```bash
chmod +x build.sh
./build.sh
```

Chaque exécutable produit des fichiers `.data` dans le dossier `data/`. Le script `plot.sage` permet ensuite de tracer les courbes à partir de ces fichiers :

```bash
sage plot.sage
```

## Prérequis

- `g++` (compilateur C++)
- [SageMath](https://www.sagemath.org/) pour le tracé des courbes

## Auteur

Martin Kerstenne
