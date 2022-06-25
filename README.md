# duplicate_detection

## 1-Introduction
Le problème de détection des doublons est un problème majeur dans le monde de l'informatique. Nous supposons que nous avons un ensemble 
des mots dans un fichier et on veut éliminer les doublons dans ce fichier.

Chaque ligne de notre fichier contient un seul mot.

Nous utilisons la distance **Levenshtein** pour comparer deux mots avec un seuil de **0.8**.
La distance de Levenshtein est une distance mathématique donnant une mesure de la similarité entre deux chaînes de caractères. Elle est égale au nombre minimal
de caractères qu'il faut supprimer, insérer ou remplacer pour passer d'une chaîne à l'autre

Par exemple pour la liste suivante : majda, imad, samir, dalila, imade, dalil. On
devrait garder seulement : majda,imad,samir,dalila.
Pour résoudre ce problème, proposons trois algorithmes.

## 2-Algorithme naive
L'algorithme est le suivant: Pour chaque mot, on compare le mot avec les autres et
éliminer ses doublons.

Les étapes de réalisation sont les suivantes:
### a- fichier set.h ce fichier contient:
       1.Structure de données  Set : Tableau dynamique
       2.La déclaration des fonctions suivantes :
          * Tableau MappingToSet(String fichier) : lis le fichier et insère chaque dans une case.
### b- set.c: implémentation des deux fonctions précédente.
### c- Algorithme 1:         
       1. set purge(String fichier): compare chaque case avec les autres cases (en utilisant la distance Levenshtein) en supprimant
       chaque case dupliqué.
       
## 3-Algorithme avec tri
L’algorithme est le suivant On trie les mots. Pour chaque mot, on la compare avec les suivants jusqu’ a qu’on trouve pas de doublons, le tri doit se faire avec un tas.
Nous utilisons dans cet algorithme structure Tas minimum dont les éléments sont des chaines de caractères. La relation d’ordre est définie par l’ordre alphabétique.

Les étapes de réalisation sont les suivantes :
### a- fichier Tas.h, ce fichier contient :
       1-Structure de données  Tas : tas
       2-La déclaration des fonctions suivantes :
          * Void Ajout(String s, tas t) : permis d’ajouter une chaine de caractère un tas
          * String ExtraireMin( tas t) : permis de retirer une chaine de caractère d’un tas
          * Tas LireToTas(String fichier) : lis le fichier et insère chaque ligne dans une case
          * Tableau MappingToTable(String fichier) : transforme le fichier en un tableau trié en utilisant le Tas
### b- fichier set.c: implémentation des trois fonctions précédente.
### c- Algorithme2.c:
       1-Tableau purge(String fichier) : compare chaque case avec les cases suivant (en utilisant la distance livenshtein) jusqu'à qu’il ne trouve pas de doublons
         (l’itération arrête dés qu’on ne trouve plus de doublons)
         
## 3-Algorithme Hash
L’algorithme est le suivant : Pour chaque mot, on calcule Hash Code du mot avec la formule (somm(ASCI)%tailleTable. Nous utilisons le chainage pour gérer les
collisions. On compare chaque mot avec les mots qui ont le même Hash Code et les cinq cases suivantes dans le tableau de hashage.

       
### a- fichier HashTable.h, ce fichier contient :  
       1- Structure de données HashTable: Tableau de hashage
       2- La déclaration des fonctions suivantes:
          * int CalculHash(String mot): Calcule le hashCode pour le mot
          * Void ajoutMot(HashTable table, String mot): insère un mot dans le tableau de hashage
          * HashTable MappingToHashTable(String fichier): transforme le fichier en un tableau
### b- fichier set.c implémentation des trois fonctions précédente
### c- algorithme 3:
       1- set purge(String fichier): on implémente l'algorithme 3
       
       
 # L'évolution du temps d'exécutins en fonction de la taille de données
 ![alt text](https://github.com/Simo1Goat/duplicate_detection/blob/c9f7d5f439b7f736082bb709d4a6ffcc73835544/Projet%20Algorithmique%20HABIBI%20MOHAMED/snapshots/executed_time.png "executed time for each algorithm")

![alt text](https://github.com/Simo1Goat/duplicate_detection/blob/c9f7d5f439b7f736082bb709d4a6ffcc73835544/Projet%20Algorithmique%20HABIBI%20MOHAMED/snapshots/plot.png "evolution time")
 

       
       
       
       
       
