[![Rebol-Easing CI](https://github.com/Oldes/Rebol-Easing/actions/workflows/main.yml/badge.svg)](https://github.com/Oldes/Rebol-Easing/actions/workflows/main.yml)

# Rebol/Easing

Collection of easing functions for [Rebol3](https://github.com/Oldes/Rebol3).
Based on Warren Moore's code: https://github.com/warrenm/AHEasing

## Usage
```rebol
ease: import 'easing

;; Using helper `tween` function
;; getting values between 100 and 200 with an in-elastic easing
t: 0.0 loop 21 [
    print [t tab tween 100 200 t 'in-cubic]
    t: t + 0.05
]
;; getting values between black and red colors with an out-elastic easing
t: 0.0 loop 21 [
    print [t tab tween 0.0.0 255.0.0 t 'out-elastic]
    t: t + 0.05
]

;; Using easing natives directly:
probe ease/in-out-quad 0.4
```

## Graph example results

Images generated using [gen-graphs.r3](https://github.com/Oldes/Rebol-Easing/blob/master/.github/gen-graphs.r3) script.

### Easing quadratic
![quadratic](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/1_ease_quad.png)
### Easing cubic
![cubic](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/2_ease_cubic.png)
### Easing quartic
![quartic](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/3_ease_quart.png)
### Easing sine
![sine](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/4_ease_sine.png)
### Easing circular
![circular](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/5_ease_circ.png)
### Easing exponential
![exponential](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/6_ease_expo.png)
### Easing elastic
![elastic](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/7_ease_elastic.png)
### Easing back
![back](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/8_ease_back.png)
### Easing bounce
![bounce](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/9_ease_bounce.png)
