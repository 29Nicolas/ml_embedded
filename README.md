# ML_embedded

## Auteurs
 - Mirado RAJAOMAROSATA
- Nicolas DEFOUR

## Structure du git
La branche main contient le code permettant l'entrainement c'est-à-dire l'extraction des descripteurs en générant un fichier csv pour pouvoir entrainer l'IA en cpp. Puis en python, l'apprentissage du modèle de l'IA, la génération du code pour l'arbre de Decision ou la création d'un fichier csv contenant le modèle entrainé. 

La branche traitement_parallele_openMP contient une amélioration de l'extraction des descripteurs par du calcul parallèle (pas demandé dans le sujet du projet)

La branche plateforme_inference est la branche de prédicition qui tournera sur la RPi c'est-à-dire la lecture d'un seul fichier audio, l'extraction de ces descripteurs, la prédiction par le modèle.

## Travail achevé
- La lecture fonctionne pour les deux plateformes (entrainement, inférence).
- l'extraction des descripteurs fonctionne pour les deux plateformes
- l'apprentissage du modèle en SVC et génére un fichier cvs pour enregistrer le modèle
- l'apprentissage du modèle d'arbre de decision fonctionne et génére un code cpp de décision

## Travail en cours
- normalisation après lecture pour arbre de décision
- prédicition par SVC