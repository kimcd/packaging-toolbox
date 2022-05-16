

#include "ASD.h"

#include <vector>
using std::vector;

#include <cmath>

#include <iostream>
using std::cerr;
using std::endl;

const std::vector<unsigned int> ASD::GEVS_FREQUENCIES = {20, 50, 800, 2000};
const std::vector<double> ASD::GEVS_ASD = {0.026, 0.16, 0.16, .026};

ASD::ASD(vector<unsigned int>& frequencies, vector<double>& asd)
: frequencies_hz(validate_frequency_input(frequencies)),
  asd_g2_hz(validate_asd_input(asd))
{
	g_rms = compute_rms();
}


vector<unsigned int> ASD::validate_frequency_input(
		const vector<unsigned int>& frequencies) const
{
	// check that frequencies are valid. how?
	return frequencies;
}


vector<double> ASD::validate_asd_input(const vector<double>& asd) const
{
	// check that frequencies are valid. how?
	return asd;
}


double ASD::compute_rms() const
{
	double area = 0.0;

	for(size_t i = 1; i <= frequencies_hz.size(); ++i)
	{

		area += compute_area(
				frequencies_hz[i - 1],
				frequencies_hz[i],
				asd_g2_hz[i-1],
				asd_g2_hz[i]);
	}

	return sqrt(area);

}


double compute_area(
		const double f1,
		const double f2,
		const double asd1,
		const double asd2)
{
	const double EPS = 0.0000001f;

	double db = compute_db(asd1, asd2);
	double oct = compute_oct(f1, f2);
	double m = db/oct;

	double area;

	// if
	if(fabs( m - (-10 * log10(2)) ) < EPS)
	{

		area = asd1 * f1 * log(f2 / f1);

	} else
	{

		area = 10 * log10(2) * ( asd2 / (10 * log10(2) + m) )
				*
				(f2 - (f1 * pow( (f1 / f2), (m / (10 * log10(2))) )) );

	}

	return area;

}

/*
vector<double> plus_6_db(const double asd)
{
	pow(10, 6/20)

}*/
