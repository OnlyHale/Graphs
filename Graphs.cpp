/***************************************************************************************
*Project Name : Graphs                                                                 *
*File Name    : Graphs.cpp                                                             *
*Language     : CPP,MSVS ver 2015 and above                                            *
*Programmers : Ратников Роман Олегович,группа:М3О-210Б-20                              * 
*Modified By  :                                                                        *
*Created      : 20/10/2021                                                             *
*Last Revision: 28/11/2021                                                             *
*Comment      : Графы	                                                               *
***************************************************************************************/

#include <iostream>

using namespace std;

//Формирование исходной матрицы

void GetMatrix(int* Matrix[], const int& N);

void GetP(int* P[],const int& N);

//Печать матрицы

void PrintMatrix(int* Matrix[], const int& N);

//Алгоритм Флойда-Уоршелла

void Floyd(int* Matrix[], const int& N, int* P[]);

//Функция получения пути

void GetWay(const int& i, const int& j, int* P[], int* Way, int& start);

// Функция печати пути

void PrintWay(int* Way, const int& start, const int& N);

//Этап 1
void Stage1();

//Этап 2
void Stage2();


// Алгоритм Краскала
void Cruscal(

	int* Matrix[], //Матрица смежности

	const int& N); //Размер матрицы




int main()
{
	system("color F0");
	setlocale(LC_ALL, "Rus");
	Stage1();
	Stage2();
	
	return 0;
}
void Stage1()
{
	
	const int N = 10;
	int** Matrix = new int * [N];
	int** P = new int* [N];
	int* Way = new int[N];
	int start = N-1;

	GetMatrix(Matrix, N);
	GetP(P, N);
	
	cout << "Исходная матрица смежности: " << endl;

	PrintMatrix(Matrix, N);

	cout << "\n\n";
	
	cout << " Работа Алгоритма Флойда-Уоршелла: " << endl;
	Floyd(Matrix, N, P);

	cout << "\n\nПолученная матрица смежности: " << endl;

	PrintMatrix(Matrix, N);
	
	int i,j;
	cout << " Введите начало и конец маршрута (для выхода введите -1 -1) : " << endl;
	while (cin >> i >> j)
	{
		if (i*j == 1)
		{
			return;
		}
		if ((0 <= i  and i <= N-1 ) and (0 <= j and j <= N-1 ))
		{   
			int start=N-1;
			cout << "\n\n Путь из " << i << " в " << j << " : " << endl;

			GetWay(i , j , P, Way, start);

			PrintWay(Way, start, N);
			cout << "\n";
			PrintMatrix(P, N);
			cout << "\n Введите начало и конец маршрута : " << endl;
		}
		else
		{
			cout << "Выберите, пожалуйста, пункты от 0 до " << N-1 << " включительно :" << endl;
		}
	}

	for (int i = 0; i < N; i++)
	{
		delete[] Matrix[i];
		delete[] P[i];
	}
	delete[] Matrix;
	delete[] P;
	delete[] Way;
}

void GetMatrix(int* Matrix[], const int& N)
{
  for (int i = 0;i < N;++i)
	{
		Matrix[i] = new int[N];
	}

	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < N;++j)
		{
			if(i==j)
				Matrix[i][j] = 0;
			else
				Matrix[i][j] = 99;

			
		}
		
	}
  
	Matrix[0][4] = 3;
	Matrix[1][2] = 5;
	Matrix[1][5] = 1;
	Matrix[2][4] = 2;
	Matrix[2][6] = 5;
	Matrix[2][8] = 4;
	Matrix[3][2] = 1;
	Matrix[3][7] = 8;
	Matrix[4][0] = 10;
	Matrix[4][3] = 3;
	Matrix[5][4] = 7;
	Matrix[5][7] = 8;
	Matrix[7][0] = 5;
	Matrix[7][6] = 11;
	Matrix[7][9] = 9;
	Matrix[8][1] = 5;
	Matrix[8][3] = 10;
	Matrix[8][5] = 2;
	Matrix[9][2] = 2;
	
	/*
	Matrix[0][1] = 2;
	Matrix[0][2] = 2;
	Matrix[0][3] = 3;
	Matrix[1][3] = 1;
	Matrix[2][4] = 5;
	Matrix[3][2] = 7;
	Matrix[4][6] = 1;
	Matrix[4][9] = 11;
	Matrix[5][9] = 3;
	Matrix[6][7] = 10;
	Matrix[7][9] = 7;
	Matrix[8][3] = 3;
	Matrix[8][4] = 10;
	Matrix[8][5] = 1;
	
	*/
}

