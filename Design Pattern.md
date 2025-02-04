Design Pattern Composite pour la fin de l’Étape 1

1. Classes à mettre en place :
	•	Une classe abstraite de base Expression :
	•	Contient une méthode virtuelle pure evaluate() pour évaluer l’expression.
	•	Permet d’unifier les feuilles (constantes et variables) et les opérateurs.
	•	Classes dérivées :
	•	Constante : Représente une feuille avec une valeur entière fixe.
	•	Variable : Représente une feuille avec un nom de variable (un caractère).
	•	OperatorNode : Représente un nœud opérateur, qui contient un opérateur et deux sous-arbres (en tant qu’objets Expression).

2. Avantages :
	•	L’arbre devient modulaire et extensible (on peut ajouter de nouveaux types de nœuds facilement).
	•	La gestion des sous-arbres est simplifiée avec des pointeurs intelligents.