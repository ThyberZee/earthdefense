### Difficulty Levels ###
  1. Start the program. It should display the Start Screen.
  1. Select which difficulty you want at the bottom then click "New Game." The game should start.
  1. Try this same procedure with different difficulty levels and notice how the game changes accordingly. The bullets should bullet speed should be directly related to the difficulty level.
### Save/Load Game ###
  1. Start the program.  It should display the Start Screen.
  1. Select difficulty level of choice and then click "New Game." The game should start.
  1. Play a little bit then click "Save Game" at the top. There should be no noticeable change in the game when Save Game is clicked, but now there should be a file called "savegame" in the directory with the executable. This file should contain all the information to reload a game state.
  1. Close and restart the program. Window should close. Start Screen should display.
  1. Now click on the "Load Game" button and behold...you continue where you left off! The "Load Game" button should load the information in the "savegame" file and continue the game where it left off last time.

### Network Play ###
  1. Start 2 instances of the program locally. Two Start Screens should be displayed.
  1. On one instance, select difficulty level of choice choose "Host Multiplayer" and then click "New Game." It should start a brand new game.
  1. On the second instance, select "Join Multiplayer" while keeping the address set to default "localhost" then click New Game.  This should start a new InGame screen.
  1. Operate each window independently to make sure that both sides are updated correctly. Each player should update on both windows when they move, as well as all the enemies and projectiles.
  1. Now set up a separate instance on two different machines on the same network.
  1. Repeat steps 2 and 3, except put in the host machine's IP in the client instance.
  1. Play both sides and confirm that both sides are synced.  Basically the two instances should be perfectly synced across the network and be mirrors of each other.

### Cheat Mode ###
  1. Start the program and check "Cheat!" New Start Screen should display.
  1. Click "New Game" and play on! InGame screen should start up and when the projectiles hit your ship, you should not die.