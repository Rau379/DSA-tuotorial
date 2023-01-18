// sample code
// it gives the shortest distance between the two nodes by calcultaing the all possible distance through each node

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    // now calculating gthe distance through each possible path
    // dis[i][j]= dis[i][k]+dis[k][j];
    for (int k = 0; k < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    // checking the negative cycle
    for (int i = 0; i < n; i++)
    {

        if (matrix[i][i] < 0)
        {
            // negative cycle detection
        }
    }
}
