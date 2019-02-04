#include <iostream>
#include <math.h>

typedef struct{
	double real, imag;
} Complex;

Complex complex(double _real, double _imag){
	Complex temp;
	temp.real = _real;
	temp.imag = _imag;
	return temp;
}

#define data_pi 3.14159265

using namespace std;

  double kvalueX(int j, double nx, double dkx){
 	double kx; 	
 	double nyqx = nx/2 + 1;
 	
 	if(j <= nyqx)
 		kx = (j-1) * dkx;	 
	 else
	 	kx = (j-nx-1) * dkx;	 	
	
	return kx; 
 }
 
  double kvalueY(int i, double ny, double dky){
 	double ky; 	
 	double nyqy = ny/2 + 1;
	 	
	 if(i <= nyqy)
	 	ky = (i-1) * dky;	 
	 else
	 	ky = (i-ny-1) * dky; 
	
	return ky;
 }

void signal(double nx, double ny, double dx, double dy){
 	double nValue = 2 * nx * ny;
 	cout << nValue << endl;
 	
 	Complex cgrid1, cgrid2, cgrid3, cmplx;
 	
 	double grid[(int) (nx*ny)];
	double store1[(int) nValue];	
	double store2[(int) nValue];
	double store3[(int) nValue];
	//index(i,j,ncol) = (j-1)*ncol+i
	double nn[2] = { nx, ny };
 	
 	double kx, ky, k;
	double dkx = 2 * data_pi / (nx* dx);
	double dky = 2 * data_pi / (ny* dy);
	int ndim = 2;
 	
 	for(int i = 1; i <= nx; i++){ 	
 		for(int j = 1; j <= ny; j++){
 			//ij=index(i,j,ny)
 			//store1(2*ij-1)=grid(ij)
 			//store1(2*ij)=0
 			cout << " +" << j << " ";
		 }
		 	cout << " -" << i << endl;
	 }
	
	//call fourn
	
	for(int i = 1; i <= nValue; i++){ 	 
			store2[i] = store1[i];
			store3[i] = store1[i];		
		 	cout << " -" << i << endl;
	 }
	 
	 for(int i = 1; i <= nx; i++){ 	
 		for(int j = 1; j <= ny; j++){
 			//ij=index(i,j,ny)
 		 	//kvalue(i, j, nx, ny, dkx, dky, kx, ky);
 		 	double dkx = 2;
 		 	double dky = 2;
 		 	kx = kvalueX(j, nx, dkx);	
			ky = kvalueY(i, ny, dky);	 	
 			float k = sqrt(kx*2 + ky*2);
 			//cout << k << "@@@";
 			int ij=1;
 			cgrid1 = complex(store1[2*ij-1], store1[2*ij]);
 			cgrid2 = complex(store2[2*ij-1], store2[2*ij]);
 			cgrid3 = complex(store3[2*ij-1], store3[2*ij]);
 			//cout << cgrid1.real << "!11111111111";
 			cmplx = complex(0,kx);
 			cgrid1 = complex(cgrid1.real * cmplx.real, cgrid1.imag * cmplx.imag);
 			
 			cmplx = complex(0,ky);
 			cgrid2 = complex(cgrid2.real * cmplx.real, cgrid2.imag * cmplx.imag);
 			
 			cgrid3 = complex(cgrid3.real*k, cgrid3.imag*k);
 			
 			store1[2*ij-1] = cgrid1.real;
 			store1[2*ij] = cgrid1.imag;
 			
 			store2[2*ij-1] = cgrid2.real;
 			store2[2*ij] = cgrid2.imag;
 			
 			store3[2*ij-1] = cgrid3.real;
 			store3[2*ij] = cgrid3.imag; 	
 			
 			//cout << " +" << j << " ";
		 }
		 	//cout << " -" << i << endl;
	 }
	 
	 //call fourn
	 //call fourn
	 //call fourn
	
  	for(int i = 1; i <= nx; i++){ 	
 		for(int j = 1; j <= ny; j++){
 			//ij=index(i,j,ny)
 			int ij=ny;
 			float grid1 = store1[2*ij-1]/ (nx*ny);
 			float grid2 = store2[2*ij-1]/ (nx*ny);
 			float grid3 = store3[2*ij-1]/ (nx*ny);
 			grid[ij] = sqrt(grid1*2 + grid2*2 + grid3*2);
 			//store1(2*ij)=0
 			cout << "++" << grid[ij] << endl;
 			//cout << " +" << j << " ";
		 }
		 //	cout << " -" << i << endl;
	 }
 }
 
 
// void kvalue(int i, int j, double nx, double ny, double dkx, double dky){
// 	int kx, ky;
// 	double nyqx = nx/2 + 1;
// 	double nyqy = ny/2 + 1;
// 	
// 	if(j <= nyqx)
// 		kx = (j-1) * dkx;	 
//	 else
//	 	kx = (j-nx-1) * dkx;
//	 	
//	 if(i <= nyqy)
//	 	ky = (i-1) * dky;	 
//	 else
//	 	ky = (i-ny-1) * dky; 
// }
 
void fourn(int ndim){
	
	float wr, wi, wpr, wpi, wtemp, theta;
	float nn[ndim];
	int ntot = 1;
	
	for(int i = 1; i <= ndim; i++){ 	
 		ntot = ntot * nn[iidim];
 		
		 cout << " -" << i << endl;
	 }
	
}
 
 
 
 
 
 
 
 
