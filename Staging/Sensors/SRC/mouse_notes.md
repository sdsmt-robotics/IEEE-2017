`/dev/mice` is a binary file that updates in real time, however all it contains is the delta x and delta y (along with some others we don't need) values. To get x and y (in what I'm assuming is pixels?) we need to sum delta x and sum delta y. Note that if the mouse is not moving then the file does not get updated. Note also that to get accurate x and y values, we need to sum *every* delta x and *every* delta y.

Proposed methodology:

1. Read in one line of `/dev/mice` with every call to `Mouse::updateSensors()`
	* I don't like this one as we're relying on `updateSensors()` to be called in real time to deal with real time data.
2. Read in as many lines as possible of `/dev/mice` with every call to `Mouse::updateSensors()`
	* I still don't like this one as `/dev/mice` updates in *real* time -- meaning that if the robot is moving, `/dev/mice` should constantly have data being added to it. This has the potential to make `Mouse::updateSensors()` a blocking function call.
3. Make a separate C++/Python executable that sums the delta x and delta y values in real time, then provides the x and y values on request via sockets, `stdin`/`stdout`, writing to a file in the executable directory, or something else.
	* Sockets is interesting, and has the potential to be more robust. In Python, they're dead simple, and in C++ they're not *too* bad.
		* I think we would set up the Python script as the socket server, and have the C++ executable as the client.
		* We would have to figure out how to make the Python script run on startup reliably.
		* I've had problems consistently using the same port -- sometimes I've had to use a different port because Linux thinks I'm still using the old one.
		* Has the potential to be difficult to debug and tweak.
	* `stdin`/`stdout`
		* I'd like to discount this one right off the bat. It doesn't seem like good design at all.
	* Writing the summed delta x and delta y values to a file
		* This is the simplest, and if we update the file as we get new data, the C++ executable can access that data on demand.
		* Can two applications open a file (one reading, the other writing) at the same time?
4. Read in k number of lines from `/dev/mice` every call to `Mouse::updateSensors()`
	* Alternative: read in however many lines as you can in k milliseconds

