# cautomaton

## TODO:  
- [] Create a sysem for the automaton itself
- [] Create a way to display it
- [] Create a way to take user input for the rule and have it translated to binary
- [] Create a way to make the ruleset


## DUMITRU:
### 1D automaton
- [x] Make a rand generator
- [x] Let the user set itsown length for gens
- [x] Let user set length for number of gens
- [] ??? Allow the user to select or create the first gen 
- [X] Make input validation
- [] (MAYBE) Think about letting the user input a string of binary numbers
### 2D automaton (Ren's notes)
- [] Conys game
- [] Different 2d automaton
- [] Wrapping all sides

## COMPILING:
### To compile everythig
make
### To compile 1D automaton
make cautomatonv2
### To compile 2D automaton
make 2dcautomaton

## USAGE:
### 1D automatoma
- Basic run with random rule and defaults for generation length and number of generations
    - `./cautomatonv2`
- Run with rule 30, 100 generations and generation lenght of 40
    - `./cautomatonv2 30 100 40`
- Run with rule 32 with rest being defaults 
    - `./cautomatonv2 31`
- Run with rule 20, 120 generations and generation lenght of default
    - `./cautomatonv2 20 120`
- Run wiht random rule and other values specified
    - `./cautomanonv2 rand 50 32`


## Problems encountered:
### 1D
- Wanted to make a library file with all of the automaton function but kept running into memory management issues (pointers & seg faults)
- 



 
