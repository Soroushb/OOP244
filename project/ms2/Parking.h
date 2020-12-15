#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

#include "Menu.h"

namespace sdds {
	const int MAX_LOT_SIZE = 100;
	class Parking {
		char* m_datafile;
		Menu m_parkingMenu;
		Menu m_vehicleMenu;
	private:
		bool isEmpty() const;
		void setEmpty();
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles();
		bool closeParking();
		bool exitParkingApp();
		bool load();
		void save();
	public:
		Parking(const char* datafile);
		Parking(const Parking&) = delete;
		void operator=(const Parking&) = delete;
		int run();
		~Parking();
	};
}

#endif