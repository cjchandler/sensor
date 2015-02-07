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

3) now go to the teensy website and download the teensyduino, download the package. Don't try to open it with a graphic user interface. I downloaded it from the https://www.pjrc.com/teensy/td_download.html. 

That will put a file named something like teensyarduino.32bit in your downloads folder. Go onto that folder on the terminal:
$ cd ~/Downloads 
Then you'll need to give permisions to that so that it can run the installer
$chmod 755 teensyduino.32bit
you might need to do sudo: 
$sudo chmod 755 teensyduino.32bit
Of course if you are using 64 bit change all the 32s to 64s
Then run the installer
$ ./teensyduino.32bit

4) in the installer, you'll need to tell it where your arduino files are. If you followed this, they will be in ~/arduino-1.0.6
You can install all the libraries, they won't hurt even if you never use them. 

5) test! go back and try to do part to. If you look in examples there should be a bunch of teensy libraries. Try the blink one and it should work. 

