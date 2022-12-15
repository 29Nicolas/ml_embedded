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



def lecture_node(i):
    if(clf.tree_.children_left[i] == clf.tree_.children_right[i]):
        return "{return " + unique_label[np.argmax(clf.tree_.value[i])] + ";}"
    else:
        txt_1 = lecture_node(clf.tree_.children_left[i])
        txt_2 = lecture_node(clf.tree_.children_right[i])
        Text_1 = "if(X[" + str(clf.tree_.feature[i]) +"] <= " + str(clf.tree_.threshold[i]) + "){" + txt_1 + "}"
        Text_2 = "else{" + txt_2 + "}"
        return Text_1 + Text_2


with open('../archive/output/output3.csv', newline='') as csvfile:
    data = list(csv.reader(csvfile))
data = np.array(data)

label_names = data[:,1024]
unique_label = np.unique(label_names)
feature_values = data[:, :1024]

# split données
X_train, X_test, y_train, y_test = train_test_split(feature_values, label_names, test_size=0.33, random_state=43)

# Decision Tree Classifier
DecisionTreeClassifier_ml = make_pipeline(preprocessing.StandardScaler(), DecisionTreeClassifier())
DecisionTreeClassifier_ml.fit(X_train, y_train)
DecisionTreeClassifier_ml.score(X_test, y_test)

clf = DecisionTreeClassifier_ml['decisiontreeclassifier']

# print(clf.tree_.value[3])
clf = DecisionTreeClassifier_ml['decisiontreeclassifier']
n_nodes = clf.tree_.node_count
children_left = clf.tree_.children_left
children_right = clf.tree_.children_right
feature = clf.tree_.feature
threshold = clf.tree_.threshold
for i in range(n_nodes):
    if clf.tree_.children_left[i] == clf.tree_.children_right[i]:
        print(
            "node={node} is a leaf node.".format(
                node=i
            )
        )
    else:
        print(
            "node={node} is a split node: "
            "go to node {left} if X[:, {feature}] <= {threshold} "
            "else to node {right}.".format(
                node=i,
                left=children_left[i],
                feature=feature[i],
                threshold=threshold[i],
                right=children_right[i],
            )
        )

txt = lecture_node(2)
print(txt)

# from sklearn.tree import _tree

# def tree_to_code(tree, feature_names):
#     tree_ = tree.tree_
#     # feature_name = [
#     #     feature_names[i] if i != _tree.TREE_UNDEFINED else "undefined!"
#     #     for i in tree_.feature
#     # ]
#     # feature_names = [f.replace(" ", "_")[:-5] for f in feature_names]
#     # print("def predict({}):".format(", ".join(feature_names)))

#     def recurse(node, depth):
#         indent = "    " * depth
#         if tree_.feature[node] != _tree.TREE_UNDEFINED:
#             name = feature_names[node]
#             threshold = tree_.threshold[node]
#             print("{}if {} <= {}:".format(indent, name, np.round(threshold,2)))
#             recurse(tree_.children_left[node], depth + 1)
#             print("{}else:  # if {} > {}".format(indent, name, np.round(threshold,2)))
#             recurse(tree_.children_right[node], depth + 1)
#         else:
#             print("{}return {}".format(indent, tree_.value[node]))

#     recurse(0, 1)

# tree_to_code(clf, ['0','1','2','3','4','5','6','7','8','9', '10', '11', '12']);
