#include "DegreePlynomial.h"
#include "Change.h"

void polynomRealRoots(std::vector<double>& kf, std::vector<double>& rootsArray);

int CDegreePlynomial::FDegreePolynomial()
{
	CDegreePlynomial func;
	func.Init();

	func.FSLDVisualFunc(ON);
	func.FOpredIntegral();
	func.FFindCor();
	func.FFindExtremum();


	std::cout << "конец";
	system("pause");
	func.FSLDVisualFunc(OFF);
	return 0;
}
double CDegreePlynomial::FCalculate(double x) 
{ 
	double summ = 0.0;
	double dx = 1;
	for (size_t i = 0; i < arr.size(); i++)
	{
		summ += arr[i] * dx;
		dx *= x;
	}
	return summ; 
}
void CDegreePlynomial::FSLDVisualFunc(bool bOn)
{
	__super::FOpredIntegral();
}
void CDegreePlynomial::FOpredIntegral()
{
	__super::FOpredIntegral();
	double delta = 0;
	double deltaleft = this->leftIntegr;
	double deltaright = this->rightIntegr;
	for (size_t i = 0; i < this->size; i++)
	{
		delta += this->arr[i] / (i + 1) * deltaright;
		delta -= this->arr[i] / (i + 1) * deltaleft;
		deltaleft *= this->leftIntegr;
		deltaright *= this->rightIntegr;
	}
	std::cout << delta;
}
void CDegreePlynomial::FFindCor()
{
	std::vector<double> deltaArr;
	for (size_t i = 0; i < arr.size(); i++)
	{
		deltaArr.push_back(arr[i] / arr[arr.size() - 1]);
	}
	polynomRealRoots(deltaArr,cor);
	std::cout << "\nКорни:";
	for (size_t i = 0; i < cor.size(); i++)
	{
		std::cout << "x" << i + 1 << " = " << cor[i] << '\n';
	}
}
void CDegreePlynomial::FFindExtremum()
{
	std::vector<double> deltaArr(arr.size()-1);
	for (size_t i = 0; i < arr.size(); i++)
	{
		deltaArr[i] = arr[i+1] * i;
	}
	polynomRealRoots(deltaArr, cor);
	std::cout << "\nЭкстремумы:";
	for (size_t i = 0; i < cor.size(); i++)
	{
		std::cout << "x" << i + 1 << " = " << cor[i] << '\n';
	}
}
void CDegreePlynomial::Init()
{
	int bYouAагрее = 0;
	std::string bigString = "";
	do
	{
		bigString = "";
		CLEARCONSOLE;
		size = Vvod<size_t>("Введите количество параметров от 1 до 9", [](size_t a) {return a > 0 || a < 10; });
		std::cout << "Вводите " << size << " значения\n";
		double delta;
		for (size_t i = 0; i < size; i++)
		{
			delta = Vvod<double>();
			this->arr.push_back(delta);
		}
		__super::Init();

		bigString += "\n" + std::to_string(arr[0]);
		for (size_t i = 1; i < size; i++)
		{
			bigString += (arr[i] < 0 ? " - " : " + ") + std::to_string(abs(arr[i])) + "*x^" + std::to_string(i);
		}
		bigString += "\nПромежуток определённого интегралла = [" + std::to_string(leftIntegr) + ";" + std::to_string(rightIntegr) + "]\n";
		bYouAагрее = Change(
			{
				{[]() {return 1; } ,"Да"},
				{[]() {return 0; } ,"Нет"},
			},
			NONEEXIT | ONETIME,
			std::string(bigString + "Вы согласны с представленными данными?"));
	} while (bYouAагрее != 1);
}

double polinom(int n, double x, std::vector<double> k)
{
	double s = 1;
	for (int i = n - 1; i >= 0; i--)
		s = s * x + k[i];
	return s;
}
double dihot(int degree, double edgeNegativ, double edgePositiv, std::vector<double> kf)
{
	for (;;)
	{
		double x = 0.5 * (edgeNegativ + edgePositiv);
		if (x == edgeNegativ || x == edgePositiv)return x;
		if (polinom(degree, x, kf) < 0)edgeNegativ = x;
		else edgePositiv = x;
	}
}

void stepUp(
	int level,
	std::vector<std::vector<double>> A,
	std::vector<std::vector<double>> B,
	std::vector<double> currentRootsCount 
)
{
	double major = 0;
	for (int i = 0; i < level; i++)
	{
		double s = fabs(A[level][i]);
		if (s > major)major = s;
	}
	major += 1.0;

	currentRootsCount[level] = 0; 
	for (int i = 0; i <= currentRootsCount[level - 1]; i++) {
		int signLeft, signRight;

		double edgeLeft, edgeRight;

		double edgeNegativ, edgePositiv;

		if (i == 0)edgeLeft = -major;
		else edgeLeft = B[level - 1][i - 1];

		double rb = polinom(level, edgeLeft, A[level]);

		if (rb == 0)
		{
			B[level][currentRootsCount[level]] = edgeLeft;
			currentRootsCount[level]++;
			continue;
		}
		if (rb > 0)signLeft = 1; else signLeft = -1;

		if (i == currentRootsCount[level - 1])edgeRight = major;
		else edgeRight = B[level - 1][i];

		rb = polinom(level, edgeRight, A[level]);

		if (rb == 0)
		{
			B[level][currentRootsCount[level]] = edgeRight;
			currentRootsCount[level]++;
			continue;
		}

		if (rb > 0)signRight = 1; else signRight = -1;

		if (signLeft == signRight)continue;

		if (signLeft < 0) { edgeNegativ = edgeLeft; edgePositiv = edgeRight; }
		else { edgeNegativ = edgeRight; edgePositiv = edgeLeft; }

		B[level][currentRootsCount[level]] = dihot(level, edgeNegativ, edgePositiv, A[level]);
		currentRootsCount[level]++;
	}
	return;
}

void polynomRealRoots(
	std::vector<double>& kf, 
	std::vector<double>& rootsArray) 
{
	std::vector<std::vector<double>> A(kf.size() + 1);
	std::vector<std::vector<double>> B(kf.size() + 1);

	std::vector<double> currentRootsCount(kf.size() + 1);

	for (int i = 1; i <= kf.size(); i++)
	{
		A[i].resize(i);
		B[i].resize(i);
	}

	for (int i = 0; i < kf.size(); i++)A[kf.size()][i] = kf[i] / kf[kf.size()];

	for (int i1 = kf.size(), i = kf.size() - 1; i > 0; i1 = i, i--)
	{
		for (int j1 = i, j = i - 1; j >= 0; j1 = j, j--)
		{
			A[i][j] = A[i1][j1] * j1 / i1;
		}
	}

	currentRootsCount[1] = 1;
	B[1][0] = -A[1][0];

	for (int i = 2; i <= kf.size(); i++)stepUp(i, A, B, currentRootsCount);

	for (int i = 0; i < currentRootsCount[kf.size()]; i++)rootsArray.push_back(B[kf.size()][i]);

	return;
}