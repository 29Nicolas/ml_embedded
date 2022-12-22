# ML_embedded

## Auteurs
- Mirado RAJAOMAROSATA
- Nicolas DEFOUR

## Structure du git
La branche main contient le code permettant l'entrainement et la prédiction. Le dossier entrainement contient les codes nécessaires à l'entrainement et le dossier predict ceux pour la prédiction sur la Rpi.

## Travail achevé
- La lecture fonctionne pour les deux plateformes (entrainement, inférence).
- l'extraction des descripteurs fonctionne pour les deux plateformes
- l'apprentissage du modèle en SVC et génére un fichier cvs pour enregistrer le modèle
- l'apprentissage du modèle d'arbre de decision fonctionne et génére un code cpp de décision
- normalisation après lecture pour arbre de décision
- prediction par l'ia arbre de decision
- prediction avec svc ok

## Travail en cours
- randomforest

## setup
 - cloner le repertoire et lancer le setup.sh (entrainement + prediction donc assez long)
 - pour clean (supprimer dossier temporaire ou des fichiers générés), utiliser clear.sh
 - pour prédire à partir de l'IA précédemment entrainé, utiliser predict.sh --> ce script compile l'algo de prédiction. Il suffit après de ce dépacer dans le dossier XXX/predict/build pour exécuter prediction_genre_musical en lui donnant en argument le nom de la musique (sans l'extension car uniquement les '.au' sont adapter pour le programme) puis en argument le nom des méthodes souhaitées (decisionTree ou/et svc)