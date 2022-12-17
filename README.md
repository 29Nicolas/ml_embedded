# ML_embedded

## Auteurs
 - Mirado RAJAOMAROSATA
- Nicolas DEFOUR

## Structure du git
La branche main contient le code permettant l'entrainement et la prédiction. Le dossier entrainement contient les codes nécessaires à l'entrainement et le dossier predict ceux pour la prédiction sur la Rpi.

La branche traitement_parallele_openMP contient une amélioration de l'extraction des descripteurs par du calcul parallèle (pas demandé dans le sujet du projet). Merge avec la branch main (fait)

La branche plateforme_inference n'est plus utilisé et plus à jour. Suppression dans peu de temps

## Travail achevé
- La lecture fonctionne pour les deux plateformes (entrainement, inférence).
- l'extraction des descripteurs fonctionne pour les deux plateformes
- l'apprentissage du modèle en SVC et génére un fichier cvs pour enregistrer le modèle
- l'apprentissage du modèle d'arbre de decision fonctionne et génére un code cpp de décision
- normalisation après lecture pour arbre de décision
- prediction par l'ia arbre de decision

## Travail en cours
- vérifier le fonctionnement de arbre de decision et des prédictions faites (evaluation du modele pour vérifier si le code est ok)
- prédiction par SVC

## setup
 - cloner le repertoire et lancer le setup.sh 
 - pour relancer, lancer resetup.sh
 - pour clean (supprimer dossier temporaire ou des fichiers générés), utiliser clear.sh