# Picross
hanjie, logigraphe, griddler, nonogram, logimage
------------------------------------------------

Il va falloir harmoniser nos types (size_t, en fait, s'est pourri !)

Les grilles de picross qui nécéssitent un backtrack pour leur résolution peuvent,
dans certains cas, avoir des solutions multiples (exemple avec "heureux"), dans
d'autres cas, une solution unique (exemple avec "BT_1_sol")

Aussi, les picross à solutions multiples sont donc correctement résolus mais ne forment pas l'image attendue !

Dans le cas des picross à solutions multiples necessitant des backtracks successifs,
(exemple BT_2_sol) le placement des cases backtrackées à noir ou à blanc détermine, dans le cas noir, la solutions la plus à gauche, dans le cas blanc, la plus à droite.
