project: main.o touch_switch.o rotary_encoder.o
	g++ main.o touch_switch.o rotary_encoder.o -o project.o

main.o: main.cpp
	g++ -c main.cpp -lwiringPi

rotary_encoder.o: ./class_files/rotary_encoder.cpp ./header_files/rotary_encoder.h
		g++ -c ./class_files/rotary_encoder.cpp -lwiringPi

touch_switch.o: ./class_files/touch_switch.cpp ./header_files/touch_switch.h
		g++ -c ./class_files/touch_switch.cpp -lwiringPi

clean:
		rm *.o project
