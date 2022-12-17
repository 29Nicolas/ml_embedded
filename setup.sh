cd entrainement;
mkdir build;
mkdir model;
cd build;
cmake ..;
make; 
./main;
cd ../scripts;
python3 DecisionTree.py;
python3 SVM.py;
cd ..;
cp -r model/ ../predict/