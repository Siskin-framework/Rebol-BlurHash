// =============================================================================
// Rebol/BlurHash extension
// =============================================================================


#include "blurhash-rebol-extension.h"

RL_LIB *RL; // Link back to reb-lib from embedded extensions

//==== Globals ===============================================================//
extern MyCommandPointer Command[];
//============================================================================//

static const char* init_block = BLURHASH_EXT_INIT_CODE;

RXIEXT const char *RX_Init(int opts, RL_LIB *lib) {
	RL = lib;
	REBYTE ver[8];
	RL_VERSION(ver);
	debug_print(
		"RXinit blurhash-extension; Rebol v%i.%i.%i\n",
		ver[1], ver[2], ver[3]);

	if (MIN_REBOL_VERSION > VERSION(ver[1], ver[2], ver[3])) {
		debug_print(
			"Needs at least Rebol v%i.%i.%i!\n",
		     MIN_REBOL_VER, MIN_REBOL_REV, MIN_REBOL_UPD);
		return 0;
	}
	if (!CHECK_STRUCT_ALIGN) {
		trace("CHECK_STRUCT_ALIGN failed!");
		return 0;
	}
	return init_block;
}

RXIEXT int RX_Call(int cmd, RXIFRM *frm, void *ctx) {
	return Command[cmd](frm, ctx);
}
