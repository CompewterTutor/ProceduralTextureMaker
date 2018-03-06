/**
 * Part of the ProceduralTextureMaker project.
 * http://github.com/johanokl/ProceduralTextureMaker
 * Released under GPLv3.
 * Johan Lindqvist (johan.lindqvist@gmail.com)
 */

#ifndef NOISETEXTUREGENERATOR_H
#define NOISETEXTUREGENERATOR_H

#include "texturegenerator.h"

/**
 * @brief The NoiseTextureGenerator class
 */
class NoiseTextureGenerator : public TextureGenerator
{
public:
   NoiseTextureGenerator();
   virtual ~NoiseTextureGenerator() {}
   virtual void generate(QSize size,
                         TexturePixel* destimage,
                         QMap<int, TextureImagePtr> sourceimages,
                         TextureNodeSettings* settings) const;
   virtual int getNumSourceSlots() const { return 1; }
   virtual QString getName() const { return QString("Noise"); }
   virtual const TextureGeneratorSettings& getSettings()  const { return configurables; }
   virtual QString getDescription() const { return QString("Pure noise."); }
   virtual TextureGenerator::Type getType() const { return TextureGenerator::Type::Generator; }

private:
   TextureGeneratorSettings configurables;
};

#endif // NOISETEXTUREGENERATOR_H
