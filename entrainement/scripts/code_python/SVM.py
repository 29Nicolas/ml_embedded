import csv
import numpy as np
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.svm import LinearSVC
from usefulCmdsAndFcns import get_metrics, plot_confusion_matrix
from sklearn.model_selection import train_test_split, cross_val_score


with open('../../predict/model/output.csv', newline='') as csvfile:
    data = list(csv.reader(csvfile))
data = np.array(data)

label_names = data[:,1024]
feature_values = data[:, :1024]

# split données
X_train, X_test, y_train, y_test = train_test_split(feature_values, label_names, test_size=0.33, random_state=43)

# SVM
svm = make_pipeline(preprocessing.StandardScaler(), LinearSVC())
svm.fit(X_train, y_train)
# score = svm.score(X_test, y_test)
# print("score : ", score)

# evaluation du modele
plot_confusion_matrix(y_test,svm.predict(X_test))
get_metrics(y_test,svm.predict(X_test))
scores = cross_val_score(svm, X_test, y_test)
print("Scores SVM: ",scores.mean())

# enregistrement du modele
with open('../../predict/model/model_svm.csv', 'w', encoding='UTF8') as f:
    # create the csv writer
    writer = csv.writer(f)

    # write a row to the csv file
    writer.writerow(svm['standardscaler'].scale_)
    writer.writerow(svm['standardscaler'].mean_)
    for i in range(10):
      writer.writerow(svm['linearsvc'].coef_[i,:])
    writer.writerow(svm['linearsvc'].intercept_)
    writer.writerow(svm['linearsvc'].classes_)