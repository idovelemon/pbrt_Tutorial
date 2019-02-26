#include "imageio.h"
#include <cctype>
#include <memory>
#include <Windows.h>

namespace pbrt_tutorial {

void WriteImage(const std::string& fileName, float* rgb, const Point2i& resolution) {
    auto HasExtension = [](const std::string& fileName, const std::string& ending) {
        if (ending.size() > fileName.size()) return false;

        return std::equal(ending.rbegin(), ending.rend(), fileName.rbegin(),
            [](char a, char b) { return std::tolower(a) == std::tolower(b); });
    };

    // Only support BMP image format now
    if (HasExtension(fileName, ".bmp")) {
        FILE* file = nullptr;
        fopen_s(&file, fileName.c_str(), "wb");
        if (!file) {
            return;
        }

        BITMAPFILEHEADER bmpFileHeader;
        memset(&bmpFileHeader, 0, sizeof(bmpFileHeader));
        bmpFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
        bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + resolution.x * resolution.y * 4;
        bmpFileHeader.bfType = (WORD)(0x4d42);

        BITMAPINFOHEADER bmpHeader;
        memset(&bmpHeader, 0, sizeof(bmpHeader));
        bmpHeader.biBitCount = 32;
        bmpHeader.biClrImportant = BI_RGB;
        bmpHeader.biHeight = resolution.y;
        bmpHeader.biPlanes = 1;
        bmpHeader.biSize = sizeof(BITMAPINFOHEADER);
        bmpHeader.biSizeImage = resolution.x * resolution.y * 4;
        bmpHeader.biWidth = resolution.x;

        std::unique_ptr<unsigned char[]> bmpData(new unsigned char[resolution.x * resolution.y * 4]);
        memset(bmpData.get(), 0, resolution.x * resolution.y * 4);
        for (int i = 0; i < resolution.y; i++) {
            for (int j = 0; j < resolution.x; j++) {
                bmpData[i * resolution.x * 4 + j * 4 + 2] = static_cast<unsigned char>(rgb[(resolution.y - 1 - i) * resolution.x * 3 + j * 3 + 0] * 255);
                bmpData[i * resolution.x * 4 + j * 4 + 1] = static_cast<unsigned char>(rgb[(resolution.y - 1 - i) * resolution.x * 3 + j * 3 + 1] * 255);
                bmpData[i * resolution.x * 4 + j * 4 + 0] = static_cast<unsigned char>(rgb[(resolution.y - 1 - i) * resolution.x * 3 + j * 3 + 2] * 255);
                bmpData[i * resolution.x * 4 + j * 4 + 3] = 0xff;
            }
        }

        fwrite(&bmpFileHeader, 1, sizeof(bmpFileHeader), file);
        fwrite(&bmpHeader, 1, sizeof(bmpHeader), file);
        fwrite(bmpData.get(), 1, resolution.x * resolution.y * 4, file);
        fclose(file);
    }
}

};