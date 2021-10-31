# Transversal Sotfware Project(PLT)
This is the final Project of our journey and schooling in ENSEA Graduate School.The principle is to make in application every courses we did in specialization IT and Systems and in to do that , we have to build a game and we choose to build a 2D based on a Tank game.

# Table of contents
## About the Game
### Presentation of game
This semester’s project will build on the Tank Stars game. This is a game with mechanics
similar gameplay to Worms, but where earthworms have been replaced by tanks.  
In this game, two tanks go head-to-head in a battle where the goal is to destroy the tank
opposing
### Rules of game
This is a two player turn based combat game.  
- At the start of the game, each player must choose a tank from two available models: The first has 80 health points (HP) and 20 attack points (AP). The second has 100 VP and
16 PA.  
- Once both players have chosen the tank, the life points are initialized.  
- During each turn, the attacking Tank can move from left to right. It can also adjust the angular trajectory and modify the power of the shot.  
- After 30 seconds, the predispositions must be made, the attack tank will launch the
missile fire following an oblique trajectory.  
- If the shot hits the defensive tank, its number of life points will decrease compared to the AP adversary.
- When the missile firing is finished, the 2 players change their roles.  
- If the number of life points of one of the two tanks reaches zero, the game ends and the tank still alive wins the game.
## Work environment
To make our project , we work on linux environment and to compile our project, we have to do this steps :  
git clone https://github.com/16999/plt.  
cd plt/  
mkdir build  
cd build/  
cmake ..  
make -j  
and do this execute the client:  
Execution du client :  
cd /home/pc/github/plt/bin && ./client  

## Build Environment
We code the game in C++ with these library:  
-dia diagram editor  
-dia2code  
-libxml2
-SFML  
-Tiled Map Editor  
........................................

29 octobre 21h40 : j'ai remis l'ancien fichier /src/client/CMakeLists.txt car le nouveau provoquait des erreurs à la compilation.
