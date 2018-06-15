#ifndef TOOLS_H_
#define TOOLS_H_
#include <time.h>
#include <fstream>

using namespace std;

class Tools {
public:
  /**
  * Constructor.
  */
  Tools();

  /**
  * Destructor.
  */
  virtual ~Tools();

	ofstream f_log;

	void Log(double cte, double speed, double steering_angle, double desired_speed);
};

#endif /* TOOLS_H_ */
