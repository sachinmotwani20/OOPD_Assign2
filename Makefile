Code_debug: LMS.cpp
	g++ -Wall  -c $< -o $@

Code_optimize: LMS.cpp
	g++ -O2   -c $< -o $@