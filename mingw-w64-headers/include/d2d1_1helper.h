/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _D2D1_1HELPER_H_
#define _D2D1_1HELPER_H_

#ifndef D2D_USE_C_DEFINITIONS

namespace D2D1 {

    D2D1FORCEINLINE D2D1_VECTOR_2F Vector2F(FLOAT x = 0.0f, FLOAT y = 0.0f) {
        D2D1_VECTOR_2F r = {x, y};
        return r;
    }

}

#endif /* D2D_USE_C_DEFINITIONS */

#endif /* _D2D1_1HELPER_H_ */
