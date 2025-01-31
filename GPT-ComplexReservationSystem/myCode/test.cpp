#include <iostream>
#include <memory>
#include "Room.h"
#include "StandardRoom.h"
#include "SuiteRoom.h"
#include "Reservation.h"
#include "ReservationManager.h"
#include <iostream>

using namespace std;
/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, const std::string& failedMessage) {
    if (!condition) {
        std::cout << failedMessage << std::endl;
    }
}

/**
 * Tests for the Room classes. (20 points)
 */
void roomTests() {
    // Create instances of StandardRoom and SuiteRoom.
    // 1. Verify the initial availability status of the rooms.
    // 2. Test the `bookRoom()` and `releaseRoom()` methods to ensure the room's status changes correctly.
    // 3. Test additional functionality for SuiteRoom, such as getting additional charges.

    // Add code to verify the above points and assert conditions accordingly.


//	std::shared_ptr<SuiteRoom> suiteroom(new SuiteRoom("101",1250));
//	std::shared_ptr<Room> standardroom(new StandardRoom("201"));



	SuiteRoom suit("101",1250);
	suit.bookRoom();
	assertTrue(suit.isRoomAvailable()==0,"room should be booked");
}

/**
 * Tests for the Reservation class. (20 points)
 */
void reservationTests() {
    // Create instances of Reservation, Room (both StandardRoom and SuiteRoom).
    // 1. Verify the reservation details such as ID, room number, and guest name.
    // 2. Test the `cancelReservation()` method to ensure it releases the room correctly.

    // Add code to verify the above points and assert conditions accordingly.

		std::shared_ptr<SuiteRoom> suiteroom(new SuiteRoom("101",1250));
		std::shared_ptr<Room> standardroom(new StandardRoom("201"));

		Reservation res1("r1",suiteroom,"bhavin");
		Reservation res2("r2",standardroom,"rutvik");

		assertTrue(res1.getGuestName()=="bhavin","guest name not matched");
		assertTrue(res1.getRoom()->getRoomNumber()==suiteroom->getRoomNumber(),"reservation room number not matched!");
		assertTrue(res1.getRoom()->isRoomAvailable()==0,"room should be booked");
		assertTrue(suiteroom->isRoomAvailable()==0,"room should be booked");
		res1.cancelReservation();
		assertTrue(suiteroom->isRoomAvailable()==1,"room should be available");



}




/**
 * Tests for the ReservationManager class. (20 points)
 */
void reservationManagerTests() {
    // Create instances of ReservationManager, Room (both StandardRoom and SuiteRoom), and Reservation.
    // 1. Test adding and listing rooms and reservations.
    // 2. Test booking a room and verify its availability status.
    // 3. Test cancelling a reservation and verify the room is released and the reservation is removed.

    // Add code to verify the above points and assert conditions accordingly.

	std::shared_ptr<SuiteRoom> suiteroom1(new SuiteRoom("S101",1250));
	std::shared_ptr<StandardRoom> standardroom1(new StandardRoom("SD201"));
	std::shared_ptr<SuiteRoom> suiteroom2(new SuiteRoom("S102",1250));
	std::shared_ptr<StandardRoom> standardroom2(new StandardRoom("SD202"));
	std::shared_ptr<StandardRoom> standardroom3(new StandardRoom("SD203"));
	std::shared_ptr<SuiteRoom> suiteroom3(new SuiteRoom("S103",1250));

	std::shared_ptr<Reservation> res1(new Reservation("r1",suiteroom1,"bhavin"));
	std::shared_ptr<Reservation> res2(new Reservation("r2",standardroom1,"rutvik"));
	std::shared_ptr<Reservation> res3(new Reservation("r3",suiteroom2,"dev"));

	ReservationManager manager;
	manager.addRoom(suiteroom1);
	manager.addRoom(suiteroom2);
	manager.addRoom(suiteroom3);
	manager.addRoom(standardroom1);
	manager.addRoom(standardroom2);
	manager.addRoom(standardroom3);

	manager.addReservation(res1);
	manager.addReservation(res2);
	manager.addReservation(res3);

	manager.listReservations();
	manager.listRooms();

	manager.cancelReservation(res1->getReservationId());

	manager.listReservations();
	manager.listRooms();



}

void alltest() {
    // Run tests for Room classes.
    roomTests();

    // Run tests for Reservation class.
    reservationTests();

    // Run tests for ReservationManager class.
    reservationManagerTests();

}
