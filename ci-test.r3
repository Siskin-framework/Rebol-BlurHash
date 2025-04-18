Rebol [
    title: "Rebol/BlurHash extension CI test"
]

print ["Running test on Rebol build:" mold to-block system/build]

;; make sure that we load a fresh extension
try [system/modules/blurhash: none]
;; use current directory as a modules location
system/options/modules: what-dir

;; import the extension
blurhash: import 'blurhash

;; print content of the module...
? blurhash

image: load %test/koule.jpg
print    [ "Encoding image of size" as-green image/size ]
time: dt [ hash: blurhash/encode image  ]
print    [ "Result:" as-green mold hash ]
print    [ "In time:" as-yellow time LF ]


file: %test/koule-blur-1.png
print    ["Decoding hash into image" as-green file "of size" as-green 512x512]
time: dt [ blured: blurhash/decode hash 512x512 ]
print    [ "In time:" as-yellow time LF ]
save file blured

file: %test/koule-blur-2.png
print    ["Decoding hash into image" as-green file "of size" as-green 32x32 "and resized to" as-green 512x512]
time: dt [ blured: resize blurhash/decode hash 32x32 512x512 ]
print    [ "In time:" as-yellow time LF ]
save file blured