# simple makefile

# define target dependencies and files
studybuddyapp: studybuddyapp.o studybuddy.o
	g++ -o studybuddyapp studybuddyapp.o studybuddy.o

# define how each object file is to be built
studybuddyapp.o: studybuddyapp.cpp studybuddy.h
	g++ -c studybuddyapp.cpp -Wall -Wextra -Wpedantic -std=c++11  

studybuddy.o: studybuddy.cpp studybuddy.h
	g++ -c studybuddy.cpp -Wall -Wextra -Wpedantic -std=c++11 

# clean up
clean:
	rm -f studybuddyapp.exe *.o