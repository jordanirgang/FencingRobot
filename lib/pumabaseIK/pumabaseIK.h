#pragma once
#include<cmath>

namespace generic{
	struct cartesian{
		float x=0;
		float y=0;
		float z=0;
	};
	struct jointSpace{
		float theta1SlnA=0;
		float theta1SlnB=0;
		
		bool isRight=true;//A is Right, top config unrelated
		float theta2SlnA=0;
		float theta2SlnB=0;
		float theta3SlnA=0;
		float theta3SlnB=0;
	};

	struct linkLengths{
		float a1=1;
		float a2=1;
		float a3=1;
		float offsetYAxisA1A2 = 0;
	};

	jointSpace ikPUMABase(cartesian *coordIN, linkLengths *linksIN, jointSpace *jointsOUT){

		jointsOUT->theta1SlnA = atan2(coordIN->y,coordIN->x); 
	//	phi_solve_R = math.pi+ sp.atan2(y,x) + sp.atan2(-sp.sqrt(x**2 + y**2-offset**2),offset)
	
		jointsOUT->theta1SlnB=  M_PI + atan2(coordIn->y,coordIN->x)+ atan2(-sqrt(
										pow(coordIN->y,2)+
										pow(coordIN->x,2)+),linkLengths->offsetYAxisA1A2);

	//	D = (z**2 + x**2 +y**2 - offset **2 -length_b**2 - length_c**2)/(2*length_b*length_c)
		float D = (pow(coordIN->z,2)+pow(coordIN->y,2) + pow(coordIN->x,2) - pow(linkLengths->a2,2) - pow(linkLengths->a3,2))
									/
			(2*linkLengths->a2*linkLengths->a3);

	//	theta_2_solve_L = sp.atan2(-sp.sqrt(1-D**2),D)
		jointsOUT->theta3SlnA = atan2(-sqrt(1-pow(D,2)),D); 
		jointsOUT->theta3SlnB = atan2(sqrt(1-pow(D,2)),D);

	//	theta_1_solve = sp.atan2(z,sp.sqrt(x**2+y**2-offset**2))-sp.atan2(length_c*sp.sin(theta_2),length_b+length_c*sp.cos(theta_2))
		jointsOUT->theta2SlnA = atan2()
		




	}
}