void GetP(int* P[],const int& N)
{
	for (int i = 0;i < N;++i)
	{
		P[i] = new int[N];
	}

	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < N;++j)
		{
			P[i][j] = i;
		}
		P[i][i] = -1;
	}
}

void PrintMatrix(int* Matrix[], const int& N)
{
  for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < N;++j)
		{

			cout <<" "<< Matrix[i][j] << '\t';


		}
		cout << "\n";
	}
}

void Floyd(int* Matrix[], const int& N, int* P[])
{
 for (int k = 0;k < N;++k)
	{
		for (int i = 0;i < N;++i)
		{
			for (int j = 0;j < N;++j)
			{
				if ((Matrix[i][k] + Matrix[k][j]) < Matrix[i][j])
				{
					Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
					P[i][j] = P[k][j]; 
					
				}
				
			}
		}

		cout << "\n " << k+1 << "-я итерация: " << endl;
		PrintMatrix(Matrix, N);
	}
}

void GetWay(const int& i, const int& j, int* P[], int* Way, int& start)
{
	
	int k;
	k = P[i][j];
	Way[start] = j;
	
	if (i == j)
	{
		
		return;
	}
	--start;
	GetWay(i, k, P, Way, start);
}

void PrintWay(int* Way, const int& start,const int& N)
{

	for (int i = start;i < N;++i)
	{
		if (i != N - 1)
		{
			cout << " " << Way[i] << " -->";
		}
		else
			cout << " " << Way[i] << endl;
	}
}


void Stage2()
{
	const int N = 10;
	int** Matrix = new int* [N];

	GetMatrix(Matrix, N);

	cout << "Исходная матрица смежности: " << endl;


	Matrix[0][4] = 3;
	Matrix[0][7] = 5;
	Matrix[1][2] = 5;
	Matrix[1][5] = 1;
	Matrix[1][8] = 5;
	Matrix[2][1] = 5;
	Matrix[2][3] = 1;
	Matrix[2][4] = 2;
	Matrix[2][6] = 5;
	Matrix[2][8] = 4;
	Matrix[2][9] = 2;
	Matrix[3][2] = 1;
	Matrix[3][4] = 3;
	Matrix[3][7] = 8;
	Matrix[3][8] = 10;
	Matrix[4][0] = 3;
	Matrix[4][2] = 2;
	Matrix[4][3] = 3;
	Matrix[4][5] = 7;
	Matrix[5][1] = 1;
	Matrix[5][4] = 7;
	Matrix[5][7] = 8;
	Matrix[5][8] = 2;
	Matrix[6][2] = 5;
	Matrix[6][7] = 11;
	Matrix[7][0] = 5;
	Matrix[7][3] = 8;
	Matrix[7][5] = 8;
	Matrix[7][6] = 11;
	Matrix[7][9] = 9;
	Matrix[8][1] = 5;
	Matrix[8][2] = 4;
	Matrix[8][3] = 10;
	Matrix[8][5] = 2;
	Matrix[9][2] = 2;
	Matrix[9][7] = 9;

	PrintMatrix(Matrix, N);

	cout << " \n Алгоритм Краскала: " << endl;
	Cruscal(Matrix, N);
	
	
	return;
	
}
	

void Cruscal(int* Matrix[], const int& N )

