# Picross
hanjie, logigraphe, griddler, nonogram, logimage
------------------------------------------------

Limitations :
Les grilles de picross qui nécéssitent un backtrack pour leur résolution peuvent,
dans certains cas, avoir des solutions multiples (exemple avec "heureux"), dans
d'autres cas, une solution unique (exemple avec "BT_1_sol")

Aussi, les picross à solutions multiples sont donc correctement résolus mais ne forment pas l'image attendue !
Dans ce cas, (exemple BT_2_sol) nous avons choisi de placer les cases backtrackées à noir et nous déterminons ainsi la solution la plus à gauche possible.
------------------------------------------------

- Installer au préalable la bibliotheque graphique "libgtkmm-3.0-dev"
- Compiler le programme avec un simple "make"
- Grilles de Picross dans le fichier Grilles/
- Page web de documentation disponible dans le dossier html/ avec le fichier Index.html
- Rapport au format pdf dans le dossier Rapport\
