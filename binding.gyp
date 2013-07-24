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
                    "src/png_compress.cpp",
                    "src/pngcrush/adler32.c",
                    "src/pngcrush/compress.c",
                    "src/pngcrush/crc32.c",
                    "src/pngcrush/deflate.c",
                    "src/pngcrush/infback.c",
                    "src/pngcrush/inffast.c",
                    "src/pngcrush/inflate.c",
                    "src/pngcrush/inftrees.c",
                    "src/pngcrush/trees.c",
                    "src/pngcrush/uncompr.c",
                    "src/pngcrush/zutil.c",
                    "src/pngcrush/pngcrush.c",
                    "src/pngcrush/png.c",
                    "src/pngcrush/pngerror.c",
                    "src/pngcrush/pngget.c",
                    "src/pngcrush/pngmem.c",
                    "src/pngcrush/pngpread.c",
                    "src/pngcrush/pngread.c",
                    "src/pngcrush/pngrio.c",
                    "src/pngcrush/pngrtran.c",
                    "src/pngcrush/pngrutil.c",
                    "src/pngcrush/pngset.c",
                    "src/pngcrush/pngtrans.c",
                    "src/pngcrush/pngwio.c",
                    "src/pngcrush/pngwrite.c",
                    "src/pngcrush/pngwtran.c",
                    "src/pngcrush/pngwutil.c"
            ]
    }]
}