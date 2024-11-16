#include "calendar.h"

void FullMoon(const Int n, const Int npn, Int& jd, Doub& frac)
{
    constexpr Doub rad = 3.141592653589793238 / 180.0;
    const Doub     c   = n + npn / 4.0;
    const Doub     t   = c / 1236.85;
    const Doub     t2  = t * t;
    const Doub     as  = 359.2242 + 29.105356 * c;
    const Doub     am  = 306.0253 + 385.816918 * c + 0.010730 * t2;
    jd                 = 2415020 + 28 * n + npn;
    Doub xtra          = 0.75933 + 1.53058868 * c + ((1.178e-4) - (1.55e-7) * t) * t2;
    if (npn == 0 || npn == 2)
    {
        xtra += (0.1734 - 3.93e-4 * t) * sin(rad * as) - 0.4068 * sin(rad * am);
    }
    else if (npn == 1 || npn == 3)
    {
        xtra += (0.1721 - 4.0e-4 * t) * sin(rad * as) - 0.6280 * sin(rad * am);
    }
    else
    {
        throw("Error in FullMoon: npn must be 0, 1, 2, or 3");
    }
    const Int i = static_cast<Int>(xtra >= 0.0 ? floor(xtra) : ceil(xtra - 1.0));
    jd += i;
    frac = xtra - i;
}

Int JulDay(const Int mm, const Int id, Int iyyy)
{
    constexpr Int igreg = 15 + 31 * (10 + 12 * 1582);
    Int           jy    = iyyy;
    Int           jm;
    if (jy == 0) throw("julday: there is no year zero.");
    if (jy < 0) ++jy;
    if (mm > 2)
    {
        jm = mm + 1;
    }
    else
    {
        --jy;
        jm = mm + 13;
    }
    Int jul = static_cast<Int>(floor(365.25 * jy) + floor(30.6001 * jm) + id + 1720995);
    if (id + 31 * (mm + 12 * iyyy) >= igreg)
    {
        const Int ja = static_cast<Int>(0.01 * jy);
        jul += 2 - ja + static_cast<Int>(0.25 * ja);
    }
    return jul;
}

void CalDat(const Int julian, Int& mm, Int& id, Int& iyyy)
{
    Int ja;
    if (constexpr Int igreg = 2299161; julian >= igreg)
    {
        const Int jAlpha = static_cast<Int>
            ((static_cast<Doub>(julian - 1867216) - 0.25) / 36524.25);
        ja = julian + 1 + jAlpha - static_cast<Int>(0.25 * jAlpha);
    }
    else if (julian < 0)
    {
        ja = julian + 36525 * (1 - julian / 36525);
    }
    else
        ja = julian;
    const Int jb = ja + 1524;
    const Int jc = static_cast<Int>(6680.0 +
                                    (static_cast<Doub>(jb - 2439870) - 122.1) /
                                    365.25);
    const Int jd = static_cast<Int>(365 * jc + (0.25 * jc));
    const Int je = static_cast<Int>((jb - jd) / 30.6001);
    id           = jb - jd - static_cast<Int>(30.6001 * je);
    mm           = je - 1;
    if (mm > 12) mm -= 12;
    iyyy = jc - 4715;
    if (mm > 2) --iyyy;
    if (iyyy <= 0) --iyyy;
    if (julian < 0) iyyy -= 100 * (1 - julian / 36525);
}
