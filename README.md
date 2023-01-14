# ML_embedded

## Auteurs
- Mirado RAJAOMAROSATA
- Nicolas DEFOUR

## Structure du git

La branche **main** contient l'ensemble des différents code de ce projet.

* :file_folder: [/Support-20221129](Support-20221129) : **dossier contenant les codes fournis**
$\qquad$ :file_folder: [C++](/Support-20221129/C++) : fonctions utiles pour l'extraction des descripteurs (fft)  
$\qquad$ :file_folder: [Python](/Support-20221129/Python/) : check pour de l'extraction
* :file_folder: [/entrainement](entrainement) : **codes de la plateforme d'entrainement**  
$\qquad$ :file_folder: [/entrainement/src](entrainement/src) :  contient le code permettant l'extraction des descripteurs de l'ensemble des données  
$\qquad$ :file_folder: [/entrainement/scripts](entrainement/scripts) : contient les codes d'entrainement et d'évaluation des modèles (en jupyter notebook, code au format python disponible dans le dossier /entrainement/scripts/code_python)

* :file_folder: [/predict](predict) : **dossier contenant les codes pour la prédiction sur la plateforme d'inférence**  
$\qquad$ :file_folder: [/predict/model](predict/model) : contient les modèles enregistrés sur la plateforme d'entrainement  
$\qquad$ :file_folder: [/predict/src](predict/src) : contient les différents codes de prédiction et d'évaluation des modèles (ainsi que les codes utiles fournis (fft)).


## Travail effectué
- La lecture fonctionne pour les deux plateformes (entrainement, inférence).
- l'extraction des descripteurs fonctionne pour les deux plateformes
- l'apprentissage du modèle en SVC et génére un fichier cvs pour enregistrer le modèle
- l'apprentissage du modèle d'arbre de decision fonctionne et génére un code cpp de décision
- prediction et évaluation du modèle arbre de decision
- prediction et évaluation du modèle svc
- prediction et évaluation du modèle randomforest 
- apprentissage et évaluation du modèle de réseau de neurone
- extraction du réseau de neurone en tflite
- prédiction et évaluation du modèle de réseau de neurone

## Dependances

Sur un ordinateur sous Ubuntu 20.04, commencer par mettre à jour :

```bash
sudo apt update
pip install --upgrade pip
sudo apt install python3-venv -y
```
 Installer l'environnement virtuel contenant tensorflow :
 ```bash
python3 -m venv vultr-tensorflow
 ```
 Puis source l'environnement dans le terminal:
 ```bash
source vultr-tensorflow/bin/activate
 ```
 Enfin, installer les autres packages utiles si nécessaire comme numpy, matplotlib et pandas.

 ## Cloner le répertoire
Vous pouvez maintenant récuperer le projet en clonant le git :
```bash
git clone https://gitlab.ensta-bretagne.fr/defourni/ml_embedded.git
```

## Build l'entrainement des modèles

Pour build, il faut commencer par toujours sourcer l'environnement virtuel sur chaque nouveau terminal: 
```bash
source vultr-tensorflow/bin/activate
 ```

 Puis ce déplacer dans le dossier clonné : 
 ```bash
 cd ml_embedded
 ```

Le répertoire contient les différents fichiers temporaires crées comme celui contenant l'ensemble des descripteurs de chaque individu de l'ensemble des données ou encore ceux contenant les enregistrements des modèles entrainés . Il n'est donc pas forcement utile de build l'ensembe du projet.

* Pour build et réaliser l'entrainement sur la plateforme d'entrainement, il faut commencer par créer un dossier 'archive' à la racine de 'ml_embedded' contenant le dossier 'genres' avec à l'intérieur les dossiers contenant les audios.

* Ensuite, passer à l'extraction des descripteurs des données :
````bash
mkdir -p entrainement/build
cd entrainement/build
cmake ..
make
./main 
cd ../..
````
Ce programme crée le fichier **[output.csv](predict/model/output.csv)** dans le répertoire [/predict/model](predict/model/)

* Créer, entrainer et évaluer les différents modèles:  
2 méthodes sont possible:  
$\qquad$ - ouvrir les jupyter notebook de chaque modèle ranger dans le dossier [/entrainement/scripts](/entrainement/scripts)  
$\qquad$ - utiliser les codes au format .py:
````bash
cd entrainement/scritps/code_python
python3 DecisionTree.py
python3 RandomForest.py
python3 SVM.py
python3 reseauNeurone.py
cd ../../..
````
Ces programmes vont enregistrer les modèles entrainés dans le répertoire [/predict/model](predict/model/) et les codes générés dans le répertoire [/predict/src](/predict/src/). A cette étape, on peut voir les performances des modèles par leur évaluation.

**L'entrainement est terminer**

## Build la prédiction

* Copier les dossiers [/predict](/predict/) sur l'ordinateur embarqué (Rpi) 

* Compiler le code cpp: 
````bash
mkdir -p predict/build
cd predict/build
cmake ..
make
````
* Prédire le genre de l'audio souhaité en utilisant le modèle souhaité : 
````bash 
./ main <nom_audio_sans_extension> <nom_modele> <nom_modele> 
````
nom_modele sont : 
 - decisionTree
 - svc
 - randomForest

 Pour utiliser le réseau de neurone, il faut copier le fichier [/predict/model/model.tflite](/predict/model/model.tflite) et l'ensemble de test [/predict/model/test_dataset.h](/predict/model/test_dataset.h) dans le dossier /exemple de la carte rpi (avec l'image du projet contenant tensorflow lite).  
 Puis build, par la commande g++ écrite dans le fichier 'makefile'.  
 Enfin, prédire et évaluer le modèle en exécutant : 
 ```bash
 ./output
 ```