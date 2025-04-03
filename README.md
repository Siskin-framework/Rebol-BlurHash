[![rebol-blurhash](https://github.com/user-attachments/assets/3b5b60cb-d8a9-48cd-82ca-9401ec1fd01c)](https://github.com/Siskin-framework/Rebol-BlurHash)

[![Rebol-BlurHash CI](https://github.com/Siskin-Framework/Rebol-BlurHash/actions/workflows/main.yml/badge.svg)](https://github.com/Siskin-Framework/Rebol-BlurHash/actions/workflows/main.yml)
[![Gitter](https://badges.gitter.im/rebol3/community.svg)](https://app.gitter.im/#/room/#Rebol3:gitter.im)
[![Zulip](https://img.shields.io/badge/zulip-join_chat-brightgreen.svg)](https://rebol.zulipchat.com/)

# Rebol/BlurHash

[Wolt's BlurHash](https://github.com/woltapp/blurhash) as an extension for [Rebol3](https://github.com/Oldes/Rebol3).

## Usage
```rebol
blurhash: import 'blurhash

;; load some input image...
image: load %test/koule.jpg

;; encode the image into blurhash text...
hash: blurhash/encode image

;; display the result in console...
? hash

;; HASH is a string of value: "KRG[vKbFE1^^cnNs+}Q$*kD"

;; decode the hash back to image of specified size...
blured1: blurhash/decode hash 512x512

;; ... or into some existing image...
blurhash/decode hash image
```

For better performance (cca 10x faster) when displaying many blured images, it is better to decode into a small image and then resize the result. Like:

```rebol
blured2: blurhash/decode hash 32x32
blured2: resize blured2 512x512
```

Which can be written also like:

```rebol
blured2: resize blurhash/decode hash 32x32 512x512
```

- - - - -

Original image:

![original](https://raw.githubusercontent.com/Siskin-Framework/Rebol-BlurHash/main/test/koule.jpg)

Blured image using direct size:

![blured1](https://raw.githubusercontent.com/Siskin-Framework/Rebol-BlurHash/main/test/koule-blur-1.png)

Blured image using small size 32x32 and then resized:

![blured2](https://raw.githubusercontent.com/Siskin-Framework/Rebol-BlurHash/main/test/koule-blur-2.png)
