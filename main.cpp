#include "headers/Constante.h"
#include "headers/Variable.h"
#include "headers/Operator_t.h"
#include "headers/Expression.h"
#include "headers/OperatorNode.h"
#include <unordered_map>
#include <memory>
#include <iostream>

int main() {
    try {
        // Contexte pour les variables
        std::unordered_map<char, int> contexte = {{'x', 2}, {'y', 4}};

        // Construction de l'arbre pour : x + (3 * y)
        auto gauche = std::make_unique<Variable>('x', contexte);
        auto droite = std::make_unique<OperatorNode>(
            Operator_t('*'),
            std::make_unique<Constante>(3),
            std::make_unique<Variable>('y', contexte)
        );
        auto racine = std::make_unique<OperatorNode>(Operator_t('+'), std::move(gauche), std::move(droite));

        // Évaluation de l'expression
        std::cout << "Résultat de l'expression : " << racine->evaluate() << std::endl;

        // Affichage de l'expression
        std::cout << "Expression : ";
        racine->afficher();
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}