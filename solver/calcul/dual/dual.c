#include <math.h>
#include "dual.h"

HyperDual hd_const(double v) {
    return (HyperDual){ v, 0, 0, 0 };
}

HyperDual hd_var(double x0) {
    return (HyperDual){ x0, 1, 1, 0 };
}

HyperDual hd_add(HyperDual u, HyperDual v) {
    return (HyperDual){ u.r + v.r,
                         u.e_1 + v.e_1,
                         u.e_2 + v.e_2,
                         u.e_1_2 + v.e_1_2 };
}

HyperDual hd_sub(HyperDual u, HyperDual v) {
    return (HyperDual){ u.r - v.r,
                         u.e_1 - v.e_1,
                         u.e_2 - v.e_2,
                         u.e_1_2 - v.e_1_2 };
}

HyperDual hd_neg(HyperDual u) {
    return (HyperDual){ -u.r, -u.e_1, -u.e_2, -u.e_1_2 };
}

HyperDual hd_mul(HyperDual u, HyperDual v) {
    return (HyperDual){
        u.r  * v.r,
        u.e_1 * v.r  + u.r * v.e_1,
        u.e_2 * v.r  + u.r * v.e_2,
        u.e_1_2* v.r  + u.r * v.e_1_2 + u.e_1 * v.e_2 + u.e_2 * v.e_1
    };
}

HyperDual hd_inv(HyperDual v) {
    double a  = v.r;
    double a2 = a * a;
    double a3 = a2 * a;
    return (HyperDual){
         1.0 / a,
        -v.e_1 / a2,
        -v.e_2 / a2,
        -v.e_1_2 / a2 + 2.0 * v.e_1 * v.e_2 / a3
    };
}

HyperDual hd_div(HyperDual u, HyperDual v) { return hd_mul(u, hd_inv(v)); }

HyperDual hd_sin(HyperDual u) {
    double s = sin(u.r), c = cos(u.r);
    return (HyperDual){
        s,
        c * u.e_1,
        c * u.e_2,
        c * u.e_1_2 - s * u.e_1 * u.e_2
    };
}

HyperDual hd_cos(HyperDual u) {
    double s = sin(u.r), c = cos(u.r);
    return (HyperDual){
        c,
        -s * u.e_1,
        -s * u.e_2,
        -s * u.e_1_2 - c * u.e_1 * u.e_2
    };
}

HyperDual hd_exp(HyperDual u) {
    double e = exp(u.r);
    return (HyperDual){
        e,
        e * u.e_1,
        e * u.e_2,
        e * u.e_1_2 + e * u.e_1 * u.e_2
    };
}

HyperDual hd_log(HyperDual u) {
    double a  = u.r;
    double a2 = a * a;
    return (HyperDual){
        log(a),
        u.e_1 / a,
        u.e_2 / a,
        u.e_1_2 / a - u.e_1 * u.e_2 / a2
    };
}

HyperDual hd_pow(HyperDual u, double n) {
    double a = u.r;
    
    // Cas spécial : base nulle
    if (a == 0.0) {
        if (n > 1.0) return (HyperDual){ 0, 0, 0, 0 }; // x^n → 0, f'→0, f''→0
        if (n == 1.0) return hd_var(0.0);               // x^1 = x
        // n < 1 : dérivée infinie en 0, on ne peut pas converger ici
        return (HyperDual){ 0, INFINITY, INFINITY, INFINITY };
    }

    double a_n   = pow(a, n);
    double a_n_1 = pow(a, n - 1.0); // Plus sûr que a_n / a
    return (HyperDual){
        a_n,
        n * a_n_1 * u.e_1,
        n * a_n_1 * u.e_2,
        n * a_n_1 * u.e_1_2 + n * (n - 1.0) * pow(a, n - 2.0) * u.e_1 * u.e_2
    };
}
HyperDual hd_tan(HyperDual u) {
    double t  = tan(u.r);
    double sec2 = 1.0 + t * t; // sec²(x) = 1 + tan²(x)
    return (HyperDual){
        t,
        sec2 * u.e_1,
        sec2 * u.e_2,
        sec2 * u.e_1_2 + 2.0 * t * sec2 * u.e_1 * u.e_2
    };
}

HyperDual hd_asin(HyperDual u) {
    double d  = sqrt(1.0 - u.r * u.r);
    double d3 = d * d * d;
    return (HyperDual){
        asin(u.r),
        u.e_1 / d,
        u.e_2 / d,
        u.e_1_2 / d + u.r * u.e_1 * u.e_2 / d3
    };
}

HyperDual hd_acos(HyperDual u) {
    double d  = sqrt(1.0 - u.r * u.r);
    double d3 = d * d * d;
    return (HyperDual){
        acos(u.r),
        -u.e_1 / d,
        -u.e_2 / d,
        -u.e_1_2 / d - u.r * u.e_1 * u.e_2 / d3
    };
}

HyperDual hd_atan(HyperDual u) {
    double d  = 1.0 + u.r * u.r;
    return (HyperDual){
        atan(u.r),
        u.e_1 / d,
        u.e_2 / d,
        u.e_1_2 / d - 2.0 * u.r * u.e_1 * u.e_2 / (d * d)
    };
}

HyperDual hd_sqrt(HyperDual u) {
    double s  = sqrt(u.r);
    double s3 = s * s * s; // Pour la dérivée seconde
    return (HyperDual){
        s,
        u.e_1 / (2.0 * s),
        u.e_2 / (2.0 * s),
        u.e_1_2 / (2.0 * s) - u.e_1 * u.e_2 / (4.0 * s3)
    };
}

HyperDual hd_abs(HyperDual u) {
    // Dérivée non définie en 0, on utilise le signe
    double sgn = (u.r > 0) ? 1.0 : (u.r < 0) ? -1.0 : 0.0;
    return (HyperDual){
        fabs(u.r),
        sgn * u.e_1,
        sgn * u.e_2,
        sgn * u.e_1_2   // dérivée seconde = 0 sauf en 0
    };
}

HyperDual hd_sinh(HyperDual u) {
    double sh = sinh(u.r), ch = cosh(u.r);
    return (HyperDual){
        sh,
        ch * u.e_1,
        ch * u.e_2,
        ch * u.e_1_2 + sh * u.e_1 * u.e_2
    };
}

HyperDual hd_cosh(HyperDual u) {
    double sh = sinh(u.r), ch = cosh(u.r);
    return (HyperDual){
        ch,
        sh * u.e_1,
        sh * u.e_2,
        sh * u.e_1_2 + ch * u.e_1 * u.e_2
    };
}

HyperDual hd_tanh(HyperDual u) {
    double t   = tanh(u.r);
    double sech2 = 1.0 - t * t;
    return (HyperDual){
        t,
        sech2 * u.e_1,
        sech2 * u.e_2,
        sech2 * u.e_1_2 - 2.0 * t * sech2 * u.e_1 * u.e_2
    };
}
