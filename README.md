# Résolveur Mathématique (Newton-Raphson et Intégration Numérique)

Ce projet est une application en C permettant de résoudre des équations non linéaires via la méthode de Newton-Raphson et de calculer des intégrales définies en utilisant les méthodes des trapèzes et de Simpson. Il intègre un analyseur lexical et syntaxique (parser) pour interpréter dynamiquement les fonctions mathématiques saisies par l'utilisateur.

## Exécutables précompilés pour test rapide

Avant d'entrer dans les détails de compilation, notez que des exécutables sont déjà fournis à la racine du projet pour vous permettre de tester rapidement l'application sans aucune installation.

Selon votre système d'exploitation, lancez depuis un terminal :
- Linux : `./main_linux`
- macOS : `./main_macos`
- Windows : `main_windows.exe`

## Fonctionnalités

1. Résolution d'équations (f(x) = 0)
   - Implémentation de la méthode de Newton-Raphson, sécurisée par des vérifications de type bissection.
   - Calcul exact et automatique des dérivées via l'arithmétique des nombres hyper-duaux.
   - Interprétation dynamique de la fonction et de l'intervalle de recherche.

2. Intégration numérique
   - Implémentation de la méthode des Trapèzes.
   - Implémentation de la méthode de Simpson.
   - Paramétrage du nombre de subdivisions pour le contrôle de la précision.

3. Analyseur d'expressions mathématiques
   - Analyse de chaînes de caractères (ex: `sin(x) + 2*x^2 - 5`) transformées en arbre syntaxique abstrait (AST) grâce à Flex et Bison.

## Compilation et Installation depuis les sources

Si vous souhaitez modifier le code ou compiler vous-même le projet, les prérequis suivants sont nécessaires :
- Un compilateur C (GCC recommandé)
- Make
- Flex
- Bison

### Instructions de compilation

1. Ouvrez un terminal à la racine du projet.
2. Lancez la commande suivante pour compiler le projet :
   ```bash
   make
   ```
   Le Makefile est conçu pour détecter votre système d'exploitation et générer l'exécutable correspondant (`main_linux`, `main_macos` ou `main_windows.exe`).
3. Pour supprimer les fichiers objets et générés lors de la compilation, utilisez :
   ```bash
   make clean
   ```

## Structure du projet

- `main.c` : Point d'entrée du programme, gère le menu principal.
- `solver/` : Cœur algorithmique du projet.
  - `calcul/` : Gestion de l'évaluation de l'AST et implémentation des nombres hyper-duaux pour la dérivation automatique.
  - `methods/` : Logique des algorithmes numériques (Newton-Raphson, Trapèzes, Simpson).
- `menu/` : Logique d'interaction utilisateur en ligne de commande (menus équation, intégrale, aide).
- `parse/` : Règles et grammaires Flex/Bison pour l'analyse lexicale et syntaxique des expressions et des intervalles.
- `utils/` : Structures de données fondamentales, incluant la gestion des arbres syntaxiques (AST).

## Guide d'utilisation

Au lancement, le programme affiche un menu interactif :

1. Résolution des équations (f(x)=0) : Vous serez invité à saisir une fonction (par exemple `cos(x) - x`), un intervalle de recherche (par exemple `[0, 1]`) et la précision souhaitée.
2. Calcul d'intégrale : Vous devrez choisir la méthode d'intégration, renseigner la fonction, l'intervalle d'intégration et le nombre de subdivisions.
3. Aide : Fournit des détails sur la syntaxe mathématique supportée (opérateurs, fonctions trigonométriques, etc.).
4. Quitter : Ferme l'application.
