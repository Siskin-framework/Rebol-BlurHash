REBOL [
	title:  "Rebol/BlurHash module builder"
	type:    module
	date:    8-Mar-2023
	home:    https://github.com/Oldes/Rebol-BlurHash
	version: 1.0.0
	author: @Oldes
]

;- all extension command specifications ----------------------------------------
commands: [
	encode: [
		"Encode an image using BlurHash algorithm"
		img [image!] "Source image"
	]
	decode: [
		"Decode BlurHash string to an image"
		text  [any-string! binary!] "Textual image representation"
		image [image! pair!]        "Output image or size of the new image"
		/contrast
		punch [integer!] "The factor to improve the contrast, default = 1"
	]
]

;-------------------------------------- ----------------------------------------
reb-code: {REBOL [Title: {Rebol BlurHash Extension} Type: module]}
enu-commands:  "" ;; command name enumerations
cmd-declares:  "" ;; command function declarations
cmd-dispatch:  "" ;; command functionm dispatcher

;- generate C and Rebol code from the command specifications -------------------
foreach [name spec] commands [
	append reb-code ajoin [lf name ": command "]
	new-line/all spec false
	append/only reb-code mold spec

	name: form name
	replace/all name #"-" #"_"
	
	append enu-commands ajoin ["^/^-CMD_BLURHASH_" uppercase copy name #","]

	append cmd-declares ajoin ["^/int cmd_" name "(RXIFRM *frm, void *ctx);"]
	append cmd-dispatch ajoin ["^-cmd_" name ",^/"]
]

;- additional Rebol initialization code ----------------------------------------
append reb-code {
print "hello blur"
}

;print reb-code

;- convert Rebol code to C-string ----------------------------------------------
init-code: copy ""
foreach line split reb-code lf [
	replace/all line #"^"" {\"}
	append init-code ajoin [{\^/^-"} line {\n"}] 
]

;-- C file templates -----------------------------------------------------------
header: {
//
// auto-generated file, do not modify!
//

#include "rebol-extension.h"

#define MIN_REBOL_VER 3
#define MIN_REBOL_REV 5
#define MIN_REBOL_UPD 4
#define VERSION(a, b, c) (a << 16) + (b << 8) + c
#define MIN_REBOL_VERSION VERSION(MIN_REBOL_VER, MIN_REBOL_REV, MIN_REBOL_UPD)

enum ext_commands {$enu-commands
};

$cmd-declares

typedef int (*MyCommandPointer)(RXIFRM *frm, void *ctx);

#define BLURHASH_EXT_INIT_CODE $init-code

#ifdef  USE_TRACES
#include <stdio.h>
#define debug_print(fmt, ...) do { printf(fmt, __VA_ARGS__); } while (0)
#define trace(str) puts(str)
#else
#define debug_print(fmt, ...)
#define trace(str) 
#endif

}
;;------------------------------------------------------------------------------
ctable: {
//
// auto-generated file, do not modify!
//
#include "blurhash-rebol-extension.h"
MyCommandPointer Command[] = {
$cmd-dispatch};
}

;- output generated files ------------------------------------------------------
write %blurhash-rebol-extension.h reword :header self
write %blurhash-commands-table.c  reword :ctable self

