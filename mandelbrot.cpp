#include <complex>
#include <fstream>
#include <iostream>

#define WIDTH 1600
#define HEIGHT 1200

using namespace std;

int mandelbrot(double real, double imag) {
  int limit = 100;
  double zReal = real;
  double zImag = imag;

  for (int i = 0; i < limit; ++i) {
    double r2 = zReal * zReal;
    double i2 = zImag * zImag;

    if (r2 + i2 > 4.0)
      return i;

    zImag = 2.0 * zReal * zImag + imag;
    zReal = r2 - i2 + real;
  }
  return limit;
}

int value(int _x, int _y) {

  double x_start = -2;
  double x_fin = 1;
  double y_start = -1;
  double y_fin = 1;

  double dx = (x_fin - x_start) / (WIDTH - 1);
  double dy = (y_fin - y_start) / (HEIGHT - 1);

  double x = x_start + _x * dx; // current real value
  double y = y_fin - _y * dy;   // current imaginary value
  return mandelbrot(x, y);
}

void write_color(ofstream *my_Image, int r, int g, int b) {
  (*my_Image) << r << ' ' << g << ' ' << b << "\n";
}

int main() {

  ofstream my_Image("mandelbrot.ppm");
  if (my_Image.is_open()) {
    my_Image << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        int val = value(x, y);
        if (val > 100) {
          write_color(&my_Image, 0, 0, 0);
        } else if (val > 90) {
          write_color(&my_Image, 255, 0, 0);
        } else if (val > 70) {
          write_color(&my_Image, 255, 102, 102);
        } else if (val > 50) {
          write_color(&my_Image, 255, 153, 51);
        } else if (val > 30) {
          write_color(&my_Image, 255, 255, 51);
        } else if (val > 20) {
          write_color(&my_Image, 255, 255, 51);
        } else if (val > 10) {
          write_color(&my_Image, 102, 204, 0);
        } else if (val > 5) {
          write_color(&my_Image, 102, 255, 255);
        } else if (val > 4) {
          write_color(&my_Image, 0, 253, 253);
        } else if (val > 3) {
          write_color(&my_Image, 102, 178, 255);
        } else if (val > 2) {
          write_color(&my_Image, 0, 102, 204);
        } else {
          write_color(&my_Image, 255, 102, 255);
        }
      }
    }
    my_Image.close();
  } else
    cout << "Could not open the file";

  return 0;
}
