#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	error_prev = 0.0;
	error_sum = 0.0;
}

void PID::SetDesired(double desired) {
	set_point = desired;
}

void PID::UpdateError(double measurement, double dt) {
	double error = set_point - measurement;
	double error_diff = (error - error_prev)/dt;
	error_sum += error;
	p_error = error;
	d_error = error_diff;
	i_error = error_sum;

	error_prev = error;
}

double PID::TotalError() {
	return Kp*p_error+Ki*i_error+Kd*d_error;
}

