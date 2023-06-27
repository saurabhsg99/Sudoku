#include <map>
#include <iostream>
#include <vector>
using namespace std;
void board(vector<vector<int>> &mat)
{

    printf("\t");
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                printf("\x1b[30m"
                       " %2d "
                       "\x1b[0m"
                       "\x1b[34m",
                       i);
                cout << "  ";
                continue;
            }
            if (i == 0)
            {
                printf("\x1b[30m"
                       "%d "
                       "\x1b[0m"
                       "\x1b[34m",
                       j);
                if (j == 3 || j == 6)
                    printf("   ");
                if (j == 9)
                    cout << endl;
                continue;
            }
            if (mat[i - 1][j - 1])
                printf("\x1b[33m"
                       "%d "
                       "\x1b[34m",
                       mat[i - 1][j - 1]);
            else
                cout << mat[i - 1][j - 1] << " ";
            if (j == 3 || j == 6)
                printf(" | ");
        }
        if (i == 3 || i == 6)
            printf("\n\t     ------------------------");
        printf("\n\t");
    }
    printf("\x1b[0m");
}

bool Iscompleted(vector<vector<int>> &mat)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (mat[i][j] == 0)
                return false;
    return true;
}

bool Isvalid(vector<vector<int>> &mat)
{

    vector<vector<bool>> square(3, vector<bool>(10, false));
    for (int i = 0; i < 9; i++)
    {
        vector<bool> col(10, false);
        vector<bool> row(10, false);
        for (int j = 0; j < 9; j++)
        {
            if (col[mat[i][j]] || row[mat[j][i]] || square[j / 3][mat[i][j]])
            { // duplicate data
                return false;
            }
            else
            {
                col[mat[i][j]] = true;
                row[mat[j][i]] = true;
                square[j / 3][mat[i][j]] = true;
            }
        }
        for (int j = 1; j < 10; j++)
        {

            if (!col[j] || !row[j])
            { // any missing
                return false;
            }
        }
        if (i == 2 || i == 5)
        {
            for (int p = 0; p < 3; p++)
            {
                for (int j = 1; j < 10; j++)
                {
                    if (!square[p][j])
                    { // any missing
                        return false;
                    }
                    else
                    {
                        square[p][j] = false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> mat1 = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                {0, 9, 8, 0, 0, 0, 0, 6, 0},

                                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                {7, 0, 0, 0, 2, 0, 0, 0, 6},

                                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    vector<vector<int>> mat2 = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                                {5, 2, 9, 1, 3, 4, 7, 6, 8},
                                {4, 8, 7, 6, 2, 9, 5, 3, 1},
                                {2, 6, 3, 4, 1, 5, 9, 8, 7},
                                {9, 7, 4, 8, 6, 3, 1, 2, 5},
                                {8, 5, 1, 7, 9, 2, 6, 4, 3},
                                {1, 3, 8, 9, 4, 7, 2, 5, 6},
                                {6, 9, 2, 3, 5, 1, 8, 7, 4},
                                {7, 4, 5, 2, 8, 6, 3, 1, 9}};
    vector<vector<int>> mat = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                               {6, 7, 2, 1, 9, 5, 3, 4, 8},
                               {1, 9, 8, 3, 4, 2, 5, 6, 7},
                               {8, 5, 9, 7, 6, 1, 4, 2, 3},
                               {4, 2, 6, 8, 5, 3, 7, 9, 1},
                               {7, 1, 3, 9, 2, 4, 8, 5, 6},
                               {9, 6, 1, 5, 3, 7, 2, 8, 4},
                               {2, 8, 7, 4, 1, 9, 6, 3, 5},
                               {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    // board(mat);
    //  int r=-1, c, value;
    //  while (!Iscompleted(mat))
    //  {
    //      board(mat);
    //      cout << "\nEnter the position (r,c) : ";
    //      cin >> r >> c;
    //      // if(r<1 || r>9)
    //      // //reenter

    //     cout << "Enter the value : ";
    //     cin >> value;
    //     mat[r][c] = value;
    // }
    if (Isvalid(mat))
        cout << "you have done it ";
    else
        cout << "gadhe ho ";

    return 0;
}