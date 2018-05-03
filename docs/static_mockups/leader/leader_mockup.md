## Gameplay Mockup: Leader

### Welcome screen
The player is prompted to enter a screen name.  
The server keeps asking for one until the one entered is not in use already.
![01](./01_name_entry.png)

### Team selection
The player picks a team. Blue and orange are the only options for now.

![02](./02_team_selection.png)

### Role selection
The player picks a role: leader or member of the team.

![03](./03_role_selection.png)

### Signal start

The leader can wait until enough players have joined to signal readiness to start.

![04](./04_start.png)

![04b](./04b_wait_start.png)

### Word grid display
The word list is shown to all players.  
A one-minute timer begins counting down to the first turn and the main game loop.

![05](./05_words_displayed.png)

### Key words display
The team leader is prompted to provide a hint.  
A one-minute timer begins counting down to the guessing stage of the turn.
![06](./06_hint_submission.png)

### Hint approval
The leader of the opposing team approves or rejects the hint.  
If the hint is rejected, the leader gets another minute to submit a new hint.  
If the hint is accepted, the hint is shown to the team members to guess the associated words.

![07](./07_wait_approval.png)

### Hint is shown to all players

The hint is shown to all players.  
A one-minute timer starts counting down.  

![08](./08_wait_guess.png)

### Members guess words

The team members pick the words they think are most closely associated with the hint, up to a maximum of the one set by the leader.

![09](./09_guess_submitted.png)
![10](./10_guess2_submitted.png)

### Opposite team submits hint

The team leader of the opposite team is given a minute to submit a hint.

![11](./11_wait_hint.png)

### Hint is approved or rejected

The hint is deemed appropriate, so it is accepted for the opposite team members to receive it.

![12](./12_hint_approval.png)

### Opposite team members guess

The members of the opposite team are given a minute to submit their guesses.

![13](./13_opposite_team_guessing.png)

### Opposite team guesses are shown

The opposite team submits guesses.

![14](./14_opposite_guess_shown.png)

And so on, until all the keyed words of a given team are marked. 

### Winner is shown

![15](./15_game_over.png)

