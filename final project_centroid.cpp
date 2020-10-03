//20131872 È²ÀçÇü_final project
#include<iostream>
#include<fstream>
using namespace std;

class ship {
private:
	int nn; // number of nodes
	int nt; // number of triangles
	double **xyz;  // for nodal coordinates
	int **tri; // for face connectivity
			   // have to compute using member function
	double surfArea;
	double surfArea_signed;
	double volume;
	double centroids_x;
	double centroids_y;
	double centroids_z;

public:  // function
	ship(); //constructor
	~ship();// destructor
	void compute_surfArea();
	void compute_surfArea_signed();
	void compute_volume();
	void compute_centroids();
};

int main()                                            //main function
{
	ship myship;
	myship.compute_surfArea();
	myship.compute_surfArea_signed();
	myship.compute_volume();
	myship.compute_centroids();
	return 0;
}

ship::ship() {
	ifstream fin;
	fin.open("tet.dat");                           // put "tet.dat" or "cube.dat" 
	fin >> nn;                                    //read in number of nodes
	xyz = new double*[nn];
	for (int i = 0; i < nn; i++)
		xyz[i] = new double[3];
	for (int i = 0; i < nn; i++)
		for (int j = 0; j < 3; j++)
			fin >> xyz[i][j];
	//read in catesian coordinates from .dat file
	fin >> nt;                                   //read in number of triangles
	tri = new int*[nt];
	for (int i = 0; i < nt; i++)
		tri[i] = new int[3];
	for (int i = 0; i < nt; i++)
		for (int j = 0; j < 3; j++)
			fin >> tri[i][j];
	fin.close();
	//read in connectivity information of triangles in constructor
	cout << "calculation start!" << endl << endl;
};
ship::~ship() {
	for (int i = 0; i < nn; i++)
		delete[] xyz[i];
	delete[]xyz;
	for (int i = 0; i < nt; i++)
		delete[] tri[i];
	delete[] tri;                                   //delete dynamic memory that i allocated in constructor
	cout << "second semister final program terminate" << endl << endl;
};

void ship::compute_surfArea() {
	double sum_area = 0.;
	for (int i = 0; i < nt; i++)
	{
		double area_i = 0.;		                

		int n1, n2, n3;
		n1 = tri[i][0];
		n2 = tri[i][1];
		n3 = tri[i][2];

		double x1, y1, z1;                          // 1st nodal coordinate
		double x2, y2, z2;                         // 2nd nodal coordinate
		double x3, y3, z3;                        // 3rd nodal coordinate

		x1 = xyz[n1][0]; y1 = xyz[n1][1]; z1 = xyz[n1][2];
		x2 = xyz[n2][0]; y2 = xyz[n2][1]; z2 = xyz[n2][2];
		x3 = xyz[n3][0]; y3 = xyz[n3][1]; z3 = xyz[n3][2];

		double r1x, r1y, r1z;
		double r2x, r2y, r2z;

		r1x = x2 - x1;
		r1y = y2 - y1;
		r1z = z2 - z1;

		r2x = x3 - x1;
		r2y = y3 - y1;
		r2z = z3 - z1;

		double sx, sy, sz;                           // surface normal vector

		sx = 0.5*(r1y*r2z - r1z*r2y);
		sy = 0.5*(r1z*r2x - r1x*r2z);             // equation that is multiplied by -1
		sz = 0.5*(r1x*r2y - r1y*r2x);
		// norm of surface normal vector

		area_i = sqrt(sx*sx + sy*sy + sz*sz);
		sum_area += area_i;
	}
	surfArea = sum_area;
	cout << "surface area is  " << surfArea << endl;
}

