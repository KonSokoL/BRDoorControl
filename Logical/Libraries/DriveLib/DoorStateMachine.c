
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DoorStateMachine(struct DoorStateMachine* inst)
{
	/*TODO: Add your code here*/
	switch (inst->state){
		case ST_INIT:
			inst->speed = 0;
			inst->state = ST_UNKNOWN;
			break;
		case ST_UNKNOWN:
			inst->speed = -100;
			if (!inst->sw1 && inst->direction == 0)
			{
				inst->state = ST_OPEN;
			}
			else if (inst->sw4 && inst->direction == 1)
			{
				inst->state = ST_CLOSE;
			}
			break;
		case ST_OPEN:
			inst->speed = 0;
			if (inst->direction == 1)
			{
				inst->state = ST_ACC_POS;
			}
			break;
		case ST_CLOSE:
			inst->speed = 0;
			if (inst->direction == 0)
			{
				inst->state = ST_ACC_NEG;
			}
			break;
		case ST_ACC_POS:
			inst->speed = 100;
			if (inst->sw2)
			{
				inst->state = ST_POS;
			}
			else if (inst->direction == 0)
			{
				inst->state = ST_DEC_NEG;
			}
			break;
		case ST_ACC_NEG:
			inst->speed = -100;
			if (!inst->sw3)
			{
				inst->state = ST_NEG;
			}
			else if (inst->direction == 1)
			{
				inst->state = ST_DEC_POS;
			}
			break;
		case ST_POS:
			inst->speed = 890;
			if (inst->sw3)
			{
				inst->state = ST_DEC_POS;
			}
			else if (inst->direction == 0)
			{
				inst->state = ST_NEG;
			}
			break;
		case ST_NEG:
			inst->speed = -890;
			if (!inst->sw2)
			{
				inst->state = ST_DEC_NEG;
			}
			else if (inst->direction == 1)
			{
				inst->state = ST_POS;
			}
			break;
		case ST_DEC_POS:
			inst->speed = 100;
			if (inst->sw4)
			{
				inst->state = ST_CLOSE;
			}
			break;
		case ST_DEC_NEG:
			inst->speed = -100;
			if (!inst->sw1)
			{
				inst->state = ST_OPEN;
			}
			break;
	}
}
