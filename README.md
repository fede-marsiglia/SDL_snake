# SDL_snake
A simple SDL 2.0 snake clone written in C

as the title states, this is a simple snake clone written in C, with a lightweight use of the SDL 2.0 libraries. The scope of
this project was to create something big enough to use the C language in nearly all its aspects, but not outrageously big. 
I tried to polish the implementation and structure of the game as much as I could, firstly for an ethical reason, and secondly to 
allow every c newbie out there (more like every programming newbie) to have a taste of a structured program of 
little dimensions (but yet larger and more complex than every textbook exercise) without having his head explode.

Talking about the implementation, there are few core data strutures which make up the game or are worth noting:

- struct snake
- struct food 
- struct buffer

the last structure is the snake's internal buffer, which is used every time he eats some food. It's role is to
take a snapshot of the last snake's block (we only need Its coordinate really) and maintain it for a game cycle.
After that cycle, the buffer is flushed, meaning that a new block is added to the snake, which is placed in the same 
spot where the old tail was lying. The reason is that, when the snake eats something, we cannot directly add a block
to his body, cause we could not know where to place it (above/below the last block, to his left/right?) so we decide to wait
one cycle and put it where the last piece was placed one cycle ago...And that's it

The rest of the implementation should be straightforward and easy to follow, so I will not spend any word commenting it
(let me know if you have troubles of course and I will fix this document).

I really hope that this tiny program will help all the starting programmers out there who are looking to extend their c 
knowledge. Let me know if it works for you and have fun :D!

