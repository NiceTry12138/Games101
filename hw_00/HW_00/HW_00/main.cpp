#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <corecrt_math_defines.h>

//using Eigen::MatrixXd;
using namespace Eigen;

using namespace std;

Eigen::Vector3f RotateAngleByCenterPoint(Eigen::Vector3f Self, const float Angle, const Eigen::Vector3f& CenterPoint, float MoveX, float MoveY) {
	Eigen::Vector3f TempPoint = Self - CenterPoint;
	float A = Angle / 180.f * M_PI;
	Eigen::Matrix3f RotateMatrix;
	RotateMatrix << cos(A), -sin(A), MoveX,
		sin(A), cos(A), MoveY,
		0, 0, 1;
	Eigen::Vector3f Result = RotateMatrix * TempPoint;

	return Result + CenterPoint;
}

int main()
{
	Eigen::Vector3f CenterPoint(0, 0, 0);
	Eigen::Vector3f Self;
	Self << 2, 1, 1;
	Eigen::Vector3f Result = RotateAngleByCenterPoint(Self, 45, CenterPoint, 1, 2);
	std::cout << Result << std::endl;
	return 0;
}