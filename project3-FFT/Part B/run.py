import fourier
from numpy.random import randint
import numpy as np
import time

size_10 = randint(0, 10, 16)
size_100 = randint(0, 10, 128)
size_1k = randint(0, 10, 1024)
size_10k = randint(0, 10, 16384)
size_100k = randint(0, 10, 131072)
size_1M = randint(0, 10, 1048576) #2.7

inputs = [size_10,size_100,size_1k,size_10k,size_100k,size_1M]
outputs = []

time_start = []
time_end = []
timeFFT=[]
timeFT=[]
#time for FFT
for i in range(5):
    time_start.append(time.time())
    outputs.append(fourier.fft(inputs[i]))
    print(i)
    print("\n")
    time_end.append(time.time())
    timeFFT.append(time_end[i]-time_start[i])
    print(timeFFT[i])




time_start = []
time_end = []

for i in range(5):
    time_start.append(time.time())
    outputs.append(fourier.ft(inputs[i]))
    print(i)
    print("\n") 
    time_end.append(time.time())
    timeFT.append(time_end[i]-time_start[i])
    print(timeFT[i])


