//#include <iostream>
//#include <cmath>
//#include <ctime>
//using namespace std;
//
//double canh(int x1, int y1, int x2, int y2)
//{
//    double A;
//    A = (pow(x1 - x2, 2)) + pow(y1 - y2, 2);
//    return A;
//}
//
//bool tamgiac(double a, double b, double c)
//{
//    if (a + b > c && a + c > b && b + c > a)
//        return true;
//    return false;
//}
//
//bool tamgiaccan(int x1, int y1, int x2, int y2, int x3, int y3)
//{
//    double A, B, C;
//    A = canh(x1, y1, x2, y2);
//    B = canh(x1, y1, x3, y3);
//    C = canh(x2, y2, x3, y3);
//    if (A + B == C && tamgiac(sqrt(A), sqrt(B), sqrt(C)) )
//            return true;
//    return false;
//}
//
//int** listTriplets(int points[][2], int n, int& result_size)
//{
//    int** a = new int* [n * 3];
//    for (int i = 0; i < n * 3; i++)
//        a[i] = new int[3];
//
//    for (int i = 0; i < n ; i++)
//        for (int j = 0; j < n ; j++)
//            for (int k = j + 1; k < n; k++)
//                if (tamgiaccan(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]) && i != j && j != k && i != k)
//                {
//                    a[result_size][0] = i;
//                    a[result_size][1] = j;
//                    a[result_size][2] = k;
//                    result_size++;
//                }
//    return a;
//}
//int main()
//{
//    int points[][2] = {
//    {1, 1},
//    {0, 0},
//    {3, 3},
//    {2, 4},
//    {3, -1} 
//    };
//    int result_size = 0;
//    int** triplets = listTriplets(points, 5, result_size);
//    for (int i = 0; i < result_size; i++)
//    {
//        cout << triplets[i][0] << ", " << triplets[i][1] << ", " << triplets[i][2] << endl;
//    }
//}