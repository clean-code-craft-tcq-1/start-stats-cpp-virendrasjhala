#include "stats.h"
#include <algorithm>
#define Not_a_number NAN
using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<double>& V) {
	//Implement statistics here
	Stats s;
	if (V.empty())
	{
		s.max = Not_a_number;
		s.min = Not_a_number;
		s.average = Not_a_number;
		
	}
	else 
	{
		std::vector<double>*temp = (std::vector<double>*)& V;
		sort(temp->begin(), temp->end());
		s.max = (float)V.back();
		s.min = (float)V.front();
		s.average = 0;
		for (auto iter = V.begin(); iter != V.end(); iter++)
		{
			s.average = s.average + *iter;
		}

		s.average = (s.average / V.size());
	}
	return s;
}

StatsAlerter::StatsAlerter(double temp, std::vector<IAlerter*> temp2)
{
	set1(temp);
   	set2(temp2);
}

StatsAlerter StatsAlerter::checkAndAlert(const std::vector<double>& V){
	StatsAlerter s1;
	int counter1 = 0;
	int counter2 = 0;
	s1.actualThreshold = getter1();
	s1.actualobj_ref = getter2();
	for (auto iter = V.begin(); iter != V.end(); iter++)
	{
		if (s1.actualThreshold > *iter)
		{
			counter1 = counter1 + 1;
		}
		else
		{
			counter2 = counter2 + 1;
		}
	}
	
	s1.actualobj_ref[0]->emailSent = counter2;
	s1.actualobj_ref[1]->ledGlows = counter1;
	
	return s1;
}




