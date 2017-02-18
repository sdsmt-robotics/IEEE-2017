## Mouse Telemetry Documentation

`/dev/mice` is a binary file that the kernel updates in real time, however all it contains is the delta x and delta y (along with some others we don't need) values. To get x and y (in what I'm assuming is pixels?) we need to sum `dx` and sum `dy`. Note that if the mouse is not moving then the file does not get updated. Note also that to get accurate x and y values, we need to sum *every* delta x and *every* delta y.

The `write.cpp` uses the `Mouse` class defined in `Mouse.h` to read in `dx` and `dy` from `/dev/input/mice` and writes the summed `dx` and `dy` to the file specified with via command line arguments.

The `read.cpp` reads the summed mouse data from the file specified via command line argument.

Note, the `FileHandler` class seeks to the beginning of the data file after each read and write to keep the file size down to 8 bytes. The created file *should* have public read permissions.

### Usage:

```sh
~ $ make
~ $ sudo ./write /dev/input/mice ~/.mouse &
~ $ ./read ~/.mouse
```
