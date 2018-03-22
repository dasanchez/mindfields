## Single Game Workflow

### 1. Build teams

As each player joins:
1. Ask if they want to join the blue team or orange team.
2. Ask them if they want to be a leader.
3. Display a view of the board game and their teammates.
4. Display an option to become a team leader if there isn't one.
5. Display an option to became a team member if player is a leader.
5. If team leader, display an option to begin the game.

The next stage begins when both team leaders signal readiness.

### 2. Initialize board game

1. Read dictionary file.
2. Populate deck with game word list from randomly picked dictionary entries.
3. Pick starting team.
4. Assign "hot" words to teams and designate the rest as neutral.
5. Display "hot" words to team leaders.
6. Display deck for all players to see and provide one minute for everyone to read it.

### 3. Main loop: Taking turns
1. Start a one-minute timer for the team leader to produce a hint and number of words associated with it.
2. When the leader submits a hint, the opposing leader must approve it. If the hint is rejected, the counter restarts at 30 seconds. If the opposing leader rejects the hint three times, the game resets.
3. If the timer for hint submission get to zero, the turn is forfeit.
4. The team members are shown the hint and number of words to guess.
5. A one-minute timer starts gor the guesses to be submitted.
6. Each member submits their guesses, from 0 to to the maximum set by the leader, until everyone submits or the counter goes to 0.
7. Guesses are ranked by popularity.
8. Guesses are evaluated one by one.
9. A guess is shown to be correct or incorrect, and the word is tagged as blue/orange/neutral. 
10. If a guess is correct, the next one is evaluated, up to the maximum set by the leader.
12. The turn ends after all guesses are evaluated or an incorrect guess is found (when a word that either belongs to the opposing team or is neutral is evaluated).

The game ends when all the words belonging to a team are uncovered, and that team wins.

