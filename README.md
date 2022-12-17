# ML_embedded

## Auteurs
 - Mirado RAJAOMAROSATA
- Nicolas DEFOUR

## Structure du git
La branche main contient le code permettant l'entrainement et la prédiction. Le dossier entrainement contient les codes nécessaires à l'entrainement et le dossier predict ceux pour la prédiction sur la Rpi.

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

## setup
 - cloner le repertoire et lancer le setup.sh 
 - pour relancer, lancer resetup.sh
 - pour clean (supprimer dossier temporaire ou des fichiers générés), utiliser clear.sh