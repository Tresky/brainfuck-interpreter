# Brainfuck Interpreter

A very simple interpreter for Brainfuck programs. It was late one night, so I decided to try this. Turns out that it took all of about 30 minutes.

Brainfuck is an esoteric language that consists of only 8 commands:

* `>` ->	Increment the pointer.
* `<` ->	Decrement the pointer.
* `+` ->	Increment the byte at the pointer.
* `-` ->	Decrement the byte at the pointer.
* `.` ->	Output the byte at the pointer.
* `,` ->	Input a byte and store it in the byte at the pointer.
* `[` ->	Jump forward past the matching ] if the byte at the pointer is zero.
* `]` ->	Jump backward to the matching [ unless the byte at the pointer is zero.
