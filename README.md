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
GPIO 6 - Green LED
GPIO 16 - Red LED
GPIO 17 - RoAPin
GPIO 22 - SWPin
GPIO 27 - RoBPin

### Touch Switch ###
[Touch Switch](https://www.sunfounder.com/learn/sensor-kit-v2-0-for-raspberry-pi-b-plus/lesson-24-touch-switch-sensor-kit-v2-0-for-b-plus.html)
GPIO 12 - Red LED
GPIO 23 - TouchPin
GPIO 26 - Green LED

### Tilt Switch ###

# Compile Code #
```gcc main.c -lwiringPi```
Run code
```sudo ./a.out```
