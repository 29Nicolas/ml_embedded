import csv
import numpy as np
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.ensemble import RandomForestClassifier

def lecture_node(i):
    '''
    fonction permettant de parcourir l'arbre de décision de manière récursif et écrivant le code cpp permettant la décision
    prend en entrée le node i courant traité
    sort le texte correspondant au morceau de code de ses enfants
    '''
    if(clf.tree_.children_left[i] == clf.tree_.children_right[i]):
        # condition d'arret : le node est une feuille de l'arbre
        # "cout << \"" + unique_label[np.argmax(clf.tree_.value[i])] + "\" << endl;
        return "return " + str(np.argmax(clf.tree_.value[i])) + ";"
    else:
        # sinon on traite les enfants
        txt_1 = lecture_node(clf.tree_.children_left[i])
        txt_2 = lecture_node(clf.tree_.children_right[i])
        if(clf.tree_.feature[i] <512):
            feature = "mu["+str(clf.tree_.feature[i]) + "]"
        else:
            feature = "sigma[" + str(clf.tree_.feature[i]-512) + "]"
        Text_1 = "if("+ feature + " <= " + str(clf.tree_.threshold[i]) + "){" + txt_1 + "}"
        Text_2 = "else{" + txt_2 + "}"
        return Text_1 + Text_2


## lecture du fichier contenant les descripteurs
# extraction des informations du csv
with open('../../predict/model/output.csv', newline='') as csvfile:
    data = list(csv.reader(csvfile))
data = np.array(data)

label_names = data[:,1024]
unique_label = np.unique(label_names)
feature_values = data[:, :1024]

# split données
X_train, X_test, y_train, y_test = train_test_split(feature_values, label_names, test_size=0.33, random_state=43)


# Random Forest
RandomForest_ml = make_pipeline(preprocessing.StandardScaler(), RandomForestClassifier(n_estimators=100))
RandomForest_ml.fit(X_train, y_train)
score = RandomForest_ml.score(X_test, y_test)
print("score random forest : ", score)
# print(len(RandomForest_ml['randomforestclassifier'].estimators_))
nb_arbre = 100


## enregistrement de la normalisation
# open the file in the write mode
with open('../../predict/model/modelRandomForest.csv', 'w', encoding='UTF8') as f:
    # create the csv writer
    writer = csv.writer(f)
    # write a row to the csv file
    writer.writerow(RandomForest_ml['standardscaler'].scale_)
    writer.writerow(RandomForest_ml['standardscaler'].mean_)

## génération du code cpp
txt = ""
txt += "#include <iostream>  \n"
txt += "#include \"codeRandomForest.h\" \n"
txt += "using namespace std; \n \n"

##fonction de decision arbre
for i in range(nb_arbre):
    txt += "int decision_tree_" + str(i) + "(double mu[], double sigma[]){\n"
    clf = RandomForest_ml['randomforestclassifier'].estimators_[i]
    txt += lecture_node(0)
    txt += "}\n"
txt += "\n"

##Fonction max
txt += "int maxTableau(double tableau[10]){\n"
txt += "double max = tableau[0];\n"
txt += "int index_max = 0;\n"
txt += "for(int i=0;i<10;i++){"
txt += "if(max<tableau[i]){"
txt += "index_max = i;"
txt +="max = tableau[i];"
txt += "}}return index_max;}\n"
txt +="\n"

##Fonction affichage resultat genre musical
txt += "void affichageResultat(int indexMaxGenres){\n"
txt += "switch(indexMaxGenres){"
for i in range(len(RandomForest_ml['randomforestclassifier'].classes_)):
    txt += "case " + str(i) +" :\n"
    txt += "cout << \"" + RandomForest_ml['randomforestclassifier'].classes_[i] + "\" << endl;break;\n"
txt += "}}\n \n"

##Fonction Forest
txt += "int randomForest(double mu[], double sigma[]){\n"
txt += "double genres[10] = {0};\n"
for i in range(nb_arbre):
    txt += "genres[decision_tree_" + str(i) + "(mu, sigma)]++;\n";

txt += "int indexMaxGenres = maxTableau(genres);\n"
txt += "affichageResultat(indexMaxGenres);"
txt += "return indexMaxGenres;\n"
txt += "}"

# écriture du code dans le fichier
fichier = open("../../predict/src/codeRandomForest.cpp", "w")
fichier.write(txt)
fichier.close()

## ecriture du h
txt = "#ifndef CODE_RANDOM_FOREST__H \n#define CODE_RANDOM_FOREST__H \n"
for i in range(nb_arbre):
    txt += "int decision_tree_" + str(i) + "(double mu[], double sigma[]);\n"
txt += "int maxTableau(double tableau[10]);\n"
txt += "void affichageResultat(int indexMaxGenres);\n"
txt += "int randomForest(double mu[], double sigma[]);\n"
txt += "#endif"
fichier = open("../../predict/src/codeRandomForest.h", "w")
fichier.write(txt)
fichier.close()
