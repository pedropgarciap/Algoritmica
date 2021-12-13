CXXFLAGS = -std=c++11 -o

CXXFLAGS_O = -c -std=c++11

all: main

main : algoritmos.o sistemaEcuaciones.o miscelanea.o ficheros.o ClaseTiempo.o calculosTiempos.o calculosMatematicos.o calculosEstadisticos.o 
	g++ $(CXXFLAGS) main Menu.cpp algoritmos.o sistemaEcuaciones.o miscelanea.o ficheros.o ClaseTiempo.o calculosTiempos.o calculosMatematicos.o calculosEstadisticos.o

algoritmos.o : algoritmos.cpp 
	g++ $(CXXFLAGS_O) algoritmos.cpp 

sistemaEcuaciones.o : sistemaEcuaciones.cpp
	g++ $(CXXFLAGS_O) sistemaEcuaciones.cpp

miscelanea.o : miscelanea.cpp
	g++ $(CXXFLAGS_O) miscelanea.cpp

ficheros.o : ficheros.cpp 
	g++ $(CXXFLAGS_O) ficheros.cpp

ClaseTiempo.o : ClaseTiempo.cpp 
	g++ $(CXXFLAGS_O) ClaseTiempo.cpp 

calculosTiempos.o : calculosTiempos.cpp
	g++ $(CXXFLAGS_O) calculosTiempos.cpp 

calculosMatematicos.o : calculosMatematicos.cpp
	g++ $(CXXFLAGS_O) calculosMatematicos.cpp

calculosEstadisticos.o : calculosEstadisticos.cpp
	g++ $(CXXFLAGS_O) calculosEstadisticos.cpp

.PHONY: clean

clean:
	rm -f main *.o
