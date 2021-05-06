#ifndef FOURIER
#define FOURIER
#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
typedef long long ll;
//================================================Check if the number is a power of 2
// bool isPowerOf2(ll n) return (((n & (n - 1)) == 0) ? 1 : 0); // returns true if n is a power of 2.
//================================================Zero Padding of the Input
// void inputPadding(vector<cd> &input)
// {
// 	ll inputSize = input.size();
// 	ll nextPowerOf2 = pow(2, ceil(log2(inputSize))); //Calculate The Smallest power of 2 greater than or equal to n
// 	ll numberOfPaddingZeros = nextPowerOf2 - inputSize;
// 	while (numberOfPaddingZeros--)
// 		input.push_back(cd(0));
// }
//================================================Cooley-Tukey FFT
void fft_(vector<cd> &x)
{ // must provide 2^n input size to function properly.

	// Check if it is splitted enough
	int N = x.size();
	if (N <= 1)
		return;

	// Split even and odd
	vector<cd> odd(N / 2);
	vector<cd> even(N / 2);
	for (int i = 0; i < N / 2; i++)
	{
		even[i] = x[i * 2];
		odd[i] = x[i * 2 + 1];
	}

	// Split on tasks
	fft_(even);
	fft_(odd);

	// Calculate DFT
	for (int k = 0; k < N / 2; k++)
	{
		cd W = exp(cd(0, -2 * M_PI * k / N));
		x[k] = even[k] + W * odd[k];
		x[k + N / 2] = even[k] - W * odd[k];
	}
}
//================================================Calculate FFT
vector<cd> fft(vector<cd> input)
{
	// ll originalInputSize = input.size();
	// if (!isPowerOf2(originalInputSize))
	// 	inputPadding(input);
	fft_(input);
	vector<cd> output = input;
	return output;
}
//================================================Calculate FT
vector<cd> ft(vector<cd> input)
{
	int N = input.size();
	double inv = 1.0 / N;
	cd theta = cd(0.0, -2.0 * M_PI * inv);
	cd w = exp(theta), W;
	vector<cd> output(N, 0);
	for (int k = 0; k < N; k++)
	{
		for (int n = 0; n < N; n++)
		{
			W = pow(w, n * k);
			output[k] += input[n] * W;
		}
	}
	return output;
}
#endif