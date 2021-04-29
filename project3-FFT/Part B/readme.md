to compile the cpp header file using pybind11 type in the terminal:
```
g++-10 -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup $(python3 -m pybind11 --includes) pybind11_wrapper.cpp -o fourier$(python3-config --extension-suffix)
```
to run the python file type in the terminal:
```
python3 run.py 