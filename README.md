# sensor

#This is Carl Chandler's fork

##feb 3 2015 
teensy code for old IMU works after I put in some strange stuff from web. handway explination is that _write was doubly defined. I do not know how or if this fixes the problem, but it does compile. I still need to test hardware (teensy and old IMU) 

#feb 6 2015 
Here's a detail instruction manual of how to intstall arduino on ubuntu so that it works with a teensy chip. Assumed is that you know how to do basic things in the terminal, like making directories etc. 

1) download the arduino 1.0.6 from the arduino website. extract in to home folder (that's cjchandler for me or the folder that has the same name as your user name) You can eaily use the prompts that come up, there is no need to use the terminal yet. 

2) now open the terminal and cd (change directory ) to arduino, probably the comand is: $cd ~/arduino-1.0.6 

now use command $./arduino 
that should start the arduino IDE or the place where you write sketches

3) now go to the teensy website and download the teensyarduino