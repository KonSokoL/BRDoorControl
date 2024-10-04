
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	ledSM.timer = 0;
	driveSM.speed = 0;
	driveSM.enable = 1;
	doorSM.state = ST_INIT;
}
