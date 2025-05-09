# Projet Ft_containers

Projet qui consiste à programmer des "containers" en C++, version 98, ces containers sont utilisés par la bibliothèque standard C++.
Les containeurs sont un moyen de stocker des données avec à la clé différentes optimisations et techniques de stockage de données.

Pour ce faire nous devons utiliser des concepts comme les templates et les interfaces.

Liste des containers c++ : https://cplusplus.com/reference/stl/

Le sujet nous demande de recréer vecteur, map et stack.

Pour stocker les données dans un vecteur, le projet va simplement stocker les données dans de la mémoire dynamiquement allouée, on pourra par la suite y accéder par "saut" de mémoire.

Le vecteur map stock les données sous format clé-valeur, pour les enregistrer dans un arbre, on accédera, ajoutera et supprimera les données en parcourant l'arbre.

Pour ce faire j'ai utilisé le concept d'arbre rouge-noir, l'algorithme stockera les données en assignant une couleur (rouge ou noir), et grâce à ces couleurs, il saura comment réorganiser l'arbre en cas d'ajout et suppression de données

![arbre](https://github.com/GitCGuillaume/ft_containers/assets/34135668/6b489f69-6775-47e0-9c70-dbb28db09309)

Image prise depuis le site: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

Le container stack est plus primitif, il peut uniquement ajouter et supprimer des données dans une pile, nous pouvons néanmoins utiliser notre vecteur comme extension.

Compilation
>make all

Lancer les programmes de test dans un terminal de commande linux
Pour lancer les tests de mes travaux
>
>./ft 123 > ft.txt
>
Pour lancer les tests de la bibliothèque standard
>
>./std 123 > std.txt

Pour différencier les résultats, si aucune donnée n'est affichée, alors les données écrites sont égaux.
>diff ft.txt std.txt
