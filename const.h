#pragma once

// Minimum speed coefficient for all phases except take-off
const double minimum_speed_coeff = 1.3;

// Minimum speed coefficient for take-off
const double minimum_speed_coeff_take_off = 1.2;

// Climb speed increments
/*
 * 1 - below 1500 ft for jet
 * 2 - below 3000 ft for jet
 * 3 - below 4000 ft for jet
 * 4 - below 5000 ft for jet
 * 5 - below 6000 ft for jet
 * 6 - below 500  ft for turbo/piston
 * 7 - below 1000 ft for turbo/piston
 * 8 - below 1500 ft for turbo/piston
 */
const double climb_speed_incr[9] = {0, 5, 10, 30, 60, 80, 20, 30, 35};

// Descent speed increments
/*
 * 1 - below 1000 ft for jet/turboprop
 * 2 - below 1500 ft for jet/turboprop
 * 3 - below 2000 ft for jet/turboprop
 * 4 - below 3000 ft for jet/turboprop
 * 5 - below 500  ft for piston
 * 6 - below 1000 ft for piston
 * 7 - below 1500 ft for piston
 */
const double descent_speed_incr[8] = {0, 5, 10, 20, 50, 5, 10, 20};
