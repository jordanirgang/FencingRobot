#pragma once
#include <Arduino.h>
namespace generic{
	struct cartesian{
		float x;
		float y;
		float z;
	};
	
	struct jointSpace{
		float theta1SlnA;
		float theta1SlnB;
		
		bool isRight=true;//A is Right, top config unrelated
		float theta2SlnA;
		float theta2SlnB;
		float theta3SlnA;
		float theta3SlnB;
	};

	struct linkLengths{
		float a1;
		float a2;
		float a3;
		float offsetYAxisA1A2;
	};

	void ikPUMABase(cartesian *coordIN, linkLengths *linksIN, jointSpace *jointsOUT){

		jointsOUT->theta1SlnA = atan2(coordIN->y,coordIN->x); 
	//	phi_solve_R = math.pi+ sp.atan2(y,x) + sp.atan2(-sp.sqrt(x**2 + y**2-offset**2),offset)
	
		jointsOUT->theta1SlnB=  M_PI + atan2(coordIN->y,coordIN->x)+ atan2(-sqrt(
										pow(coordIN->y,2)+
										pow(coordIN->x,2)+linksIN->offsetYAxisA1A2),linksIN->offsetYAxisA1A2);

	//	D = (z**2 + x**2 +y**2 - offset **2 -length_b**2 - length_c**2)/(2*length_b*length_c)
		float D = (pow(coordIN->z,2)+pow(coordIN->y,2) + pow(coordIN->x,2) - pow(linksIN->a2,2) - pow(linksIN->a3,2))
									/
			(2*linksIN->a2*linksIN->a3);

	//	theta_2_solve_L = sp.atan2(-sp.sqrt(1-D**2),D)
		jointsOUT->theta3SlnA = atan2(-sqrt(1-pow(D,2)),D); 
		jointsOUT->theta3SlnB = atan2(sqrt(1-pow(D,2)),D);

	//	theta_1_solve = sp.atan2(z,sp.sqrt(x**2+y**2-offset**2))-sp.atan2(length_c*sp.sin(theta_2),length_b+length_c*sp.cos(theta_2))
		jointsOUT->theta2SlnA = atan2(coordIN->z,sqrt(pow(coordIN->x,2)+pow(coordIN->y,2)-pow(linksIN->offsetYAxisA1A2,2))
										- atan2(linksIN->a3*sin(jointsOUT->theta3SlnA),linksIN->a2+linksIN->a3*cos(jointsOUT->theta3SlnA)));
		jointsOUT->theta2SlnA = atan2(coordIN->z,sqrt(pow(coordIN->x,2)+pow(coordIN->y,2)-pow(linksIN->offsetYAxisA1A2,2))
		- atan2(linksIN->a3*sin(jointsOUT->theta3SlnB),linksIN->a2+linksIN->a3*cos(jointsOUT->theta3SlnB)));
		
	}
}
