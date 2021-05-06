#include<iostream>
#include<math.h>

using namespace std;

bool isTriangle(double a, double b, double c)
{
    if (a + b > c && a + c > b && b + c > a) return 1;
    return 0;
}

int** listTriplets(int points[][2], int n, int& result_size)
{
    int **a;
    a = new int*[n*3];
    for (int i = 0; i < n*3; i++)
        a[i] = new int[3];

    for (int i=0; i < n; i++)
        for (int j=0; j < n-1; j++)
            for (int k =j+1; k < n; k++)
            {
                if (i != j && i != k && j != k)
                {
                    double AB = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1],2)),
                        AC = sqrt(pow(points[i][0] - points[k][0],2) + pow(points[i][1] - points[k][1],2)),
                        BC = sqrt(pow( points[k][0] - points[j][0],2) + pow(points[k][1] - points[j][1],2));

                    if (isTriangle(AB, AC, BC) && AB == AC)
                    {
                        
                        a[result_size][0] = i;
                        a[result_size][1] = j;
                        a[result_size][2] = k;
                        result_size++;
                    }
                }
            }

    return a;
}

int main() {
    int points[][2] = {
    {0, 0},
    {2, -2},
    {6, 2},
    {4, 0},
    {3, 1}
    };
    int result_size=0;
    int** triplets = listTriplets(points, 5, result_size);
    for (int i = 0; i < result_size; ++i) {
        cout << triplets[i][0] << ", " << triplets[i][1] << ", " << triplets[i][2] << endl;
    }
} 
