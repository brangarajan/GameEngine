#include <sb6.h>

#pragma pack(1)

typedef struct {
    GLbyte          idlength;
    GLbyte          colorMapType;
    GLbyte          imageType;
    unsigned short	colorMapOrigin;
    unsigned short	colorMapLength;
    unsigned char	colorMapDepth;
    unsigned short	x_origin;
    unsigned short	y_origin;
    unsigned short	width;
    unsigned short	height;
    GLbyte          bitsPerPixel;
    GLbyte          imageDescriptor;
} TGAHEADER;

#pragma pack(8)