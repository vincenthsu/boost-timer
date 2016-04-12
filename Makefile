TARGET = simple-timer

all: *.cpp
	g++ *.cpp -o $(TARGET) -lboost_system -lboost_thread

clean:
	rm $(TARGET)

