COMPILER  = g++

DEBUG  = -g

EXE  = app

HDRS  = WordData.h\
	WordDataList.h\
	WordList.h\
        CLinkedList.h\
        WordCList.h\
        WordVectorList.h\

OBJS  = WordData.o\
	WordDataList.o\
	app.o\
	WordCList.o\
        WordVectorList.o\


SRC  = 	WordData.cpp\
	WordDataList.cpp\
	app.cpp\
	WordCList.cpp\
        WordVectorList.cpp\


##########################################################################
$(EXE): $(OBJS) $(HDRS) $(SRC)
	$(COMPILER) -o $(EXE) $(OBJS) $(DEBUG)

WordData.o:  WordData.cpp WordData.h 
	$(COMPILER) -c WordData.cpp $(DEBUG)

WordDataList.o:  WordData.h WordDataList.cpp WordDataList.h WordList.h 
	$(COMPILER) -c WordDataList.cpp $(DEBUG)

app.o:  WordDataList.h WordList.h app.cpp 
	$(COMPILER) -c app.cpp $(DEBUG)

WordCList.o:	CLinkedList.h WordCList.cpp WordCList.h WordList.h 
	$(COMPILER) -c WordCList.cpp $(DEBUG)

WordVectorList.o:   WordVectorList.cpp WordVectorList.h WordList.h
	$(COMPILER) -c WordVectorList.cpp $(DEBUG)

clean:
	rm *.o $(EXE)

