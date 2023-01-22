# ML_embedded

## Auteurs
- Mirado RAJAOMAROSATA
- Nicolas DEFOUR

## Structure du git

La branche **main** contient l'ensemble des différents code de ce projet.

* :file_folder: [/Support-20221129](Support-20221129) : **dossier contenant les codes fournis**
     *  :file_folder: [C++](/Support-20221129/C++) : fonctions utiles pour l'extraction des descripteurs (fft)  
     *  :file_folder: [Python](/Support-20221129/Python/) : check pour de l'extraction
* :file_folder: [/entrainement](entrainement) : **codes de la plateforme d'entrainement**  
    * :file_folder: [/entrainement/creation_dataset](entrainement/creation_dataset) :  contient le code permettant l'extraction des descripteurs de l'ensemble des données  
    * :file_folder: [/entrainement/model](entrainement/model) : contient les codes d'entrainement et d'évaluation des modèles (en jupyter notebook)

* :file_folder: [/inference](inference) : **dossier contenant les codes pour la prédiction sur la plateforme d'inférence**  
     *  :file_folder: [/predict/utils](predict/utils) :contient des fonctions communes à plusieurs modèles comme les codes utiles fournis (fft).  
     *  :page_facing_up: [dataset.csv](dataset.csv) : contient les descripteurs de tous les individus de l'ensemble des données.  
     *  :file_folder: [/inference/SVC](predict/SVC) : contient les codes pour l'utilisation du modèle SVC  
     *  :file_folder: [/predict/DecisionTree](predict/DecisionTree) : contient les codes pour l'utilisation du modèle Decision Tree  
     *  :file_folder: [/predict/RandomForest](predict/RandomForest) : contient les codes pour l'utilisation du modèle Random Forest  
     *  :file_folder: [/predict/NeuronalNetwork](predict/NeuronalNetwork) : contient les codes pour l'utilisation du modèle Neuronal Network  

Dans chaque répertoire de modèle, on retrouve :  
- 'predict_<nom_modele>.cpp' permettant de prédire le genre musical de la musique souhaité
- 'eval_<nom_modele>.cpp' permettant d'évaluer l'accuracy et la comparer avec celle obtenue sur la plateforme d'apprentissage.
- 'test_dataset.h', fichier contenant l'ensemble de test identique à la plateforme d'apprentissage pour pouvoir comparer les performances
- makefile.sh : contenant les lignes de commande pour compiler les codes avec g++
- fichiers contenant le modèle appris (code cpp/h et/ou csv ou ...)




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
cd entrainement/creation_dataset
chmod +x creation_dataset.sh
````
Ce programme crée le fichier **[dataset.csv](inference/dataset.csv)** dans le répertoire [/inference](inference)

* Créer, entrainer et évaluer les différents modèles en ouvrant les jupyter notebook de chaque modèle ranger dans le dossier [/entrainement/model](/entrainement/model)  

Ces programmes vont enregistrer les modèles entrainés et les codes générés dans leur répertoire respectif de [/inference/](inference/). A cette étape, on peut voir les performances des modèles par leur évaluation.

**L'entrainement est terminer**

## Utilisation des modèles sur la plateforme d'inférence

* Copier les dossiers [/inference](/inference/) sur l'ordinateur embarqué (Rpi) 

* Choisir le dossier du modèle souhaité entre SVC, DecisionTree, RandomForest.

* Générer les exécutables pour réaliser la prédiction et l'évaluation du modèle:
````bash
chmod +x makefile.sh; 
./makefile.sh
````

* Pour évaluer la performance et la comparer avec la plateforme d'apprentissage (normalement égale):
````bash
./eval
````

* Il est aussi possible de prédire le genre d'un audio souhaité mais il faut avoir le fichier audio dans le repertoire archive/genres/nom_genre/fichier_audio avec archive au même niveau que inference (utiliser pour débogguer pendant le dev): 
````bash 
./predict <nom_audio_sans_extension>
````

* Pour le réseau de neurone, se placer dans le répertoire associé puis compiler les codes:
````bash
cd NeuronalNetwork
./makefile.sh
````
 pour évaluer les performances avec le modèle non optimisé :
 ````bash
 ./output
 ````
 pour le modèle optimisé (qui ne fonctionne pas à cause d'un problème de version de tensorflowlite)
 ````bash
 ./output_optimizer 
 ````
