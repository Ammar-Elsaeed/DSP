import matplotlib.pyplot as plt
from numpy.random import randint
import numpy as np
import time
import fourier
#===========================================Initialization
size_10 = randint(0, 10, 16)
size_100 = randint(0, 10, 128)
size_1k = randint(0, 10, 1024)
size_10k = randint(0, 10, 16384)
size_100k = randint(0, 10, 131072) # 3-4 Minutes
size_1M = randint(0, 10, 1048576) #2.7 H

inputs = [size_10,size_100,size_1k,size_10k,size_100k,size_1M]
outputsFFT = []
outputsFT = []
#===========================================FFT Time & Output Caclulations
time_start = []
time_end = []
timeFFT=[]
timeFT=[]

for i in range(6):
    time_start.append(time.time())
    outputsFFT.append(fourier.fft(inputs[i]))
    print(i)
    print("\n")
    time_end.append(time.time())
    timeFFT.append(time_end[i]-time_start[i])
    print(timeFFT[i])
#===========================================FT Time & Output Caclulations
time_start = []
time_end = []

for i in range(4):
    time_start.append(time.time())
    outputsFT.append(fourier.ft(inputs[i]))
    print(i)
    print("\n") 
    time_end.append(time.time())
    timeFT.append(time_end[i]-time_start[i])
    print(timeFT[i])
#===========================================Error Calculations
MSE=[]
for i in range(4):
    MSE.append(np.square(np.absolute(np.subtract(outputsFT[i],outputsFFT[i]))).mean())
    print(MSE[i])
#===========================================Time Complexity Plot
plt.subplot(211)
lineFFT=plt.plot([10,100,1000,10000,100000,1000000],timeFFT)
plt.setp(lineFFT, color='r',marker='.')
lineFT=plt.plot([10,100,1000,10000],timeFT)
plt.setp(lineFT, color='b',marker='.')
plt.title('Time Complexity')
plt.xlabel('Input Size')
plt.ylabel('Time')
#plt.grid(True)
#===========================================Output Error Plot
plt.subplot(212)
lineError=plt.plot([10,100,1000,10000],MSE)
plt.setp(lineFFT, color='g',marker='.')
plt.title('Output Error')
plt.xlabel('Input Size')
plt.ylabel('Error')
plt.tight_layout()
plt.show()
  
