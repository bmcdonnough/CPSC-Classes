#include "ppmUtil.h"

void writeHeader(FILE *image, header_t head)
{
    fprintf(image, "%c%c\n%d %d\n%d\n", head.type[0], head.type[1],
            head.width, head.height, head.maxVal);
}
void writePixels(FILE *image, pixel_t *p, header_t head)
{
    fwrite(p, sizeof(p), (head.width * head.height), image);
}

pixel_t *readPixels(FILE *image, header_t head)
{
    pixel_t *pixels = allocatePixMemory(head);

    for (int i = 0; i < head.width * head.height; i++)
    {
        fread(&pixels[i].r, sizeof(pixels->r), 1, image);
        fread(&pixels[i].g, sizeof(pixels->g), 1, image);
        fread(&pixels[i].b, sizeof(pixels->b), 1, image);
    }

    return pixels;
}

pixel_t *read(FILE *in, header_t *head)
{
    readHeader(in, head);

    return readPixels(in, *head);
}
void write(FILE *image, header_t head, pixel_t *pix)
{
    writeHeader(image, head);
    writePixels(image, pix, head);
}

pixel_t *allocatePixMemory(header_t h)
{
    pixel_t *pixMem = (pixel_t *)malloc(h.height * h.width * sizeof(pixel_t));

    return pixMem;
}

void ckComment(FILE *in)
{
    char buffer[100];
    char c;
    c = fgetc(in);
    while (c == '#' || c == ' ' || c == '\n')
    {
        if (c == '#')
        {
            fgets(buffer, sizeof(buffer), in);
        }
        c = fgetc(in);
    }

    fseek(in, -1, SEEK_CUR);
}

void readHeader(FILE *in, header_t *hdr)
{
    // Read in the type from the header and check for comments
    fscanf(in, "%c%c", &hdr->type[0], &hdr->type[1]);
    ckComment(in);

    // Read in the width from the header and check for comments
    fscanf(in, "%u[^#]", &hdr->width);
    ckComment(in);

    // Read in the height from the header and check for comments
    fscanf(in, "%u[^#]", &hdr->height);
    ckComment(in);

    // Read in the maxVal from the header and check for comments
    fscanf(in, "%u[^#]", &hdr->maxVal);
    ckComment(in);
}

void freeMemory(pixel_t *pix)
{
    free(pix);
}
