# Udacity Self Driving Car Nanodegree
## PID Control Project 

### Overview

This is a project for Udacity's Self Driving Car Nanodegree. The objective of this project is to implement a PID controller in C++ to maneuver the vehicle around a race track in a simulated environment. The simulator will provide the cross track error (CTE) and the velocity (mph) for the computation the appropriate steering angle and throttle.

---

### Video Demo

<img src="/images/demo.gif" width="800">

---

### Implementation Summary

**PID Controller Overview**

Error, ![](https://latex.codecogs.com/gif.latex?e) is defined as the difference between the desired and the current measured state:

![](https://latex.codecogs.com/gif.latex?e=desired-measurement)

P-Controller: provide control signal which proportional to the error:

![](https://latex.codecogs.com/gif.latex?control=K_{p}e)

Drawback: Tends to overshoot.

PD-Controller: provide control signal which proportional to the error and the temporal derivative of error:

![](https://latex.codecogs.com/gif.latex?control=K_{p}e+K_{d}\frac{de}{dt})

This means that when the controller has made enough correction to reduce the error to zero, it won't go overshooting, but it will notice that it has already reduced the error. When the error is becoming smaller overtime, the derivative component maintains a counter corrective action which allows the error to gracefully approach the desired level without overshooting.

However P-Controller and PD-Controller cannot correct systematic bias, hence the need of a PID-Controller.

PID-Controller: provide control signal which proportional to the error, the temporal derivative of error and the integral (or summation for discrete case) of all the error ever observed:

![](https://latex.codecogs.com/gif.latex?control%3DK_%7Bp%7De%2BK_%7Bd%7D%5Cfrac%7Bde%7D%7Bdt%7D%2BK_%7Bi%7D%5Csum%20e)

**Controller Implementation**

Two separate PID controllers are implemented for controlling of steering angle and throttle.

The steering angle controller is set to achieve a constant desired CTE of 0.

The throttle controller is set to achieve two different desired speeds depending on the current value of CTE. The rational is as follows: if the current portion of the track is very curvy, the car will inevitably experience higher CTE relative to a straight portion. In that case, it is reasonable to slow down the vehicle.

The actual implementation of the throttle controller is as follow:

```
if (CTE '<' threshold)
	desired_speed = full_desired_speed;
else
	desired_speed = slow_down_rate * full_desired_speed;

```


**Parameter tuning strategy**

---

### Results

<img src="/images/cte.png" width="600">

<img src="/images/speed.png" width="600">

---

### Installation

1. Download the Udacity Self Driving Car Nanodegree simulator from [here](https://github.com/udacity/self-driving-car-sim/releases).

2. Set up and install [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) by running the shell script in the project top directory:

```
$ install-ubuntu.sh
```

**Other Important Dependencies**

* cmake >= 3.5
* make >= 4.1
* gcc/g++ >= 5.4

---

### How to run

The main program can be built and run by doing the following from the project top directory.


1. mkdir build

2. cd build

3. cmake ..

4. make

5. ./pid

Open the simulator, select `Project 4: PID Controller` and press `Start`.

