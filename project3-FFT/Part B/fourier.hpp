#ifndef FOURIER
#define FOURIER
#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
typedef long long ll;
//================================================Calculate Cooley-Tukey FFT
vector<cd> fft(vector<cd> &input)
{ // must provide 2^n input size to function properly.

	// Check if it is splitted enough
	int N = input.size();
	if (N <= 1)
		return input;

	// Split even and odd
	vector<cd> output(N);
	vector<cd> odd(N / 2);
	vector<cd> even(N / 2);
	for (int i = 0; i < N / 2; i++)
	{
		even[i] = input[i * 2];
		odd[i] = input[i * 2 + 1];
	}

	// Split on tasks
	even = fft(even);
	odd = fft(odd);

	// Calculate DFT
	for (int k = 0; k < N / 2; k++)
	{
		cd W = exp(cd(0, -2 * M_PI * k / N));
		output[k] = even[k] + W * odd[k];
		output[k + N / 2] = even[k] - W * odd[k];
	}
	return output;
}
//================================================Calculate FT
vector<cd> ft(vector<cd> input)
{
	int N = input.size();
	double inv = 1.0 / N;
	cd theta = cd(0.0, -2.0 * M_PI * inv);
	cd W = exp(theta), W_nk;
	vector<cd> output(N, 0);
	for (int k = 0; k < N; k++)
	{
		for (int n = 0; n < N; n++)
		{
			W_nk = pow(W, n * k);
			output[k] += input[n] * W_nk;
		}
	}
	return output;
}
#endif