{

	// Ребро

	struct Edge

	{

		int weight; // Вес Ребра

		int i; //номер первой точки грани

		int j; //номер второй точки грани

	};

	Edge* edges; //массив рёбер

	int max_edges = (N - 1) * N / 2; //максимальное число рёбер у неоринтир. графа

	int** spanning_tree; //матрица остовного дерева

	int* connected_dots; //массив связей у точек

	int edge_count; //число рёбер в графе

	int tree_weight = 0; //вес остовного дерева

	//выделяем память под массив остовного дерева

	spanning_tree = new int* [N];

	for (int i = 0; i < N; i++)
	{
		spanning_tree[i] = new int[N]();
	}

	//выделяем память под массив рёбер

	edges = new Edge[max_edges];

	//заполняем матрицу

	for (int i = 0; i < N; i++)

	{

		for (int j = 0; j < N; j++)

		{

			if (i != j)
			{
				spanning_tree[i][j] = 99;
			}

			else
			{
				spanning_tree[i][j] = 0;
			}

		}

	}

	

	connected_dots = new int[N];

	for (int i = 0; i < N; i++)
	{
		connected_dots[i] = i;
	}

	//заполняем массив рёбер

	edge_count = 0;

	for (int i = 0; i < N; i++)

	{

		for (int j = 0; j < N; j++)

		{

			if (Matrix[i][j] < 99)

			{

				edges[edge_count].weight = Matrix[i][j];

				edges[edge_count].i = i;

				edges[edge_count].j = j;

				edge_count++;

			}

		}

	}

	//сортируем массив рёбер

	
	int end = edge_count;
	Edge Bufer;
	for (int i = 0; i < edge_count; i++)
	{

		
		for (int j = 0; j < end-1;j++)
		{
			if (edges[j].weight > edges[j+1].weight)
			{

				Bufer = edges[j+1];

				edges[j+1] = edges[j];

				edges[j] = Bufer;
				

			}
		}
		end--;
	}
	
	
	//заполняем матрицу дерева

	for (int i = 0; i < edge_count; i++)

	{

		//сравниваем начальные точки для выбраных частей дерева

		if (connected_dots[edges[i].i] != connected_dots[edges[i].j])

		{

			//промежуточный результат
			cout << "\n\n"<<i+1<<"-я итерация " << endl;
			PrintMatrix(spanning_tree, N);

			//массив связей на данной итерации

			for (int k = 0; k < N; k++)
			{
				cout << connected_dots[k] << ' ';
			}

			cout << endl;

			//если начальные точки не равны, то запоминаем в матрицу дерева вес грани

			spanning_tree[edges[i].i][edges[i].j] = edges[i].weight;

			spanning_tree[edges[i].j][edges[i].i] = edges[i].weight;

			//перестраиваем связи у точек

			int old_start_dot = connected_dots[edges[i].j]; //старая связь

			int new_start_dot = connected_dots[edges[i].i]; //новая связь

			for (int j = 0; j < N; j++)

			{

				if (connected_dots[j] == old_start_dot)  // Старая связь
				{
					connected_dots[j] = new_start_dot;   //Новая связь
				}

			}

		}

	}

	

	cout << "Матрица остовного дерева" << endl;

	PrintMatrix(spanning_tree, N);

	//массив связей на данной итерации

	for (int k = 0; k < N; k++) cout << connected_dots[k] << ' ';

	cout << endl;

	tree_weight = 0;

	for (int i = 0; i < N; i++)

	{

		for (int j = 0; j < i; j++)

		{

			if (spanning_tree[i][j] < 99)
			{
				tree_weight += spanning_tree[i][j];
			}

		}

	}

	cout << "Вес дерева : " << tree_weight << endl;

	
	//удаляем матрицы

	for (int i = 0; i < N; i++)
	{
		delete[] spanning_tree[i];
	}
	delete[] connected_dots;

	delete[] edges;

	delete[] spanning_tree;
	
	return ;
}

		
	
