Overview
========
The LED Blinky demo application provides a sanity check for the new SDK build environments and board bring up. The LED Blinky demo 
uses the systick interrupt to realize the function of timing delay. The example takes turns to shine the LED. The purpose of this 
demo is to provide a simple project for debugging and further development.

Toolchain supported
===================
- IAR embedded Workbench 8.22.2
- Keil MDK 5.24a
- MCUXpresso10.2.0
- GCC ARM Embedded 7-2017-q4-major

Hardware requirements
=====================
- Mini/micro USB cable
- LPCXpresso54114 board
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
1.  Connect a micro USB cable between the PC host and the CMSIS DAP USB port (J7) on the board
2. Download the program to the target board.
3. Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
When the demo runs successfully, you will find the LED is blinking.
Customization options
=====================

