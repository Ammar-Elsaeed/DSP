#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;

//Cooley-Tukey FFT
void fft_(vector<cd>& x) { // must provide 2^n input size to function properly.

	// Check if it is splitted enough
    int N=x.size();
	if (N <= 1) {
		return;
	}

	// Split even and odd
	vector<cd> odd(N/2);
	vector<cd> even(N/2);
	for (int i = 0; i < N / 2; i++) {
		even[i] = x[i*2];
		odd[i] = x[i*2+1];
	}

	// Split on tasks
	fft_(even);
	fft_(odd);


	// Calculate DFT
	for (int k = 0; k < N / 2; k++) {
		cd W = exp(cd(0, -2 * M_PI * k / N)) ;
		x[k] = even[k] + W * odd[k];
		x[k + N/2] = even[k] - W * odd[k];
	}
}
//================================================
vector<cd> fft(vector<cd> input)
{
    fft_(input);
    vector<cd>output=input;
    return output;
}
//================================================
vector<cd> ft(vector<cd> input)
{
    int N=input.size();
    double inv=1.0/N;
     cd theta= cd(0.0,-2.0 * M_PI * inv);
    cd w=exp(theta),W;
    vector<cd> output(N,0);
    for(int k=0;k<N;k++)
    {
        for(int n=0;n<N;n++)
        {
            W=pow(w,n*k);
            output[k] += input[n] * W;
        }
    }
    return output;
}
// // Driver code
// int main()
// {
//     vector<cd> input{1,1,1,1,0,0,0,0};
//     vector<cd> outFFT =fft(input);
//     vector<cd> outFT = ft(input);
// 	for (int i = 0; i <input.size(); i++)
// 		cout << outFFT[i] <<" "<<outFT[i]<< endl;

// 	return 0;
// }

// g++-10 -std=c++17 fft.cpp                     
// g++-10 -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup $(python3 -m pybind11 --includes) pybind11_wrapper.cpp -o fourier$(python3-config --extension-suffix)