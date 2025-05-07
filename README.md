# Géométrie

### Objectif

Ce projet est un mini-projet en C++ ayant pour but de :

* manipuler les bases de la **programmation orientée objet** ;
* représenter des **figures géométriques simples** (triangle, carré, cercle) ;
* visualiser les figures via une **interface graphique simplifiée**.

---

### Utilisation

Après compilation, l’exécutable permet d’afficher différentes figures géométriques à l’aide d’une classe graphique type `CTurtle`.

**Exécution :**

```bash
./geometrie
```

---

### Installation & dépendances

Aucune bibliothèque externe n’est requise en dehors du standard C++.
Le code est découpé selon une structure modulaire propre à l’apprentissage de la POO.

---

### Compilation

#### Build :

Utiliser le makefile pour compiler, puis exécuter avec:
./main.exe

#### Test :

```bash
g++ -std=c++11 -Iinclude src/shapes/*.cpp tests/test_shapes.cpp -o test_shapes
./test_shapes
```

---

### 📁 Structure du projet

```text
main.cpp               : point d’entrée
include/               : fichiers headers
├── shapes/            : interfaces des formes géométriques
src/                   : fichiers d’implémentation
├── shapes/            : implémentations des formes
tests/ (optionnel)     : fichiers de test
```
