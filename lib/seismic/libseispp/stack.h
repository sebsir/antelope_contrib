#ifndef _STACK_H_
#define _STACK_H_

#include <vector>
#include "SeisppKeywords.h"
#include "TimeWindow.h"
#include "TimeSeries.h"
#include "ensemble.h"
namespace SEISPP {
enum StackType {BasicStack, MedianStack, RobustSNR};

//@{
// Generalized stacking object.
// Stacking is a common theme in seismic data processing.  This generalizes the 
// concept in a single object.  The approach uses here is decidely not procedural.
// The philosphy of this object is that the object is created through the computation
// of the stack.  
//@}

class Stack
{
public:
	int fold;
	vector<double>weights;
	double sumwt;
	TimeSeries stack; 
	Stack();
	Stack(TimeSeriesEnsemble& d,TimeWindow twin);
	Stack(TimeSeriesEnsemble& d,TimeWindow stack_twin, TimeWindow robust_twin, StackType method);
	Stack(const Stack& old);
	Stack& operator=(const Stack& other);
private:
	StackType stacktype;
};
}
#endif
