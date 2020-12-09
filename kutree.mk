# Makefile for the new ntuple processing
main: histset.o KUTree.o ParTreeProcessing.C
	g++ -o compiledThreads ParTreeProcessing.C -pthread `root-config --cflags --libs`

histset.o: histset.C SUSTools.h KUTree.o
	g++ -c -pthread histset.C `root-config --cflags --libs`

KUTree.o: KUTree.C KUTree.h
	g++ -c -pthread KUTree.C `root-config --cflags --libs`

clean:
	rm *.o
