#include <iostream>
#include <string>

#include "const.h"

using namespace std;

/* 5 different configurations, specified with a stall speed */
enum StallConfig
{
	TO, IC, CR, AP, LD
};


/* Aircraft representation structure */
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
	double v_stall[5];

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

	/*
	 * Data from PTF file
	 */

	// Standard descent CAS between 3,000/6,000 and 10,000 ft, knots
	double v_descent1;

	// Standard descent CAS between 10,000 ft and Mach transition altitude, knots
	double v_descent2;

	// Standard climb CAS between 1,500/6,000 and 10,000 ft, knots
	double v_climb1;

	// Standard climb CAS between 10,000 ft and Mach transition altitude, knots
	double v_climb2;

	// Standard descent Mach number above Mach transition altitude 
	double Mach_descent;

	/*
	 * Methods
	 */

	double get_CAS_descent( double height_in_ft )
	{
		if (engine_type == "Piston")
		{
			if (height_in_ft < 500)
				return minimum_speed_coeff * v_stall[LD] + descent_speed_incr[5];
			if (height_in_ft < 1000)
				return minimum_speed_coeff * v_stall[LD] + descent_speed_incr[6];
			if (height_in_ft < 1500)
				return minimum_speed_coeff * v_stall[LD] + descent_speed_incr[7];
			if (height_in_ft < 10000)
				return v_descent1;
			return v_descent2;
		}
		else
		{
			if (height_in_ft < 1000)
				return minimum_speed_coeff * v_stall[LD] + descent_speed_incr[1];
			if (height_in_ft < 1500)
				return minimum_speed_coeff * v_stall[LD] + descent_speed_incr[2];
			if (height_in_ft < 2000)
				return minimum_speed_coeff * v_stall[LD] + descent_speed_incr[3];
			if (height_in_ft < 3000)
				return minimum_speed_coeff * v_stall[LD] + descent_speed_incr[4];
			if (height_in_ft < 6000)
				return min(v_descent1, 220.);
			if (height_in_ft < 10000)
				return min(v_descent1, 250.);
			return v_descent2;
		}
	}

	double get_CAS_climb( double height_in_ft )
	{
		if (engine_type == "Jet")
		{
			if (height_in_ft < 1500)
				return minimum_speed_coeff * v_stall[TO] + climb_speed_incr[1];
			if (height_in_ft < 3000)
				return minimum_speed_coeff * v_stall[TO] + climb_speed_incr[2];
			if (height_in_ft < 4000)
				return minimum_speed_coeff * v_stall[TO] + climb_speed_incr[3];
			if (height_in_ft < 5000)
				return minimum_speed_coeff * v_stall[TO] + climb_speed_incr[4];
			if (height_in_ft < 6000)
				return minimum_speed_coeff * v_stall[TO] + climb_speed_incr[5];
			if (height_in_ft < 10000)
				return min(v_climb1, 250.);
			return v_climb2;
		}
		else
		{
			if (height_in_ft < 500)
				return minimum_speed_coeff * v_stall[TO] + climb_speed_incr[6];
			if (height_in_ft < 1000)
				return minimum_speed_coeff * v_stall[TO] + climb_speed_incr[7];
			if (height_in_ft < 1500)
				return minimum_speed_coeff * v_stall[TO] + climb_speed_incr[8];
			if (height_in_ft < 10000)
				return min(v_climb1, 250.);
			return v_climb2;
		}
	}
};

void main()
{
	double heights_descent[7] = {500,  1250, 1750, 2500, 4000, 9000, 15000};
	double heights_climb[7]   = {1000, 2000, 3500, 4500, 5500, 9000, 15000};
	AircraftParams Airbus_A306;
	
	Airbus_A306.engine_type  = "Jet";
	Airbus_A306.v_stall[LD]  = 97;
	Airbus_A306.v_stall[TO]  = 117;
	Airbus_A306.v_descent1   = 250;
	Airbus_A306.v_descent2   = 280;
	Airbus_A306.v_climb1     = 250;
	Airbus_A306.v_climb2     = 310;
	Airbus_A306.Mach_descent = 0.79;

	for (int i = 0; i < 7; i++)
		cout << "CAS at descent at height of " << heights_descent[i] << " ft is --- " << Airbus_A306.get_CAS_descent(heights_descent[i]) << " knots" << endl; 
	cout << endl;
	for (int i = 0; i < 7; i++)
		cout << "CAS at climb at height of "   << heights_climb[i]   << " ft is --- " << Airbus_A306.get_CAS_climb(heights_climb[i])   << " knots" << endl;
}
