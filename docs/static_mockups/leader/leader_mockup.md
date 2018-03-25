## Gameplay Mockup: Leader

### Welcome screen
The player is prompted to enter a screen name.  
The server keeps asking for one until the one entered is not in use already.
![01](./01_welcome.png)

### Team selection
The player picks a team. Blue and orange are the only options for now.

![02](./02_team_selection.png)

### Role selection
The player picks a role: leader or member of the team.

![03](./03_role_selection.png)

### Board game display
The board game is shown to all players.  
A one-minute timer begins counting down to the first turn and the main game loop.

![04](./04_game_words.png)

### Key words display
The team leader is prompted to provide a hint.  
A one-minute timer begins counting down to the guessing stage of the turn.
![05](./05_key_words.png)

### Hint submission
The leader submits the hint for approval when ready.

![06](./06_hint_issued.png)

### Hint approval
The leader of the opposing team approves or rejects the hint.  
If the hint is rejected, the leader gets another minute to submit a new hint.  
If the hint is accepted, the hint is shown to the team members to guess the associated words.

![07](./07_hint_approval.png)

### Members guess words

The hint is shown to all players.  
A one-minute timer starts counting down.  
The team members pick the words they think are most closely associated with the hint, up to a maximum of the one set by the leader.

![08](./08_members_guess.png)

### First guess shown

The guesses are evaluated one by one, up to the maximum set by the team leader.  
The word is marked.  
If the guess is correct, the next word is evaluated.
If the guess is incorrect, the turn is over.

![09](./09_guess_1_shown.png)

### Second guess shown

The word is marked.  
The number set by the team leader is reached, so the turn ends.

![10](./10_guess_2_shown.png)

### Opposite team submits hint

The team leader of the opposite team is given a minute to submit a hint.

![11](./11_opposite_team_hint.png)

### Hint is approved or rejected

The hint is deemed appropriate, so it is accepted for the opposite team members to receive it.

![12](./12_opposite_hint_approval.png)

### Opposite team members guess

The members of the opposite team are given a minute to submit their guesses.

![13](./13_opposite_team_guessing.png)

### Oppsite team guesses are shown

The guesses submitted by the opposite team are evaluated and marked accordingly.

![14](./14_opposite_guesses_shown.png)

And so on, until all the keyed words of a given team are marked. The winning team is displayed then.