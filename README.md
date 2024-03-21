# PMD-Text-Generator
An experimental application which renders a dialogue box similar to that seen in the early Pokémon Mystery Dungeon games.

## Previews
![Cinderace](Previews/preview_01.gif "Cinderace")

## Notes
The project was originally meant for creating image sequences resembing mystery dungeon dialogue. As such program doesn't do much outside of displaying text. There exists code that has been commented out allowing the program to capture each frame of a given sequence. Restoring this is a simple matter of uncommenting the code which enables frame capturing and updating the number of captured frames to equal the length of the captured string.

## Usage
To build the project you will need a copy of [SFML 2.6.1](https://www.sfml-dev.org/download/sfml/2.6.1/) and [Pugixml-1.14](https://github.com/zeux/pugixml/releases/download/v1.14/pugixml-1.14.zip) in same folder as the project folder. SFML requires DLLs to be place in the build folder alongside the executable. Instructions on how to do this can be found on the SFML quickstart page.

## Credits
Font and interface uses sprites from Pokémon Mystery Dungeon: Explorers of Sky by Nintendo and Spike Chunsoft.
Character portraits were taken from the [PMD Sprite Repository](https://sprites.pmdcollab.org/).
