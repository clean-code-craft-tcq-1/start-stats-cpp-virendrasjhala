#pragma once
#include <vector>

namespace Statistics {
	 
	class Stats
	{
		public:
		double average;
		double max;
		double min;

	};
	Stats ComputeStatistics(const std::vector<double>& V);

}

class IAlerter
{
public:
	int emailSent = 1;
	int ledGlows = 1;

};
class EmailAlert:public IAlerter
{
};
class LEDAlert:public EmailAlert
{
};
class StatsAlerter:public LEDAlert
{
	float Threshold;
	std::vector<IAlerter*> obj_ref;
public:
	float actualThreshold;
	std::vector<IAlerter*> actualobj_ref;

	StatsAlerter() { }
	StatsAlerter( float temp, std::vector<IAlerter*> temp2);
	
	StatsAlerter checkAndAlert(const std::vector<double>& V);

	void set1(float temp) {
		Threshold = temp;
	}
	void set2( std::vector<IAlerter*> temp2) {
		obj_ref.insert(obj_ref.end(), temp2.begin(), temp2.end());
	}
	auto getter1(){
		return Threshold;
	}
	auto getter2(){
		return obj_ref;
	}
};


