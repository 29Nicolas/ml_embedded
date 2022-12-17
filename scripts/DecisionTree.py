import csv
import numpy as np
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.tree import DecisionTreeClassifier


def lecture_node(i):
    '''
    fonction permettant de parcourir l'arbre de décision de manière récursif et écrivant le code cpp permettant la décision
    prend en entrée le node i courant traité
    sort le texte correspondant au morceau de code de ses enfants
    '''
    if(clf.tree_.children_left[i] == clf.tree_.children_right[i]):
        # condition d'arret : le node est une feuille de l'arbre
        return "cout << '" + unique_label[np.argmax(clf.tree_.value[i])] + "' << endl; return '" + unique_label[np.argmax(clf.tree_.value[i])] + "';"
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
with open('../archive/output/output3.csv', newline='') as csvfile:
    data = list(csv.reader(csvfile))
data = np.array(data)

label_names = data[:,1024]
unique_label = np.unique(label_names)
feature_values = data[:, :1024]

# split données
X_train, X_test, y_train, y_test = train_test_split(feature_values, label_names, test_size=0.33, random_state=43)

# Decision Tree Classifier: entrainement de l'IA
DecisionTreeClassifier_ml = make_pipeline(preprocessing.StandardScaler(), DecisionTreeClassifier())
DecisionTreeClassifier_ml.fit(X_train, y_train)
DecisionTreeClassifier_ml.score(X_test, y_test)
clf = DecisionTreeClassifier_ml['decisiontreeclassifier']

# génération du code cpp
txt = "string decision_tree(double mu[], double sigma[]){"
txt += lecture_node(0)
txt += "}"

# écriture du code dans le fichier
fichier = open("code.cpp", "a")
fichier.write(txt)
fichier.close()