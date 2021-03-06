#ifndef POINT_H
#define POINT_H

// #define DEBUG_FILE

#define WIDTH	640
#define HEIGHT	480
#define NUM_PIXELS	(WIDTH*HEIGHT)

#define XVAL(idx)	(idx%WIDTH)
#define YVAL(idx)	(idx/WIDTH)

#define THRESHOLD	10	// threshold for point test
#define MIN_SIZE	3
#define MAX_SIZE	(30*30)
#define MIN_SKEW	-5
#define MAX_SKEW	5

#define COL_THRESHOLD	20	// threshold for being in the same column

class Point {
private:
	int min[2];
	int max[2];
	int size;
	int center[2];
public:
	Point();
	void add_line(int left, int right); // adds a line of pixels to POINT
	void add_point(int index);
	int* get_center(); // calculates center and returns pointer to center
	int test_point(int index); // x-failure: 0, y-falure: -1, new point and success = 1
	int test_shape(); // 
};

/** point finder
takes the working green array, finds center points

returns number of center points
*/
int point_finder(unsigned char* working_green, int (*center_points)[2], int length);

/* sorts array of order pairs and sorts them by column
 * @param center_points 		array of center points
 * @param num_points			number of center points
 * @param col_idx 				array of colom index points (output)
 * @param col_idx_size			size of col_idx array
 * @returns number of columns					
*/
int sort_by_col(int (*center_points)[2], int num_points, int* col_idx, int col_idx_size);

#endif //POINT_H