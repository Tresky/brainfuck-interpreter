# Brainfuck Interpreter

A very simple interpreter for Brainfuck programs. It was late one night, so I decided to try this. Turns out that it took all of about 30 minutes.

Brainfuck is an esoteric language that consists of only 8 commands. Amazingly, this language is actually Turing-complete; meaning that given enough time and memory, and a patient enough programmer, it can be used to solve any computational problem that any higher-level language could.

### Commands
* `>` ->	Increment the pointer.
* `<` ->	Decrement the pointer.
* `+` ->	Increment the byte at the pointer.
* `-` ->	Decrement the byte at the pointer.
* `.` ->	Output the byte at the pointer.
* `,` ->	Input a byte and store it in the byte at the pointer.
* `[` ->	Jump forward past the matching ] if the byte at the pointer is zero.
* `]` ->	Jump backward to the matching [ unless the byte at the pointer is zero.

### Test Files
* `hello.bf` should print `Hello World` to the terminal.
* `skiploop.bf` should simply execute and halt. If this test doesn't halt it means that loops are not being skipped properly.
* `add.bf` should add `2+5=7` and print the answer to the terminal.

For more information on Brainfuck: [http://www.muppetlabs.com/~breadbox/bf/](http://www.muppetlabs.com/~breadbox/bf/)
