u#include <chrono>
#include <iostream> 
#include <cmath>


using namespace std;
using ns=chrono::nanoseconds;
using get_time=chrono::steady_clock;
int answer_to_everyhing()
{
	return sin(100) * cos(20);
}


int main()
{
	auto start = get_time::now();
	for (long i = 0; i < 10000; i++) answer_to_everyhing();
	auto end = get_time::now();
	auto diff = end - start;
	cout << "Elapsed time is" << chrono::duration_cast<ns>(diff).cout() << "ns" << endl;


	return 0;

}
