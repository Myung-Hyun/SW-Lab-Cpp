#include <fstream>
#include<cmath>
#include <iostream>
#include <chrono>

using namespace std;
using ns=chrono::nanoseconds;
using get_time = chrono::steady_clock;
constexpr auto PI = 3.141592;;



int main()
{
	ofstream myout("mytext.txt");
	float T = 0.1;
	float dt = 0.0002;


	if (!myout)
	{
		cout << "Cannot";
		return 1;
	}

	float sig_power = 0.0;
	float nz_power = 0.0;
	float SNR = 0.0;

	for (dt; dt < 0.01; dt += 0.0002) {
		auto start = get_time::now();

		for (float t = 0.; t < T; t += dt)
		{
			float di = 0.0;
			
			di = (2*sin(200*PI*(t+dt))- 2*sin(200 * PI * t))/ dt;

			float signal = 2. *(2*PI*100) * cos(200. * PI * t);
			float noise = di - signal;

			sig_power += pow(signal, 2);
			nz_power += pow(noise, 2);

		}
		auto end = get_time::now();
		auto diff = end - start;
		sig_power = sig_power / T;
		nz_power = nz_power / T;
		SNR = 10 * log(sig_power / nz_power);

		myout << SNR << " " << chrono::duration_cast<ns>(diff).count() << endl;
	}

	myout.close();



	return 0;

}