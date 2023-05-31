g++ -std=c++11 File/file.cpp -c
mv file.o obj
g++ -std=c++11 main.cpp obj/file.o -o out
mv out builds