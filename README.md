# GameHub

**A personal game hub that keeps track of the user's information and is updated based on the games played. The game options are**
- **Rock Paper Scissors**
- **Tic Tac Toe**
- **Snake**
- **Wordle.**

### Login
The login process contains either registering or logging in into an existing account. This is done through file creation, entering a username, password (which is hidden from sight) and a score which is updated throughout the game process. The user's information is stored as an object of the class User and is passed through functions to be updated.

### Rock Paper Scissors

The usual Rock Paper Scissors game based on the input of the user and a random pick from ["Rock", "Paper", "Scissors"]. The program responds according to the regular Rock Paper Scissors rules and adds score to the user's account.

### Tic Tac Toe

Tic Tac Toe is a two player game, played on an output created board. Each player has a turn in which they pick an index to put their mark on. The game is over when one player wins and does not count towards the individual's account. This is done with input validation and replacing elements in the output created board.

### Snake

Snake is played using the WASD on the keyboard. It is one dot(.) that has a tail added every time a fruit(O) is caught. The user can only lose if the head of the snake touches it's tail. When the user is out of bounds, the snake will come out of the other side of the screen. This is done with X and Y coordinates for each component and modified accordingly inside of functions, such as the snake's tail following the head. Each element of the tail moves to the X and Y coordinates of the next element, creating a snake-like output consistent with the WASD movements.

### Wordle

The program picks a random 5 letter word from a file filled with them, and the user enters a 5 letter word which is validated.
- If the input word has a letter that exists in the random word and is placed exactly in the correct spot, the letter would be printed **green**.
- If the input word has a letter that exists in the random word and is incorrectly placed, the letter would be printed **yellow**.
- If the input word has a letter that does not exist within the random word, it would be printed out **regularly**.

The user wins if they guess the random word within 5 tries.

### Resources

[Login System with Registration & Filestoring & Filesystem C++ Tutorial Visual Studio](https://www.youtube.com/watch?v=I_aWPGCaaFA&list=PLGo2GDbIwEaOSi3gHgVNoF82YOSbXeGpG&index=22&ab_channel=HazardEdit)

[How To Make a Tic Tac Toe Game in C++ - QUICK AND EASY TUTORIAL](https://www.youtube.com/watch?v=OuEHYoCHGUQ&list=PLGo2GDbIwEaOSi3gHgVNoF82YOSbXeGpG&index=24&ab_channel=Devression)

[Snake Game in C++ in 20 minutes (Tutorial)](https://www.youtube.com/watch?v=gWq0tJLsjRs&list=PLGo2GDbIwEaOSi3gHgVNoF82YOSbXeGpG&index=28&t=802s&ab_channel=ErtjanArapi)

[C++ Tutorial 18 - Simple Snake Game (Part 3)](https://www.youtube.com/watch?v=PSoLD9mVXTA&list=PLGo2GDbIwEaOSi3gHgVNoF82YOSbXeGpG&index=29&ab_channel=NVitanovic)

[5-letter words](https://www.thefreedictionary.com/5-letter-words.htm)

[Colorizing text and console background in C++](https://www.geeksforgeeks.org/colorizing-text-and-console-background-in-c/)
