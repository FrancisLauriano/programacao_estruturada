#include <stdio.h>

double areaTriangulo(double b, double h);
double areaRetangulo(double b, double h);

int main(){
    double base, altura, area_triangulo, area_retangulo;

    printf("Base:\n");
    scanf("%lf", &base);

    printf("Altura:\n");
    scanf("%lf", &altura);

    area_triangulo = areaTriangulo(base, altura);
    area_retangulo = areaRetangulo(base, altura);

    printf("A area do triangulo é: %.2lf\n", area_triangulo);
    printf("A area do retangulo é: %.2lf\n", area_retangulo);

    return 0;
}

double areaTriangulo(double b, double h){
    return (b * h) / 2;
}

double areaRetangulo(double b, double h){
    return b *h;
}