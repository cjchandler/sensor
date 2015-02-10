# sensor

#This is Carl Chandler's fork

##feb 3 2015 
teensy code for old IMU works after I put in some strange stuff from web. handway explination is that _write was doubly defined. I do not know how or if this fixes the problem, but it does compile. I still need to test hardware (teensy and old IMU) 

#feb 6 2015 
Here's a detail instruction manual of how to intstall arduino on ubuntu so that it works with a teensy chip. Assumed is that you know how to do basic things in the terminal, like making directories etc. 

1) download the arduino 1.0.6 from the arduino website. extract in to home folder (that's cjchandler for me or the folder that has the same name as your user name) You can eaily use the prompts that come up, there is no need to use the terminal yet. 

2) now open the terminal and cd (change directory ) to arduino, probably the comand is:
<pre><code> $cd ~/arduino-1.0.6 
</code></pre>

now use command 
<pre><code>$./arduino</code></pre> 
that should start the arduino IDE or the place where you write sketches

3) now go to the teensy website and download the teensyarduino

##feb 7 2015 
Today I worked on getting the adc chip working for hydrophones. It spits out 
data over the arduino, but lots left to do. Needs a 5 volt supply and -12 volt 
supply. 


##feb 10 2015
I'm just writting documentation today, how to install ros on ubuntu and how to 
make it work with the sensor sketches for teensy and arduino in this folder.  

1) install ros. This is pretty simple on ubuntu, use apt-get and follow the 
instructions on this page  http://wiki.ros.org/indigo/Installation/Ubuntu

the part about editing your .bashrc file probably can be skiped. You'll need to
source ros in the terminal everytime you use it, but I found even with this
in my .bashrc I still had to source. Perhaps there is a simple way around this
but I haven't found it. 

2) Our code has been made into ros packages with catkin, so do the tutorials with that build tool. The bare bones that you need is a cattkin workspace. You can do this ( in your home folder):
<pre><code>$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
</code></pre>

This is just a folder named catkin_ws in your home directory  with a /src 
sub-directory. 

3) now we need the arduino libraries
<pre><code>$cd ~/catkin_ws/src
$git clone https://github.com/ros-drivers/rosserial
</code></pre>
we need actually a different version of this git repository, so: 
<pre><code>$cd ~/catkin_ws/src/rosserial
$git checkout -b tags/0.6.3
</code></pre>
now we can go back the workspace src.  
<pre><code>$cd ~/catkin_ws/src 
</code></pre>
we also need to put in some special message headers. This allows us to use 
our own ros messages for the IMU and motor controllers etc. 
<pre><code>$git clone https://github.com/arvpUofA/arvp_msgs.git
</code></pre>

Now we are finally ready to build the catkin_ws:
<pre><code>$cd ~/catkin_ws
$catkin_make
$catkin_make install
$source ~/catkin_ws/install/setup.bash
</code></pre>

Now that this last line "source ..." needs to be put in every time you open 
a new terminal tab or window 

4)Now everything ros needs is installed, but you still need to put the libraries for arduino somewhere where arduino can find them. Go to your home directory , and
make sure you've tested out your arduino IDE at least once. If you followed the 
instructions from me on installing that for teensy in your home directory 
you will have a directory called /sketchbook or /Arduino . 
if you have both, you probably have two different versions of arduino IDE installed on the same machine, and do the following steps for both.

<pre><code>$cd ~/Arduino/libraries
</code></pre> 
or depending on the name you happen to have 
<pre><code>$cd ~/sketchbook/libraries
$rm -rf ros_lib
$rosrun rosserial_arduino make_libraries.py .
</code></pre>

5) That should be everything you need installed. To test it, open the arduino IDE and in the examples there should be a ros_lib section and in that a helloworld example. Open that, and run it with a teensy or other arduino board connected. 

To make sure it's working follow the directions here: http://wiki.ros.org/rosserial_arduino/Tutorials/Hello%20World

Remember that when you open a new terminal, you'll need to 
<pre><code>$source ~/catkin_ws/install/setup.bash
</code></pre>

You may also run into an error message while using an arduino DUE that looks something like "cannot convert Serial to Serial1" 
We solved this by opening the offending header file and changing Serial1 in that file to Serial. This is probably not the best way to do it, but it worked for us. 