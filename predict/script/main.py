import numpy as np
import csv

with open('../model/model_svm.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile)
    i = 0
    data = np.zeros((10,1024))
    means = np.zeros((1024, 1))
    scales =  np.zeros((1024, 1))
    iter = np.zeros(10)
    for row in spamreader:
        if(i==0):
            for j in range(1024):
                means[j, 0] = row[j]
        elif(i==1):
            for j in range(1024):
                scales[j, 0] = row[j]
        elif(i<10):
            for j in range(1024):
                data[i, j] = row[j]
        else:
            for j in range(10):
                iter[j] = row[j]
        i += 1

with open('descripteur.csv', newline='') as csvfile:
    x = list(csv.reader(csvfile))

a = np.zeros((1024, 1))
for i in range(len(x[0])):
    a[i, 0] = x[0][i]
a = (a-means)/(scales)

c = np.dot(data, a).T + iter;
# print(c.shape)
print((c))
print(np.argmax(c))