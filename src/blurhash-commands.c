// =============================================================================
// Rebol/BlurHash extension commands
// =============================================================================

#include "blurhash-rebol-extension.h"
#include "encode.h"
#include "decode.h"

#define COMMAND        int
#define ARG_Double(n)  RXA_DEC64(frm,n)


COMMAND cmd_encode(RXIFRM *frm, void *ctx) {
	RXIARG img = RXA_ARG(frm, 1);
	REBCNT len;

	const char *hash = blurHashForPixels(3, 3, img.width, img.height, ((REBSER*)img.series)->data, 4*img.width);
	if (!hash) return RXR_NONE;

	len = strlen(hash);

	REBSER* ser = RL_MAKE_STRING(len, FALSE);
	memcpy(ser->data, hash, len);

	SERIES_TAIL(ser) = len;
	RXA_SERIES(frm, 1) = ser;
	RXA_TYPE(frm, 1) = RXT_STRING;
	RXA_INDEX(frm, 1) = 0;
	return RXR_VALUE;
}

COMMAND cmd_decode(RXIFRM *frm, void *ctx) {
	REBSER *hash = RXA_SERIES(frm,1);
	REBSER *reb_img;
	REBXYF size;
	REBINT width, height, res;
	REBINT punch = 1;

	if (RXA_TYPE(frm, 2) == RXT_PAIR) {
		size = RXA_PAIR(frm, 2);
		width  = ROUND_TO_INT(size.x);
		height = ROUND_TO_INT(size.y);
		reb_img = (REBSER *)RL_MAKE_IMAGE(width, height);
	} else {
		width = RXA_IMAGE_WIDTH(frm, 2);
		height = RXA_IMAGE_HEIGHT(frm, 2);
		reb_img = (REBSER *)RXA_ARG(frm,2).image;
	}

	if (RXA_TYPE(frm, 4) == RXT_INTEGER) {
		punch = RXA_INT32(frm, 4);
	}

	res = decodeToArray(SERIES_DATA(hash), width, height, punch, 4, reb_img->data);
	if (res != 0) return RXR_NONE;

	RXA_TYPE(frm, 1) = RXT_IMAGE;
	RXA_IMAGE_WIDTH(frm, 1) = width;
	RXA_IMAGE_HEIGHT(frm, 1) = height;
	RXA_IMAGE(frm, 1) = reb_img;
	return RXR_VALUE;
}
