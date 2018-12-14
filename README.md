# Filler

Filler est un jeu algorithmique qui consiste à remplir une grille d’une taille connue à l’avance avec des pièces de taille et de formes aléatoires, sans que les pièces ne se su- perposent de plus d’une seule case et sans qu’elles ne depassent de la grille. Si l’une de ces conditions n’est pas remplie, la partie s’arrête.

Chaque pièce posée avec succès rapporte un certain nombre de points, et a un seul joueur, le but du jeu pourrait être d’obtenir le meilleur score possible. Cepedant, c’est avec deux joueurs que le filler prend tout son intérêt. Chaque joueur a pour but de poser un maximum de pièces tout en tentant d’empêcher son adversaire de le faire. A la fin de la partie, celui avec le plus de point remporte le match...

Le but est de créer un joueur de Filler. A chaque tour, le joueur actif reçoit l’état de la grille et doit maximiser ses points tout en tentant de minimiser ceux de l’adversaire en l’éliminant le plus vite possible.

Les objectifs de ce projet rassemblent toujours les objectifs usuels des projets de dé- but de cursus : rigueur, pratique du C et pratique d’algorithmes élémentaires. Mais à la différence d’un jeu plus simple comme le Fillit, il ne s’agit plus de simplement agencer ses pièces le plus efficacement possible, mais maintenant d’empêcher son adversaire de le faire! Il vous faudra donc créer un algorithme de remplissage pour contrer l’algorithme ennemi.