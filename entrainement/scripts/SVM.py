import csv
import numpy as np
from sklearn import preprocessing
from sklearn.model_selection import train_test_split, cross_val_score, GridSearchCV
from sklearn.linear_model import LogisticRegression
from sklearn.neural_network import MLPClassifier
from sklearn.svm import SVC
from sklearn.pipeline import make_pipeline
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import LinearSVC
from sklearn.tree import DecisionTreeClassifier


with open('../../archive/output/output3.csv', newline='') as csvfile:
    data = list(csv.reader(csvfile))
data = np.array(data)

label_names = data[:,1024]
feature_values = data[:, :1024]

# split données
X_train, X_test, y_train, y_test = train_test_split(feature_values, label_names, test_size=0.33, random_state=43)

# SVM
svm = make_pipeline(preprocessing.StandardScaler(), LinearSVC())
svm.fit(X_train, y_train)
svm.score(X_test, y_test)

# open the file in the write mode
with open('../model/model_svm.csv', 'w', encoding='UTF8') as f:
    # create the csv writer
    writer = csv.writer(f)

    # write a row to the csv file
    writer.writerow(svm['standardscaler'].scale_)
    writer.writerow(svm['standardscaler'].mean_)
    for i in range(10):
      writer.writerow(svm['linearsvc'].coef_[i,:])
    writer.writerow(svm['linearsvc'].intercept_)