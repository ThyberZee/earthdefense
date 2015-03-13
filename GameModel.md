## GameModel interface: ##

#### void initializeGame(): ####
initializes game state.  Currently just creates a player object, but in the future, this should load the first level initialize the highScore manager

#### void resetGame(): ####
This resets the game state by deleting all entities and then calling initializeGame on itself.

#### void update(): ####
updates every entity contained in the gamemodel.

#### void loadGame(string filename): ####
this function takes a file and uses it to create entities and set current score. see GameFileFormat.
#### void saveGame(string filename): ####

#### string state(): ####
returns a string representing the state of the model, including the position and type of every entity.  The format is like this:

```
enemy 45 39
enemy 28 293
projectile 492 29
projectile 92 490
player 23 53
```

###  ###