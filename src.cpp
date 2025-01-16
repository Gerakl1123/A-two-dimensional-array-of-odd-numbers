#include <iostream>
#include <cstdlib>
#include <ctime>

//fill array new mem 
void FillArrMEM(int* arr[], const int row, const int col) {
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }
}

// fill array random number && checr num % 2 != 0 
void FillArray(int* const arr[], const int row, const int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = rand() % 50; 
            if (arr[i][j] % 2 != 0) {
                arr[i][j] -= 1;
            }
        }
    }
}

// show array
void ShowArray(int* arr[], const int row, const int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// delete mem arr pointer
void DeleteArray(int* arr[], const int row) {
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int rows, cols;

    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> rows >> cols;

   
    if (rows <= 0 || cols <= 0) {
        std::cerr << "Количество строк и столбцов должно быть положительным!" << std::endl;
        return 1;
    }

    int** arr = new int* [rows];

    srand(time(NULL));

    //Function
    FillArrMEM(arr, rows, cols);
    FillArray(arr, rows, cols);
    ShowArray(arr, rows, cols);
    DeleteArray(arr, rows);

    // Delete MEM
    delete[] arr;
    arr = nullptr;

    system("pause");
    return 0;
}