void ship::compute_surfArea_signed() {

	double sum_signed_area = 0.;
	for (int i = 0; i < nt; i++)
	{
		double signed_area_i = 0.;

		int n1, n2, n3;
		n1 = tri[i][0];
		n2 = tri[i][1];
		n3 = tri[i][2];

		double x1, y1, z1;                           // 1st nodal coordinate
		double x2, y2, z2;                          // 2nd nodal coordinate
		double x3, y3, z3;                         // 3rd nodal coordinate

		x1 = xyz[n1][0]; y1 = xyz[n1][1]; z1 = xyz[n1][2];
		x2 = xyz[n2][0]; y2 = xyz[n2][1]; z2 = xyz[n2][2];
		x3 = xyz[n3][0]; y3 = xyz[n3][1]; z3 = xyz[n3][2];

		double r1x, r1y, r1z;
		double r2x, r2y, r2z;

		r1x = x2 - x1;
		r1y = y2 - y1;
		r1z = z2 - z1;

		r2x = x3 - x1;
		r2y = y3 - y1;
		r2z = z3 - z1;

		double sx, sy, sz;                          // surface normal vector

		sx = 0.5*(r1y*r2z - r1z*r2y);
		sy = 0.5*(r1z*r2x - r1x*r2z);            // equation that is multiplied by -1
		sz = 0.5*(r1x*r2y - r1y*r2x);

		signed_area_i = sx + sy + sz;         // area of i th order triangle that is signed.

		sum_signed_area += signed_area_i;
		if (i == 0)
			cout << "signed surface area is ";
		if (i != nt - 1)
			cout << "(" << signed_area_i << ")" << " + ";
		else
			cout << "(" << signed_area_i << ")";
	}
	surfArea_signed = sum_signed_area;     // signed surface of area would be 0 which is sum of signed i th triangles.
	cout << " = " << surfArea_signed << endl;
}

void ship::compute_volume() {
	double sum_volume = 0.;
	for (int i = 0; i < nt; i++)
	{
		double area_i = 0.;

		int n1, n2, n3;
		n1 = tri[i][0];
		n2 = tri[i][1];
		n3 = tri[i][2];

		double x1, y1, z1;                          // 1st nodal coordinate
		double x2, y2, z2;                          // 2nd nodal coordinate
		double x3, y3, z3;                          // 3rd nodal coordinate

		x1 = xyz[n1][0]; y1 = xyz[n1][1]; z1 = xyz[n1][2];
		x2 = xyz[n2][0]; y2 = xyz[n2][1]; z2 = xyz[n2][2];
		x3 = xyz[n3][0]; y3 = xyz[n3][1]; z3 = xyz[n3][2];

		double r1x, r1y, r1z;
		double r2x, r2y, r2z;

		r1x = x2 - x1;
		r1y = y2 - y1;
		r1z = z2 - z1;

		r2x = x3 - x1;
		r2y = y3 - y1;
		r2z = z3 - z1;

		double sx, sy, sz;                            // surface normal vector

		sx = 0.5*(r1y*r2z - r1z*r2y);
		sy = 0.5*(r1z*r2x - r1x*r2z);               // equation that is multiplied by -1
		sz = 0.5*(r1x*r2y - r1y*r2x);

		area_i = sqrt(sx*sx + sy*sy + sz*sz);

		double unit_norm_x = sx / area_i;
		double unit_norm_y = sy / area_i;
		double unit_norm_z = sz / area_i;
		// ´ÜÀ§º¤ÅÍ (unit normal vector)
		// let's set F vector as  <x/3,y/3,z/3>
		double quadra_x;
		double quadra_y;
		double quadra_z;

		quadra_x = (x1 + x2 + x3) / 3;          // quadrature point of x
		quadra_y = (y1 + y2 + y3) / 3;         // quadrature point of y 
		quadra_z = (z1 + z2 + z3) / 3;         // quadrature point of z

		double dot_product =
			unit_norm_x*quadra_x / 3 + unit_norm_y*quadra_y / 3 + unit_norm_z*quadra_z / 3;
		// dot product of F vector and quadrature point
		double volume_i = dot_product * area_i;
		// i th order volume would be multiply of dot_product and i th area
		sum_volume += volume_i;

	}volume = sum_volume;                     // volume would be sum of  i th volume
	cout << "volume is " << volume << endl;
}

