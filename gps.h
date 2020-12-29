/** \file gps.h
 *  \brief Constants, function prototypes for GPS
 *  \author Created: Harshit Walia and Sahil Sahil
 *  \date 24JAN2018
*/
#ifndef GPS_H
#define GPS_H

#define round(x) ((x < 0) ? (ceil((x)-0.5)) : (floor((x)+0.5)))

#define SIMGPS 1
#define GPSBUFFERSZ 20
#define GPSDATASZ 256

struct location
{
	double utc;				///<UTC Time
	double date;			///<UTC Date
    double latitude;		///<Latitude eg: 4124.8963 (XXYY.ZZKK.. DEG,MIN,SEC.SS)
    double longitude;		///<Longitude 08151.6838 (XXXYY.ZZKK.. DEG,MIN,SEC.SS)
    double speed;			///<Speed
    double altitude;		///<Altitude eg: 280.2 (Meters above mean sea level)
    double course;			///<Course
};

typedef struct location loc_t;


///\cond INTERNAL
// Initialize device
extern void gps_init(void);

// Activate device
extern void gps_on(void);

// Get the actual location

// Turn off device (low-power consumption)
extern void gps_off(void);

// -------------------------------------------------------------------------
// Internal functions
// -------------------------------------------------------------------------

// convert deg to decimal deg latitude, (N/S), longitude, (W/E)
void gps_convert_deg_to_dec(double *, char, double *, char);
double gps_deg_dec(double);
int  StReadGPSData(char * fname);
loc_t gps_location(void);
///\endcond
#endif
