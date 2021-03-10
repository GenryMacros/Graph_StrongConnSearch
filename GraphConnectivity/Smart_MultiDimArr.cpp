template<class T>
sMatrix<T> ::sMatrix(int X, int Y) {
	arrCount = X;
	arrElems = Y;
	matrix = new T * [X];
	for (int i = 0; i < X; i++) {
		matrix[i] = new T[Y];
	}
}
template<class T>
sMatrix<T>::sMatrix(int X, int Y, T fill) {
	arrCount = X;
	arrElems = Y;
	matrix = new  T * [X];
	for (int i = 0; i < X; i++) {
		matrix[i] = new T[Y];
		for (int j = 0; j < Y; j++) {
			matrix[i][j] = fill;
		}
	}
}
template<class T>
sMatrix<T> ::~sMatrix() {
	if (matrix == nullptr)return;
	for (int i = 0; i < arrCount; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
template<class T>
sMatrix<T> ::sMatrix(const sMatrix& cop) {
	if (matrix != nullptr) {
		for (int i = 0; i < arrCount; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	arrCount = cop.arrCount;
	arrElems = cop.arrElems;
	matrix = new  T * [arrCount];
	for (int i = 0; i < arrCount; i++) {
		matrix[i] = new T[arrElems];
		for (int j = 0; j < arrElems; j++) {
			matrix[i][j] = cop.matrix[i][j];
		}
	}
}
template<class T>
sMatrix<T> ::sMatrix(sMatrix& cop) {
	if (matrix != nullptr) {
		for (int i = 0; i < arrCount; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	arrCount = cop.arrCount;
	arrElems = cop.arrElems;
	matrix = cop.matrix;
	cop.matrix = nullptr;
}
template<class T>
void sMatrix<T> ::GenerateMatrix(int X, int Y) {
	arrCount = X;
	arrElems = Y;
	matrix = new T * [X];
	for (int i = 0; i < X; i++) {
		matrix[i] = new T[Y];
	}
}
template<class T>
void sMatrix<T> ::ResetValues(T value) {
	for (int i = 0; i < arrCount; i++) {
		for (int j = 0; j < arrElems; j++) {
			matrix[i][j] = value;
		}
	}
}