void ship::compute_centroids() {
	for (int i = 0; i < nt; i++)
	{
		int n1, n2, n3;
		n1 = tri[i][0];
		n2 = tri[i][1];
		n3 = tri[i][2];

		double x1, y1, z1;                          // 1st nodal coordinate
		double x2, y2, z2;                          // 2nd nodal coordinate
		double x3, y3, z3;                          // 3rd nodal coordinate

		x1 = xyz[n1][0]; y1 = xyz[n1][1]; z1 = xyz[n1][2];
		x2 = xyz[n2][0]; y2 = xyz[n2][1]; z2 = xyz[n2][2];
		x3 = xyz[n3][0]; y3 = xyz[n3][1]; z3 = xyz[n3][2];

		double r1x, r1y, r1z;
		double r2x, r2y, r2z;

		r1x = x2 - x1;
		r1y = y2 - y1;
		r1z = z2 - z1;

		r2x = x3 - x1;
		r2y = y3 - y1;
		r2z = z3 - z1;

		double sx, sy, sz;                          // surface normal vector

		sx = 0.5*(r1y*r2z - r1z*r2y);
		sy = 0.5*(r1z*r2x - r1x*r2z);            // equation multiplied by -1
		sz = 0.5*(r1x*r2y - r1y*r2x);
		// norm of surface normal vector

		double area_i = sqrt(sx*sx + sy*sy + sz*sz);

		double unit_norm_x = sx / area_i;
		double unit_norm_y = sy / area_i;
		double unit_norm_z = sz / area_i;
		// unit vector of ith order triangle
		double quadra_2order_px_1 = (x2 + x3) / 2;
		double quadra_2order_px_2 = (x1 + x3) / 2;
		double quadra_2order_px_3 = (x2 + x1) / 2;
		// quadrature points of x (there are total three points)
		double quadra_2order_py_1 = (y2 + y3) / 2;
		double quadra_2order_py_2 = (y1 + y3) / 2;
		double quadra_2order_py_3 = (y2 + y1) / 2;
		// quadrature points of y (there are total three points)
		double quadra_2order_pz_1 = (z2 + z3) / 2;
		double quadra_2order_pz_2 = (z1 + z3) / 2;
		double quadra_2order_pz_3 = (z2 + z1) / 2;
		// quadrature points of y (there are total three points)
		double quadra_square_x = 0.; double quadra_square_y = 0.; double quadra_square_z = 0.;

		quadra_square_x = 0.5*(quadra_2order_px_1*quadra_2order_px_1 + quadra_2order_px_2*quadra_2order_px_2 +
			quadra_2order_px_3*quadra_2order_px_3);
		//F=<0.5*x*x>, put three quadrature points of x and combine in advance
		quadra_square_y = 0.5*(quadra_2order_py_1*quadra_2order_py_1 + quadra_2order_py_2*quadra_2order_py_2 +
			quadra_2order_py_3*quadra_2order_py_3);
		//F=<0.5*y*y>, put three quadrature points of y and combine in advance
		quadra_square_z = 0.5*(quadra_2order_pz_1*quadra_2order_pz_1 + quadra_2order_pz_2*quadra_2order_pz_2 +
			quadra_2order_pz_3*quadra_2order_pz_3);
		//F=<0.5*z*z>, put three quadrature points of z and combine in advance

		double dot_product_x = (quadra_square_x*unit_norm_x*area_i) / 3;
		double dot_product_y = (quadra_square_y*unit_norm_y*area_i) / 3;
		double dot_product_z = (quadra_square_z*unit_norm_z*area_i) / 3;
		// devide by 3 cause there are three quadrature points

		centroids_x += dot_product_x;
		centroids_y += dot_product_y;
		centroids_z += dot_product_z;
		// cetroids of x,y,z would be sum of i th order of them.
	}
	cout << "centroids of solid is " << "(" << centroids_x / volume << ", " << centroids_y / volume << ", " << centroids_z / volume << ")" << endl;
}

