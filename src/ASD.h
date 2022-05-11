

#ifndef SRC_ASD_H_
#define SRC_ASD_H_

#include <vector>
#include <cmath>

class ASD
{
public:

	/*
	 @brief Static member for GEVS.

	 NOTE static members are declared within the class definition, but defined
	 outside the class.
	 */
	static const std::vector<unsigned int> GEVS_FREQUENCIES;
	static const std::vector<double> GEVS_ASD;


	/*
	 @brief Construct with parameters
	 */
	ASD(std::vector<unsigned int> frequencies,
			std::vector<double> asd );

	/*
	 @brief Inline getter for g_rms data member.
	 */
	inline double get_rms() const
	{
		return g_rms;
	}



private:

	/*
	 @brief vector of frequencies [Hz].

	 Must be ordered.
	 */
	std::vector<unsigned int> frequencies_hz;


	std::vector<double> asd_g2_hz;


	double g_rms;


	double compute_rms() const;


	std::vector<unsigned int> validate_frequency_input(
			const std::vector<unsigned int>& frequencies) const;


	std::vector<double> validate_asd_input(
			const std::vector<double>& asd) const;



};

/*
 * @brief Free functions
 */
inline double compute_db(const double asd1, const double asd2)
{
	return 10 * log10(asd2/asd1);
}


inline double compute_oct(const int f1, const int f2)
{
	return log10(static_cast<double>(f2) / f1) / log10(2);
}


double compute_area(
		const double f1,
		const double f2,
		const double asd1,
		const double asd2);



#endif /* SRC_ASD_H_ */
