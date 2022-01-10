
# Transversal Software Project(PLT)
_C'est le projet final de notre voyage et de notre scolarité dans l'école d'études supérieures de l'ENSEA.Le principe est de faire appel à chaque cours que nous avons fait dans la spécialisation, et de le faire, nous devons construire un jeu et nous avons choisi de construire un 2D basé sur un jeu de Tanks._


[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](http://forthebadge.com)  [![forthebadge](http://forthebadge.com/images/badges/powered-by-electricity.svg)](http://forthebadge.com)

## Informations sur le jeu

### Presentation du jeu
_Le projet de ce semestre consiste à créer un jeu appelé Tank Stars. C'est un jeu avec des mécanismes gameplay similaire à Worms, mais où les vers de terre ont été remplacés par des Tanks. Dans ce jeu, deux Tanks s'affrontent dans une bataille où le but est de détruire le Tank adverse pour gagner_  

### Règles du jeu
_C'est un jeu de combat basé sur deux joueurs.  
- Au début de la partie, chaque joueur doit choisir un réservoir à partir de deux modèles disponibles: le premier compte 80 Points de Vie(PV) et 20 Points d'Attaque (AP). La seconde a 100 VP et 16 PA.  
- Une fois que les deux joueurs ont choisi leurs tanks, les points de vie sont initialisés.  
- Pendant chaque tour, le tank d'attaque peut se déplacer de gauche à droite. Il peut également ajuster la trajectoire angulaire et modifier la puissance du tir.  
- Après 30 secondes, les prédispositions doivent être effectuées, le tank d'attaque lancera le
feu de missile à la suite d'une trajectoire oblique.
- Si le tir atteint le tank défensif, son nombre de points de vie diminuera par rapport à l'adversaire AP.
- Lorsque le tir de missiles est effectué, les 2 joueurs changent leurs rôles.  
- Si le nombre de points de vie de l'un des deux réservoirs atteint zéro, le jeu se termine et le tank qui est toujours en vie remporte le jeu._

Le projet sera effectué et codé en C ++ sur Linux et on créera un compte Github

### Commandes de jeu
LEFT : déplacer le tank à gauche  
RIGHT : déplacer le tank à droite  
W : tourner la tourelle dans le sens antihoraire  
X : tourner la tourelle dans le sens horaire  
ESPACE : lancer un tir  
ENTREE : démarrer une partie  

### Installation des bibliothèques nécessaires pour la compilation

sudo apt install git  
sudo apt-get install dia  
sudo apt install cmake  
sudo apt install g++  
sudo apt install lcov  
sudo apt install gcovr  
sudo apt-get install libxml2-dev  
sudo apt-get install libsfml-dev  
sudo apt-get install libboost-test-dev  

#### récupérer le projet :
    git clone https://github.com/16999/plt. 
    On obtient un dossier appélé plt
#### compilation du projet :
    make 
#### Suppression de tous les fichiers générés :
    make clean
#### Exécution des tests :
    make test
#### Execution du state :
    cd bin  
    ./client state  
#### Execution du client :
    cd bin  
    ./client client
#### Execution du render :
    cd bin  
    ./client render
#### Execution de l'IA simple:
    cd bin  
    ./client dumbAI
#### Execution de l'IA heuristic :
    cd bin  
    ./client heuristicAI
#### Execution de l'IA Avancée :
    cd bin  
    ./client AdvancedAI
#### Execution de l'IA aléatoire contre l'IA heuristique:
    cd bin  
    ./client AIvsAI
#### Execution de l'IA aléatoire contre l'IA heuristique:
    cd bin  
    ./client AIvsAI2
### Exécution des jalons


#### Jalon 1.final
    cd bin  
    ./client state
#### Jalon 2.1
    cd bin  
    ./client 
#### Jalon 2.2
    cd bin  
    ./client render
#### Jalon 2.final
    cd bin  
    ./client dumbAI
#### Jalon 3.1
    cd bin  
    ./client heurisricAI
#### Jalon 3.final
    cd bin  
    ./client advancedAI
#### Jalon 4.1
    cd bin  
    ./client adavanced

## Build With

We code the game in C++ with these library:  
 dia diagram editor  
 dia2code  
 libxml2 -SFML  
 Tiled Map Editor  
 Atom ,Visual Studio - Editeur de textes

## Versions
Listez les versions ici 
_exemple :_
**Dernière version stable :** 5.0
**Dernière version :** 5.1
Liste des versions : [Clic here to see the new version](https://github.com/16999/plt/tags)
_(phttps://github.com/16999/plt/tags)_

## Authors

(https://github.com/16999/plt)
* **Shuman Lin**(https://github.com/ShumanLIN)
* **Eddy Lobjois** (https://github.com/16999)
* **Ouattara Siaka** _alias_ [davson1](https://github.com/Davson1)  
https://github.com/16999/plt/ShumanLIN  
https://github.com/16999/plt/16999  
https://github.com/16999/plt/Davson1  
  
........................................
