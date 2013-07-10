{
    "targets": [{
            "target_name": "png_compress",
            "cflags": [
                "-g",
                "-I.",
                "-O3",
                "-funroll-loops",
                "-fomit-frame-pointer",
                "-Wshadow",
                "-DZ_SOLO",
                "-DNO_ALONE"
            ],
            "sources": [
                    "png_compress.cpp",
                    "pngcrush/adler32.c",
                    "pngcrush/compress.c",
                    "pngcrush/crc32.c",
                    "pngcrush/deflate.c",
                    "pngcrush/infback.c",
                    "pngcrush/inffast.c",
                    "pngcrush/inflate.c",
                    "pngcrush/inftrees.c",
                    "pngcrush/trees.c",
                    "pngcrush/uncompr.c",
                    "pngcrush/zutil.c",
                    "pngcrush/pngcrush.c",
                    "pngcrush/png.c",
                    "pngcrush/pngerror.c",
                    "pngcrush/pngget.c",
                    "pngcrush/pngmem.c",
                    "pngcrush/pngpread.c",
                    "pngcrush/pngread.c",
                    "pngcrush/pngrio.c",
                    "pngcrush/pngrtran.c",
                    "pngcrush/pngrutil.c",
                    "pngcrush/pngset.c",
                    "pngcrush/pngtrans.c",
                    "pngcrush/pngwio.c",
                    "pngcrush/pngwrite.c",
                    "pngcrush/pngwtran.c",
                    "pngcrush/pngwutil.c"
            ]
    }]
}