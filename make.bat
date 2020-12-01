del main.exe
del build
mkdir build 

g++ -static -O2 -Wall -std=gnu++17 -c constants.cpp -o build\constants.o
g++ -static -O2 -Wall -std=gnu++17 -c timestamp.cpp -o build\timestamp.o
g++ -static -O2 -Wall -std=gnu++17 -c data_point.cpp -o build\data_point.o
g++ -static -O2 -Wall -std=gnu++17 -c fenwick_tree.cpp -o build\fenwick_tree.o
g++ -static -O2 -Wall -std=gnu++17 -c file_reader.cpp -o build\file_reader.o
g++ -static -O2 -Wall -std=gnu++17 -c database.cpp -o build\database.o
g++ -static -O2 -Wall -std=gnu++17 -c operation.cpp -o build\operation.o
g++ -static -O2 -Wall -std=gnu++17 -c main.cpp -o build\main.o
g++ -static -O2 -Wall -std=gnu++17 -o main.exe build\main.o build\constants.o build\data_point.o build\timestamp.o build\fenwick_tree.o build\file_reader.o build\database.o build\operation.o


