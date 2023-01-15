g++ -std=c++11 -o output -I/home/pi/tensorflow evalNeuronalNetwork.cpp libtensorflow-lite.a -pthread -lrt -ldl;
./output;
rm output;