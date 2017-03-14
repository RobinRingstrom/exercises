#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int no_of_hits = 0; // no of matches found
int max_steps = 14;
clock_t start;
clock_t stop;
double elapsed_time = 0.0;

// expands at <depth> levels down
void expand(float x, float y, int depth);

int main()
{
    int depth = 0;
    float pos_x = 0.0;
    float pos_y = 0.0;

    for(depth = 1; depth <= max_steps; depth++)
    {
        start = clock();
        expand(pos_x, pos_y, depth);
        stop = clock();
        elapsed_time = (double)(stop-start) / CLOCKS_PER_SEC;
        printf("No of steps: %d     Hits: %d    Time: %0.1lf seconds (next calculated to %0.1lf)\n",depth, no_of_hits, elapsed_time, elapsed_time * 6);
        no_of_hits = 0;
    }

    return 0;
}


void expand(float x, float y, int depth)
{
    if(depth < 1) // target depth reached
    {
        if(x == 0.0 && y == 0.0)    // found a match
        {
            no_of_hits++;
        }
    }
    else
    {
        expand(x -1 , y, depth -1);  // W
        expand(x + 1, y, depth -1);  // E
        expand(x - 0.5, y + 1, depth -1);  // NW
        expand(x + 0.5, y + 1, depth -1);  // NE
        expand(x - 0.5, y - 1, depth -1);  // SW
        expand(x + 0.5, y - 1, depth -1);  // SE
    }
}
