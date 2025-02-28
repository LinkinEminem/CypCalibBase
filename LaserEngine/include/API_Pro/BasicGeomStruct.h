#ifndef __PT3D__
#define __PT3D__
typedef struct Pt3D{
	float	x;
	float	y;
	float	z;
    float	confidence;
} Pt3D;
#endif

#ifndef __GRIDCOORD2D__
#define __GRIDCOORD2D__
typedef struct GridCoord2D{
	int		x;
	int		y;
} GridCoord2D;
#endif

#ifndef __GRIDPTS__
#define __GRIDPTS__
typedef struct GridPts{
	unsigned int	size;
    Pt3D*			pts;				//Array of points in 3D space (x,y,z)
    GridCoord2D*	coords;				//Array of position of the points in the 2D grid (x,y)
    Pt3D			objtoscannervec;	//Object to Scanner Direction
} GridPts;

#ifndef __SCANLINE__
#define __SCANLINE__
typedef struct ScanLine{
    unsigned int		size;
    Pt3D*				pts;				//Array of points in 3D space (x,y,z)
    Pt3D				scannertoobjvec;	//Scanner to Object Direction
} ScanLine;
#endif

#endif
