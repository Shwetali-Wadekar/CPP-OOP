#include <iostream>
#include <memory>
#include "Event.h"
#include "Concert.h"
#include "Conference.h"
#include "Attendee.h"
#include "EventSystem.h"

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
 * Tests for the Event class and its derived classes (Concert, Conference). (20 points)
 */
void eventTests() {
    // Create instances of Concert and Conference.
    // 1. Verify the title and description retrieval.
    // 2. Test the `display()` method for different formats.
    // 3. Test additional functionality specific to Concert and Conference.

	//    Concert(const std::string& title, const std::string& description,
 //   const std::string& bandName, const std::string& venue);

	Concert pink("pink concert","for lgbtq","pink band","sttutgart");

	assertTrue(pink.getTitle()=="pink concert","title not matched");
	assertTrue(pink.getDescription()=="for lgbtq","description not matched");



    // Test Concert specific methods
	assertTrue(pink.getVenue()=="stuttgart","venue not matched");

    // Test display method for Concert
	pink.display();
	cout<<endl;

	pink.display("short");
	cout<<endl;
	pink.display("big");
	cout<<endl;


    // Test Conference specific methods
	std::vector<std::string> speakers= { "left", "right","central"};

	Conference ted("tedtalks","engineers of tommorow",speakers,"mannheim");
	assertTrue(ted.getTitle()=="tedtalks","title not matched");
	assertTrue(ted.getDescription()=="engineers of tommorow","description not matched");
	ted.display();
	cout<<endl;





    // Test display method for Conference

	ted.display("short");
	cout<<endl;
	ted.display("big");
	cout<<endl;

}

/**
 * Tests for the Attendee class. (20 points)
 */
void attendeeTests() {
    // Create instances of Attendee.
    // 1. Test the registration and unregistration of events.
    // 2. Verify the list of registered events.
	Attendee bhavin("bhavin");
	bhavin.registerEvent("pink concert");
	bhavin.registerEvent("photography");

	bhavin.listRegisteredEvents();
	cout<<endl;

    // Test registration status
	assertTrue(bhavin.isRegistered("photography"),"registration failed");

    // Test unregistration
	bhavin.unregisterEvent("photography");
	assertTrue(bhavin.isRegistered("photography")==0,"unregistration failed");

    // Test listing registered events
	bhavin.listRegisteredEvents();
	cout<<endl;
}

/**
 * Tests for the EventSystem class. (20 points)
 */
void eventSystemTests() {
    // Create instances of EventSystem, Event (Concert and Conference), and Attendee.
    // 1. Test adding and listing events and attendees.
    // 2. Test attendee registration for events and verify the event and attendee details.
    // 3. Test searching for events by keyword and verify the results.
    // 4. Test removing events and attendees.

    EventSystem system;

    // Add events
	std::vector<std::string> speakers= { "left", "right","central"};
	Concert* babypink= new Concert("babypink concert","for baby lgbtq","pink band","sttutgart");

	Concert* pink= new Concert("pink concert","for lgbtq","pink band","sttutgart");
	Conference* ted= new Conference("tedtalks","engineers of tommorow",speakers,"mannheim");

	system.addEvent(std::unique_ptr<Event>(babypink));

	system.addEvent(std::unique_ptr<Event>(pink));
	system.addEvent(std::unique_ptr<Event>(ted));

    // Register attendees
	system.registerAttendee("bhavin");
	system.registerAttendee("rutvik");


    // Register attendees for events
	system.attendeeRegisterForEvent("bhavin","tedtalks");
	system.attendeeRegisterForEvent("rutvik","pink concert");
	system.attendeeRegisterForEvent("bhavin","babypink concert");
	system.attendeeRegisterForEvent("rutvik","babypink concert");

	cout<<"listAttendeesForEvent for tedtalk"<<endl;
    // Test listing events and attendees
	system.listAttendeesForEvent("tedtalks");
	cout<<endl;
	cout<<"listAttendeesForEvent for pink concert"<<endl;
	system.listAttendeesForEvent("pink concert");
	cout<<endl;
	cout<<"listAttendeesForEvent for babypink concert"<<endl;
	system.listAttendeesForEvent("babypink concert");
	cout<<endl;

    // Test searching for events
	system.searchEventsByKeyword("pink");

    // Test removing attendees and events
//	system.unregisterAttendee("bhavin");
	system.attendeeUnregisterFromEvent("bhavin","babypink concert");


    // Check remaining events and attendees
	cout<<"listAttendeesForEvent for tedtalk"<<endl;
	system.listAttendeesForEvent("tedtalks");
	cout<<endl;
	cout<<"listAttendeesForEvent for pink concert"<<endl;
	system.listAttendeesForEvent("pink concert");
	cout<<endl;
	cout<<"listAttendeesForEvent for babypink concert"<<endl;
	system.listAttendeesForEvent("babypink concert");
	cout<<endl;

	cout<<"display all events:"<<endl;
	system.displayAllEvents();


}

/**
 * Run all tests. (40 points)
 */
void alltest() {
    eventTests();

    attendeeTests();

    eventSystemTests();
}

