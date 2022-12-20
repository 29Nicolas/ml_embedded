import numpy as np
import csv

with open('../model/model_svm.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile)
    i = 0
    data = np.zeros((10,1024))
    iter = np.zeros(10)
    for row in spamreader:
        if(i<10):
            for j in range(1024):
                # print(row[j])
                data[i, j] = row[j]
        else:
            for j in range(10):
                # print(row[j])
                iter[j] = row[j]
        i += 1

with open('descripteur.csv', newline='') as csvfile:
    x = list(csv.reader(csvfile))
x = np.array(x)
print((x.T).shape)
print(data.shape)
c = data@x+iter;
print(c)