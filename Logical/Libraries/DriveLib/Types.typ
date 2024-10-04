
TYPE
	DoorStates : 
		(
		ST_INIT,
		ST_UNKNOWN,
		ST_OPEN,
		ST_CLOSE,
		ST_ACC_POS,
		ST_ACC_NEG,
		ST_POS,
		ST_NEG,
		ST_DEC_POS,
		ST_DEC_NEG
		);
	EtadCodes : 
		(
		DISABLED := 64,
		SWITCHED_ON := 35,
		READY := 33
		);
	CmddCodes : 
		(
		CMD_SHUTDOWN := 6,
		CMD_SWITCH_ON := 7,
		CMD_ENABLE := 15
		);
END_TYPE
