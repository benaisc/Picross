# Picross
hanjie, logigraphe, griddler, nonogram, logimage
------------------------------------------------

Il va falloir harmoniser nos types (size_t, en fait, s'est pourri !)

Les grilles de picross qui nécéssitent un backtrack pour leur résolution peuvent,
dans certains cas, avoir des solutions multiples (exemple avec "heureux"), dans
d'autres cas, une solution unique (exemple avec "calendrier4")

Aussi, les picross à solutions multiples sont donc résolus mais ne forment pas
l'image attendue !
