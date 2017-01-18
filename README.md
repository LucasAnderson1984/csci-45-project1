# csci-45-project1 #
## Team ##
Joses Paras <br />
Lucas Anderson <br />
Tanpreet Dhaliwal

## Rules ##
<p>The specific rules for this project are:</p>
1. You must use at least two sensors (either checked out from me, or bought on your own nickel).
2. It must be controlled by software on the Pi
3. Use at least 2 LEDs to show the status of the thing
4. Bonus points for awesomeness

- - - -
# Project Proposal #
<p>We each will learn how to operate a single sensor or more, then we will come together to make a simple puzzle in the style of the game 'Mastermind' or otherwise a simpler version of the example below.</p>
_Fill out more later.  Have the team discussion on the specifics._

Example: [Xbox Puzzle](https://www.youtube.com/watch?v=o_8e6XgAiow)

## Sensors ##
Rotary Encoder <br />
Touch Switch <br />
Tilt Switch

## Responsibilities ##
Programming the touch switch - Joses <br />
Programming the rotary encoder - Lucas <br />
Programming the tilt switch - Tanpreet

## Pin Mapping ##
### Rotary Encoder ###
[Rotary Encoder](https://www.sunfounder.com/learn/sensor-kit-v2-0-for-raspberry-pi-b-plus/lesson-27-rotary-encoder-module-sensor-kit-v2-0-for-b-plus.html) <br />
GPIO 6 - Green LED <br />
GPIO 16 - Red LED <br />
GPIO 17 - RoAPin <br />
GPIO 22 - SWPin <br />
GPIO 27 - RoBPin

### Touch Switch ###
[Touch Switch](https://www.sunfounder.com/learn/sensor-kit-v2-0-for-raspberry-pi-b-plus/lesson-24-touch-switch-sensor-kit-v2-0-for-b-plus.html) <br />
GPIO 12 - Red LED <br />
GPIO 23 - TouchPin <br />
GPIO 26 - Green LED

### Tilt Switch ###
[Tilt Switch](https://www.sunfounder.com/learn/sensor-kit-v2-0-for-raspberry-pi-b-plus/lesson-7-tilt-switch-module-sensor-kit-v2-0-for-b-plus.html) <br />

# Compile Code #
Run code: <br />
```
gcc main.c -lwiringPi
sudo ./a.out
```
