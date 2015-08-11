#include <iostream>
#include <string>

using namespace std;

struct AircraftParams
{
	/*
	 * Aircraft type
	 */

	// Number of aircarft's engines
	int num_of_engines;

	// Either 'Jet', 'Turboprop' or 'Piston'
	string engine_type;

	// Either 'J', 'H', 'M' or 'L'
	char wake_category;

	/*
	 * Mass in tonnes
	 */

	// Reference mass
	double m_reference;

	// Minimum mass
	double m_minimum;

	// Maximum mass
	double m_maximum;

	// Maximum payload mass
	double m_payload;

	/*
	 * Flight envelope
	 */

	// Maximum operating speed, knots
	double v_maximum_op;

	// Maximum operating Mach number
	double Mach_maximum_op;

	// Maximum operating altitude, feet
	double h_maximum_op;

	// Maximum altitude at MTOW and ISA, feet
	double h_maximum;

	// Weight gradient on maximal altitude, feet/kg
	double grad_weight;

	// Temperature gradient on maximal altitude, feet/K
	double grad_temperature;

	/*
	 * Aerodynamics
	 */

	// Reference wing surface area, m ^ 2
	double S;

	// Parasitic drag coefficient - cruise	
	double parasitic_coeff_cruise;

	// Induced drag coefficient - cruise	
	double induced_coeff_cruise;

	// Parasitic drag coefficient - approach
	double parasitic_coeff_approach;

	// Induced drag coefficient - approach
	double induced_coeff_approach;

	// Parasitic drag coefficient - landing
	double parasitic_coeff_landing;

	// Induced drag coefficient - landing
	double induced_coeff_landing;

	// Parasite drag coefficient - landing gear
	double parasite_coeff_landing_gear;

	// Stall speed, knots
	double v_stall;

	// Buffet onset lift coefficient - jet only
	double buffet_onset_lift_coeff;

	// Buffeting gradient - jet only
	double K;

	/* 
	 * Engine thrust
	 */

	// 1st maximal climb thrust coefficient
	/*
	 * Newton for      jet/piston
	 * knot-Newton for turboprop
	 */
	double climb_thrust_coeff1;

	// 2nd maximal climb thrust coefficient, feet
	double climb_thrust_coeff2;

	// 3rd maximal climb thrust coefficient
	/*
	 * feet ^ (-2) for jet
	 * Newton      for turboprop
	 * knot-Newton for piston
	 */
	double climb_thrust_coeff3;

	// 1st thrust temperature coefficient, K
	double temperature_thrust_coeff1;

	// 2nd thrust temperature coefficient, K ^ (-1)
	double temperature_thrust_coeff2;

	// Low altitude descent thrust coefficient
	double thrust_descent_coeff_low;	

	// Hight altitude descent thrust coefficient
	double thrust_descent_coeff_high;

	// Transition altitude for calculation of descent thrust, feet
	double h_descent;

	// Approach thrust coefficient
	double approach_thrust_coeff;

	// Landing thrust coefficient
	double landing_thrust_coeff;

	// Reference descent speed, knots
	double v_reference_descent;

	// Reference descent Mach number
	double Mach_reference_descent;

	/*
	 * Fuel flow
	 */
	
	// 1st thrust specific fuel consumption coefficient
	/*
	 * kg / (min * kN)        for jet
	 * kg / (min * kN * knot) for turboprop
	 * kg / min               for piston
	 */
	double thrust_fuel_coeff1;

	// 2nd thrust specific fuel consumption coefficient, knots
	double thrust_fuel_coeff2;

	// 1st descent fuel flow coefficient, kg/min
	double descent_fuel_coeff1;

	// 2nd descent fuel flow coefficient, feet
	double descent_fuel_coeff2;

	// Cruise fuel flow correction coefficient
	double fuel_fcr;

	/*
	 * Ground movement, metres
	 */

	// Take-off length
	double take_off_length;

	// Landing length
	double landing_length;

	// Wingspan
	double wingspan;

	// Length
	double length;
};

void main()
{
}
