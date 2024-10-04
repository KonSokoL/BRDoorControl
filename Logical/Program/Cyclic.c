
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	DoorStateMachine(&doorSM);
	driveSM.speed = doorSM.speed;
	ledSM.state = doorSM.state;
	DriveStateMachine(&driveSM);
	LedStateMachine(&ledSM);
	ledSM.timer += 1;
}
