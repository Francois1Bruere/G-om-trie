# Géométrie

### Objectif

Tracer des triangles, des carrés et des cercles.

### Utilisation

Après compilation, l’exécutable permet d’afficher différentes figures géométriques à l’aide d’une classe graphique type `CTurtle`.

### Compilation

Utiliser le makefile pour compiler ou commande suivante:

```bash
g++ -std=c++23 -Iinclude -o main src/*.cpp src/shapes/*.cpp main.cpp -lgdi32 -luser32
```


**Exécution :**

```bash
./main
```

---

### Installation & dépendances

Aucune bibliothèque externe n’est requise en dehors du standard C++.

---


#### Test :

```bash
<<<<<<< HEAD
g++ -std=c++23 -Iinclude src/shapes/*.cpp test/*.cpp -o test_shapes
=======
g++ -std=c++23 -Iinclude src/shapes/*.cpp tests/test_shapes.cpp -o test_shapes
./test_shapes
>>>>>>> 6eb6b48ae346d5400714b73c6595d6c50e36c58d
```

---

### Structure du projet

```text
main.cpp               : point d’entrée
include/               : fichiers headers
├── shapes/            : interfaces des formes géométriques
src/                   : fichiers d’implémentation
├── shapes/            : implémentations des formes
tests/                 : fichiers de test
```
