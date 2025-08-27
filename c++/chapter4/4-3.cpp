#include<cstdio>
#include<iostream>
using namespace std;

const float PI=3.1415926;
const float FENCE_PRICE=35;
const float CONCRETE_PRICE=20;

class Circle
{
    public:
        Circle(): r(0) {}

        Circle(float _r): r(_r) {}

        float circumference();
        float area();

    private:
        float r;
};

float Circle::circumference()
{
    return 2*PI*r;
}

float Circle::area()
{
    return r*r*PI;
}

int main()
{
    float r;
    printf("Enter the radius of the pool:");
    scanf("%f",&r);

    Circle pool(r);
    Circle poolRim(r+3);

    float FenceCost=poolRim.circumference()*FENCE_PRICE;
    printf("Fencing cost is:$ %f\n",FenceCost);

    float ConcreteCost=(poolRim.area()-pool.area())*CONCRETE_PRICE;
    printf("Concrete cost is:$ %f\n",ConcreteCost);
    return 0;
}