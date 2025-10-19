# Implementation Plan (Project: CTRL Gaming Controller)
What triggers this feature (user action, game event, startup, etc.)
What input or data is needed
Step-by-step: which functions get called and what they do
What data gets created, modified, or displayed
What happens when the operation completes

## Feature 1: All Buttons
**Trigger:** User interaction with Arduino firmware set-up

**Input/Data Needed:** 
- Name of button (string)
- List of all buttons possible to be pressed (vector of button objects)
- List of buttons being pressed at one time (vector of button objects + bools)
- Marker for whether the button is being pressed (bool)

**Implementation flow**:
1. When user turns on controller, in `main.cpp` , controller is constructed and initialized with respective buttons
2. Controller will implemnent a loop to get user input on what buttons are being pressed at the moment
3. Whenever a button(s) is pressed, the file `"XInput.h` will translate input from the controller into language that the compiler would be able to understand
4. This translation will be sent to `callCommand()` for respective `buttonFunction` to be called
5. **Buttons**: Each button has an assigned number when designing PCB boards
      - X Y A B Buttons + L1R1 Buttons
      - Trigger Buttons: specifically intialized with back-end code to hold pressure value data
      - Menu button: intialized to pull up controller settings
      - Power button: intialized so that when pressed, calls for `~Controller()` and sets `bool isRunning()` to false

**Data modified/created/displayed**: 
- Initialization of individual button commands on `controller.cpp`
  - including string name, vector of button objects 
- Vector to hold user inputs + commands called
- bool isPressed
- double pressureValues for triggers

**Result of operation**:
- Commands for buttons are called for computer to compile
- Result will show depending what the user calls
  - Example: if A is pressed, player on computer may jump
  - If menu button is pressed, game will receive comamnd to open game menu
  - If power button pressed, controller shuts down
## Feature 2: Left/Right Joysticks
**Trigger:** User interaction with Arduino firmware set-up

**Input/Data Needed:**
- 2 Joystick objects (Left + Right)
- int values for x & y coordinate

**Implementation flow**:
1. When user turns on controller, in `main.cpp` , controller is constructed and initializes `Joystick1` and `Joystick2`
2. Controller will implemnent a loop to get user input on what buttons are being pressed at the moment
3. Whenever joystick is moved, the file `"XInput.h` will translate input from the controller into language that the compiler would be able to understand
4. This translation will be sent to `callCommand()` for respective Joystick `move()` function to set x,y coordinates
5. **Joysticks**: Joysticks hold x,y coordinate values to facilitate character movement and direction
   - Left joystick: mainly used for character movement, software application may compile commands from controller to initiate character movement
   - Right joystick: mainly used for other movements (eg. camera POV movement, specific character gestures)

**Data modified/created/displayed**:
- Initialization of joysticks on `controller.cpp` from `Controller()` initializer
- Vector to hold user inputs + commands called
- double values for x, y coordinates

**Result of operation**:
- Joystick movements are called for computer to compile
- Result will show depending what the user calls
  - Example: if joystick left moved to coordinate (0,1), player will move up
  - If moved to (1,1), player will move towards upper-right direction
  - If joystick right is moved to (0,1), camera POV will look up.

## Feature 3: Firmware Body (Using Arduino)
**Construction Plan**
- PCB Board purchased from "Saber C++"
- PCB Design/Implementation completed on "Kicad"
- Main component: **Arduino Pro Micro**
  - Pins that connect to PC, and provide seamless connection form buttons/joysticks to PC
  - Basically, it's like the brain of the controller that sends messages to the PC 
  - Pins also connect to different buttons and joystick switches, so that messages form the buttons are transmitted into the micro board for it to be sent to PC

