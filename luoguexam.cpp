#include<iostream>
#include<string.h>
#include <iomanip>
#include <cmath>;
#define pi 3.1415926

using namespace std;

void Q2RTransform(double q2r[]);
void R2QTransform(double r2q[]);
void Q2ATransform(double q2a[]);
void A2QTransform(double a2q[]);
void TTransform(double t[]);

int main(){
    char opt[5];
    double q2r[4];
    double r2q[9];
    double q2a[4];
    double a2q[3];
    double t[10];

    cout << "请输入" << endl;
    cin >> opt;
    if (!strcmp(opt, "Q2R")){
        int i;
        for (i=0;i<4;i++) {
            cin >> q2r[i];
        }
        Q2RTransform(q2r);
    }

    if (!strcmp(opt, "R2Q")){
        int i;
        for (i=0;i<9;i++) {
            cin >> r2q[i];
        }
        R2QTransform(r2q);
    }

    if (!strcmp(opt, "Q2A")){
        int i;
        for (i=0;i<4;i++){
            cin >> q2a[i];
        }
        Q2ATransform(q2a);
    }

    if (!strcmp(opt, "A2Q")){
        int i;
        for (i=0;i<3;i++){
            cin >> a2q[i];
        }
        A2QTransform(a2q);
    }

    if (!strcmp(opt, "T")){
        int i;
        for (i=0;i<10;i++){
            cin >> t[i];
        }
        TTransform(t);
    }

}

void Q2RTransform(double q2r[]){
    double w, x, y, z;
    int i, j;
    double R[3][3];
    w = q2r[0];
    x = q2r[1];
    y = q2r[2];
    z = q2r[3];
    R[0][0] = 1 - 2*y*y - 2*z*z;
    R[0][1] = 2*(x*y - w*z);
    R[0][2] = 2*(x*z + w*y);
    R[1][0] = 2*(x*y + w*z);
    R[1][1] = 1 - 2*x*x - 2*z*z;
    R[1][2] = 2*(y*z - w*x);
    R[2][0] = 2*(x*z - w*y);
    R[2][1] = 2*(y*z + w*x);
    R[2][2] = 1 - 2*x*x - 2*y*y;
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<setiosflags(ios::fixed)<<setprecision(2);
            cout << R[i][j] << " ";
        }
    }
}

void R2QTransform(double r2q[]){
    double w, x, y, z;
    double r11, r12, r13, r21, r22, r23, r31, r32, r33;

    r11 = r2q[0];
    r12 = r2q[1];
    r13 = r2q[2];
    r21 = r2q[3];
    r22 = r2q[4];
    r23 = r2q[5];
    r31 = r2q[6];
    r32 = r2q[7];
    r33 = r2q[8];

    w = 0.5 * sqrt(1+r11+r22+r33);
    x = (r32 - r23)/(4 * w);
    y = (r13 - r31)/(4 * w);
    z = (r21 - r12)/(4 * w);

    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout << w << " " << x << " " << y << " " << z << endl;
}

void Q2ATransform(double q2a[]){
    double q0, q1, q2, q3;
    double a, b, c;

    q0 = q2a[0];
    q1 = q2a[1];
    q2 = q2a[2];
    q3 = q2a[3];

    a = atan2(2*(q0*q1 + q2*q3), 1 - 2*(q1*q1+q2*q2)) * (180/pi);
    b = asin(2*(q0*q2 - q3*q1)) * (180/pi);
    c = atan2(2*(q0*q3 +q1*q2), 1 - 2*(q2*q2+q3*q3)) * (180/pi);

    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout << a << " " << b << " " << c << endl;
}

void A2QTransform(double a2q[]){
    double w, x, y, z;
    double a, b, c;
    a = a2q[0] * (pi/180);
    b = a2q[1] * (pi/180);
    c = a2q[2] * (pi/180);

    w = cos(a/2) * cos(b/2) * cos(c/2) + sin(a/2) * sin(b/2) * sin(c/2);
    x = sin(a/2) * cos(b/2) * cos(c/2) - cos(a/2) * sin(b/2) * sin(c/2);
    y = cos(a/2) * sin(b/2) * cos(c/2) + sin(a/2) * cos(b/2) * sin(c/2);
    z = cos(a/2) * cos(b/2) * sin(c/2) - sin(a/2) * sin(b/2) * cos(c/2);

    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout << w << " " << y << " " << z << " " << x << endl;
}

void TTransform(double t[]){

}