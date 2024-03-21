# PMD-Text-Generator
An experimental application which renders a dialogue box similar to that seen in the early Pokémon Mystery Dungeon games.

## Notes
The project was originally meant for creating image sequences resembing mystery dungeon dialogue. As such program doesn't do much outside of displaying text. There exists code that has been commented out allowing the program to capture each frame of a given sequence. Restoring this is a simple matter of uncommenting the code which enables frame capturing and updating the number of captured frames to equal the length of the captured string.

## Usage
To build the project you will need a copy of SFML 2.6.1 and Pugixml-1.14 in same folder as the project folder. For SFML to work it requires DLLs to be place in the build folder alongside the executable. Instructions on how to do this can be found on the SFML quickstart page. If there is any problems compiling the solution I would recommend checking the quickstart page for both SFML and Pugixml to make sure all the dependencies are being found by the project.
