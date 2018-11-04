Project Name: Wormhole

Background Architecture:
-> A mesh simulates a galaxy and the movement in between separate star systems
-> Each star system contains an array of objects (planets) 
-> Each planet is a grid, that is dynamically created that allows for variable terrain.
    -> This terrain should be created with a mathematical function that can be stored so that the planet name and number can be used as seed values.

Classes to be used:
-> system
    -> x coordinate
    -> y coordinate
    -> z coordinate
    -> unary star systems all of them
    -> name loaded from a file containing names + a random number
    -> system * parent
    -> system * left
    -> system * right
    -> system * child_left
    -> system * child_right
    -> number of planets
    -> planet array;
    -> allegiance
    -> size of star
-> planet
    -> oxygen content
    -> carbon content
    -> water percentage
    -> metal content
    -> life factor (if in the 99.9th percentile, then yes, life exists, else, just a barren planet)
    -> temperature (depends on size of star system);
    -> outpost or not;
    -> 3x3 grid that'll be procedurally generated;
    -> name of system it belongs to
-> ship
    -> top speed (multiple of c)
    -> cruising speed (multiple of c < c)
    -> capacity
    -> fuel source
    -> allegiance
    -> firepower (float val)
    -> shield strength
    -> vessel category
-> person
    -> allegiance
    -> position in space

Files Required
-> systems.dat : lists all the systems
-> planets.dat : lists all planets in order of system 
-> names.dat : lists names in alphabetical order and is used to randomly assign a name to planet/star
-> progress.dat : charts course through system/planets + logs all activities
