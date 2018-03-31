#pragma once

#include "renderDevice.hpp"
#include "arrayBitmap.hpp"

class Texture
{
public:
	inline Texture(RenderDevice& deviceIn, const ArrayBitmap& texData,
			enum RenderDevice::PixelFormat internalPixelFormat,
			bool generateMipmaps, bool shouldCompress) :
		device(&deviceIn),
		texId(device->createTexture2D(texData.getWidth(),
				texData.getHeight(), texData.getPixelArray(),
				RenderDevice::FORMAT_RGBA,
				internalPixelFormat, generateMipmaps, shouldCompress)),
		width((uint32)texData.getWidth()),
		height((uint32)texData.getHeight()) {}
	inline ~Texture()
	{
		texId = device->releaseTexture2D(texId);
	}

	inline uint32 getId();
	inline uint32 getWidth();
	inline uint32 getHeight();
private:
	RenderDevice* device;
	uint32 texId;
	uint32 width;
	uint32 height;

	NULL_COPY_AND_ASSIGN(Texture);
};

inline uint32 Texture::getId()
{
	return texId;
}

inline uint32 Texture::getWidth()
{
	return width;
}

inline uint32 Texture::getHeight()
{
	return height;
}

