/**
 * An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate 
 * of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner.
 * Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel 
 * to the Y-axis. Two rectangles overlap if the area of their intersection is positive. To be clear, 
 * two rectangles that only touch at the corner or edges do not overlap.Given two axis-aligned rectangles 
 * rec1 and rec2, return true if they overlap, otherwise return false.
 * Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3] Output: true
 * Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1] Output: false
 * Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3] Output: false
 * */

#include <stdio.h>
#define MAX(a, b) \
    ((a) < (b) ? (b) : (a))
#define MIN(a, b) \
    ((a) > (b) ? (b) : (a))

int findDist(int r1LowerP, int r1UpperP, int r2LowerP, int r2UpperP)
{
    return (MIN(r1UpperP, r2UpperP) - MAX(r1LowerP, r2LowerP));
}

int findOverlapArea(int rect1[], int rect2[])
{
    int xDist = findDist(rect1[0], rect1[2], rect2[0], rect2[2]);
    int yDist = findDist(rect1[1], rect1[3], rect2[1], rect2[3]);
    if (xDist < 0 || yDist < 0)
    {
        return 0;
    }

    return xDist * yDist;
}

int main()
{
    int rect1[] = {0, 0, 1, 1};
    int rect2[] = {2, 2, 3, 3};

    int area = findOverlapArea(rect1, rect2);
    if (area > 0)
    {
        printf("Rectangle overlap with area = %d\n", area);
    }
    else
    {
        printf("Rectangles do not overlap\n");
    }
    return 0;
}