#include<stdio.h>
int limit[]={8,4,2,1};
int count( int S[], int m, int n )
{
    int i, j, x, y,k;

    // We need n+1 rows as the table is consturcted in bottom up manner using
    // the base case 0 value case (n = 0)
    int table[n+1][m];

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table enteries in bottom up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x=0;
            // Count of solutions including S[j]
            for(k=1;k<=limit[j];k++){
                x += (i-k*S[j] >= 0)? table[i - k*S[j]][j]: 0;
            }
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = (x + y)%100000007;
        }
    }
    return table[n][m-1];
}

// Driver program to test above function
int main()
{
    int arr[] = {1, 2, 3, 4};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 20;
    printf(" %d ", count(arr, m, n));
    return 0;
}
