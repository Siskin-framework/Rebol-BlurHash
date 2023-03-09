
//
// auto-generated file, do not modify!
//

#include "rebol-extension.h"

#define MIN_REBOL_VER 3
#define MIN_REBOL_REV 5
#define MIN_REBOL_UPD 4
#define VERSION(a, b, c) (a << 16) + (b << 8) + c
#define MIN_REBOL_VERSION VERSION(MIN_REBOL_VER, MIN_REBOL_REV, MIN_REBOL_UPD)

enum ext_commands {
	CMD_BLURHASH_ENCODE,
	CMD_BLURHASH_DECODE,
};


int cmd_encode(RXIFRM *frm, void *ctx);
int cmd_decode(RXIFRM *frm, void *ctx);

typedef int (*MyCommandPointer)(RXIFRM *frm, void *ctx);

#define BLURHASH_EXT_INIT_CODE \
	"REBOL [Title: {Rebol BlurHash Extension} Type: module]\n"\
	"encode: command [\"Encode an image using BlurHash algorithm\" img [image!] \"Source image\"]\n"\
	"decode: command [\"Decode BlurHash string to an image\" text [any-string! binary!] \"Textual image representation\" image [image! pair!] \"Output image or size of the new image\" /contrast punch [integer!] \"The factor to improve the contrast, default = 1\"]\n"

#ifdef  USE_TRACES
#include <stdio.h>
#define debug_print(fmt, ...) do { printf(fmt, __VA_ARGS__); } while (0)
#define trace(str) puts(str)
#else
#define debug_print(fmt, ...)
#define trace(str) 
#endif

