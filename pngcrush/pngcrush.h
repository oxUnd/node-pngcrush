/* pngcrush.h */

/*
 * This software is released under a license derived from the libpng
 * license (see LICENSE, in pngcrush.c).
 */

/* Special defines for pngcrush. */

#ifndef PNGCRUSH_H
#define PNGCRUSH_H

#define PNG_INIT_FILE_SIZE 1024
#define PNG_BIG_FILE_SIZE 10240

typedef struct {
    png_bytep data;
    png_size_t length;
    png_size_t current;
} user_png_struct;

typedef user_png_struct * user_png_structp;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
    user_png_structp png_reduce(user_png_structp buffer, int argc, char *argv[]);
#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* !PNGCRUSH_H */
