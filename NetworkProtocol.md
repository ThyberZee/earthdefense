# network protocol #

Multiplayer gameplay will require a special case to set up.  The main issue is with syncing up non-deterministic enemy ai events.  The easiest way to keep both players in sync is to create a master model that handles ai logic, and a
> slave model that listens to the master to update its own objects.

Naive approach:

Create a MasterModel that handles all the logic for representing and updating game state.  This model adheres to a simple cascading approach for updating state:  the model has an update method that executes its own logic and calls its children's update methods, which call their children's update methods, etc.  This single model will work for both single player and multiplayer with very little extra configuration.

When multiplayer is desired, the second player will create a SlaveModel.  This model is very similar to the MasterModel except for one key difference: the update method.  The MasterModel will run update logic on the game state every frame, and send the SlaveModel data over the network that indicates the position of all it's child object.  The SlaveModel then simply reads that data and updates the position of it's own objects accordingly.  This requires heavy network traffic, but it will keep both sides in sync pretty well.

protocal:

every frame (1/30 second) the master model will emit a message similar in structure to a save file--one that contains position data for all objects currently alive.

server -> client:
```
player 2 3
enemy 20 49
enemy 57 02
bullet 20 39
bullet 19 304
```

Both models will also have to send user input back and forth.

client 

&lt;-&gt;

 sever:

leftKeyDown
leftKeyUp
rightKeyUp
rightKeyDown
fireKeyDown
fireKeyUp