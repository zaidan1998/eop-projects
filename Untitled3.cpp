#include <iostream>
#include <time.h>


class timer {
	private:
		unsigned long begTime;
	public:
		void start() {
			begTime = clock();
		}

		unsigned long elapsedTime() {
			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
		}

		bool isTimeout(unsigned long seconds) {
			return seconds >= elapsedTime();
		}
};


void main() {
	unsigned long seconds = 10;
	timer t;
	t.start();
	cout << "timer started . . ." << endl;
	while(true) {
		if(t.elapsedTime() >= seconds) {
			break;
		}
		else {
			// do other things
		}
	}
	cout << seconds <<  " seconds elapsed" << endl;

	cin >> seconds;	// it's just to stop the execution and look at the output
}
