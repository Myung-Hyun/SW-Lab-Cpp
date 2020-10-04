#include <fstream>
#include<cmath>
#include <iostream>
#include <chrono> //성능 측정

using namespace std;
using ns=chrono::nanoseconds;
using get_time = chrono::steady_clock;
constexpr auto PI = 3.141592;; //constexpr는 컴파일 시간 상수. 컴파일 타임에 식의 값을 알 수 있다.
//즉 컴파일 타임에 상수를 확실히 사용하고 싶은 경우 사용. constexpr는 항상 const이지만 역은 아니다.


/*
Compare performance of integration and differentiation of 2sin⁡(𝜔𝑡) where 𝜔=2𝜋∙100 and time interval is [0, 0.1sec]. 
That is, plot (SNR) in terms of computation time of different ∆ sizes. If time is too short, repeat 1000 times or 10000 times.
*/

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

	for (dt; dt < 0.01; dt += 0.0002) 
	{
		auto start = get_time::now();

		for (float t = 0.; t < T; t += dt)
		{
			float itg = 0.0; //적분값.
			for (float i = 0.; i <= t; i += dt)
			{

				float temp = dt * 2. * sin(200. * PI * i);
				itg += temp;
			}

			float signal = -2. * cos(200. * PI * t) / (2 * PI * 100);
			float noise = itg - 2. / (200. * PI) - signal;

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
