project: main.o touch_switch.o rotary_encoder.o tilt_switch.o master_mind.o
	g++ main.o touch_switch.o rotary_encoder.o tilt_switch.o master_mind.o -lwiringPi -o project.o

main.o: main.cpp
	g++ -c main.cpp -lwiringPi

rotary_encoder.o: ./class_files/rotary_encoder.cpp ./header_files/rotary_encoder.h
		g++ -c ./class_files/rotary_encoder.cpp -lwiringPi

tilt_switch.o: ./class_files/tilt_switch.cpp ./header_files/tilt_switch.h
		g++ -c ./class_files/tilt_switch.cpp -lwiringPi

touch_switch.o: ./class_files/touch_switch.cpp ./header_files/touch_switch.h
		g++ -c ./class_files/touch_switch.cpp -lwiringPi

master_mind.o: ./class_files/master_mind.cpp ./header_files/master_mind.h
		g++ -c ./class_files/master_mind.cpp

clean:
		rm *.o project
