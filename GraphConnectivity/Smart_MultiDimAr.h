#pragma once

template<class T>
class sMatrix {
public:
	T** matrix = nullptr;
	int arrCount;
	int arrElems;
	sMatrix() = default;
	sMatrix(int X, int Y);
	sMatrix(int X, int Y, T fill);
	~sMatrix();
	sMatrix(const sMatrix& cop);
	sMatrix(sMatrix& cop);
	T* operator[](int const index) {
		return matrix[index];
	}
	void GenerateMatrix(int X, int Y);;
	void ResetValues(T value);
};

#include "Smart_MultiDimArr.cpp"