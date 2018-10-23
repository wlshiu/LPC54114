Overview
========
The mailbox_interrupt example shows how to use mailbox to exchange message.

In this example:
The core 0(CM4) writes value to mailbox for Core 1(CM0+), it causes mailbox interrupt
on CM0+ side. CM0+ reads value from mailbox increments and writes it to mailbox register
for CM4, it causes mailbox interrupt on CM4 side. CM4 reads value from mailbox increments
and writes it to mailbox register for CM0 again.

Toolchain supported
===================
- IAR embedded Workbench 8.22.2
- Keil MDK 5.24a
- MCUXpresso10.2.0
- GCC ARM Embedded 7-2017-q4-major

Hardware requirements
=====================
- Mini/micro USB cable
- LPCLPCXpresso54114 board
- Personal Computer

Board settings
==============
No special settings are required.

Prepare the Demo
================
1.  Connect a micro USB cable between the PC host and the CMSIS DAP USB port (J7) on the board
2.  Open a serial terminal with the following settings (See Appendix A in Getting started guide for description how to determine serial port number):
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
The log below shows example output of the Mailbox interrupt example in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Mailbox interrupt example
Copy CORE1 image to address: 0x20010000, size: 2522
Write to CM0+ mailbox register: 1
Read value from CM4 mailbox register: 2
Write to CM0+ mailbox register: 3
Read value from CM4 mailbox register: 4
Write to CM0+ mailbox register: 5
Read value from CM4 mailbox register: 6
Write to CM0+ mailbox register: 7
.
.
.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

