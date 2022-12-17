mkdir entrainement/build;
mkdir entrainement/model;
mkdir predict/model;
mkdir predict/build;
cd entrainement/build;
cmake ..;
make; 
./main;
cd ../scripts;
python3 DecisionTree.py;
python3 SVM.py;
cd ..;
cp model/*.csv ../predict/model/;
cp model/*.cpp ../predict/src;
cp model/*.h ../predict/src;
cd ../predict/build;
cmake ..;
make;
./main;