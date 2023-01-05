## import des librairies
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import tensorflow as tf
from sklearn.model_selection import train_test_split
from sklearn import preprocessing
from tensorflow.keras.models import Sequential
from tensorflow import keras
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout


## importer les data
data = pd.read_csv('../../../predict/model/output.csv')
data = np.array(data.values)
label_names = data[:,1024]
unique_label = np.unique(label_names)
feature_values = data[:, :1024]


# split données
X_train, X_test, y_train, y_test = train_test_split(feature_values, label_names, test_size=0.33, random_state=43)


# enc labelNames to indices
encName2Ind = preprocessing.LabelEncoder()
encName2Ind.fit(unique_label)
labelIndices_unique = encName2Ind.transform(unique_label)
labelIndices  = encName2Ind.transform(label_names)

# Conversion des noms des labels en indices
labelInd_train = encName2Ind.transform(y_train)
labelInd_test = encName2Ind.transform(y_test)

X_train = tf.convert_to_tensor(X_train, dtype=tf.float32)
X_test = tf.convert_to_tensor(X_test, dtype=tf.float32)
y_train = tf.convert_to_tensor(labelInd_train, dtype=tf.float32)
y_test = tf.convert_to_tensor(labelInd_test, dtype=tf.float32)


# Normalisation 
images_mean = np.mean(X_train, axis=0, keepdims=True)
images_std = np.std(X_test, axis=0, keepdims=True) + 1e-7
X_train = (X_train - images_mean) / images_std
X_test = (X_test - images_mean) / images_std


## creation du reseau de neuronne
model = Sequential(name="Sequential_CNN")
# couche de classification
model.add(Dense(256, activation='relu', input_shape = [1024]))
model.add(Dense(len(unique_label), activation='softmax'))


# paramètres
NB_EPOCHS = 40
LEARNING_RATE = 0.1
MOMENTUM = 0.09
DECAY = 0.01

#  Choix de la tâche à effectuer = choix de la fonction de loss/pertes/coûts à minimise
loss_fcn = tf.keras.losses.SparseCategoricalCrossentropy()# sans alias

# compilation ...
model.compile(loss=loss_fcn, optimizer='ADAM', metrics=['accuracy'])
#model.compile(loss='mean_squared_error', optimizer=optimizer, metrics=['mean_asbolute_error', 'mean_squared_error'])

#... et entrainement
history = model.fit(X_train, y_train, epochs=NB_EPOCHS)


score = model.evaluate(X_test, y_test)
print(score)
from sklearn.metrics import confusion_matrix, classification_report
#Confution Matrix and Classification Report
Y_pred = model.predict(X_test)
y_pred = np.argmax(Y_pred, axis=1)
print()
print()
print('Confusion Matrix')
print(confusion_matrix(y_test, y_pred))
print()
print()
print('Classification Report')
print(classification_report(labelInd_test, y_pred, target_names=unique_label))
# ------------------------------------------------>


# Convert the model.
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()

# Save the model.
with open('../../../predict/model/model.tflite', 'wb') as f:
  f.write(tflite_model)




