

#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>
#include <fstream>
#include <random> // gaussian
#include <math.h>

using namespace std;

int main()
{


	ofstream my_out("out.txt");

	default_random_engine generator;
	normal_distribution<double> myGauss(350.0, 17.07);

	int y[501], Ntry=300000;

	for (int i = 0;i < 501;i++)
	{
		y[i] = 0;
	}

	for (int i = 0; i < Ntry; i++)
	{
		double number = myGauss(generator);
		int quant = round(number); //quantization
		y[quant - 100]++;
	}

	for (int i = 0; i < 501;i++)
	{
		my_out << y[i] << endl;
	}

	/*
	ofstream my_out("out.txt");

	srand((unsigned int)time(NULL));

	int  y[501], Ntry = 100000;
	for (int i = 0;i < 501;i++)
	{
		y[i] = 0;
	}

	float std_deviation = 0;

	for (int j = 0; j < Ntry; j++)
	{
		int y_sum = 0; // 초기화 위치 중요함. 
		for (int i = 0; i < 100; i++)
		{
			int temp = ((rand() % 6) + 1);
			y_sum += temp; // 100~600 인 RV y 생성
		
		}
		
		std_deviation += pow((y_sum - 350), 2); 
		y[y_sum - 100]++;  

	}
	std_deviation = std_deviation / (float)Ntry; // 표준편차: 편차 제곱의 평균을 제곱근 씌운 것.
	cout << sqrt(std_deviation);

	for (int i = 0; i < 501;i++)
	{
		my_out << y[i] << endl;
	}*/
	


	return 0;
}






// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
