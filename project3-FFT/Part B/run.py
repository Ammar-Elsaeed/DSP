import matplotlib.pyplot as plt
from numpy.random import randint
import numpy as np
import time
import fourier

def calcTimeAndOutput(numSignalLengths,fourierAlgo):
    outputs,outputsTime=[],[]
    for i in range(numSignalLengths):
        time_start=time.time()
        if(fourierAlgo=='FFT'):
            outputs.append(fourier.fft(inputs[i]))
        elif(fourierAlgo=='FT'):
            outputs.append(fourier.ft(inputs[i])) 
        time_end=time.time()
        outputsTime.append(time_end-time_start)
    return outputs,outputsTime
#===========================================Initialization
size_10 = randint(0, 10, 16)
size_100 = randint(0, 10, 128)
size_1k = randint(0, 10, 1024)
size_10k = randint(0, 10, 16384)
size_100k = randint(0, 10, 131072) # 3-4 Minutes in FT
size_1M = randint(0, 10, 1048576) #2.7 H in FT

inputs = [size_10,size_100,size_1k,size_10k,size_100k,size_1M]
timeFFT,timeFT,outputsFFT,outputsFT = [],[],[],[]
#===========================================FFT Time & Output Caclulations
outputsFFT,timeFFT=calcTimeAndOutput(6,'FFT')
#===========================================FT Time & Output Caclulations
outputsFT,timeFT=calcTimeAndOutput(4,'FT')
#===========================================Mean Square Error Calculations
MSE=[]
for i in range(4):
    MSE.append(np.square(np.absolute(np.subtract(outputsFT[i],outputsFFT[i]))).mean())
#===========================================Time Complexity Plot
plt.subplot(211)
lineFFT=plt.plot([10,100,1000,10000,100000,1000000],timeFFT,label='FFT - (nlogn)')
plt.setp(lineFFT, color='r',marker='.')
lineFT=plt.plot([10,100,1000,10000],timeFT,label='FT - (n^2)')
plt.setp(lineFT, color='b',marker='.')
plt.title('Time Complexity')
plt.xlabel('Input Size')
plt.ylabel('Time')
plt.legend(loc="upper right")
#===========================================Output Error Plot
plt.subplot(212)
lineError=plt.plot([10,100,1000,10000],MSE)
plt.setp(lineError, color='g',marker='.')
plt.title('MSE Of The Output')
plt.xlabel('Input Size')
plt.ylabel('Error')
#===========================================Show The Plot & Arrange The Layout  
plt.tight_layout()
plt.show()
  
