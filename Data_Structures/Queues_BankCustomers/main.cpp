/*
 Thomas Li

*/
#include<iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

/*
 Represents a single event in the bank simulation, either an arrival or departure
 Stores information about customer event including arrival time, length of service, customerID, and 
 whether event is an arrival or departure.
*/
class Event {
	public: 
		int time;
		int length;
		int customerid;
		bool isArrival;

		/*
		Constructs an Event object
		*/
		Event(int id, int t, int l, bool arrival) {
			customerid = id;
			time = t;
			length = l;
			isArrival = arrival;
		}
		
		/*
		Comparison operator overload for priority ordering in the priority queue used by stl <queue>
		Orders events specifically by the time in the Event object.
		*/
		bool operator<(const Event& other) const{
			return time > other.time; //if this has larger time, it has a smaller priority.
		}
};

/*
 Represents a Customer in the bank simulation with their arrival time and transaction length. To be stored in the Bank Queue.
*/
class Customer {
public:
	int arrivalTime;
	int length;
	int customerid;

	/*
	constructs a Customer object.
	*/
	Customer(int id, int aTime, int L) {
		customerid = id;
		arrivalTime = aTime;
		length = L;
	}
};

void simulate();
void processArrival(Event arrivalEvent, priority_queue<Event>& eventListPQueue,
	queue<Customer>& bankQueue, bool& tellerAvailable);
void processDeparture(Event departureEvent, priority_queue<Event>& eventListPQueue,
	queue<Customer>& bankQueue, bool& tellerAvailable, int& totalWaitTime);

int main() {
	simulate();
}


/*
Main simulation for the bank queue system. Reads events from an input file, processes them, and outputs simulation results. 
Tracks the number of customers processed and calculates average waiting time.
*/
void simulate() {
	ifstream inputFile("in1.txt");
	if (!inputFile) {
		cout << "Error: File not found." << endl;
		return;
	}


	priority_queue<Event> eventListPQueue;
	queue<Customer> bankQueue;

	bool tellerAvailable = true;

	int aTime;
	int transTime;
	int id = 1;

	int totalWaitTime = 0;
	int totalCustomers = 0;
	while (inputFile >> aTime >> transTime) {
		eventListPQueue.push(Event(id, aTime, transTime, true));
		id++;
	}
	inputFile.close();
	cout << "Simulation Begins" << endl;

	while (!eventListPQueue.empty()) {
		Event currentEvent = eventListPQueue.top();
		if (currentEvent.isArrival) {
			processArrival(currentEvent, eventListPQueue, bankQueue, tellerAvailable);
		} 
		else {
			processDeparture(currentEvent, eventListPQueue, bankQueue, tellerAvailable, totalWaitTime);
		}
	}
	totalCustomers = id - 1;
	cout << "Final Statistics: " << endl;
	cout << "    Total number of people processed: " << totalCustomers << endl;
	double averageWaitTime = static_cast<double>(totalWaitTime) / totalCustomers;
	cout << "    Average amount of time spent waiting: " << averageWaitTime << endl;
}

/*
Processes an arrival event in the simulation...Determines if a customer can be served at the moment.
*/
void processArrival(Event arrivalEvent, priority_queue<Event>& eventListPQueue,
	queue<Customer>& bankQueue, bool& tellerAvailable) {
	eventListPQueue.pop();
	cout << "Processing customer #" << arrivalEvent.customerid << " arrival at time: "
		<< arrivalEvent.time << endl;

	if (bankQueue.empty() && tellerAvailable) {
		int departureTime = arrivalEvent.time + arrivalEvent.length;
		eventListPQueue.push(Event(arrivalEvent.customerid, departureTime, 0, false));
		tellerAvailable = false;
	}
	else {
		bankQueue.push(Customer(arrivalEvent.customerid, arrivalEvent.time, arrivalEvent.length));
	}
}

/*
Processes a departure event in the simulation. Moves the customer to the next in line if there is one waiting and updates total wait time.
*/
void processDeparture(Event departureEvent, priority_queue<Event>& eventListPQueue,
	queue<Customer>& bankQueue, bool& tellerAvailable, int& totalWaitTime) {
	eventListPQueue.pop();
	cout << "Processing customer #" << departureEvent.customerid << " departure at time: " << departureEvent.time << endl;

	if (!bankQueue.empty()) {
		Customer nextCustomer = bankQueue.front();
		bankQueue.pop();

		int waitTime = departureEvent.time - nextCustomer.arrivalTime;
		totalWaitTime += waitTime;

		int departureTime = departureEvent.time + nextCustomer.length;
		eventListPQueue.push(Event(nextCustomer.customerid, departureTime, 0, false));
	}
	else {
		tellerAvailable = true;
	}
}