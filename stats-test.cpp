#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
	auto computedStats = Statistics::ComputeStatistics({ 1.5, 8.9, 3.2, 4.5 });
	double epsilon = 0.001;
	/*
	std::cout << "CASE 1 :" << "\n";
	std::cout << "All fields of computedStats (average, max, min) are returned with some value :" << "\n";
	std::cout << "computedStats.average : " << computedStats.average <<"\n";
	std::cout << "computedStats.max : "     << computedStats.max     << "\n";
	std::cout << "computedStats.min : "     << computedStats.min     << "\n";
	std::cout << "\n";
	*/
	REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
	REQUIRE(std::abs(computedStats.max - 8.9)       < epsilon);
	REQUIRE(std::abs(computedStats.min - 1.5)       < epsilon);
}

TEST_CASE("average is NaN for empty array") {
	auto computedStats = Statistics::ComputeStatistics({});
	
	//All fields of computedStats (average, max, min) must be
	//NAN (not-a-number), as defined in math.h
	//Design the REQUIRE statement here.
	/*
	std::cout << "CASE 2:" << "\n";
	std::cout << "All fields of computedStats (average, max, min) = NAN " << "\n";
	std::cout << "\n";
	*/
	REQUIRE(std::abs(std::isnan(computedStats.average) == 1) );
	REQUIRE(std::abs(std::isnan(computedStats.max )    == 1) );
	REQUIRE(std::abs(std::isnan(computedStats.min )    == 1) );

	//Use http://www.cplusplus.com/reference/cmath/isnan/
}

TEST_CASE("raises alerts when max is greater than threshold") {
	EmailAlert emailAlert;
	LEDAlert ledAlert;
	std::vector<IAlerter*> alerters = { &emailAlert, &ledAlert };
	const double maxThreshold = 10.2;
	StatsAlerter statsAlerter(maxThreshold, alerters);
	statsAlerter.checkAndAlert({ 99.8, 34.2, 4.5, 6.7 });
	/*
	std::cout << "CASE 3:" << "\n";
	std::cout << " emailAlert.emailSent : " << emailAlert.emailSent << "\n";
	std::cout << " ledAlert.ledGlows : "    << ledAlert.ledGlows    << "\n";
	std::cout << "\n";
	*/
	REQUIRE(emailAlert.emailSent);
	REQUIRE(ledAlert.ledGlows);
}
