Scope of this project is to end up being a chess game that handles chess matches and offers bots of different "difficulties" (different chess engine depths between 1 and, say, 5 or so)

This project WON'T implement advanced techniques, like DSA III stuff. It won't be an optimised chess engine, just a naive brute-forcing analysis of all the legal moves every single turn and choosing the most valuable one each turn.

Right now it has the board and one piece, the knight, which you can move anywhere if it's a legal move :D

To-do list:
* Fix the knight from falling off the board by discarding tiles outside the range of (0 <= i < 8, 0 <= j < 8)
* Add the movement of the rest of the pieces
