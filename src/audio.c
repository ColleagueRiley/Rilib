/*
*
*	Rilib 0.01-dev
*
*
* <Rilib technologies>
* This is free and unencumbered software released into the public domain.
* Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
* software, either in source code form or as a compiled binary, for any purpose,
* commercial or non-commercial, and by any means.
* In jurisdictions that recognize copyright laws, the author or authors of this
* software dedicate any and all copyright interest in the software to the public
* domain. We make this dedication for the benefit of the public at large and to
* the detriment of our heirs and successors. We intend this dedication to be an
* overt act of relinquishment in perpetuity of all present and future rights to
* this software under copyright law.
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include "rilib.h"
#include "deps/miniaudio.h"

#include <stdio.h>

ma_engine engine;

i32 riAudio_init() {
    ma_result result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        fprintf(stderr, "Failed to initialize audio engine\n");
        return -1;
    }
    return 0;
}

i32 riAudio_play(const char* file) {
    ma_result result = ma_engine_play_sound(&engine, file, NULL);
    if (result != MA_SUCCESS) {
        fprintf(stderr, "Failed to play sound %s\n", file);
        ma_engine_uninit(&engine);
        return -1;
    }
    return 1;
}

void riAudio_free() {
    ma_engine_uninit(&engine);
}
 
